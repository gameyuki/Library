#ifndef INPUTDEVICE_H
#define	INPUTDEVICE_H

#include<Windows.h>
#include<dinput.h>
#include<XInput.h>

#include"Library\SingletonBase\SingletonBase.h"


namespace Lib
{

	class InputDevice : public SingletonBase<InputDevice>
	{
	public:
		InputDevice();
		~InputDevice();

	private:

	};

}

#endif