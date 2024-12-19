#include "radiobuttonView.h"

radiobuttonView::radiobuttonView(HWND hwnd, int id_myradiobutton, wstring radiobuttonname, elementPlace eplace, radiobuttonModel* model) : hWnd(hwnd), ID_MYRADIOBUTTON(id_myradiobutton), radiobuttonName(radiobuttonname), place(eplace)
{
	wchar_t radio[]{ L"BUTTON" };	
	hRadio = CreateWindow(radio, radiobuttonName.c_str(), WS_CHILD | BS_AUTORADIOBUTTON | WS_VISIBLE,
		place.x, place.y, place.width, place.height, hWnd, (HMENU)ID_MYRADIOBUTTON, NULL, NULL);

	_model = model;
	_model->addObserver(this);
}

radiobuttonView::~radiobuttonView()
{

}

int radiobuttonView::getID()
{
	return ID_MYRADIOBUTTON;
}

wstring radiobuttonView::getText()
{
	TCHAR buff[1024] = { 0 };
	GetWindowText(hRadio, buff, 1024);

	return wstring(&buff[0], sizeof(buff) / sizeof(buff[0]));
}

void radiobuttonView::setText(wstring str)
{
	SetWindowText(hRadio, str.c_str());
}

void radiobuttonView::update()
{
	wstring text = getText();
	setText(text);
}