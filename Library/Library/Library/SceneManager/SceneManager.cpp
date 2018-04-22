//--------------------------------------------------
//	include
//--------------------------------------------------
#include"SceneManager.h"
#include"SceneBase\SceneBase.h"
#include"..\MyDefine\macro.h"

namespace Lib
{

	//--------------------------------------------------
	//	private variable
	//--------------------------------------------------
	/*-1なのは0から始まりなので絶対に他のシーンと被らないから */
	const int SceneManager::m_EmptySceneID = -1;


	//--------------------------------------------------
	//	public function
	//--------------------------------------------------
	SceneManager::SceneManager() : m_pCurrentScene(nullptr)
	{

	}

	SceneManager::~SceneManager()
	{
		/* シーンが残っていたら削除する */
		for (auto itr = m_pSceneDate.begin(); itr != m_pSceneDate.end(); itr++)
		{
			SafeDelete(*itr);
		}
	}

	bool SceneManager::Initialize()
	{
		/* コンテナに何かを詰めておく */
		SceneBase* pEmptyScene = new SceneBase(m_EmptySceneID);
		m_pSceneDate.push_back(pEmptyScene);

		/* 空のシーンを現在のシーンとして登録しておく */
		m_pCurrentScene = pEmptyScene;

		return true;
	}

	void SceneManager::Finalize()
	{
		for (auto itr = m_pSceneDate.begin(); itr != m_pSceneDate.end(); itr++)
		{
			/* 空のシーンを探して削除する */
			if ((*itr)->GetSceneID() == m_EmptySceneID)
			{
				SafeDelete(*itr);
				break;
			}
		}
	}

	bool SceneManager::Update()
	{
		switch (m_pCurrentScene->GetState())
		{
		case SceneBase::INIT_STATE:
			m_pCurrentScene->Initialize();

			break;
		case SceneBase::UPDATE_STATE:
			m_pCurrentScene->Update();

			break;
		case SceneBase::FAINAL_STATE:
			int NextSceneID = m_pCurrentScene->GetNextSceneID();
			m_pCurrentScene->Finalize();

			for (auto itr = m_pSceneDate.begin(); itr != m_pSceneDate.end(); itr++)
			{
				if ((*itr)->GetSceneID() == NextSceneID)
				{
					//遷移先のポインタ先を現在のシーンに設定している
					m_pCurrentScene = (*itr);
					return false;
				}
			}

			/* 遷移先が見つからなければ動作を終了させる */
			return true;

			break;

		}
	}

	bool SceneManager::AddScene(SceneBase* _pScene)
	{
		for (auto itr = m_pSceneDate.begin(); itr != m_pSceneDate.end(); itr++)
		{
			/* 既にある場合は失敗 */
			if ((*itr)->GetSceneID() == _pScene->GetSceneID())
			{
				return false;
			}

			m_pSceneDate.push_back(_pScene);

			return true;
		}
	}

	void SceneManager::SetEntryScene(SceneBase* _pScene)
	{
		for (auto itr = m_pSceneDate.begin(); itr != m_pSceneDate.end(); itr++)
		{
			/* ちゃんと登録されているかの確認 */
			if ((*itr)->GetSceneID() == _pScene->GetSceneID())
			{
				/* 現在のシーンとして設定 */
				m_pCurrentScene = (*itr);
			}
		}
	}

	void SceneManager::DeleteScene(SceneBase* _pScene)
	{
		for (auto itr = m_pSceneDate.begin(); itr != m_pSceneDate.end(); itr++)
		{
			if ((*itr)->GetSceneID() == _pScene->GetSceneID())
			{
				switch ((*itr)->GetState())
				{
				case SceneBase::INIT_STATE:
					break;
				case SceneBase::UPDATE_STATE:
					/* オブジェクトがまだ生きている状態であれば破壊する */
					(*itr)->Finalize();
					break;
				case SceneBase::FAINAL_STATE:
					break;
				}
			}
		}
	}
}