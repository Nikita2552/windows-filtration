#include "editView.h"

editView::editView(HWND hwnd, int id_myedit, wstring editname, elementPlace eplace, editModel* model) : hWnd(hwnd), ID_MYEDIT(id_myedit), editName(editname), place(eplace)
{
	wchar_t edit[]{ L"EDIT" };	
	hEdit = CreateWindow(edit, editName.c_str(), WS_CHILD | WS_VISIBLE,
		place.x, place.y, place.width, place.height, hWnd, (HMENU)ID_MYEDIT, NULL, NULL);

	_model = model;
	_model->addObserver(this);
}

editView::~editView()
{

}

int editView::getID()
{
	return ID_MYEDIT;
}

wstring editView::getText()
{
	TCHAR buff[1024] = { 0 };
	GetWindowText(hEdit, buff, 1024);

	return wstring(&buff[0], sizeof(buff) / sizeof(buff[0]));
}

void editView::setText(wstring str)
{
	SetWindowText(hEdit, str.c_str());
}

void editView::update()
{
	wstring text = getText();
	setText(text);
}

exampleMemento* editView::save()
{
	vector<float> vec;
	return new exampleMemento(getText(), vec);  //TODO: Заменить на подходящие значения!
}

void editView::restore(exampleMemento* memento)
{
	setText(memento->getImg());   //TODO: Заменить на подходящие значения!
}
