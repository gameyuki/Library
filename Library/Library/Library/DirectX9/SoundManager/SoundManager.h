#ifndef SOUNDMANAGER_H
#define	SOUNDMANAGER_H

//--------------------------------------------------
//	include
//--------------------------------------------------
#include"Library\DirectX9\SoundManager\DirectSoundDevice\DirectSoundDevice.h"
#include"Library\SingletonBase\SingletonBase.h"
#include<Windows.h>

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
	*	�f�X�g���N�^
	*/
	~SoundManager();

	/*
	*	�T�E���h����
	*	������	IDirectSoundBuffer8�C���^�[�t�F�[�X
	*	������	���얽��
	*/
	void SoundOperation(IDirectSoundBuffer8* _pDSBuffer, SOUND_OPERATION _operation);

	/*
	*	�T�E���h�t�@�C���W�J
	*	������	�t�@�C����(�t�@�C���p�X)
	*	������	IDirectSoundBuffer8�C���^�[�t�F�[�X
	*/
	int SoundLoad(char* _filename, IDirectSoundBuffer8* _pDSBuffer);

private:
	//--------------------------------------------------
	//	private function
	//--------------------------------------------------
	/*
	*	�R���X�g���N�^
	*/
	SoundManager(HWND _hWnd);

	//--------------------------------------------------
	//	private variable
	//--------------------------------------------------
	/*
	*	�n���h��
	*/
	HWND m_hWnd;

	/*
	*	DirectSound�C���X�^���X
	*/
	DirectSoundDevice* m_pSoundDevice;

};

#endif