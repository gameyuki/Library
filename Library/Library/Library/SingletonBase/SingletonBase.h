#ifndef SINGLETONBASE_H
#define	SINGLETONBASE_H

//--------------------------------------------------
//	include
//--------------------------------------------------
#include<Windows.h>


/*
*	Singletonの基底クラス
*
*/
template <typename Type>
class SingletonBase
{
public:

	/*
	*	インスタンスの生成
	*/
	inline static void Create()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new Type();
		}
	}

	/*
	*	インスタンスの破棄
	*/
	inline static void Delete()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}

	/*
	*	インスタンスの取得	
	*	return インスタンス
	*/
	inline static Type* GetInstance()
	{
		return m_pInstance;
	}

protected:
	/*
	*	シングルトンインスタンス
	*/
	static Type* m_pInstance;

	/* コンストラクタ関数とデストラクタ関数は理由が無い場合以外は触らない */
	/* どのタイミングでこのクラスが作られたかとか */
	inline SingletonBase() {};
	inline  virtual ~SingletonBase() {};
};


#endif