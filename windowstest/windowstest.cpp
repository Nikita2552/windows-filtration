// windowstest.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "windowstest.h"
#include "layerUI.h"

#define MAX_LOADSTRING 100
#define ID_MYBUTTON 1    /* идентификатор для кнопочки внутри главного окна */
#define ID_MYRADIO0 2
#define ID_MYEDIT 3
#define ID_MYLISTBOX 4
#define ID_MYCOMBOBOX 5
#define ID_MYRADIO1 6
#define ID_MYRADIO2 7

layerUI* ui;

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSTEST, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSTEST));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}


//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSTEST));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSTEST);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);  

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HWND hButton, hCombo, hEdit, hRadio0, hRadio1, hRadio2, hListBox;
    int ListItem = NULL;
    wchar_t Buf[10]{};
    
    switch (message)
    {
    case WM_CREATE:
        {  
        /* при создании окна внедряем в него кнопочку */
        wchar_t button[]{ L"BUTTON"};
        wchar_t buttonName[]{ L"My button" };        
        hButton = CreateWindow(button, buttonName, WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
            5, 5, 100, 20, hWnd, (HMENU)ID_MYBUTTON, NULL, NULL);
        

        wchar_t combo[]{ L"COMBOBOX" };
        wchar_t comboName[]{ L"My combobox" };        
        hCombo = CreateWindow(combo, NULL, WS_CHILD | WS_VISIBLE,
            5, 35, 100, 20, hWnd, (HMENU)ID_MYCOMBOBOX, NULL, NULL);

        wchar_t edit[]{ L"EDIT" };
        wchar_t editName[]{ L"My edit" };        
        hEdit = CreateWindow(edit, editName, WS_CHILD | WS_VISIBLE,
            5, 65, 200, 20, hWnd, (HMENU)ID_MYEDIT, NULL, NULL);

        wchar_t radio[]{ L"BUTTON" };
        wchar_t radioName[]{ L"My radio button" };
        hRadio0 = CreateWindow(radio, radioName, WS_CHILD | BS_AUTORADIOBUTTON | WS_VISIBLE,
            5, 95, 200, 20, hWnd, (HMENU)ID_MYRADIO0, NULL, NULL);
        hRadio1 = CreateWindow(radio, radioName, WS_CHILD | BS_AUTORADIOBUTTON | WS_VISIBLE,
            5, 125, 200, 20, hWnd, (HMENU)ID_MYRADIO1, NULL, NULL);
        hRadio2 = CreateWindow(radio, radioName, WS_CHILD | BS_AUTORADIOBUTTON | WS_VISIBLE,
            5, 155, 200, 20, hWnd, (HMENU)ID_MYRADIO2, NULL, NULL);

        wchar_t listbox[]{ L"LISTBOX" };
        wchar_t listboxName[]{ L"My listbox" };
        hListBox = CreateWindow(listbox, NULL, WS_CHILD | LBS_STANDARD | WS_VISIBLE ,
            5, 185, 100, 100, hWnd, (HMENU)ID_MYLISTBOX, NULL, NULL);

        // Отменяем режим перерисовки списка
        SendMessage(hListBox, WM_SETREDRAW, FALSE, 0L);

        // Добавляем в список несколько строк

        wchar_t messg[]{ L"Зеленый" };
        SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)messg);

        wchar_t messr[]{ L"Красный" };
        SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)messr);

        wchar_t messb[]{ L"Синий" };
        SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)messb);

        // Включаем режим перерисовки списка
        SendMessage(hListBox, WM_SETREDRAW, TRUE, 0L);

        // Перерисовываем список
        InvalidateRect(hListBox, NULL, TRUE);

        ui = new layerUI(hWnd);

        }
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);

            ui->update(wmId);

            // Разобрать выбор в меню:
            switch (wmId)
            {
                case ID_MYLISTBOX:
                    {
                        if (HIWORD(wParam) == LBN_DBLCLK)
                        {
                            ListItem = (int)SendMessage(hListBox, LB_GETCURSEL, 0, 0);                   
                            

                            if (ListItem != LB_ERR)
                                SendMessage(hListBox, LB_GETTEXT, ListItem, (LPARAM)Buf);
                                                        
                            wchar_t listmess[]{ L"this is answer to a button click" };
                            //MessageBox(hWnd, (LPCTSTR)Buf, (LPCTSTR)listmess, MB_OK);
                            SetWindowText(hEdit, (LPCTSTR)Buf);
                            
                            return 0;
                        }
                    }
                    break;
                case ID_MYBUTTON:
                    {
                        //wchar_t butt[]{ L"Button" };
                        //wchar_t buttmess[]{ L"This is button" };                        
                        
                        //MessageBox(hWnd, butt, buttmess, MB_OK);
                        TCHAR buff[1024] = { 0 };
                        GetWindowText(hCombo, buff, 1024);
                        SetWindowText(hEdit, buff);

                        return 0;
                    }
                case ID_MYRADIO0:
                {
                    switch (Button_GetCheck(hRadio0))
                    {
                    case BST_CHECKED:
                        //MessageBox(NULL, L"radio0 is checked", L"radio", MB_OK);
                        SetWindowText(hEdit, L"radio0 is checked");
                        break;

                    case BST_INDETERMINATE:
                        MessageBox(NULL, L"radio0 is indeterminate", L"radio", MB_OK);                        
                        break;

                    case BST_UNCHECKED:                        
                        MessageBox(NULL, L"radio2 is unchecked", L"radio", MB_OK);                        
                        break;
                    }
                }
                break;
                case ID_MYRADIO1:
                {
                    switch (Button_GetCheck(hRadio1))
                    {
                    case BST_CHECKED:
                        //MessageBox(NULL, L"radio1 is checked", L"radio", MB_OK);
                        SetWindowText(hEdit, L"radio1 is checked");
                        break;

                    case BST_INDETERMINATE:
                        MessageBox(NULL, L"radio1 is indeterminate", L"radio", MB_OK);
                        break;

                    case BST_UNCHECKED:
                        MessageBox(NULL, L"radio1 is unchecked", L"radio", MB_OK);
                        break;
                    }
                }
                break;
                case ID_MYRADIO2:
                {
                    switch (Button_GetCheck(hRadio2))
                    {
                    case BST_CHECKED:
                        //MessageBox(NULL, L"radio2 is checked", L"radio", MB_OK);
                        SetWindowText(hEdit, L"radio2 is checked");
                        break;

                    case BST_INDETERMINATE:
                        MessageBox(NULL, L"radio2 is indeterminate", L"radio", MB_OK);
                        break;

                    case BST_UNCHECKED:
                        MessageBox(NULL, L"radio2 is unchecked", L"radio", MB_OK);
                        break;
                    }
                }
                break;
                case IDM_ABOUT:
                    DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                    break;
                case IDM_EXIT:
                    DestroyWindow(hWnd);
                    break;
                default:
                    return DefWindowProc(hWnd, message, wParam, lParam);
            }            
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
