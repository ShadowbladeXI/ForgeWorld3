#pragma once

#include <Windows.h>

class Window {

public:
	Window(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow);

	void WINAPI createWindow(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow);
};