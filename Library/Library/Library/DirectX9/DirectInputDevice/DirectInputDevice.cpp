//--------------------------------------------------
//	include
//--------------------------------------------------
#include"DirectInputDevice.h"
#include"..\Library\Library\MyDefine\macro.h"

namespace Lib
{

	//--------------------------------------------------
	//	コンストラクタ : デストラクタ
	//--------------------------------------------------
	DirectInputDevice::DirectInputDevice(HWND _hWnd) :m_hWnd(_hWnd)
	{
	}

	DirectInputDevice::~DirectInputDevice()
	{
	}

	//--------------------------------------------------
	//	public function
	//--------------------------------------------------
	void DirectInputDevice::InitDinput()
	{

		/* DirectInputオブジェクトの作成 */
		if (FAILED(DirectInput8Create(
			GetModuleHandle(NULL),
			DIRECTINPUT_VERSION,
			IID_IDirectInput8,
			(VOID**)&m_pDinput,
			NULL)))
		{
			OutPutError("DirectInputの作成に失敗しました");
		}
	}

	bool DirectInputDevice::KeyInitialize()
	{
		/* キーデバイスの初期化 */
		if (FAILED(m_pDinput->CreateDevice(
			GUID_SysKeyboard,
			&m_pKeyDevice,
			NULL)))
		{
			OutPutError("キーの作成に失敗しました");
			return false;
		}

		/* データフォーマット */
		if (FAILED(m_pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
		{
			OutPutError("キーの作成に失敗しました");
			return false;
		}

		/* 協調レベルの設定 */
		if (FAILED(m_pKeyDevice->SetCooperativeLevel(
			m_hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
		{
			OutPutError("キーの作成に失敗しました");
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
			OutPutError("マウスの作成に失敗しました");
			return false;
		}

		/* データフォーマット */
		if (FAILED(m_pDIMouse->SetDataFormat(&c_dfDIMouse)))
		{
			OutPutError("DirectInputの作成に失敗しました");
			return false;
		}

		/* 協調レベルの設定 */
		if (FAILED(m_pDIMouse->SetCooperativeLevel(m_hWnd,
			DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)))
		{
			OutPutError("マウスの作成に失敗しました");
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
			OutPutError("マウスの作成に失敗しました");
			return false;
		}

		diprop.dwData = Buffer_Size;

		if (FAILED(m_pDIMouse->SetProperty(
			DIPROP_BUFFERSIZE,
			&diprop.diph)))
		{
			OutPutError("マウスの作成に失敗しました");
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
		if (m_pKeyDevice != nullptr)
		{
			m_pKeyDevice->Unacquire();
		}
		SafeRelease(m_pKeyDevice);
	}

	void DirectInputDevice::ReleaseMouse()
	{
		if (m_pDIMouse != nullptr)
		{
			m_pDIMouse->Unacquire();
		}
		SafeRelease(m_pDIMouse);
	}
}