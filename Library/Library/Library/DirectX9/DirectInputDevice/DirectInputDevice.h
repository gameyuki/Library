#ifndef DIRECTINPUTDEVICE_H
#define	DIRECTINPUTDEVICE_H

//--------------------------------------------------
//	include
//--------------------------------------------------
#include<dinput.h>
#include<Windows.h>


#include"Library\SingletonBase\SingletonBase.h"


namespace Lib
{
	namespace Dx9
	{
		//--------------------------------------------------
		//	Struct
		//--------------------------------------------------
		struct MOUSEKIND
		{
			/* クリック情報(クリックされていればtrue). */
			bool IsLeftClick, IsRightClick;
			/* マウスの移動量 */
			int lx, ly, lz;//(Zはホイール)
		};

		//--------------------------------------------------
		//	enum
		//--------------------------------------------------
		/* キーボードの状態 */
		enum KEYSTATE
		{
			KEYS_PRESSED,	//<<単発押し
			KEYS_RELEASE,	//<<離された時の1舜
			KEYS_DOWN,		//<<長押し用
			KEYS_OFF		//<<ボタン未入力
		};

		//--------------------------------------------------
		//	class
		//--------------------------------------------------
		/*
		*	DirectInputクラス
		*/
		class DirectInputDevice :public SingletonBase<DirectInputDevice>
		{
		public:
			//--------------------------------------------------
			//	public function
			//--------------------------------------------------
			/*
			*	コンストラクタ
			*/
			DirectInputDevice(HWND _hWnd);

			/*
			*	デストラクタ
			*/
			~DirectInputDevice();

			/*
			*	DirectInputオブジェクトの作成
			*/
			void InitDinput();

			/*
			*	キーオブジェクトの初期化
			*/
			bool KeyInitialize();

			/*
			*	マウスオブジェクトの初期化
			*/
			bool MouseInitialize();

			/*
			*	Dinputの削除
			*/
			void Finalize();

			/*
			*	マウスのチェック
			*/
			void MouseCheck(MOUSEKIND* _Mouse);

			/*
			*	マウスの座標を返す
			*/
			inline POINT GetMousePos()
			{
				GetCursorPos(&m_Po);
				return m_Po;
			}

			/*
			*	キーボードのチェック
			*/
			void KeyDownCheck(KEYSTATE* _Key, int _DIK);

		private:
			//--------------------------------------------------
			//	private function
			//--------------------------------------------------
			/*
			*	キーボードの解放
			*/
			void ReleaseKey();

			/*
			*	マウスの解放
			*/
			void ReleaseMouse();

			//--------------------------------------------------
			//	private variable
			//--------------------------------------------------

			/*
			*	DirectInputオブジェクトの格納先
			*/
			LPDIRECTINPUT8 m_pDinput = nullptr;

			/*
			*	マウスデバイス
			*/
			LPDIRECTINPUTDEVICE8 m_pDIMouse = nullptr;

			/*
			*	キーデバイス
			*/
			LPDIRECTINPUTDEVICE8 m_pKeyDevice = nullptr;

			/*
			*	DirectInputクラス固有のハンドル
			*/
			HWND m_hWnd;

			/*
			*	マウス座標
			*/
			POINT m_Po;

			/*
			*	マウスのバッファーの大きさ
			*/
			const int Buffer_Size = 64;

			/*
			*	キー配列
			*/
			BYTE diks[256];

			/*
			*	前キー配列
			*/
			static int Old_diks[256];
		};
	}
}
#endif