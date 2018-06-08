#ifndef MATH_H
#define	MATH_H

namespace Lib
{
	const float g_Pi = 3.14159265358979323846f;

	//�����_��
	//inline int MyRandom()
	//{
	//	return;
	//}

	//���W�A�����p�x�ɕϊ�
	inline float To(int _radian)
	{
		return (_radian * (180.f / g_Pi));
	}

	//�p�x�����W�A���ɕϊ�
	inline float ToRadian(float _d)
	{
		return (_d * (g_Pi / 180.f));
	}

}

#endif