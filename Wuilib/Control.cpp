#include "Control.h"
Control::Control(int resourceId, Control*p)
{
	Wnd = CreateDialog(GetModuleHandle(0), MAKEINTRESOURCE(resourceId),p==NULL?NULL:p->Wnd, DialogProc);
}

void Control::Show(int cmdShow) {
	::ShowWindow(Wnd, cmdShow);
}