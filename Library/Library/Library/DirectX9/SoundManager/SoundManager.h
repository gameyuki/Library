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
*	音声操作用列挙子
*/
enum SOUND_OPERATION
{
	/* 再生 */
	PLAY,
	/* 停止 */
	STOP,
	/* ループ再生 */
	LOOP,
	/* リセット */
	RESET,
	/* 停止とリセット */
	STOP_RESET
};

//--------------------------------------------------
//	class
//--------------------------------------------------
/*
*	サウンドクラス管理用クラス
*/
class SoundManager : public SingletonBase<SoundManager>
{
public:
	//--------------------------------------------------
	//	public function
	//--------------------------------------------------
	/*
	*	デストラクタ
	*/
	~SoundManager();

	/*
	*	サウンド操作
	*	第一引数	IDirectSoundBuffer8インターフェース
	*	第二引数	操作命令
	*/
	void SoundOperation(IDirectSoundBuffer8* _pDSBuffer, SOUND_OPERATION _operation);

	/*
	*	サウンドファイル展開
	*	第一引数	ファイル名(ファイルパス)
	*	第二引数	IDirectSoundBuffer8インターフェース
	*/
	int SoundLoad(char* _filename, IDirectSoundBuffer8* _pDSBuffer);

private:
	//--------------------------------------------------
	//	private function
	//--------------------------------------------------
	/*
	*	コンストラクタ
	*/
	SoundManager(HWND _hWnd);

	//--------------------------------------------------
	//	private variable
	//--------------------------------------------------
	/*
	*	ハンドル
	*/
	HWND m_hWnd;

	/*
	*	DirectSoundインスタンス
	*/
	DirectSoundDevice* m_pSoundDevice;

};

#endif