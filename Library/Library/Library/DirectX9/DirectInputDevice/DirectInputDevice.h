#ifndef DIRECTINPUTDEVICE_H
#define	DIRECTINPUTDEVICE_H

//--------------------------------------------------
//	include
//--------------------------------------------------
#include<dinput.h>
#include<Windows.h>


#include"Library\SingletonBase\SingletonBase.h"


//--------------------------------------------------
//	Struct
//--------------------------------------------------
typedef struct
{
	/* クリック情報(クリックされていればtrue). */
	bool IsLeftClick, IsRightClick;	
	/* マウスの移動量 */
	int lx, ly, lz;//(Zはホイール)

} MOUSEKIND;

//--------------------------------------------------
//	enum
//--------------------------------------------------
/* キーボードの状態 */
enum KEYSTATE
{
	PUSH,
	RELEASE,
	ON,
	OFF
};

/* キーボードの種類 */
enum KEYKIND
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	FIRE,
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	SPACE,
	ESC,
	LSHIFT,
	RSHIFT,
	ESCAPE,
	KEYMAX
};

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
	*	デストラクタ
	*/
	~DirectInputDevice() {};

	/*
	*	DirectInputオブジェクトの作成
	*/
	void InitDinput(HWND _hWnd);

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
	void KeyCheckDinput(KEYSTATE* _Key, int _DIK);

private:
	//--------------------------------------------------
	//	private function
	//--------------------------------------------------

	/*
	*	隠しコンストラクタ
	*/
	DirectInputDevice(HWND _hwnd);

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
	LPDIRECTINPUT8 m_pDinput = NULL; 

	/* 
	*	マウスデバイス 
	*/
	LPDIRECTINPUTDEVICE8 m_pDIMouse = NULL;

	/* 
	*	キーデバイス
	*/
	LPDIRECTINPUTDEVICE8 m_pKeyDevice = NULL;

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
};
#endif