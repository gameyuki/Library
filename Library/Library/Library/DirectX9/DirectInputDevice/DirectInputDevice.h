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
	/* �N���b�N���(�N���b�N����Ă����true). */
	bool IsLeftClick, IsRightClick;	
	/* �}�E�X�̈ړ��� */
	int lx, ly, lz;//(Z�̓z�C�[��)

} MOUSEKIND;

//--------------------------------------------------
//	enum
//--------------------------------------------------
/* �L�[�{�[�h�̏�� */
enum KEYSTATE
{
	PUSH,
	RELEASE,
	ON,
	OFF
};

/* �L�[�{�[�h�̎�� */
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
*	DirectInput�N���X
*/
class DirectInputDevice :public SingletonBase<DirectInputDevice>
{
public:
	//--------------------------------------------------
	//	public function
	//--------------------------------------------------
	/*
	*	�f�X�g���N�^
	*/
	~DirectInputDevice() {};

	/*
	*	DirectInput�I�u�W�F�N�g�̍쐬
	*/
	void InitDinput(HWND _hWnd);

	/* 
	*	�L�[�I�u�W�F�N�g�̏�����
	*/
	bool KeyInitialize();

	/*
	*	�}�E�X�I�u�W�F�N�g�̏�����
	*/
	bool MouseInitialize();

	/*
	*	Dinput�̍폜
	*/
	void Finalize();

	/*
	*	�}�E�X�̃`�F�b�N
	*/
	void MouseCheck(MOUSEKIND* _Mouse);

	/*
	*	�}�E�X�̍��W��Ԃ� 
	*/
	inline POINT GetMousePos()
	{
		GetCursorPos(&m_Po);
		return m_Po;
	}
	/*
	*	�L�[�{�[�h�̃`�F�b�N
	*/
	void KeyCheckDinput(KEYSTATE* _Key, int _DIK);

private:
	//--------------------------------------------------
	//	private function
	//--------------------------------------------------

	/*
	*	�B���R���X�g���N�^
	*/
	DirectInputDevice(HWND _hwnd);

	/*
	*	�L�[�{�[�h�̉��
	*/
	void ReleaseKey();

	/*
	*	�}�E�X�̉��
	*/
	void ReleaseMouse();

	//--------------------------------------------------
	//	private variable
	//--------------------------------------------------

	/* 
	*	DirectInput�I�u�W�F�N�g�̊i�[��
	*/
	LPDIRECTINPUT8 m_pDinput = NULL; 

	/* 
	*	�}�E�X�f�o�C�X 
	*/
	LPDIRECTINPUTDEVICE8 m_pDIMouse = NULL;

	/* 
	*	�L�[�f�o�C�X
	*/
	LPDIRECTINPUTDEVICE8 m_pKeyDevice = NULL;

	/*
	*	DirectInput�N���X�ŗL�̃n���h��
	*/
	HWND m_hWnd;

	/*
	*	�}�E�X���W
	*/
	POINT m_Po;

	/*
	*	�}�E�X�̃o�b�t�@�[�̑傫��
	*/
	const int Buffer_Size = 64;
};
#endif