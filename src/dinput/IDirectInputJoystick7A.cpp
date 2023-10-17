#include "IDirectInput7A.h"
#include "IDirectInputJoystick7A.h"
#include "../keymapping.h"

#include <list>

extern bool IsJoystickAcquired;
extern std::list<RAWMOUSE> g_lastMouseEvents2;
extern std::list<RAWKEYBOARD> g_lastKeyboardEvents2;
extern bool g_keyboardButtonState2[256];
std::list<DIDEVICEOBJECTDATA> g_generatedJoystickEvents;

extern bool g_UseAccumulation;
extern float g_SpeedMultiplierX;
extern float g_SpeedMultiplierY;

HRESULT m_IDirectInputJoystick7A::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
	(void)riid;
	(void)ppvObj;

	return DIERR_GENERIC;
}

ULONG m_IDirectInputJoystick7A::AddRef()
{
	return ++m_references;
}

ULONG m_IDirectInputJoystick7A::Release()
{
	ULONG ref = --m_references;
	if(ref == 0) delete this;
	return ref;
}

HRESULT m_IDirectInputJoystick7A::GetCapabilities(LPDIDEVCAPS)
{
	// Not used
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::EnumObjects(LPDIENUMDEVICEOBJECTSCALLBACKA, LPVOID, DWORD)
{
	// Used but not needed
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::GetProperty(REFGUID, LPDIPROPHEADER)
{
	// Not used
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::SetProperty(REFGUID, LPCDIPROPHEADER)
{
	// Used but not needed
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::Acquire()
{
	void AcquireJoystickInput(); AcquireJoystickInput();
	//void AcquireMouseInput(); AcquireMouseInput();
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::Unacquire()
{
	void UnAcquireJoystickInput(); UnAcquireJoystickInput();
	//void UnAcquireMouseInput(); UnAcquireMouseInput();
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::GetDeviceState(DWORD, LPVOID)
{
	// Not used
	return DI_OK;
}

#define JOY_BUTTON_1  DIJOFS_BUTTON0
#define JOY_BUTTON_2  DIJOFS_BUTTON1
#define JOY_BUTTON_3  DIJOFS_BUTTON2
#define JOY_BUTTON_4  DIJOFS_BUTTON3
#define JOY_BUTTON_5  DIJOFS_BUTTON4
#define JOY_BUTTON_6  DIJOFS_BUTTON5
#define JOY_BUTTON_7  DIJOFS_BUTTON6
#define JOY_BUTTON_8  DIJOFS_BUTTON7
#define JOY_BUTTON_9  DIJOFS_BUTTON8
#define JOY_BUTTON_10 DIJOFS_BUTTON9
#define JOY_BUTTON_11 DIJOFS_BUTTON10
#define JOY_BUTTON_12 DIJOFS_BUTTON11
#define JOY_BUTTON_13 DIJOFS_BUTTON12
#define JOY_BUTTON_14 DIJOFS_BUTTON13
#define JOY_BUTTON_15 DIJOFS_BUTTON14
#define JOY_BUTTON_16 DIJOFS_BUTTON15
#define JOY_BUTTON_17 DIJOFS_BUTTON16
#define JOY_BUTTON_18 DIJOFS_BUTTON17
#define JOY_BUTTON_19 DIJOFS_BUTTON18
#define JOY_BUTTON_20 DIJOFS_BUTTON19
#define JOY_BUTTON_21 DIJOFS_BUTTON20
#define JOY_BUTTON_22 DIJOFS_BUTTON21
#define JOY_BUTTON_23 DIJOFS_BUTTON22
#define JOY_BUTTON_24 DIJOFS_BUTTON23
#define JOY_BUTTON_25 DIJOFS_BUTTON24
#define JOY_BUTTON_26 DIJOFS_BUTTON25
#define JOY_BUTTON_27 DIJOFS_BUTTON26
#define JOY_BUTTON_28 DIJOFS_BUTTON27
#define JOY_BUTTON_29 DIJOFS_BUTTON28
#define JOY_BUTTON_30 DIJOFS_BUTTON29
#define JOY_BUTTON_31 DIJOFS_BUTTON30
#define JOY_BUTTON_32 DIJOFS_BUTTON31

int ReplaceKeyId(int keyId) {
	//Standard 32 JOY_BUTTON keys
	if      (keyId == DIK_Q) {
		return JOY_BUTTON_3;
	}
	else if (keyId == DIK_E) {
		return JOY_BUTTON_4;
	}
	else if (keyId == DIK_W) { 
		return JOY_BUTTON_5;
	}
	else if (keyId == DIK_S) { 
		return JOY_BUTTON_6;
	}
	else if (keyId == DIK_LCONTROL) {
		return JOY_BUTTON_7;
	}
	else if (keyId == DIK_LSHIFT) { 
		return JOY_BUTTON_8;
	}
	else if (keyId == DIK_SPACE) {
		return JOY_BUTTON_9;
	}
	else if (keyId == DIK_LALT) {
		return JOY_BUTTON_10;
	}
	else if (keyId == DIK_TAB) { 
		return JOY_BUTTON_11;
	}
	else if (keyId == DIK_R) { 
		return JOY_BUTTON_12;
	}
	else if (keyId == DIK_X) { 
		return JOY_BUTTON_13;
	}
	else if (keyId == DIK_A) { 
		return JOY_BUTTON_14;
	}
	else if (keyId == DIK_D) { 
		return JOY_BUTTON_15;
	}
	else if (keyId == DIK_F) { 
		return JOY_BUTTON_16;
	}
	else if (keyId == DIK_ESCAPE) { 
		return JOY_BUTTON_17;
	}
	else if (keyId == DIK_C) { 
		return JOY_BUTTON_18;
	}
	else if (keyId == DIK_L) { 
		return JOY_BUTTON_19;
	}
	else if (keyId == DIK_M) { 
		return JOY_BUTTON_20;
	}
	else if (keyId == DIK_0) { 
		return JOY_BUTTON_21;
	}
	else if (keyId == DIK_1) { 
		return JOY_BUTTON_22;
	}
	else if (keyId == DIK_2) { 
		return JOY_BUTTON_23;
	}
	else if (keyId == DIK_3) { 
		return JOY_BUTTON_24;
	}
	else if (keyId == DIK_4) { 
		return JOY_BUTTON_25;
	}
	else if (keyId == DIK_5) { 
		return JOY_BUTTON_26;
	}
	else if (keyId == DIK_6) { 
		return JOY_BUTTON_27;
	}
	else if (keyId == DIK_7) { 
		return JOY_BUTTON_28;
	}
	else if (keyId == DIK_8) { 
		return JOY_BUTTON_29;
	}
	else if (keyId == DIK_9) { 
		return JOY_BUTTON_30;
	}
	else if (keyId == DIK_F5) {
		return JOY_BUTTON_31;
	}
	else if (keyId == DIK_F9) {
		return JOY_BUTTON_32;
	}
	else {
		//Other keys on the keyboard just for completeness' sake...
		if ((keyId == DIK_LEFT)
			|| (keyId == DIK_RIGHT)
			|| (keyId == DIK_UP)
			|| (keyId == DIK_DOWN)
			|| (keyId == DIK_RCONTROL)
			|| (keyId == DIK_RSHIFT)
			|| (keyId == DIK_T)
			|| (keyId == DIK_Z)
			|| (keyId == DIK_U)
			|| (keyId == DIK_I)
			|| (keyId == DIK_O)
			|| (keyId == DIK_P)
			|| (keyId == DIK_G)
			|| (keyId == DIK_H)
			|| (keyId == DIK_J)
			|| (keyId == DIK_K)
			|| (keyId == DIK_Y)
			|| (keyId == DIK_V)
			|| (keyId == DIK_RALT)
			|| (keyId == DIK_RETURN)) {
			return keyId;
		}
		//Sadly, these keys are in conflict with the joystick axis and button values so I have to remap them to something else. This shit is too complicated for me.
		if (keyId == DIK_B){
			return (DIK_MEDIASELECT + 1);
		}
		else if (keyId == DIK_N) {
			return (DIK_MEDIASELECT + 2);
		}
		else if (keyId == DIK_RALT) {
			return (DIK_MEDIASELECT + 3);
		}
		else if (keyId == DIK_F1) {
			return (DIK_MEDIASELECT + 4);
		}
		else if (keyId == DIK_F2) {
			return (DIK_MEDIASELECT + 5);
			}
		else if (keyId == DIK_F3) {
			return (DIK_MEDIASELECT + 6);

			}
		else if (keyId == DIK_F4) {
			return (DIK_MEDIASELECT + 7);

			}
		else if (keyId == DIK_F6) {
			return (DIK_MEDIASELECT + 8);

			}
		else if (keyId == DIK_F7) {
			return (DIK_MEDIASELECT + 9);

			}
		else if (keyId == DIK_F8) {
			return (DIK_MEDIASELECT + 10);

			}
		else if (keyId == DIK_F10) {
			return (DIK_MEDIASELECT + 11);

			}
		else if (keyId == DIK_F11) {
			return (DIK_MEDIASELECT + 12);

			}
		else if (keyId == DIK_F12) {
			return (DIK_MEDIASELECT + 13);
			}
		else if (keyId == DIK_BACKSPACE) {
			return (DIK_MEDIASELECT + 14);
			}
		else if (keyId == DIK_UNDERLINE) {
			return (DIK_MEDIASELECT + 15);
			}
		else if (keyId == DIK_SLASH) {
			return (DIK_MEDIASELECT + 16);
		}
		else if (keyId == DIK_ADD) {
			return (DIK_MEDIASELECT + 17);
			}
		else if (keyId == DIK_MINUS) {
			return (DIK_MEDIASELECT + 18);
		}
		else if (keyId == DIK_PERIOD) {
			return (DIK_MEDIASELECT + 19);
		}
		else if (keyId == DIK_COMMA) {
			return (DIK_MEDIASELECT + 20);
		}
		else if (keyId == DIK_INSERT) {
			return (DIK_MEDIASELECT + 21);
		}
		else if (keyId == DIK_BACKSLASH) {
			return (DIK_MEDIASELECT + 22);
		}
		else if (keyId == DIK_OEM_102) {
			return (DIK_MEDIASELECT + 23);
		}
		else if (keyId == DIK_EQUALS) {
			return (DIK_MEDIASELECT + 24);
		}
		else if (keyId == DIK_RBRACKET) {
			return (DIK_MEDIASELECT + 25);
		}
		//else if (keyId == DIK_RIGHT) {
		//	return MOUSE_DY;
		//}
		//else if (keyId == DIK_UP) {
		//	return MOUSE_UP;
		//}
		//else if (keyId == DIK_DOWN) {
		//	return MOUSE_DOWN;
		//}
		//else if (keyId == DIK_LCONTROL) {
		//	return MOUSE_LEFT;
		//}
		//else if (keyId == DIK_RSHIFT) {
		//	return MOUSE_RIGHT;
		//}
		//else if (keyId == DIK_RETURN) {
		//	return MOUSE_UP;
		//}
		return -1;
	}
}

int lastKeyID = -1;

HRESULT m_IDirectInputJoystick7A::GetDeviceData(DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD)
{
	// Used but not needed
	if (!IsJoystickAcquired)
	{
		*pdwInOut = 0;
		return DI_OK;
	}

	if (!g_lastMouseEvents2.empty())
	{
		LONG relativeX = 0;
		LONG relativeY = 0;
		do
		{
			RAWMOUSE& rawMouse = g_lastMouseEvents2.front();
			RAWKEYBOARD& rawKeyboard = g_lastKeyboardEvents2.front();

			//rawKeyboard.VKey

			if (rawMouse.lLastX != 0)
				relativeX = (g_UseAccumulation ? relativeX : 0) + rawMouse.lLastX;
			if (rawMouse.lLastY != 0)
				relativeY = (g_UseAccumulation ? relativeY : 0) + rawMouse.lLastY;
			if (rawMouse.usButtonFlags & (RI_MOUSE_WHEEL | RI_MOUSE_HWHEEL))
			{
				float wheelDelta = static_cast<float>(static_cast<short>(rawMouse.usButtonData));
				float numTicks = wheelDelta / WHEEL_DELTA;

				bool isHorizontalScroll = (rawMouse.usButtonFlags & RI_MOUSE_HWHEEL) == RI_MOUSE_HWHEEL;
				bool isScrollByPage = false;
				float scrollDelta = numTicks;
				if (isHorizontalScroll)
				{
					unsigned long scrollChars = 1;
					SystemParametersInfo(SPI_GETWHEELSCROLLCHARS, 0, &scrollChars, 0);
					scrollDelta *= scrollChars;
				}
				else
				{
					unsigned long scrollLines = 3;
					SystemParametersInfo(SPI_GETWHEELSCROLLLINES, 0, &scrollLines, 0);
					if (scrollLines == WHEEL_PAGESCROLL)
						isScrollByPage = true;
					else
						scrollDelta *= scrollLines;
				}

				DIDEVICEOBJECTDATA zMotion;
				zMotion.dwOfs = DIJOFS_Z;
				zMotion.dwData = static_cast<DWORD>(static_cast<LONG>(scrollDelta > 0 ? ceilf(scrollDelta) : floorf(scrollDelta)));
				g_generatedJoystickEvents.push_back(zMotion);
			}
			if (rawMouse.usButtonFlags & (RI_MOUSE_BUTTON_1_DOWN | RI_MOUSE_BUTTON_1_UP))
			{
				DIDEVICEOBJECTDATA mouseButton;
				mouseButton.dwOfs = JOY_BUTTON_1;
				mouseButton.dwData = (rawMouse.usButtonFlags & RI_MOUSE_BUTTON_1_DOWN ? 0x80 : 0);
				g_generatedJoystickEvents.push_back(mouseButton);
			}
			if (rawMouse.usButtonFlags & (RI_MOUSE_BUTTON_2_DOWN | RI_MOUSE_BUTTON_2_UP))
			{
				DIDEVICEOBJECTDATA mouseButton;
				mouseButton.dwOfs = JOY_BUTTON_2;
				mouseButton.dwData = (rawMouse.usButtonFlags & RI_MOUSE_BUTTON_2_DOWN ? 0x80 : 0);
				g_generatedJoystickEvents.push_back(mouseButton);
			}
			if (rawMouse.usButtonFlags & (RI_MOUSE_BUTTON_3_DOWN | RI_MOUSE_BUTTON_3_UP))
			{
				DIDEVICEOBJECTDATA mouseButton;
				mouseButton.dwOfs = DIMOFS_BUTTON2;
				mouseButton.dwData = (rawMouse.usButtonFlags & RI_MOUSE_BUTTON_3_DOWN ? 0x80 : 0);
				g_generatedJoystickEvents.push_back(mouseButton);
			}
			if (rawMouse.usButtonFlags & (RI_MOUSE_BUTTON_4_DOWN | RI_MOUSE_BUTTON_4_UP))
			{
				DIDEVICEOBJECTDATA mouseButton;
				mouseButton.dwOfs = DIMOFS_BUTTON3;
				mouseButton.dwData = (rawMouse.usButtonFlags & RI_MOUSE_BUTTON_4_DOWN ? 0x80 : 0);
				g_generatedJoystickEvents.push_back(mouseButton);
			}
			if (rawMouse.usButtonFlags & (RI_MOUSE_BUTTON_5_DOWN | RI_MOUSE_BUTTON_5_UP))
			{
				DIDEVICEOBJECTDATA mouseButton;
				mouseButton.dwOfs = DIMOFS_BUTTON4;
				mouseButton.dwData = (rawMouse.usButtonFlags & RI_MOUSE_BUTTON_5_DOWN ? 0x80 : 0);
				g_generatedJoystickEvents.push_back(mouseButton);
			}
			g_lastMouseEvents2.pop_front();
		} while (!g_lastMouseEvents2.empty());

		if (relativeX != 0)
		{
			DIDEVICEOBJECTDATA xMotion;
			xMotion.dwOfs = DIJOFS_X;
			xMotion.dwData = static_cast<DWORD>(static_cast<LONG>(relativeX * g_SpeedMultiplierX));
			g_generatedJoystickEvents.push_back(xMotion);
		}
		if (relativeY != 0)
		{
			DIDEVICEOBJECTDATA yMotion;
			yMotion.dwOfs = DIJOFS_Y;
			yMotion.dwData = static_cast<DWORD>(static_cast<LONG>(relativeY * g_SpeedMultiplierY));
			g_generatedJoystickEvents.push_back(yMotion);
		}
	}
	if (!g_lastKeyboardEvents2.empty())
	{
		do
		{
			RAWKEYBOARD& rawKeyboard = g_lastKeyboardEvents2.front();
			DWORD keyId = VK_Keys_Map[rawKeyboard.VKey];
			if (keyId != 0)
			{
				if ((rawKeyboard.Message == WM_KEYDOWN) && !g_keyboardButtonState2[keyId])
				{
					DIDEVICEOBJECTDATA keyboardKey;
					keyboardKey.dwOfs = ReplaceKeyId(keyId);
					keyboardKey.dwData = 0x80;
					g_generatedJoystickEvents.push_back(keyboardKey);
					g_keyboardButtonState2[keyId] = true;
				}
				else if (rawKeyboard.Message == WM_KEYUP)
				{
					DIDEVICEOBJECTDATA keyboardKey;
					keyboardKey.dwOfs = ReplaceKeyId(keyId);
					keyboardKey.dwData = 0;
					g_generatedJoystickEvents.push_back(keyboardKey);
					g_keyboardButtonState2[keyId] = false;
				}
			}
			g_lastKeyboardEvents2.pop_front();
		} while (!g_lastKeyboardEvents2.empty());
	}

	if (!rgdod)
	{
		*pdwInOut = static_cast<DWORD>(g_generatedJoystickEvents.size());
		return DI_OK;
	}
	if (*pdwInOut > 0 && !g_generatedJoystickEvents.empty())
	{
		*pdwInOut = std::min<DWORD>(*pdwInOut, g_generatedJoystickEvents.size());
		for (DWORD i = 0; i < *pdwInOut; ++i)
		{
			CopyMemory(reinterpret_cast<void*>(reinterpret_cast<DWORD>(rgdod) + (cbObjectData * i)), &g_generatedJoystickEvents.front(), cbObjectData);
			g_generatedJoystickEvents.pop_front();
		}
		return DI_OK;
	}
	*pdwInOut = 0;
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::SetDataFormat(LPCDIDATAFORMAT)
{
	// Not used
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::SetEventNotification(HANDLE)
{
	// Used but not needed
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::SetCooperativeLevel(HWND hwnd, DWORD dwFlags)
{
	//void InitMouseRawInput(HWND hwnd); InitMouseRawInput(hwnd);
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::GetObjectInfo(LPDIDEVICEOBJECTINSTANCEA, DWORD, DWORD)
{
	// Not used
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::GetDeviceInfo(LPDIDEVICEINSTANCEA)
{
	// Not used
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::RunControlPanel(HWND, DWORD)
{
	// Not used
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::Initialize(HINSTANCE, DWORD, REFGUID)
{
	// Not used
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::CreateEffect(REFGUID, LPCDIEFFECT, LPDIRECTINPUTEFFECT*, LPUNKNOWN)
{
	// Not used
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::EnumEffects(LPDIENUMEFFECTSCALLBACKA, LPVOID, DWORD)
{
	// Not used
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::GetEffectInfo(LPDIEFFECTINFOA, REFGUID)
{
	// Not used
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::GetForceFeedbackState(LPDWORD)
{
	// Not used
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::SendForceFeedbackCommand(DWORD)
{
	// Not used
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::EnumCreatedEffectObjects(LPDIENUMCREATEDEFFECTOBJECTSCALLBACK, LPVOID, DWORD)
{
	// Not used
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::Escape(LPDIEFFESCAPE)
{
	// Not used
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::Poll()
{
	// Used but not needed
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::SendDeviceData(DWORD, LPCDIDEVICEOBJECTDATA, LPDWORD, DWORD)
{
	// Not used
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::EnumEffectsInFile(LPCSTR, LPDIENUMEFFECTSINFILECALLBACK, LPVOID, DWORD)
{
	// Not used
	return DI_OK;
}

HRESULT m_IDirectInputJoystick7A::WriteEffectToFile(LPCSTR, DWORD, LPDIFILEEFFECT, DWORD)
{
	// Not used
	return DI_OK;
}
