// WindowsProject3.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "WindowsProject3.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK MyDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
HWND hD;
HWND hWnd;
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
    LoadStringW(hInstance, IDC_WINDOWSPROJECT3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);
    

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT3));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            if (!IsDialogMessage(hD, &msg))
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT3);
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

    hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
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

HWND hWin1,hWin2 , hWin3 ,hWin4, hButton ;
HBRUSH hBrush;
//HWND hWnd;
HDC hdc;
HDC hdcm;

TCHAR buffer[100];

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
       
        hWin1 = CreateWindow(_T("static"), nullptr, WS_CHILD | WS_VISIBLE, 30, 10, 300, 30, hWnd, (HMENU)1, hInst, nullptr);
        SetDlgItemText(hWnd, 1, _T("input data")); 
        hWin2 = CreateWindow(_T("edit"), nullptr, WS_CHILD | WS_VISIBLE | ES_LEFT | WS_BORDER, 30, 40, 300, 30, hWnd, (HMENU)2, hInst, nullptr);
       hButton = CreateWindow(_T("button"), _T("calculate"), WS_CHILD | WS_VISIBLE | WS_BORDER, 175, 180, 120, 30, hWnd, (HMENU)5, hInst, nullptr);
       hWin3 = CreateWindow(_T("static"), nullptr, WS_CHILD | WS_VISIBLE, 30, 70, 300, 30, hWnd, (HMENU)3, hInst, nullptr);
       SetDlgItemText(hWnd, 3, _T("output data"));
       hWin4 = CreateWindow(_T("edit"), nullptr, WS_CHILD | WS_VISIBLE | ES_LEFT | WS_BORDER, 30, 100, 300, 30, hWnd, (HMENU)4, hInst, nullptr);
      SetDlgItemText(hWnd,1,_T("input data"));
       //SendMessage(hWin,WM_SETTEXT,0,(LPARAM)_T("trend is high"));
       

        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            if (lParam == (LPARAM)hButton)
            {
               
                int d;
                GetDlgItemText(hWnd, 2, buffer, 100);
                d = _tstoi(buffer);
                d *= d;
                _itow_s(d,buffer, 10);
                SetDlgItemText(hWnd,4, buffer);
            }
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_RED:
               hD = CreateDialog(hInst, MAKEINTRESOURCE(IDD_Dialog), hWnd, MyDialog);
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

INT_PTR CALLBACK MyDialog(HWND hD, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hD, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == 7)
        {
            
            HBRUSH hBrush;
            int buffer;
            buffer = GetDlgItemInt(hD, 4, NULL, 1);
            buffer *= buffer;
            SetDlgItemInt(hD, 6,buffer, FALSE );
            DeleteObject((HBRUSH)GetClassLong(hWnd, GCLP_HBRBACKGROUND));
            hBrush = CreateSolidBrush(RGB(0, 100, 255 ));
            SetClassLong(hWnd, GCLP_HBRBACKGROUND, (LONG)hBrush);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        
        break;

    }
    return (INT_PTR)FALSE;
}

