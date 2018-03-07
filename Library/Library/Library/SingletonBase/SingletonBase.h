#ifndef SINGLETONBASE_H
#define	SINGLETONBASE_H

//--------------------------------------------------
//	include
//--------------------------------------------------
#include<Windows.h>


/*
*	Singleton�̊��N���X
*
*/
template <typename Type>
class SingletonBase
{
public:

	/*
	*	�C���X�^���X�̐���
	*/
	inline static void Create()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new Type();
		}
	}

	/*
	*	�C���X�^���X�̔j��
	*/
	inline static void Delete()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}

	/*
	*	�C���X�^���X�̎擾	
	*	return �C���X�^���X
	*/
	inline static Type* GetInstance()
	{
		return m_pInstance;
	}

protected:
	/*
	*	�V���O���g���C���X�^���X
	*/
	static Type* m_pInstance;

	/* �R���X�g���N�^�֐��ƃf�X�g���N�^�֐��͗��R�������ꍇ�ȊO�͐G��Ȃ� */
	/* �ǂ̃^�C�~���O�ł��̃N���X�����ꂽ���Ƃ� */
	inline SingletonBase() {};
	inline  virtual ~SingletonBase() {};
};


#endif