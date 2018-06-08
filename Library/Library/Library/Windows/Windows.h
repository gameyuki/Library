#ifndef WINDOWS_H
#define	WINDOWS_H

//--------------------------------------------------
//	include
//--------------------------------------------------
#include<Windows.h>


namespace Lib
{
	//--------------------------------------------------
	//	 class
	//--------------------------------------------------
	/*
	*	Window生成用クラス
	*/
	class Windows
	{
	public:
		//--------------------------------------------------
		//	public function
		//--------------------------------------------------
		/*
		*	コンストラクタ
		*/
		Windows();

		/*
		*	デストラクタ
		*/
		~Windows();

		/*
		*	ウインドウ生成
		*	第一引数	ウィンドウの名前
		*	第二引数	ウィンドウの横幅
		*	第三引数	ウインドウの高さ
		*/
		bool Initialize(
			LPCTSTR _pWindowName,
			int _windowWidth,
			int _windowHeight);

		/*
		*	ウインドウ破棄
		*/
		void Finalize();

		/*
		*	ウインドウの更新
		*	ウインドウが破棄されていたらtrue 生きていたらfalse
		*/
		bool Update();

		/*
		*	ウインドウハンドルを返す
		*/
		inline HWND GetWndHandle() const
		{
			return m_hWnd;
		}

	private:
		//--------------------------------------------------
		//	private variable
		//--------------------------------------------------
		/*
		*	ウインドウハンドル
		*/
		HWND m_hWnd;
		/*
		*	ウインドウメッセージ構造体変数
		*/
		MSG m_WindowMsg;
	};
}

#endif