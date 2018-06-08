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

	/* @ */
	//--------------------------------------------------
	//	public function
	//--------------------------------------------------
	bool XInputDevice::GetLeftAnalog(Analog _analogstate)
	{
		switch (_analogstate)
		{
		case ANALOG_UP:
			if (m_Xinput.Gamepad.sThumbLY > -MAX / 4)
			{
				return true;
			}
			break;
		case ANALOG_DOWN:
			if (m_Xinput.Gamepad.sThumbLY < MAX / 4)
			{
				return true;
			}
			break;
		case ANALOG_LEFT:
			if (m_Xinput.Gamepad.sThumbLX < -MAX / 4)
			{
				return true;
			}
			break;
		case ANALOG_RIGHT:
			if (m_Xinput.Gamepad.sThumbLX > MAX / 4)
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
			if (m_PadoldState[_buttonIndex] == PAD_DOWN)
			{
				m_PadState[_buttonIndex] = PAD_DOWN;
			}
			else
			{
				m_PadState[_buttonIndex] = PAD_PRESSED;
			}

			m_PadoldState[_buttonIndex] = PAD_DOWN;
		}
		else
		{
			if (m_PadoldState[_buttonIndex] == PAD_DOWN)
			{
				m_PadState[_buttonIndex] = PAD_RELEASE;
			}
			else
			{
				m_PadState[_buttonIndex] = PAD_OFF;
			}

			m_PadoldState[_buttonIndex] = PAD_OFF;
		}
	}
}