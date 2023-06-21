#pragma once

#include <windows.h>

namespace console_helper {

	void reset_color() {
		(void)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_BLUE);
	}

	void set_color(unsigned int color) {
		(void)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}

	void set_size(int width, int height) {
		HWND consoleWindow = GetConsoleWindow();

		RECT windowRect;
		(void)GetClientRect(consoleWindow, &windowRect);

		(void)MoveWindow(consoleWindow, windowRect.left, windowRect.top, width, height, TRUE);
	}
}
