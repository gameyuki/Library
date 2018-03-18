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
	*	�f�X�g���N�^
	*/
	~TextureManager();

	/*
	*	�摜�̓ǂݍ���
	*	������	�t�@�C���̖��O
	*	������	�e�N�X�`���[ID�̃A�h���X
	*/
	bool LoadTexture(LPCTSTR _fname,int* _textureID);

	/*
	*	�摜�̓\��t��
	*	������	�e�e�N�X�`���[ID�̃A�h���X
	*/
	//���k
	void SetTexture(int* texID);

	/*
	*	�摜�̉��
	*/
	void Release();

private:
	//--------------------------------------------------
	//	private function
	//--------------------------------------------------
	/*
	*	�R���X�g���N�^
	*/
	TextureManager();

	//--------------------------------------------------
	//	private variable
	//--------------------------------------------------
	/*
	*	TextureID�i�[�R���e�i
	*/
	std::vector<LPDIRECT3DTEXTURE9> m_pTexture;
};

#endif