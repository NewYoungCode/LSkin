#pragma once
#include <Windows.h>
#include "Application.h"
class Control
{
public:
	HWND Wnd;
	Control(int resourceId,Control*p=NULL);
	void Show(int cmdShow=SW_SHOW);
};
