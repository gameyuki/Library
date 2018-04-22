#ifndef DIRECTGRAPHICSDEVICE_H
#define	DIRECTGRAPHICSDEVICE_H

//--------------------------------------------------
//	include
//--------------------------------------------------
#include<Windows.h>
#include<d3d9.h>
#include<d3dx9.h>

#include"Library\SingletonBase\SingletonBase.h"

namespace Lib
{

	//--------------------------------------------------
	//	class
	//--------------------------------------------------
	/*
	*	Direct3D初期化用クラス
	*/
	class DirectGraphicsDevice : public SingletonBase<DirectGraphicsDevice>
	{
	public:
		//--------------------------------------------------
		//	public function
		//--------------------------------------------------
		/*
		*	コンストラクタ
		*	第一引数	ウィンドウハンドル
		*	第二引数	ウインドウの横の長さ
		*	第三引数	ウインドウの縦の長さ
		*	第四引数	ウインドウがフルスクリーンか否か
		*	true ならフルスクリーン falseならウインドウサイズ
		*/
		DirectGraphicsDevice(HWND _hWnd, float w, float h, bool f);
		/*
		*	デストラクタ
		*/
		~DirectGraphicsDevice();

		/*
		*	初期化用関数
		*	成功すればtrue 失敗すればfalse
		*/
		bool Initialize();

		/*
		*	解放関数
		*/
		void Finalize();

		/*
		*	デバイスアクセス
		*/
		inline LPDIRECT3DDEVICE9 GetD3Device9()
		{
			return m_pD3Device;
		}

		/*
		*	描画開始用
		*	各シーンに
		*/
		void BeginScene();

		/*
		*	ページフリッピング用
		*	//相談	名前
		*/
		void EndScene();

	private:
		//--------------------------------------------------
		//	private function
		//--------------------------------------------------
		/*
		*	パラメーター初期化
		*/
		void InitD3Dpp();

		/*
		*	描画用設定
		*/
		void SetRenderlingConfiguration();

		//--------------------------------------------------
		//	private variable
		//--------------------------------------------------
		/*
		*	Direct3D用インターフェース
		*/
		LPDIRECT3D9 m_pDirect3D;

		/*
		*	Direct3DDevice用インターフェース
		*/
		LPDIRECT3DDEVICE9 m_pD3Device;

		/*
		*	Direct3Dパラメーター用インターフェース
		*/
		D3DPRESENT_PARAMETERS m_D3dpp;

		/*
		*	ウィンドウサイズ用
		*/
		D3DPRESENT_PARAMETERS m_D3dppwnd;

		/*
		*	フルスクリーン用
		*/
		D3DPRESENT_PARAMETERS m_D3dppfull;

		/*
		*	Direct3Dパラメーター用ディスプレイインターフェース
		*/
		D3DDISPLAYMODE	m_D3DdisplayMode;

		/*
		*	ハンドル
		*/
		HWND m_hWnd;

		/*
		*	ウィンドウの縦と横
		*/
		float m_Width;
		float m_Height;

		/*
		*	フルスクリーンか否か
		*	フルスクリーンならtrue
		*	ウィンドウサイズならfalse
		*/
		bool m_Fullscreen;
	};

}
#endif