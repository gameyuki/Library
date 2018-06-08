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
	*	Window�����p�N���X
	*/
	class Windows
	{
	public:
		//--------------------------------------------------
		//	public function
		//--------------------------------------------------
		/*
		*	�R���X�g���N�^
		*/
		Windows();

		/*
		*	�f�X�g���N�^
		*/
		~Windows();

		/*
		*	�E�C���h�E����
		*	������	�E�B���h�E�̖��O
		*	������	�E�B���h�E�̉���
		*	��O����	�E�C���h�E�̍���
		*/
		bool Initialize(
			LPCTSTR _pWindowName,
			int _windowWidth,
			int _windowHeight);

		/*
		*	�E�C���h�E�j��
		*/
		void Finalize();

		/*
		*	�E�C���h�E�̍X�V
		*	�E�C���h�E���j������Ă�����true �����Ă�����false
		*/
		bool Update();

		/*
		*	�E�C���h�E�n���h����Ԃ�
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
		*	�E�C���h�E�n���h��
		*/
		HWND m_hWnd;
		/*
		*	�E�C���h�E���b�Z�[�W�\���̕ϐ�
		*/
		MSG m_WindowMsg;
	};
}

#endif