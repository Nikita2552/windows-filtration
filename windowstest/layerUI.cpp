#include "layerUI.h"

layerUI::layerUI(HWND hwnd): hWnd(hwnd)
{
	/* ��������� ������ */
	testbuttonm = new buttonModel();
	elementPlace eplace0 = { 5, 290, 150, 20 };
	wstring butname0 = L"test button to class";
	testbutton = new buttonView(hWnd, TESTBUTTON, butname0, eplace0, testbuttonm);
	testbuttonc = new buttonController(testbuttonm);

	/* ��������� ������ */
	testbutton2m = new buttonModel();
	elementPlace eplace1 = { 5, 320, 150, 20 };
	wstring butname1 = L"test button to class 2";
	testbutton2 = new buttonView(hWnd, TESTBUTTON2, butname1, eplace1, testbutton2m);
	testbutton2c = new buttonController(testbutton2m);

	/* ��������� ��������� */
	testcombom = new comboboxModel();
	elementPlace eplace2 = { 5, 350, 150, 20 };
	wstring comboname = L"test combo to class";
	testcombo = new comboboxView(hWnd, TESTCOMBO, comboname, eplace2, testcombom);
	testcomboc = new comboboxController(testcombom);

	/* ��������� ���� */
	testeditm = new editModel();
	elementPlace eplace3 = { 5, 380, 150, 20 };
	wstring editname = L"test edit to class";
	testedit = new editView(hWnd, TESTEDIT, editname, eplace3, testeditm);
	testeditc = new editController(testeditm);

	/* ��������� �����-������ */
	radio0m = new radiobuttonModel();
	elementPlace eplace4 = { 5, 430, 150, 20 };
	wstring radioname0 = L"test radio 0 to class";
	radio0 = new radiobuttonView(hWnd, TESTRADIO0, radioname0, eplace4, radio0m);
	radio0c = new radiobuttonController(radio0m);

	radio1m = new radiobuttonModel();
	elementPlace eplace5 = { 5, 460, 150, 20 };
	wstring radioname1 = L"test radio 1 to class";
	radio1 = new radiobuttonView(hWnd, TESTRADIO1, radioname1, eplace5, radio1m);
	radio1c = new radiobuttonController(radio1m);

	radio2m = new radiobuttonModel();
	elementPlace eplace6 = { 5, 490, 150, 20 };
	wstring radioname2 = L"test radio 2 to class";
	radio2 = new radiobuttonView(hWnd, TESTRADIO2, radioname2, eplace6, radio2m);
	radio2c = new radiobuttonController(radio2m);

	/* ��������� �������� � ������ � ���� */
	listm = new listboxModel();
	elementPlace eplace7 = { 5, 520, 150, 100 };
	wstring listname = L"test listbox to class";
	list = new listboxView(hWnd, TESTLIST, listname, eplace7, listm);
	listc = new listboxController(listm);

	list->addString(L"Green");
	list->addString(L"Red");
	list->addString(L"Blue");

	//TODO: ��������� ��������� � ����������� � ��������� �� ��������! +-
	//TODO: �������� ������� � ������� ��� ���������� � �������� +
	//TODO: �������� ������-������� � �������� � �������� +
	//TODO: �������� ����������� �������� � �������� ����������� ��� "������� ������" +	
	//TODO: ������� ��������� ���������� � �������� ��� � layerUI +-	

	//TODO: �������� ����� ����� - ������ ������ (Memento) - ��� ����������� ������� �������� +
	//TODO: �������� ������� ��������� (Event Queue) + 
	//TODO: ���������� �������� (Singleton) � ������� ��������� +
	//TODO: �������� ������ ������� ���� (Game Loop) ����� ��������� ����� � ������� +-
	//TODO: �������� ������ ����������� (Locality Data) ������ � ������� +-
	//TODO: �������� ��������� ���������, ��������� ������ ��������� (Subclass Sandbox) + 
	
	//TODO LATER: ������� ��������� � �������� ���������� MVC, ��������� ��������� ������, �������������
	//TODO LATER: ������� ����, ��������� �����, ������ �������, ������������� � ��������� ������
	//TODO LATER: ��������� MVC �� ���������. �������� �������������� �������� ��� ��������� ������ �� ������ �����
	//TODO LATER: �������� ������ ��������� ��� ������ �����, ����������� �� ������ ��������
	//TODO LATER: �������� ��� �������� � ������������, ��� ������� ���, ����� ���������� ���� ��������������
	// � ��� ����� ���� ������������ �� ������ ������� ���, ����� �� ����������� �� �� ������
	//TODO LATER: �������� TODO, ���������� "+-"
	//TODO LATER: ���������� �������� ��������	
}

layerUI::~layerUI()
{
	delete testbutton;
	delete testbuttonm;
	delete testbuttonc;

	delete testbutton2;
	delete testbutton2m;
	delete testbutton2c;

	delete testcombo;
	delete testcombom;
	delete testcomboc;

	delete testedit;
	delete testeditm;
	delete testeditc;

	delete radio0;
	delete radio0m;
	delete radio0c;

	delete radio1;
	delete radio1m;
	delete radio1c;

	delete radio2;
	delete radio2m;
	delete radio2c;

	delete list;
	delete listm;
	delete listc;
}

void layerUI::update(int wmid)
{
	switch (wmid)
	{
	case TESTBUTTON:
		testbuttonc->startTest();
		break;
	case TESTBUTTON2:
		testbutton2c->startTest();
		break;
	case TESTCOMBO:
		testcomboc->startTest();
		break;
	//case TESTEDIT:
	//	testeditc->startTest();
	//	break;
	case TESTRADIO0:
		radio0c->startTest();
		break;
	case TESTRADIO1:
		radio1c->startTest();
		break;
	case TESTRADIO2:
		radio2c->startTest();
		break;
	case TESTLIST:
		listc->startTest();
		break;
	default:
		break;
	}
}
