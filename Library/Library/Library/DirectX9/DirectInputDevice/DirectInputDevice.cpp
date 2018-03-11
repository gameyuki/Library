//--------------------------------------------------
//	include
//--------------------------------------------------
#include"DirectInputDevice.h"
#include"Library\MyDefine\macro.h"

//--------------------------------------------------
//	public function
//--------------------------------------------------
void DirectInputDevice::InitDinput(HWND _hWnd)
{
	m_hWnd = _hWnd;

	/* DirectInputオブジェクトの作成 */
	if (FAILED(DirectInput8Create(
		GetModuleHandle(NULL),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(VOID**)&m_pDinput,
		NULL)))
	{
		MessageBox(0, "DirectInputの作成に失敗しました", NULL, MB_OK);
	}
}

bool DirectInputDevice::KeyInitialize() 
{
	if (FAILED(m_pDinput->CreateDevice(
		GUID_SysKeyboard,
		&m_pKeyDevice,
		NULL)))
	{
		MessageBox(0, "キーの作成に失敗しました", NULL, MB_OK);
		return false;
	}

	if (FAILED(m_pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		MessageBox(0, "キーの作成に失敗しました", NULL, MB_OK);
		return false;
	}

	if (FAILED(m_pKeyDevice->SetCooperativeLevel(
		m_hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		MessageBox(0, "キーの作成に失敗しました", NULL, MB_OK);
		return false;
	}

	m_pKeyDevice->Acquire();
	return true;
}

bool DirectInputDevice::MouseInitialize()
{
	/* マウスの初期化 */
	if (FAILED(m_pDinput->CreateDevice(
		GUID_SysMouse,
		&m_pDIMouse,
		NULL)))
	{
		MessageBox(0, "マウスの作成に失敗しました", NULL, MB_OK);
		return false;
	}

	/* データフォーマット */
	if (FAILED(m_pDIMouse->SetDataFormat(&c_dfDIMouse)))
	{
		MessageBox(0, "DirectInputの作成に失敗しました", NULL, MB_OK);
		return false;
	}

	/* 協調レベルの設定 */
	if (FAILED(m_pDIMouse->SetCooperativeLevel(m_hWnd,
		DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)))
	{
		MessageBox(0, "マウスの作成に失敗しました", NULL, MB_OK);
		return false;
	}

	DIPROPDWORD diprop;
	diprop.diph.dwSize = sizeof(diprop);
	diprop.diph.dwHeaderSize = sizeof(diprop.diph);
	diprop.diph.dwObj = 0;
	diprop.diph.dwHow = DIPH_DEVICE;
	diprop.dwData = DIPROPAXISMODE_REL;

	if (FAILED(m_pDIMouse->SetProperty(
		DIPROP_AXISMODE,
		&diprop.diph)))
	{
		MessageBox(0, "マウスの作成に失敗しました", NULL, MB_OK);
		return false;
	}

	diprop.dwData = Buffer_Size;

	if (FAILED(m_pDIMouse->SetProperty(
		DIPROP_BUFFERSIZE,
		&diprop.diph)))
	{
		MessageBox(0, "マウスの作成に失敗しました", NULL, MB_OK);
		return false;
	}
	m_pDIMouse->Acquire();
	return true;
}

void DirectInputDevice::Finalize()
{
	ReleaseKey();
	ReleaseMouse();
}

void DirectInputDevice::MouseCheck(MOUSEKIND* _Mouse)
{
	DIMOUSESTATE MouseState;

	m_pDIMouse->Acquire();
	HRESULT hr = m_pDIMouse->GetDeviceState(sizeof(DIMOUSESTATE), &MouseState);
	if (SUCCEEDED(hr))
	{
		if (MouseState.rgbButtons[0])
		{
			_Mouse->IsLeftClick = true;
		}
		else
		{
			_Mouse->IsLeftClick = false;
		}

		if (MouseState.rgbButtons[1])
		{
			_Mouse->IsRightClick = true;
		}
		else
		{
			_Mouse->IsRightClick = false;
		}

		if (MouseState.lX)
		{
			_Mouse->lx = MouseState.lX;
		}

		if (MouseState.lY)
		{
			_Mouse->ly = MouseState.lY;
		}

		/* ホイール */
		if (MouseState.lZ)
		{
			_Mouse->lz = MouseState.lZ;
		}
	}
}

void DirectInputDevice::KeyCheckDinput(KEYSTATE* _Key, int _DIK)
{
	BYTE diks[256];
	static int old_diks[256] = { OFF };

	HRESULT hr = m_pKeyDevice->Acquire();

	if ((hr == DI_OK) || (hr == S_FALSE))
	{

		m_pKeyDevice->GetDeviceState(sizeof(diks), &diks);
		if (diks[_DIK] & 0x80)
		{
			if (old_diks[_DIK] == OFF)
			{
				*_Key = PUSH;
			}
			else
			{
				*_Key = ON;
			}

			old_diks[_DIK] = ON;
		}
		else
		{
			if (old_diks[_DIK] == ON)
			{
				*_Key = RELEASE;
			}
			else
			{
				*_Key = OFF;
			}
			old_diks[_DIK] = OFF;
		}
	}
}

//--------------------------------------------------
//	private function
//--------------------------------------------------
void DirectInputDevice::ReleaseKey()
{
	if (m_pKeyDevice)
	{
		m_pKeyDevice->Unacquire();
	}
	SafeRelease(m_pKeyDevice);
}

void DirectInputDevice::ReleaseMouse()
{
	if (m_pDIMouse != NULL)
	{
		m_pDIMouse->Unacquire();
	}
	SafeRelease(m_pDIMouse);
}