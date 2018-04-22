#ifndef OBJECTBASE_H
#define OBJECTBASE_H

namespace Lib
{

	//--------------------------------------------------
	//	 class
	//--------------------------------------------------
	/*
	*	オブジェクトの基底クラス
	*/
	class ObjectBase
	{
	public:
		//--------------------------------------------------
		//	public function
		//--------------------------------------------------
		/*
		*	コンストラクタ
		*/
		ObjectBase();

		/*
		*	デストラクタ
		*/
		virtual ~ObjectBase();

		/*
		*	初期化関数
		*	成功すればtrue 失敗すればfalse
		*/
		virtual bool Initialize();

		/*
		*	終了関数
		*/
		virtual void Finalize();

		/*
		*	更新関数
		*/
		virtual void Update();

		/*
		*	描画関数
		*/
		virtual void Draw();
	};
}

#endif