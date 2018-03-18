#ifndef TEXTUREMANAGER_H
#define	TEXTUREMANAGER_H

//--------------------------------------------------
//	include
//--------------------------------------------------
#include<d3d9.h>
#include<d3dx9.h>
#include<vector>
#include"Library\SingletonBase\SingletonBase.h"

//--------------------------------------------------
//	class
//--------------------------------------------------
class TextureManager : public SingletonBase<TextureManager>
{
public:
	//--------------------------------------------------
	//	public function
	//--------------------------------------------------
	/*
	*	デストラクタ
	*/
	~TextureManager();

	/*
	*	画像の読み込み
	*	第一引数	ファイルの名前
	*	第二引数	テクスチャーIDのアドレス
	*/
	bool LoadTexture(LPCTSTR _fname,int* _textureID);

	/*
	*	画像の貼り付け
	*	第一引数	各テクスチャーIDのアドレス
	*/
	//相談
	void SetTexture(int* texID);

	/*
	*	画像の解放
	*/
	void Release();

private:
	//--------------------------------------------------
	//	private function
	//--------------------------------------------------
	/*
	*	コンストラクタ
	*/
	TextureManager();

	//--------------------------------------------------
	//	private variable
	//--------------------------------------------------
	/*
	*	TextureID格納コンテナ
	*/
	std::vector<LPDIRECT3DTEXTURE9> m_pTexture;
};

#endif