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


	void set_console_font(LPCWSTR fontName, int sizeY, int sizeX) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_FONT_INFOEX fontInfo;
		fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
		fontInfo.nFont = 0;
		fontInfo.dwFontSize.X = sizeX;  // Width of the font; 0 means the default size
		fontInfo.dwFontSize.Y = sizeY; // Height of the font
		fontInfo.FontFamily = FF_DONTCARE;
		fontInfo.FontWeight = FW_NORMAL;
		wcscpy_s(fontInfo.FaceName, fontName); // Font name

		(void)SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
	}

	void set_console_font(LPCWSTR fontName, int sizeY) {
		set_console_font(fontName, sizeY, 0);
	}

	void set_console_font(LPCWSTR fontName) {
		set_console_font(fontName, 20);
	}
}
