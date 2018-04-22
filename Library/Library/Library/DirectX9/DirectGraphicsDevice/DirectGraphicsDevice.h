#ifndef DIRECTGRAPHICSDEVICE_H
#define	DIRECTGRAPHICSDEVICE_H

//--------------------------------------------------
//	include
//--------------------------------------------------
#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>

#include"Library\SingletonBase\SingletonBase.h"

namespace Lib
{

	//--------------------------------------------------
	//	class
	//--------------------------------------------------
	/*
	*	Direct3D�������p�N���X
	*/
	class DirectGraphicsDevice : public SingletonBase<DirectGraphicsDevice>
	{
	public:
		//--------------------------------------------------
		//	public function
		//--------------------------------------------------
		/*
		*	�R���X�g���N�^
		*	������	�E�B���h�E�n���h��
		*	������	�E�C���h�E�̉��̒���
		*	��O����	�E�C���h�E�̏c�̒���
		*	��l����	�E�C���h�E���t���X�N���[�����ۂ�
		*	true �Ȃ�t���X�N���[�� false�Ȃ�E�C���h�E�T�C�Y
		*/
		DirectGraphicsDevice(HWND _hWnd, float w, float h, bool f);
		/*
		*	�f�X�g���N�^
		*/
		~DirectGraphicsDevice();

		/*
		*	�������p�֐�
		*	���������true ���s�����false
		*/
		bool Initialize();

		/*
		*	����֐�
		*/
		void Finalize();

		/*
		*	�f�o�C�X�A�N�Z�X
		*/
		inline LPDIRECT3DDEVICE9 GetD3Device9()
		{
			return m_pD3Device;
		}

		/*
		*	�`��J�n�p
		*	�e�V�[����
		*/
		void BeginScene();

		/*
		*	�y�[�W�t���b�s���O�p
		*	//���k	���O
		*/
		void EndScene();

	private:
		//--------------------------------------------------
		//	private function
		//--------------------------------------------------
		/*
		*	�p�����[�^�[������
		*/
		void InitD3Dpp();

		/*
		*	�`��p�ݒ�
		*/
		void SetRenderlingConfiguration();

		//--------------------------------------------------
		//	private variable
		//--------------------------------------------------
		/*
		*	Direct3D�p�C���^�[�t�F�[�X
		*/
		LPDIRECT3D9 m_pDirect3D;

		/*
		*	Direct3DDevice�p�C���^�[�t�F�[�X
		*/
		LPDIRECT3DDEVICE9 m_pD3Device;

		/*
		*	Direct3D�p�����[�^�[�p�C���^�[�t�F�[�X
		*/
		D3DPRESENT_PARAMETERS m_D3dpp;

		/*
		*	�E�B���h�E�T�C�Y�p
		*/
		D3DPRESENT_PARAMETERS m_D3dppwnd;

		/*
		*	�t���X�N���[���p
		*/
		D3DPRESENT_PARAMETERS m_D3dppfull;

		/*
		*	Direct3D�p�����[�^�[�p�f�B�X�v���C�C���^�[�t�F�[�X
		*/
		D3DDISPLAYMODE	m_D3DdisplayMode;

		/*
		*	�n���h��
		*/
		HWND m_hWnd;

		/*
		*	�E�B���h�E�̏c�Ɖ�
		*/
		float m_Width;
		float m_Height;

		/*
		*	�t���X�N���[�����ۂ�
		*	�t���X�N���[���Ȃ�true
		*	�E�B���h�E�T�C�Y�Ȃ�false
		*/
		bool m_Fullscreen;
	};

}
#endif