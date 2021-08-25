#pragma once
#include <Windows.h>
#include "Application.h"
#include <iostream>

typedef struct {
	int x, y, width, height;
}Rect;

class Control
{
public:
	Control(int resourceId, Control*p = NULL);
	HWND Wnd = 0;
	int ResourceId = 0;
	void Enable(bool enable = true);
	Control GetDlgItem(int resourceId);
	Control(LPCTSTR className);
	Control(HWND hWnd);
	virtual	~Control();
	virtual  BOOL  WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual bool operator==(const Control& right);

	void GetText(TCHAR *text,size_t MAX_SIZE_);
	void SetText(LPCTSTR text);
	void Show(int cmdShow = SW_SHOW);
	void Hide();
	void Close();
	void Invalidate();
	Rect GetRect();
	void SetRect(const Rect&rect);
protected:
	virtual bool OnPaint(HDC hdc);
	virtual void OnSize();
	virtual bool OnCtlColor(HWND hWnd, HDC hdc);
	virtual void OnCtlMessage(const Control&ctr);
	virtual void OnDestroy();

};
