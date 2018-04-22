#ifndef SCENEBASE_H
#define	SCENEBASE_H

namespace Lib
{

	//--------------------------------------------------
	//	 class
	//--------------------------------------------------
	/*
	*	シーン生成用基底クラス
	*/
	class SceneBase
	{
	public:
		//--------------------------------------------------
		//	public enum
		//--------------------------------------------------
		/*
		*	シーンの状態列挙
		*/
		enum STATE
		{
			/* 初期化状態 */
			INIT_STATE,
			/* 更新状態 */
			UPDATE_STATE,
			/* 終了状態 */
			FAINAL_STATE
		};

		//--------------------------------------------------
		//	public function
		//--------------------------------------------------
		/*
		*	コンストラクタ
		*	引数で継承先のシーンが識別する
		*/
		SceneBase(int _sceneID);

		/*
		*	デストラクタ
		*	誤ってインスタンス化させないように
		*/
		virtual ~SceneBase();

		/*
		*	基底初期化関数
		*	成功すればtrue しなければfalse
		*/
		virtual bool Initialize();

		/*
		*	基底終了関数
		*/
		virtual void Finalize();

		/*
		*	基底シーン更新関数
		*/
		virtual void Update();

		/*
		*	現在のシーンの状態を返す
		*/
		inline STATE GetState() const
		{
			return m_State;
		}

		/*
		*	現在のシーンのID(種類)を返す
		*/
		inline int GetSceneID() const
		{
			return m_SceneID;
		}

		/*
		*	遷移先(次)のシーンIDを返す
		*/
		inline int GetNextSceneID() const
		{
			return m_NextSceneID;
		}

	protected:
		//--------------------------------------------------
		//	protected variable
		//--------------------------------------------------
		/*
		*	シーンの状態(種類)
		*/
		STATE m_State;

		/*
		*	シーンのID
		*/
		int m_SceneID;

		/*
		*	次のシーンID
		*/
		int m_NextSceneID;
	};
}

#endif