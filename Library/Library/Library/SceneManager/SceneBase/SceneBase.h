#ifndef SCENEBASE_H
#define	SCENEBASE_H

/*
*	�V�[�������p���N���X
*/
class SceneBase
{
public:
	//--------------------------------------------------
	//	public enum
	//--------------------------------------------------
	/* 
	*	�V�[���̏�ԗ�
	*/
	enum STATE
	{
		/* ��������� */
		INIT_STATE,
		/* �X�V��� */
		UPDATE_STATE,
		/* �I����� */
		FAINAL_STATE
	};

	//--------------------------------------------------
	//	public function
	//--------------------------------------------------
	/*
	*	�R���X�g���N�^
	*	�����Ōp����̃V�[�������ʂ���
	*/
	SceneBase(int _sceneID);

	/*
	*	�f�X�g���N�^
	*	����ăC���X�^���X�������Ȃ��悤��
	*/
	virtual ~SceneBase();

	/*
	*	��ꏉ�����֐�
	*	���������true ���Ȃ����false
	*/
	virtual bool Initialize();

	/*
	*	���I���֐�
	*/
	virtual void Finalize();

	/*
	*	���V�[���X�V�֐�
	*/
	virtual void Update();

	/* 
	*	���݂̃V�[���̏�Ԃ�Ԃ�
	*/
	inline STATE GetState() const
	{
		return m_State;
	}

	/* 
	*	���݂̃V�[����ID(���)��Ԃ�
	*/
	inline int GetSceneID() const
	{
		return m_SceneID;
	}

	/* 
	*	�J�ڐ�(��)�̃V�[��ID��Ԃ� 
	*/
	inline int GetNextSceneID() const
	{
		return m_NextSceneID;
	}

protected:
	//--------------------------------------------------
	//	protected variable
	//--------------------------------------------------
	/* 
	*	�V�[���̏��(���) 
	*/
	STATE m_State;

	/*
	*	�V�[����ID 
	*/
	int m_SceneID;

	/* 
	*	���̃V�[��ID 
	*/
	int m_NextSceneID;
};

#endif