#include "buttonView.h"

buttonView::buttonView(HWND hwnd, int id_mybutton, wstring buttonname, elementPlace eplace, buttonModel* model) : hWnd(hwnd), ID_MYBUTTON(id_mybutton), buttonName(buttonname), place(eplace)
{
	wchar_t button[]{ L"BUTTON" };
	hButton = CreateWindow(button, buttonName.c_str(), WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
		place.x, place.y, place.width, place.height, hWnd, (HMENU)ID_MYBUTTON, NULL, NULL);

	_model = model;
	_model->addObserver(this);
}

buttonView::~buttonView()
{

}

int buttonView::getID()
{
	return ID_MYBUTTON;
}

wstring buttonView::getText()
{
	TCHAR buff[1024] = { 0 };
	GetWindowText(hButton, buff, 1024);

	return wstring(&buff[0], sizeof(buff) / sizeof(buff[0]));
}

void buttonView::setText(wstring str)
{	
	SetWindowText(hButton, str.c_str());
}

void buttonView::update()
{
	vector <float> getdata = _model->getTestData();

	wstring wstr = L"";
	unsigned int i = 0;
	while (i < getdata.size())
	{
		wstr += L" " + convertfromfloat(getdata.at(i));
		i++;
	}
	
	setText(wstr);
}

wstring convertfromfloat(float num)
{
	wstringstream wss;
	wss << num;
	wstring wstr = wss.str();

	return wstr;
}
