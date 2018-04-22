//--------------------------------------------------
//	include
//--------------------------------------------------
#include"DirectSoundDevice.h"

#include<dsound.h>
#include"..\Library\Library\MyDefine\macro.h"

namespace Lib
{

	//--------------------------------------------------
	//	 �R���X�g���N�^  :  �f�X�g���N�^
	//--------------------------------------------------
	DirectSoundDevice::DirectSoundDevice(HWND _hWnd) :m_hWnd(_hWnd)
	{
	}

	DirectSoundDevice::~DirectSoundDevice()
	{
	}

	//--------------------------------------------------
	//	public function
	//--------------------------------------------------
	HRESULT DirectSoundDevice::InitDSound()
	{
		if (FAILED(DirectSoundCreate8(NULL, &m_pDirectSound, NULL)))
		{
			OutPutError("�T�E���h�f�o�C�X�̐����Ɏ��s���܂���");
		}

		if (FAILED(m_pDirectSound->SetCooperativeLevel(m_hWnd, DSSCL_PRIORITY)))
		{
			OutPutError("�T�E���h�f�o�C�X�̐����Ɏ��s���܂���");
		}

		return S_OK;
	}

	/* ���k */
	bool DirectSoundDevice::OpenWave(TCHAR* _filename, WAVEFORMATEX &_wFmt, char** _pWaveData, DWORD &_waveSize)
	{
		if (_filename == 0)
		{
			return false;
		}

		HMMIO hMmio = NULL;
		MMIOINFO mmioInfo;

		// Wave�t�@�C���I�[�v��
		memset(&mmioInfo, 0, sizeof(MMIOINFO));
		hMmio = mmioOpen(_filename, &mmioInfo, MMIO_READ);
		if (!hMmio)
		{
			OutPutError("�t�@�C���I�[�v���Ɏ��s���܂���");
			return false;
		}

		// RIFF�`�����N����
		MMRESULT MmRes;
		MMCKINFO RiffChunk;
		RiffChunk.fccType = mmioFOURCC('W', 'A', 'V', 'E');
		MmRes = mmioDescend(hMmio, &RiffChunk, NULL, MMIO_FINDRIFF);
		if (MmRes != MMSYSERR_NOERROR)
		{
			mmioClose(hMmio, 0);
			return false;
		}

		// �t�H�[�}�b�g�`�����N����
		MMCKINFO FormatChunk;
		FormatChunk.ckid = mmioFOURCC('f', 'm', 't', ' ');
		MmRes = mmioDescend(hMmio, &FormatChunk, &RiffChunk, MMIO_FINDCHUNK);
		if (MmRes != MMSYSERR_NOERROR)
		{
			mmioClose(hMmio, 0);
			return false;
		}

		DWORD Fmsize = FormatChunk.cksize;
		DWORD Size = mmioRead(hMmio, (HPSTR)&_wFmt, Fmsize);
		if (Size != Fmsize)
		{
			mmioClose(hMmio, 0);
			return false;
		}

		//�@��ɖ߂��Ă���
		mmioAscend(hMmio, &FormatChunk, 0);

		// �f�[�^�`�����N����
		MMCKINFO DataChunk;
		DataChunk.ckid = mmioFOURCC('d', 'a', 't', 'a');
		MmRes = mmioDescend(hMmio, &DataChunk, &RiffChunk, MMIO_FINDCHUNK);
		if (MmRes != MMSYSERR_NOERROR)
		{
			mmioClose(hMmio, 0);
			return false;
		}

		*_pWaveData = new char[DataChunk.cksize];
		Size = mmioRead(hMmio, (HPSTR)*_pWaveData, DataChunk.cksize);
		if (Size != DataChunk.cksize)
		{
			delete[] * _pWaveData;
			return false;
		}

		_waveSize = Size;

		mmioClose(hMmio, 0);

		return true;
	}

}