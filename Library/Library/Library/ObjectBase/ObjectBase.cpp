#include"ObjectBase.h"

namespace Lib
{

	//---------------------------------------------
	//	コンストラクタ	デストラクタ
	//---------------------------------------------
	ObjectBase::ObjectBase()
	{
	}


	//---------------------------------------------
	//	Public Functions
	//---------------------------------------------
	ObjectBase::~ObjectBase()
	{
	}

	bool ObjectBase::Initialize()
	{
		return true;
	}

	void ObjectBase::Finalize()
	{
	}

	void ObjectBase::Update()
	{
	}

	void ObjectBase::Draw()
	{
	}
}