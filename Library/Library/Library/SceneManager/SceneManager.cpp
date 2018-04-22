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
	/*-1�Ȃ̂�0����n�܂�Ȃ̂Ő�΂ɑ��̃V�[���Ɣ��Ȃ����� */
	const int SceneManager::m_EmptySceneID = -1;


	//--------------------------------------------------
	//	public function
	//--------------------------------------------------
	SceneManager::SceneManager() : m_pCurrentScene(nullptr)
	{

	}

	SceneManager::~SceneManager()
	{
		/* �V�[�����c���Ă�����폜���� */
		for (auto itr = m_pSceneDate.begin(); itr != m_pSceneDate.end(); itr++)
		{
			SafeDelete(*itr);
		}
	}

	bool SceneManager::Initialize()
	{
		/* �R���e�i�ɉ������l�߂Ă��� */
		SceneBase* pEmptyScene = new SceneBase(m_EmptySceneID);
		m_pSceneDate.push_back(pEmptyScene);

		/* ��̃V�[�������݂̃V�[���Ƃ��ēo�^���Ă��� */
		m_pCurrentScene = pEmptyScene;

		return true;
	}

	void SceneManager::Finalize()
	{
		for (auto itr = m_pSceneDate.begin(); itr != m_pSceneDate.end(); itr++)
		{
			/* ��̃V�[����T���č폜���� */
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
					//�J�ڐ�̃|�C���^������݂̃V�[���ɐݒ肵�Ă���
					m_pCurrentScene = (*itr);
					return false;
				}
			}

			/* �J�ڐ悪������Ȃ���Γ�����I�������� */
			return true;

			break;

		}
	}

	bool SceneManager::AddScene(SceneBase* _pScene)
	{
		for (auto itr = m_pSceneDate.begin(); itr != m_pSceneDate.end(); itr++)
		{
			/* ���ɂ���ꍇ�͎��s */
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
			/* �����Ɠo�^����Ă��邩�̊m�F */
			if ((*itr)->GetSceneID() == _pScene->GetSceneID())
			{
				/* ���݂̃V�[���Ƃ��Đݒ� */
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
					/* �I�u�W�F�N�g���܂������Ă����Ԃł���Δj�󂷂� */
					(*itr)->Finalize();
					break;
				case SceneBase::FAINAL_STATE:
					break;
				}
			}
		}
	}
}