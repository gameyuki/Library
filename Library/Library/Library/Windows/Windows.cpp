//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include"Windows.h"
#include"Library\MyDefine\macro.h"

LRESULT WINAPI WinProc(HWND _hWnd, UINT _msg, WPARAM _wp, LPARAM _lp)
{
	switch (_msg)
	{
	case WM_KEYDOWN:
		switch (_wp)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_CLOSE:
		DestroyWindow(_hWnd);
		return 0;
	}

	return DefWindowProc(_hWnd, _msg, _wp, _lp);
}

//--------------------------------------------------
//	public function
//--------------------------------------------------
Windows::Windows() :m_hWnd(nullptr)
{

}

Windows::~Windows()
{
	Finalize();
}

bool Windows::Initialize(LPCTSTR _pWindowName, int _windowWidth, int _windowHeight, DWORD _style)
{
	//Window�N���X�̐ݒ�
	WNDCLASSEX Wndclass;
	Wndclass.cbSize = sizeof(Wndclass);
	Wndclass.style = CS_HREDRAW | CS_VREDRAW;
	Wndclass.lpfnWndProc = WinProc;
	Wndclass.cbClsExtra = 0;
	Wndclass.cbWndExtra = 0;
	Wndclass.hInstance = GetModuleHandle(nullptr);
	Wndclass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	Wndclass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	Wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	Wndclass.lpszMenuName = nullptr;
	Wndclass.lpszClassName = _pWindowName;
	Wndclass.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);

	/* �E�C���h�E�N���X�̓o�^ */
	RegisterClassEx(&Wndclass);

	m_hWnd = CreateWindow(
		_pWindowName,
		_pWindowName,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0,
		0,
		_windowWidth,
		_windowHeight,
		nullptr,
		nullptr,
		GetModuleHandle(nullptr),
		nullptr);

	if (m_hWnd == nullptr)
	{
		DebugBreak();
		MessageBox(0, "�E�C���h�E�̍쐬�Ɏ��s���܂���", NULL, MB_OK);
		return false;
	}

	UpdateWindow(m_hWnd);

	ZeroMemory(&m_WindowMsg, sizeof(m_WindowMsg));

	return true;
}

void Windows::Finalize()
{
	if (m_hWnd != nullptr)
	{
		SendMessage(m_hWnd, WM_CLOSE, 0, 0);
	}
}

bool Windows::Update()
{
	if (m_WindowMsg.message != WM_QUIT)
	{
		if (PeekMessage(&m_WindowMsg, nullptr, 0, 0, PM_REMOVE))	//PeekMessage�Ń��b�Z�[�W�����Ă��Ȃ����m�F���ė��Ă��������
		{
			TranslateMessage(&m_WindowMsg);		//���b�Z�[�W��Proc���ǂ߂�悤�ɖ|�󂷂�
			DispatchMessage(&m_WindowMsg);		//���b�Z�[�W��Proc�ɑ��M���Ă���
		}

		return false;
	}

	m_hWnd = nullptr;

	return true;
}