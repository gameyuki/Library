#ifndef XINPUTDEVICE_H
#define	XINPUTDEVICE_H

//--------------------------------------------------
//	include
//--------------------------------------------------
#include<Windows.h>
#include<Xinput.h>

#include"Library\SingletonBase\SingletonBase.h"

//--------------------------------------------------
//	enum
//--------------------------------------------------
enum PadState
{
	PADON,
	PADOFF,
	PADPUSH,
	PADRELEASE
};

enum ButtonIndex
{
	BUTTON_A,
	BUTTON_B,
	BUTTON_X,
	BUTTON_Y,
	BUTTON_RB,
	BUTTON_LB,
	BUTTON_START,
	BUTTON_INDEXMAX
};

enum Analog
{
	ANALOG_UP,
	ANALOG_DOWN,
	ANALOG_LEFT,
	ANALOG_RIGHT,
	ANALOG_MAX
};

//--------------------------------------------------
//	Xinput使用用クラス
//--------------------------------------------------
class XInputDevice : public SingletonBase<XInputDevice>
{
public:
	/*
	*	デストラクタ
	*/
	~XInputDevice() {};

	/*
	*	コントローラーの状態取得
	*	//毎シーン呼ぶ
	*/
	inline void GetControllerState()
	{
		XInputGetState(0,&m_Xinput);
	}

	/*
	*	ボタンの状態取得
	*/
	inline PadState GetButtonState(ButtonIndex _index)
	{
		return m_PadState[_index];
	}

	/*
	*	左スティックのチェック
	*/
	bool GetLeftAnalog(Analog _analogstate);

	/*
	*	ボタンのチェック
	*/
	void CheckButtonState(WORD _butttonID,int _buttonIndex);

private:
	//--------------------------------------------------
	//	private function
	//--------------------------------------------------
	/*
	*	隠しコンストラクタ
	*/
	XInputDevice();

	//--------------------------------------------------
	//	private variable
	//--------------------------------------------------
	/*
	*	Xinput構造体変数
	*/
	XINPUT_STATE m_Xinput;

	/*
	*	現在のボタン情報
	*/
	PadState m_PadState[BUTTON_INDEXMAX];

	/*
	*	前のボタン情報
	*/
	PadState m_PadoldState[BUTTON_INDEXMAX] = { PADOFF };
};

#endif