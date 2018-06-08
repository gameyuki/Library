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
	*	���݂�PAD���
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
	*	�{�^���̎��
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
	*	�X�e�B�b�N���
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
	*	Xinput�g�p�p�N���X
	*/
	class XInputDevice : public SingletonBase<XInputDevice>
	{
	public:
		//--------------------------------------------------
		//	public function
		//--------------------------------------------------
		/*
		*	�R���X�g���N�^
		*/
		XInputDevice();

		/*
		*	�f�X�g���N�^
		*/
		~XInputDevice();

		/*
		*	�R���g���[���[�̏�Ԏ擾
		*	//���V�[���Ă�
		*/
		inline void GetControllerState()
		{
			XInputGetState(0, &m_Xinput);
		}

		/*
		*	�{�^���̏�Ԏ擾
		*/
		inline PadState GetButtonState(ButtonIndex _index)
		{
			return m_PadState[_index];
		}

		/*
		*	���X�e�B�b�N�̃`�F�b�N
		*/
		bool GetLeftAnalog(Analog _analogstate);

		/*
		*	�{�^���̃`�F�b�N
		*/
		void CheckButtonState(WORD _butttonID, int _buttonIndex);

	private:
		//--------------------------------------------------
		//	private variable
		//--------------------------------------------------
		/*
		*	Xinput�\���̕ϐ�
		*/
		XINPUT_STATE m_Xinput;

		/*
		*	���݂̃{�^�����
		*/
		PadState m_PadState[BUTTON_INDEXMAX];

		/*
		*	�O�̃{�^�����
		*/
		PadState m_PadoldState[BUTTON_INDEXMAX] = { PAD_OFF };

		/*
		*	
		*/
		const float MAX = 65536;
	};

}

#endif