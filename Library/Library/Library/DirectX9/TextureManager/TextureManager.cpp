//--------------------------------------------------
//	include
//--------------------------------------------------
#include"TextureManager.h"
#include"Library\DirectX9\DirectGraphicsDevice\DirectGraphicsDevice.h"
#include"..\Library\Library\MyDefine\macro.h"

namespace Lib
{

	//--------------------------------------------------
	//	�R���X�g���N�^�F�f�X�g���N�^
	//--------------------------------------------------
	TextureManager::TextureManager()
	{
	}

	TextureManager::~TextureManager()
	{
	}

	//--------------------------------------------------
	//	public function
	//--------------------------------------------------
	bool TextureManager::LoadTexture(LPCTSTR _fname, int &_textureID)
	{
		LPDIRECT3DTEXTURE9 tex;

		if (FAILED(D3DXCreateTextureFromFileEx(
			Dx9::DirectGraphicsDevice::GetInstance()->GetD3Device9(),
			_fname,
			0,
			0,
			0,
			0,
			D3DFMT_A1R5G5B5,                // �F�������\��
			D3DPOOL_MANAGED,
			D3DX_FILTER_LINEAR,
			D3DX_FILTER_LINEAR,
			D3DCOLOR_ARGB(255, 0, 255, 0),  //�΂𓧉�
			NULL,
			NULL,
			&tex)))
		{
			OutPutError("�摜�̓ǂݍ��݂Ɏ��s���܂����B");
			return false;
		}

		_textureID = m_pTexture.size();
		m_pTexture.push_back(tex);

		return true;
	}

	void TextureManager::SetTexture(int* _ptexID)
	{
		Dx9::DirectGraphicsDevice::GetInstance()->GetD3Device9()->SetTexture(0, m_pTexture[*_ptexID]);
	}

	void TextureManager::Release()
	{
		for (auto itr = m_pTexture.begin(); itr != m_pTexture.end(); itr++)
		{
			SafeRelease(*itr);
		}
	}
}