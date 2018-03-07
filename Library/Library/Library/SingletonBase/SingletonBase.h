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
	inline static void Create();

	/*
	*	インスタンスの破棄
	*/
	inline static void Delete();

	/*
	*	インスタンスの取得	
	*	return インスタンス
	*/
	inline static Type* GetInstance();

protected:
	/*
	*	シングルトンインスタンス
	*/
	static Type* m_pInstance;

	/* コンストラクタ関数とデストラクタ関数は理由が無い場合以外は触らない */
	/* どのタイミングでこのクラスが作られたかとか */
	SingletonBase();
	 virtual ~SingletonBase();
};


#endif