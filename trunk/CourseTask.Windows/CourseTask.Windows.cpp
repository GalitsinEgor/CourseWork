// CourseTask.Windows.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "CourseTask.Windows.h"

#define MAX_LOADSTRING 100

// Global Variables:
const LPCWSTR szTitle = L"Title";                 // The title bar text
const LPCWSTR szWindowClass = L"mainWindowClass";         // the main window class name
const int mwWidth = 800;
const int mwHeight = 600;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
HWND CreateTextArea(HWND, int);
HWND CreateButton(HWND, LPCWSTR);
HWND CreateResultLabel(HWND);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // Initialize global strings
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_COURSETASKWINDOWS));

    MSG msg;

    // Main message loop:
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
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASS wcex = { 0 };
    wcex.lpfnWndProc = WndProc;
    wcex.hInstance = hInstance;
    wcex.lpszClassName = szWindowClass;
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)COLOR_APPWORKSPACE;
    return RegisterClass(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPED | WS_VISIBLE | WS_SYSMENU,
      10, 10, mwWidth, mwHeight, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
HWND resultLabelHandler;
int counter = 0;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    
    

    switch (message)
    {
    case WM_CREATE:
        CreateTextArea(hWnd, 0);
        CreateTextArea(hWnd, 1);
        CreateButton(hWnd, L"Рассчитать");
        resultLabelHandler = CreateResultLabel(hWnd);
        break;
    case WM_COMMAND:
        if (LOWORD(wParam) == 10000)
        {
            std::wstring df = std::wstring(L"Result: ") + std::to_wstring(counter);
            LPCWSTR msg = df.c_str(); 

            SetWindowText(resultLabelHandler, msg);
            counter++;
            //MessageBox(hWnd, TEXT("Button Pressed"), TEXT(""), 0);
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

HWND CreateTextArea(HWND parent, int index) {
    int x = 10;
    int y = 10;
    int width = 200;
    int height = 150;

    x = x + (width * index) + (x * index);

    HWND textBox = CreateWindow(L"EDIT", 
        NULL, WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL, 
        x, y, width, height,
        parent, nullptr, nullptr, nullptr);

    return textBox;
         
}

HWND CreateButton(HWND parent, LPCWSTR text) {
    HWND hwndButton = CreateWindow(
        L"BUTTON",  // Predefined class; Unicode assumed 
        text,      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
        10,         // x position 
        200,         // y position 
        100,        // Button width
        50,        // Button height
        parent,     // Parent window
        (HMENU)10000,       
        (HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE),
        NULL);      // Pointer not needed.

    return hwndButton;
}

HWND CreateResultLabel(HWND parent) {
    HWND hLabel = CreateWindow(L"static", L"ST_U",
        WS_CHILD | WS_VISIBLE | WS_TABSTOP,
        430, 10, 200, 50,
        parent, NULL,
        (HINSTANCE)GetWindowLong(parent, GWL_HINSTANCE), NULL);

    return hLabel;
}