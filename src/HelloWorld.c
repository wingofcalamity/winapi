#include <windows.h>

// pragma to save effort on the linker
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "gdi32.lib")

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR szCmdLine, int iCmdShow) {
  MessageBox(NULL, TEXT("Hello World"), TEXT("MessageBox"), 0x20L);
  return 0;
}