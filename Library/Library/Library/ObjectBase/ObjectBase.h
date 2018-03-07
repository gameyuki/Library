#ifndef OBJECTBASE_H
#define OBJECTBASE_H


/*
*	�I�u�W�F�N�g�̊��N���X
*/
class ObjectBase
{
public:
	/*
	*	�R���X�g���N�^
	*/
	ObjectBase();

	/*
	*	�f�X�g���N�^
	*/
	virtual ~ObjectBase();

	/*
	*	�������֐�
	*	���������true ���s�����false
	*/
	virtual bool Initialize();

	/* 
	*	�I���֐�
	*/
	virtual void Finalize();

	/*
	*	�X�V�֐�
	*/
	virtual void Update();

	/*
	*	�`��֐�
	*/
	virtual void Draw();
};

#endif