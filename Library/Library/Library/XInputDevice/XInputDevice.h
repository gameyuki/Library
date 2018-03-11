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
//	Xinput�g�p�p�N���X
//--------------------------------------------------
class XInputDevice : public SingletonBase<XInputDevice>
{
public:
	/*
	*	�f�X�g���N�^
	*/
	~XInputDevice() {};

	/*
	*	�R���g���[���[�̏�Ԏ擾
	*	//���V�[���Ă�
	*/
	inline void GetControllerState()
	{
		XInputGetState(0,&m_Xinput);
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
	void CheckButtonState(WORD _butttonID,int _buttonIndex);

private:
	//--------------------------------------------------
	//	private function
	//--------------------------------------------------
	/*
	*	�B���R���X�g���N�^
	*/
	XInputDevice();

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
	PadState m_PadoldState[BUTTON_INDEXMAX] = { PADOFF };
};

#endif