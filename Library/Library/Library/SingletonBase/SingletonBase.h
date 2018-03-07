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
	inline static void Create();

	/*
	*	�C���X�^���X�̔j��
	*/
	inline static void Delete();

	/*
	*	�C���X�^���X�̎擾	
	*	return �C���X�^���X
	*/
	inline static Type* GetInstance();

protected:
	/*
	*	�V���O���g���C���X�^���X
	*/
	static Type* m_pInstance;

	/* �R���X�g���N�^�֐��ƃf�X�g���N�^�֐��͗��R�������ꍇ�ȊO�͐G��Ȃ� */
	/* �ǂ̃^�C�~���O�ł��̃N���X�����ꂽ���Ƃ� */
	SingletonBase();
	 virtual ~SingletonBase();
};


#endif