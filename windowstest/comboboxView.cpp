#include "comboboxView.h"


comboboxView::comboboxView(HWND hwnd, int id_mycombobox, wstring comboboxname, elementPlace eplace, comboboxModel* model) : hWnd(hwnd), ID_MYCOMBOBOX(id_mycombobox), comboboxName(comboboxname), place(eplace)
{
	wchar_t combo[]{ L"COMBOBOX" };	
	hCombo = CreateWindow(combo, NULL, WS_CHILD | WS_VISIBLE,
		place.x, place.y, place.width, place.height, hWnd, (HMENU)ID_MYCOMBOBOX, NULL, NULL);

	_model = model;
	_model->addObserver(this);
}

comboboxView::~comboboxView()
{

}

int comboboxView::getID()
{
	return ID_MYCOMBOBOX;
}

wstring comboboxView::getText()
{
	TCHAR buff[1024] = { 0 };
	GetWindowText(hCombo, buff, 1024);

	return wstring(&buff[0], sizeof(buff) / sizeof(buff[0]));
}

void comboboxView::setText(wstring str)
{
	SetWindowText(hCombo, str.c_str());
}

void comboboxView::update()
{
	wstring text = getText();
	setText(text);
}
