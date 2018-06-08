#ifndef DIRECTSOUNDDEVICE_H
#define	DIRECTSOUNDDEVICE_H

//--------------------------------------------------
//	include
//--------------------------------------------------
#include<Windows.h>
#include<mmsystem.h>
#include<dsound.h>

namespace Lib
{
	namespace Dx9
	{
		//--------------------------------------------------
		//	class
		//--------------------------------------------------
		/*
		*	DirectSound�N���X
		*/
		class DirectSoundDevice
		{
		public:
			//--------------------------------------------------
			//	public function
			//--------------------------------------------------
			/*
			*	�R���X�g���N�^
			*/
			DirectSoundDevice(HWND _hWnd);

			/*
			*	�f�X�g���N�^
			*/
			~DirectSoundDevice();

			/*
			*	Directsound�̏�����
			*/
			HRESULT InitDSound();

			/*
			*	�T�E���h�t�@�C�����J��
			*/
			bool OpenWave(TCHAR* _filename, WAVEFORMATEX &_wFmt, char** _pWaveData, DWORD &_waveSize);

			/*
			*	IDirectSound8�C���^�[�t�F�[�X��Ԃ�
			*/
			inline IDirectSound8* GetSound()
			{
				return m_pDirectSound;
			}
		private:
			//--------------------------------------------------
			//	private variable
			//--------------------------------------------------
			/*
			*	�n���h��
			*/
			HWND m_hWnd;

			/*
			*	IDirectSound8�C���^�[�t�F�[�X
			*/
			IDirectSound8* m_pDirectSound = nullptr;
		};
	}

}

#endif