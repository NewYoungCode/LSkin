#include "resource.h"
#define MAX_LOADSTRING 100
#include "../Wuilib/Wuilib.h"
#include "os.h"
#include "GdiPlus.hpp"
class MainFrm :public Control {
public:
	Control btn1 = this->GetDlgItem(IDC_BUTTON1);
	Control custCtr = this->GetDlgItem(IDC_CUSTOM1);

	MainFrm(int id, Control*p = 0) :Control(id, p) {}

	void OnCtlMessage(const Control&ctr) {
		if (btn1 == ctr) {
			MainFrm *c = new MainFrm(IDD_DIALOG1);
			c->Show();
		}
	}
	bool OnPaint(HDC hdc) {
		Gdiplus::Graphics gp(hdc);
		Gdiplus::Pen pen(Gdiplus::Color::Red, 1);

		auto rect = GetRect();

		Gdiplus::SolidBrush sb(Gdiplus::Color::Azure);
		gp.FillRectangle(&sb, Gdiplus::Rect(0, 0, rect.width/2, rect.height));
		return false;
	}
	bool OnCtlColor(HWND wd, HDC hdc) {
		return false;
	}
	void OnDestroy() {
		Application::exit();
	}
};

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	Application app;
	Gdiplus::Init();

	MainFrm mainFrm(IDD_DIALOG1);
	mainFrm.SetText(TEXT("这是窗口1"));
	mainFrm.SetRect({ 0,0,800,600 });
	mainFrm.Show();

	return app.exec();
}