#ifndef  MACRO_H
#define  MACRO_H

template<typename Type>
inline void SafeRelease(Type*& _type)
{
	if (_type != nullptr)
	{
		(_type)->Release();
		(_type) = nullptr;
	}
}

template<typename Type>
inline void SafeDelete(Type*& _type)
{
	if (_type != nullptr)
	{
		delete _type;
		(_type) = nullptr;
	}
}

template<typename Type>
inline void SafeDeleteArray(Type*& _type)
{
	if (_type != nullptr)
	{
		delete[] _type;
		(_type) = nullptr;
	}
}
#endif