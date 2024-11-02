﻿// OpenFIGI.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <Windows.h>
#include "Request.h"
#include "states/WindowState.h"
#include "states/FileState.h"
#include "utilities/jsonparse.h"


int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow)
{
    
    FileState fileState;
    Request request(fileState);
    JsonParse jsonParse;
    HWND hwnd = NULL;

    if (AllocConsole()) {
        FILE* file;
        freopen_s(&file, "CONOUT$", "w", stdout);
        std::cout << "Console logging initialized.\n";
    }

    WindowState win(hwnd, fileState, request, jsonParse);
    if (!win.CreateParentWindow())
    {
        return 0;
    }

    ShowWindow(win.Window(), nCmdShow);

    MSG msg = { };
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Create an instance of the window class. This handles all the setup and window creation.
    //WindowState window_state(hInstance, nCmdShow, fileState, request, jsonParse);
    //return window_state.RunMsgLoop();   // Run the message loop and return the application's exit code.
    
    FreeConsole();
    return 0;
}
//
//int main()
//{
//
//	// AAPL US0378331005
//	//std::vector<std::string> vec = { "BBG000H4FSM0" }; // SPX
//	std::vector<std::string> vec = { "US0378331005", "BBG000BDR7W8", "BBG000H4FSM0"}; // SPX
//	//std::vector<std::string> vec = {"US0378331005", "AAPL", "BBG000B9XRY4", "037833100", "0540528"};
//
//	//Request request(vec);
//
//	// auto ids = Request::GetIdentifiers(&vec);
//
//	//request.GetIdentifierType();
//	//request.GetIdentifiers();
//
//
//	//AppWindow appWindow;
//	//wWinMain();
//
//	//appWindow.wWinMain(hInstance, hPrevInstance, pCmdLine, nCmdShow);
//
//	int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);
//
//
//	return 0;
//}
