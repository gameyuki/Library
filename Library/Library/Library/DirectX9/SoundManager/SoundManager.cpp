//--------------------------------------------------
//	include
//--------------------------------------------------
#include"SoundManager.h"

namespace Lib
{

	//--------------------------------------------------
	//	 コンストラクタ  :  デストラクタ
	//--------------------------------------------------
	/*
	*	相談
	*	ここでnewをしてもいいのか
	*/
	SoundManager::SoundManager(HWND _hWnd) :m_hWnd(_hWnd), m_pSoundDevice(nullptr)
	{
		m_pSoundDevice = new DirectSoundDevice(m_hWnd);
	}

	SoundManager::~SoundManager()
	{
	}

	//--------------------------------------------------
	//	public function
	//--------------------------------------------------
	void SoundManager::SoundOperation(IDirectSoundBuffer8* _pDSBuffer, SOUND_OPERATION _operation)
	{
		switch (_operation)
		{
		case PLAY:
			_pDSBuffer->Play(0, 0, 0);
			break;
		case LOOP:
			_pDSBuffer->Play(0, 0, DSBPLAY_LOOPING);
			break;
		case STOP:
			_pDSBuffer->Stop();
			break;
		case RESET:
			_pDSBuffer->SetCurrentPosition(0);
			break;
		case STOP_RESET:
			_pDSBuffer->Stop();
			_pDSBuffer->SetCurrentPosition(0);
			break;
		}

	}

	int SoundManager::SoundLoad(char* _filename, IDirectSoundBuffer8* _pDSBuffer)
	{
		WAVEFORMATEX wFmt;
		char *pWaveData = 0;
		DWORD waveSize = 0;

		if (!m_pSoundDevice->OpenWave((_filename), wFmt, &pWaveData, waveSize))
		{
			return 0;
		}

		DSBUFFERDESC DSBufferDesc;
		DSBufferDesc.dwSize = sizeof(DSBUFFERDESC);
		DSBufferDesc.dwFlags = 0;
		DSBufferDesc.dwBufferBytes = waveSize;
		DSBufferDesc.dwReserved = 0;
		DSBufferDesc.lpwfxFormat = &wFmt;
		DSBufferDesc.guid3DAlgorithm = GUID_NULL;

		IDirectSoundBuffer *PtmpBuf = 0;
		m_pSoundDevice->GetSound()->CreateSoundBuffer(&DSBufferDesc, &PtmpBuf, NULL);
		PtmpBuf->QueryInterface(IID_IDirectSoundBuffer8, (void**)_pDSBuffer);

		PtmpBuf->Release();
		if (_pDSBuffer == 0)
		{
			m_pSoundDevice->GetSound()->Release();
			return 0;
		}

		LPVOID LpvWrite = 0;
		DWORD DwLength = 0;

		if (DS_OK == _pDSBuffer->Lock(0, 0, &LpvWrite, &DwLength, NULL, NULL, DSBLOCK_ENTIREBUFFER))
		{
			memcpy(LpvWrite, pWaveData, DwLength);
			_pDSBuffer->Unlock(LpvWrite, DwLength, NULL, 0);
		}

		delete[] pWaveData;

		return 0;
	}
}