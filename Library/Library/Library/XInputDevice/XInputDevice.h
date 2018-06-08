#ifndef XINPUTDEVICE_H
#define	XINPUTDEVICE_H

//--------------------------------------------------
//	include
//--------------------------------------------------
#include<Windows.h>
#include<Xinput.h>

#include"Library\SingletonBase\SingletonBase.h"

namespace Lib
	/*@*/
{

	//--------------------------------------------------
	//	enum
	//--------------------------------------------------
	/*
	*	現在のPAD情報
	*/
	enum PadState
	{
		PAD_DOWN,
		PAD_OFF,
		PAD_PRESSED,
		PAD_RELEASE,
		PAD_MAX
	};

	/*
	*	ボタンの種類
	*/
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

	/*
	*	スティック情報
	*/
	enum Analog
	{
		ANALOG_UP,
		ANALOG_DOWN,
		ANALOG_LEFT,
		ANALOG_RIGHT,
		ANALOG_MAX
	};

	//--------------------------------------------------
	//	class
	//--------------------------------------------------
	/*
	*	Xinput使用用クラス
	*/
	class XInputDevice : public SingletonBase<XInputDevice>
	{
	public:
		//--------------------------------------------------
		//	public function
		//--------------------------------------------------
		/*
		*	コンストラクタ
		*/
		XInputDevice();

		/*
		*	デストラクタ
		*/
		~XInputDevice();

		/*
		*	コントローラーの状態取得
		*	//毎シーン呼ぶ
		*/
		inline void GetControllerState()
		{
			XInputGetState(0, &m_Xinput);
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
		void CheckButtonState(WORD _butttonID, int _buttonIndex);

	private:
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
		PadState m_PadoldState[BUTTON_INDEXMAX] = { PAD_OFF };

		/*
		*	
		*/
		const float MAX = 65536;
	};

}

#endif