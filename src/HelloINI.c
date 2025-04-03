#include <windows.h>
#include <wchar.h>

// pragma to save effort on the linker
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "gdi32.lib")

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR szCmdLine, int iCmdShow) {
  wchar_t msgBuffer[20];
  wchar_t titleBuffer[20];
  DWORD msg = GetPrivateProfileString(
    L"HELLOWORLD",
    L"msg",
    L"Hello World!",
    msgBuffer,
    sizeof(msgBuffer),
    L".\\HelloINI.ini"
  );
  DWORD title = GetPrivateProfileString(
    L"HELLOWORLD",
    L"title",
    L"Hello World!",
    titleBuffer,
    sizeof(titleBuffer),
    L".\\HelloINI.ini"
  );

  int W_WIDTH = GetPrivateProfileInt(L"WINDOW", L"WIDTH", 640, L".\\config.ini");
  int W_HEIGHT = GetPrivateProfileInt(L"WINDOW", L"HEIGHT", 480, L".\\config.ini");

  wchar_t messageB[100];
  swprintf(messageB, sizeof(messageB) / sizeof(wchar_t), L"The window is %dx%d", W_WIDTH, W_HEIGHT);

  MessageBox(NULL, msgBuffer, titleBuffer, 0x20L);
  MessageBox(NULL, messageB, titleBuffer, 0x20L);
  return 0;
}