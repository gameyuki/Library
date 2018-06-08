#ifndef SINGLETONBASE_H
#define	SINGLETONBASE_H

//--------------------------------------------------
//	include
//--------------------------------------------------
#include<Windows.h>

//--------------------------------------------------
//	 class
//--------------------------------------------------
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
	*	�������@�ϒ������@�n���h���p
	*/
	template <typename ...Args>
	inline static void Create(Args... args)
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new Type(args...);
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

/*
*	������
*/
template <typename Type>
Type* SingletonBase<Type>::m_pInstance = nullptr;

#endif