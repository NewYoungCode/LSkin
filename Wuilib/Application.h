#pragma once
#include <Windows.h>
extern BOOL CALLBACK DialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
extern LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
class Application
{
public:
	Application();
	int exec();
	void exit();
};

