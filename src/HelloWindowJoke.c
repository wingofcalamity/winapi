#include <windows.h>
#include <wchar.h>

#include <stdlib.h>

// pragma to save effort on the linker
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "gdi32.lib")

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int GLOBAL_COUNTER = 0;

int getRandom(int max) {
  return rand() % (max + 1);
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR szCmdLine, int iCmdShow) {
  wchar_t szAppName[36];
  GetPrivateProfileString(L"WINDOW", L"NAME", L"WINNAME", szAppName, sizeof(szAppName) / sizeof(wchar_t), L".\\config.ini");
  int W_WIDTH = GetPrivateProfileInt(L"WINDOW", L"WIDTH", 640, L".\\config.ini");
  int W_HEIGHT = GetPrivateProfileInt(L"WINDOW", L"HEIGHT", 480, L".\\config.ini");

  HWND hwnd;
  MSG msg;
  WNDCLASS wndclass;

  wndclass.style = CS_HREDRAW | CS_VREDRAW;
  wndclass.lpfnWndProc = WndProc;
  wndclass.cbClsExtra = 0;
  wndclass.cbWndExtra = 0;
  wndclass.hInstance = hInstance;
  wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
  wndclass.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
  wndclass.lpszMenuName = NULL;
  wndclass.lpszClassName = szAppName;

  if(!RegisterClass(&wndclass)) {
    MessageBox(NULL, TEXT("Error creating Window"), szAppName, MB_ICONERROR | MB_OK);
    return 1;
  }

  hwnd = CreateWindow(
    szAppName,
    szAppName,
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    W_WIDTH,
    W_HEIGHT,
    NULL,
    NULL,
    hInstance,
    NULL
  );

  ShowWindow(hwnd, iCmdShow);
  UpdateWindow(hwnd);

  while(GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
  HDC hdc;
  PAINTSTRUCT ps;
  RECT rect;

  switch (message) {
    case WM_CREATE:
      return 0;

    case WM_PAINT:
      hdc = BeginPaint(hwnd, &ps);
      GetClientRect(hwnd, &rect);
      DrawText(hdc, TEXT("ALL THIS FOR SOME TEXT"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
      EndPaint(hwnd, &ps);
      break;

    case WM_CLOSE:
      // int choice = MessageBox(hwnd,L"Do you want to close?", L"Close?", MB_ICONWARNING | MB_OKCANCEL);

      // enshittification
      int choice = 0;
      RECT window;
      GetClientRect(hwnd, &window);
      MessageBeep(0);
      int screenWidth = GetSystemMetrics(SM_CXSCREEN);
      int screenHeight = GetSystemMetrics(SM_CYSCREEN);
      int width = window.right - window.left;
      int height = window.bottom - window.top;
      SetWindowPos(hwnd, HWND_TOPMOST, getRandom(screenWidth-width), getRandom(screenHeight-height), 0, 0, SWP_NOSIZE);
      GLOBAL_COUNTER++;
      // endshittification

      if(choice == IDOK | GLOBAL_COUNTER == 10) {
        PostQuitMessage(0);
      }
      
      return 0;
    case WM_DESTROY:
      PostQuitMessage(0);
      return 0;
  }
  return DefWindowProc(hwnd, message, wParam, lParam);
}
