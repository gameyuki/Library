#ifndef  MACRO_H
#define  MACRO_H

//--------------------------------------------------
//	include
//--------------------------------------------------
#include<Windows.h>


//--------------------------------------------------
//	public function
//--------------------------------------------------
/*
*	Release�p�e���v���[�g�֐�
*/
template<typename Type>
inline void SafeRelease(Type*& _type)
{
	if (_type != nullptr)
	{
		(_type)->Release();
		(_type) = nullptr;
	}
}

/*
*	delete�p�e���v���[�g�֐�
*/
template<typename Type>
inline void SafeDelete(Type*& _type)
{
	if (_type != nullptr)
	{
		delete _type;
		(_type) = nullptr;
	}
}

/*
*	delete �z��p�e���v���[�g�֐�
*/
template<typename Type>
inline void SafeDeleteArray(Type*& _type)
{
	if (_type != nullptr)
	{
		delete[] _type;
		(_type) = nullptr;
	}
}

/*
*	�G���[�p���b�Z�[�W�֐�
*/
void OutPutError(char* _errorlog)
{
	MessageBox(0, _errorlog, "", MB_OK);
}

#endif