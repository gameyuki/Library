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
			/* �N���b�N���(�N���b�N����Ă����true). */
			bool IsLeftClick, IsRightClick;
			/* �}�E�X�̈ړ��� */
			int lx, ly, lz;//(Z�̓z�C�[��)
		};

		//--------------------------------------------------
		//	enum
		//--------------------------------------------------
		/* �L�[�{�[�h�̏�� */
		enum KEYSTATE
		{
			KEYS_PRESSED,	//<<�P������
			KEYS_RELEASE,	//<<�����ꂽ����1�w
			KEYS_DOWN,		//<<�������p
			KEYS_OFF		//<<�{�^��������
		};

		//--------------------------------------------------
		//	class
		//--------------------------------------------------
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
			*	�R���X�g���N�^
			*/
			DirectInputDevice(HWND _hWnd);

			/*
			*	�f�X�g���N�^
			*/
			~DirectInputDevice();

			/*
			*	DirectInput�I�u�W�F�N�g�̍쐬
			*/
			void InitDinput();

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
			void KeyDownCheck(KEYSTATE* _Key, int _DIK);

		private:
			//--------------------------------------------------
			//	private function
			//--------------------------------------------------
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
			LPDIRECTINPUT8 m_pDinput = nullptr;

			/*
			*	�}�E�X�f�o�C�X
			*/
			LPDIRECTINPUTDEVICE8 m_pDIMouse = nullptr;

			/*
			*	�L�[�f�o�C�X
			*/
			LPDIRECTINPUTDEVICE8 m_pKeyDevice = nullptr;

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

			/*
			*	�L�[�z��
			*/
			BYTE diks[256];

			/*
			*	�O�L�[�z��
			*/
			static int Old_diks[256];
		};
	}
}
#endif