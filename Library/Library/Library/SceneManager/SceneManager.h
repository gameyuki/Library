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
	*	�V�[���Ǘ��N���X
	*/
	class SceneManager
	{
	public:
		//--------------------------------------------------
		//	public function
		//--------------------------------------------------
		/*
		*	�R���X�g���N�^
		*/
		SceneManager();

		/*
		*	�f�X�g���N�^
		*/
		~SceneManager();

		/*
		*	�������֐�
		*/
		bool Initialize();

		/*
		*	�I���֐�
		*/
		void Finalize();

		/*
		*	�V�[���̍X�V�֐�
		*/
		bool Update();

		/*
		*	�V�[���̒ǉ�
		*/
		bool AddScene(SceneBase* _pScene);

		/*
		*	���݂̃V�[���ɐݒ�
		*/
		void SetEntryScene(SceneBase* _pScene);

		/*
		*	�V�[���̍폜
		*/
		void DeleteScene(SceneBase* _pScene);

	private:
		//--------------------------------------------------
		//	private variable
		//--------------------------------------------------
		/*
		*	��V�[����ID
		*/
		static const int		m_EmptySceneID;

		/*
		*	���݂̃V�[��
		*/
		SceneBase*				m_pCurrentScene;

		/*
		*	�V�[�����i�[���Ă���R���e�i
		*/
		std::vector<SceneBase*> m_pSceneDate;
	};
}

#endif