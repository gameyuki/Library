#ifndef SCENEMANAGER_H
#define	SCENEMANAGER_H

//--------------------------------------------------
//	include
//--------------------------------------------------
#include<vector>

namespace Lib
{

	//--------------------------------------------------
	//	Forward declaration
	//--------------------------------------------------
	class SceneBase;

	//--------------------------------------------------
	//	 class
	//--------------------------------------------------
	/*
	*	シーン管理クラス
	*/
	class SceneManager
	{
	public:
		//--------------------------------------------------
		//	public function
		//--------------------------------------------------
		/*
		*	コンストラクタ
		*/
		SceneManager();

		/*
		*	デストラクタ
		*/
		~SceneManager();

		/*
		*	初期化関数
		*/
		bool Initialize();

		/*
		*	終了関数
		*/
		void Finalize();

		/*
		*	シーンの更新関数
		*/
		bool Update();

		/*
		*	シーンの追加
		*/
		bool AddScene(SceneBase* _pScene);

		/*
		*	現在のシーンに設定
		*/
		void SetEntryScene(SceneBase* _pScene);

		/*
		*	シーンの削除
		*/
		void DeleteScene(SceneBase* _pScene);

	private:
		//--------------------------------------------------
		//	private variable
		//--------------------------------------------------
		/*
		*	空シーンのID
		*/
		static const int		m_EmptySceneID;

		/*
		*	現在のシーン
		*/
		SceneBase*				m_pCurrentScene;

		/*
		*	シーンを格納しているコンテナ
		*/
		std::vector<SceneBase*> m_pSceneDate;
	};
}

#endif