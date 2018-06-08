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
		*	DirectSoundクラス
		*/
		class DirectSoundDevice
		{
		public:
			//--------------------------------------------------
			//	public function
			//--------------------------------------------------
			/*
			*	コンストラクタ
			*/
			DirectSoundDevice(HWND _hWnd);

			/*
			*	デストラクタ
			*/
			~DirectSoundDevice();

			/*
			*	Directsoundの初期化
			*/
			HRESULT InitDSound();

			/*
			*	サウンドファイルを開く
			*/
			bool OpenWave(TCHAR* _filename, WAVEFORMATEX &_wFmt, char** _pWaveData, DWORD &_waveSize);

			/*
			*	IDirectSound8インターフェースを返す
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
			*	ハンドル
			*/
			HWND m_hWnd;

			/*
			*	IDirectSound8インターフェース
			*/
			IDirectSound8* m_pDirectSound = nullptr;
		};
	}

}

#endif