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
*	Release用テンプレート関数
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
*	delete用テンプレート関数
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
*	delete 配列用テンプレート関数
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
*	エラー用メッセージ関数
*/
void OutPutError(char* _errorlog)
{
	MessageBox(0, _errorlog, "", MB_OK);
}

#endif