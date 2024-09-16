#pragma once
#include <conio.h>
#include <iostream>
#include <Windows.h>

#define KEY_UP    72
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_DOWN  80

#define defaultColor 7,0

enum Arrow {
	ARROW_NONE,
	ARROW_UP,
	ARROW_DOWN,
	ARROW_LEFT,
	ARROW_RIGHT
};

 struct KeyPress {
	 Arrow arrow = ARROW_NONE;
	 char caracter = ' ';
};

 struct cords {
   int x = 0;
   int y = 0;
 };

 KeyPress waitKeyPress() {
   using namespace std;
   int c, ex;

   c = _getch();

   if (c && c != 224) {
     return { ARROW_NONE, (char)c };
   }
   else {
     switch (ex = _getch()) {
     case KEY_UP     /* H */:
       return { ARROW_UP, ' ' };
     case KEY_DOWN   /* K */:
       return { ARROW_DOWN, ' ' };
     case KEY_LEFT   /* M */:
       return { ARROW_LEFT, ' ' };
     case KEY_RIGHT: /* P */
       return { ARROW_RIGHT, ' ' };
     default:
       return { ARROW_NONE, ' ' };
     }
   }
 }

 void CursorGoTo(int x, int y) {
   COORD pos = { x, y };
   HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorPosition(output, pos);
 }

 void setTextColor(int textColor, int backroundColor) {
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor + (backroundColor * 16));
   return;
 }

 cords getTerminalSize() {
   int width, height;
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   width = (int)(csbi.srWindow.Right - csbi.srWindow.Left + 1);
   height = (int)(csbi.srWindow.Bottom - csbi.srWindow.Top + 1);

   return { width, height };
 }

 void disableScrolling() {
   ShowScrollBar(GetConsoleWindow(), SB_VERT, 0);
   SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), { (short)getTerminalSize().x, (short)getTerminalSize().y });
 }

 void clearConsole(char fill = ' ') {
   COORD tl = { 0,0 };
   CONSOLE_SCREEN_BUFFER_INFO s;
   HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
   GetConsoleScreenBufferInfo(console, &s);
   DWORD written, cells = s.dwSize.X * s.dwSize.Y;
   FillConsoleOutputCharacter(console, fill, cells, tl, &written);
   FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
   SetConsoleCursorPosition(console, tl);
 }

 bool consoleResized() {
   PINPUT_RECORD lpBuffer = new INPUT_RECORD;
   LPDWORD numReadInputs = new DWORD;
   PeekConsoleInputW(GetStdHandle(STD_INPUT_HANDLE), lpBuffer, 1, numReadInputs); 
   if (numReadInputs == 0) return false;
   if (lpBuffer->EventType == WINDOW_BUFFER_SIZE_EVENT) { 
     ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), lpBuffer, 1, numReadInputs);
     delete lpBuffer;
     delete numReadInputs;
     return true; 
   }
   
   if (lpBuffer->EventType == MENU_EVENT || lpBuffer->EventType == MOUSE_EVENT || lpBuffer->EventType == FOCUS_EVENT) { 
     ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), lpBuffer, 1, numReadInputs); 
   }

   if (lpBuffer->EventType == KEY_EVENT && !_kbhit()) {
     // weard caracter (clear buffer)
     ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), lpBuffer, 1, numReadInputs);
   }

   delete lpBuffer;
   delete numReadInputs;
   return false; 
 }

 int getch_noblock() {
   if (_kbhit())
     return _getch();
   else
     return -1;
 }