#ifndef MATH_H
#define	MATH_H

namespace Lib
{
	const float g_Pi = 3.14159265358979323846f;

	//ランダム
	//inline int MyRandom()
	//{
	//	return;
	//}

	//ラジアンを角度に変換
	inline float To(int _radian)
	{
		return (_radian * (180.f / g_Pi));
	}

	//角度をラジアンに変換
	inline float ToRadian(float _d)
	{
		return (_d * (g_Pi / 180.f));
	}

}

#endif