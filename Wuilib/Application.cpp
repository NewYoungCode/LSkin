#include "Application.h"

BOOL CALLBACK Global_DialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LONG USERDATA = GetWindowLong(hWnd, GWLP_USERDATA);
	Control *ctrPtr = dynamic_cast<Control*>((Control*)USERDATA);
	if (ctrPtr) {
		return ctrPtr->WndProc(hWnd, uMsg, wParam, lParam);
	}
	return FALSE;
}

LRESULT CALLBACK Global_WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	LONG objPtr = GetWindowLong(hwnd, GWLP_USERDATA);
	//if (objPtr) {
	//	LSkin::Control *ptr = (LSkin::Control*)objPtr;
	//	//交予实例对象去处理这个函数并返回
	//	return 	ptr->WndProc(hwnd, message, wParam, lParam);
	//}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

Application::Application() {
	//设计窗口
	HINSTANCE hInstance = GetModuleHandle(0);
	WNDCLASS     wc;
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS | CS_OWNDC | CS_SAVEBITS;
	wc.lpfnWndProc = Global_WndProc;
	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = TEXT("WuiLib");
	if (!RegisterClass(&wc)) //注册窗口
	{
		MessageBox(NULL, TEXT("This program requires Windows NT!"),
			wc.lpszClassName, MB_ICONERROR);
		return;
	}
}

int Application::exec()
{
	{
		MSG msg;
		while (GetMessage(&msg, 0, 0, 0) != 0)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return msg.wParam;
	}
}

void Application::exit() {
	PostQuitMessage(0);
}

