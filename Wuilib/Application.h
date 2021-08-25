#pragma once
#include <Windows.h>
#include "Control.h"
extern BOOL CALLBACK Global_DialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
extern LRESULT CALLBACK Global_WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);


class Application
{
public:
	Application();
	int exec();
	static void exit();
};

