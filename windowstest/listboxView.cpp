#include "listboxView.h"

listboxView::listboxView(HWND hwnd, int id_mylistbox, wstring listboxname, elementPlace eplace, listboxModel* model) : hWnd(hwnd), ID_MYLISTBOX(id_mylistbox), listboxName(listboxname), place(eplace)
{
	wchar_t listbox[]{ L"LISTBOX" };	
	hListbox = CreateWindow(listbox, listboxname.c_str(), WS_CHILD | LBS_STANDARD | WS_VISIBLE,
		place.x, place.y, place.width, place.height, hWnd, (HMENU)ID_MYLISTBOX, NULL, NULL);

	_model = model;
	_model->addObserver(this);
}

listboxView::~listboxView()
{

}

int listboxView::getID()
{
	return ID_MYLISTBOX;
}

void listboxView::addString(wstring str)
{
	// Отменяем режим перерисовки списка
	SendMessage(hListbox, WM_SETREDRAW, FALSE, 0L);

	// Добавляем в список строку	
	SendMessage(hListbox, LB_ADDSTRING, 0, (LPARAM)str.c_str());

	// Включаем режим перерисовки списка
	SendMessage(hListbox, WM_SETREDRAW, TRUE, 0L);

	// Перерисовываем список
	InvalidateRect(hListbox, NULL, TRUE);	
}

wstring listboxView::getActiveStringText()
{
	int ListItem = (int)SendMessage(hListbox, LB_GETCURSEL, 0, 0);
	TCHAR buff[1024] = { 0 };

	if (ListItem != LB_ERR)
		SendMessage(hListbox, LB_GETTEXT, ListItem, (LPARAM)buff);

	return wstring(&buff[0], sizeof(buff) / sizeof(buff[0]));
}

void listboxView::update()
{
	
}

