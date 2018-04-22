//--------------------------------------------------
//	include
//--------------------------------------------------
#include"XInputDevice.h"

namespace Lib
{

	//--------------------------------------------------
	//	コンストラクタ : デストラクタ
	//--------------------------------------------------
	XInputDevice::XInputDevice()
	{
	}

	XInputDevice::~XInputDevice()
	{
	}

	//--------------------------------------------------
	//	public function
	//--------------------------------------------------
	bool XInputDevice::GetLeftAnalog(Analog _analogstate)
	{
		switch (_analogstate)
		{
		case ANALOG_UP:
			if (m_Xinput.Gamepad.sThumbLY > -65535 / 4)
			{
				return true;
			}
			break;
		case ANALOG_DOWN:
			if (m_Xinput.Gamepad.sThumbLY < 65535 / 4)
			{
				return true;
			}
			break;
		case ANALOG_LEFT:
			if (m_Xinput.Gamepad.sThumbLX < -65535 / 4)
			{
				return true;
			}
			break;
		case ANALOG_RIGHT:
			if (m_Xinput.Gamepad.sThumbLX > 65535 / 4)
			{
				return true;
			}
			break;
		}

		return false;
	}

	void XInputDevice::CheckButtonState(WORD _butttonID, int _buttonIndex)
	{
		if (m_Xinput.Gamepad.wButtons & _butttonID)
		{
			if (m_PadoldState[_buttonIndex] == PADON)
			{
				m_PadState[_buttonIndex] = PADON;
			}
			else
			{
				m_PadState[_buttonIndex] = PADPUSH;
			}

			m_PadoldState[_buttonIndex] = PADON;
		}
		else
		{
			if (m_PadoldState[_buttonIndex] == PADON)
			{
				m_PadState[_buttonIndex] = PADRELEASE;
			}
			else
			{
				m_PadState[_buttonIndex] = PADOFF;
			}

			m_PadoldState[_buttonIndex] = PADOFF;
		}
	}
}