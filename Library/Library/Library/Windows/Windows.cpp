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
	//Windowクラスの設定
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

	/* ウインドウクラスの登録 */
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
		MessageBox(0, "ウインドウの作成に失敗しました", NULL, MB_OK);
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
		if (PeekMessage(&m_WindowMsg, nullptr, 0, 0, PM_REMOVE))	//PeekMessageでメッセージが来ていないか確認して来ていたら入る
		{
			TranslateMessage(&m_WindowMsg);		//メッセージをProcが読めるように翻訳する
			DispatchMessage(&m_WindowMsg);		//メッセージをProcに送信している
		}

		return false;
	}

	m_hWnd = nullptr;

	return true;
}