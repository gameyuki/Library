#ifndef SOUNDMANAGER_H
#define	SOUNDMANAGER_H

//--------------------------------------------------
//	include
//--------------------------------------------------
#include"Library\DirectX9\SoundManager\DirectSoundDevice\DirectSoundDevice.h"
#include"Library\SingletonBase\SingletonBase.h"
#include<Windows.h>

namespace Lib
{

	//--------------------------------------------------
	//	enum
	//--------------------------------------------------
	/*
	*	��������p�񋓎q
	*/
	enum SOUND_OPERATION
	{
		/* �Đ� */
		PLAY,
		/* ��~ */
		STOP,
		/* ���[�v�Đ� */
		LOOP,
		/* ���Z�b�g */
		RESET,
		/* ��~�ƃ��Z�b�g */
		STOP_RESET
	};

	//--------------------------------------------------
	//	class
	//--------------------------------------------------
	/*
	*	�T�E���h�N���X�Ǘ��p�N���X
	*/
	class SoundManager : public SingletonBase<SoundManager>
	{
	public:
		//--------------------------------------------------
		//	public function
		//--------------------------------------------------
		/*
		*	�R���X�g���N�^
		*/
		SoundManager(HWND _hWnd);

		/*
		*	�f�X�g���N�^
		*/
		~SoundManager();

		//@�N���X���ŃT�E���h���g���Ă���̂Ɋ֐����ɂ��T�E���h���g���̂͏�����������
		/*
		*	�T�E���h����
		*	������	IDirectSoundBuffer8�C���^�[�t�F�[�X
		*	������	���얽��
		*/
		void Operation(IDirectSoundBuffer8* _pDSBuffer, SOUND_OPERATION _operation);

		/*
		*	�T�E���h�t�@�C���W�J
		*	������	�t�@�C����(�t�@�C���p�X)
		*	������	IDirectSoundBuffer8�C���^�[�t�F�[�X
		*/
		int Load(char* _filename, IDirectSoundBuffer8* _pDSBuffer);

	private:
		//--------------------------------------------------
		//	private function
		//--------------------------------------------------

		//--------------------------------------------------
		//	private variable
		//--------------------------------------------------
		/*
		*	�n���h��
		*/
		HWND m_hWnd;

		/*
		*	DirectX9�p DirectSound�C���X�^���X
		*/
		Dx9::DirectSoundDevice* m_pSoundDevice;

	};

}

#endif