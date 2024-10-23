#pragma once

#define ID_BUTTON_FILE 1001  // Button ID for "File" button
#define ID_BUTTON_SAVE 1002  // Button ID for "Save" button

#include <Windows.h>
#include "FileState.h"

class FileState;

class WindowState
{
public:
	WindowState(HINSTANCE hInstance, int nCmdShow);
	~WindowState();

	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	int RunMsgLoop();
	
	int PARENT_WINDOW_HEIGHT = 400;
	int PARENT_WINDOW_WIDTH = 650;
	int nWidth;
	int nHeight;

	HWND get_handle();

	FileState file_state;

private:

	HINSTANCE hInstance;	// A handle to an instance.This is the base address of the module in memory.
	int nCmdShow;
	HWND hwnd;				// A handle to a window.



	bool RegisterWindowClass();
	bool CreateMainWindow();
};