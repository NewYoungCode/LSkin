#include "Control.h"
Control::Control(int resourceId, Control*p)
{
	Wnd = CreateDialog(GetModuleHandle(0), MAKEINTRESOURCE(resourceId), p == NULL ? NULL : p->Wnd, Global_DialogProc);
	::SetWindowLong(Wnd, GWLP_USERDATA, (LONG)this);
	this->ResourceId = resourceId;
}

void Control::Enable(bool enable)
{
	::EnableWindow(Wnd, enable);
}

Control Control::GetDlgItem(int resourceId) {
	HWND hwnd = ::GetDlgItem(Wnd, resourceId);
	Control out(hwnd);
	out.ResourceId = resourceId;
	return out;
}

BOOL  Control::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	if (uMsg == WM_NOTIFY) {
	

	}

	/*if (uMsg == WM_ERASEBKGND) {
		return true;
	}*/
	//自身窗口重绘
	if (uMsg == WM_PAINT) {
		PAINTSTRUCT pst{};
		HDC hdc = BeginPaint(hWnd, &pst);
		bool b = OnPaint(hdc);
		EndPaint(hWnd, &pst);
		if (b) {
			return TRUE;
		}
	}

	if (uMsg == WM_SIZE) {
		OnSize();
	}

	if (uMsg == WM_CLOSE) {
		::DestroyWindow(hWnd);
	}
	if (uMsg == WM_DESTROY) {
		OnDestroy();
	}

	//子控件改颜色  
	if (uMsg == 0x0132 || uMsg == 0x0133 || uMsg == 0x0134 || uMsg == 0x0135 || uMsg == 0x0136 || uMsg == 0x0137 || uMsg == 0x0138 || uMsg == 0x01E1) {
		HWND ctrHwnd = (HWND)lParam;
		HDC hdc = ::GetDC(ctrHwnd);
		bool b = OnCtlColor(ctrHwnd, hdc);
		::ReleaseDC(ctrHwnd, hdc);
		if (b) {
			return TRUE;
		}
	}
	if (uMsg == WM_COMMAND) {
		Control ctr((HWND)lParam);
		OnCtlMessage(ctr);
	}
	return FALSE;
}

bool  Control::operator==(const Control& right)
{
	if (this->Wnd != 0 && this->Wnd == right.Wnd) {
		return true;
	}
	if (this->ResourceId != 0 && this->ResourceId == right.ResourceId) {
		return true;
	}
	return false;
}


Control::~Control() {

}

Control::Control(LPCTSTR className)
{

}

void Control::GetText(TCHAR *text, size_t MAX_SIZE_) {
	::GetWindowText(Wnd, text, MAX_SIZE_);
}

void Control::SetText(LPCTSTR text)
{
	::SetWindowText(Wnd, text);
}


Control::Control(HWND hWnd)
{
	this->Wnd = hWnd;
}

void Control::Show(int cmdShow) {
	::ShowWindow(Wnd, cmdShow);
}

void Control::Hide() {
	::ShowWindow(Wnd, SW_HIDE);
}

void Control::Close() {

	::SendMessage(Wnd, WM_CLOSE, 0, 0);
}

void Control::Invalidate() {
	::InvalidateRect(Wnd, NULL, true);
}

Rect Control::GetRect()
{
	RECT rect;
	::GetWindowRect(Wnd, &rect);
	return Rect{ rect.left,rect.top,rect.right - rect.left,rect.bottom - rect.top };
}

void Control::SetRect(const Rect  &rect)
{
	::MoveWindow(Wnd, rect.x, rect.y, rect.width, rect.height, true);
}

void Control::OnCtlMessage(const Control&ctr) {

}

void Control::OnDestroy()
{
}

void Control::OnSize() {

}

bool Control::OnCtlColor(HWND hWnd, HDC hdc)
{
	return false;
}

bool Control::OnPaint(HDC hdc)
{
	return false;
}
