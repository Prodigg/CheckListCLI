/*#include <iostream>
#include "CheckList.h"


int main() {
	using namespace std;

	
}*/

#include <conio.h>
#include <iostream>
#include "TUI.h"
using namespace std;

#define KEY_UP    72
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_DOWN  80

int main() {
  int c, ex;
  MenuList menuList;
  MenuPointList list = { "Test1", "Test2", "Test3 12345678901234567890", "Test4", "Test5", "Test6" };
  KeyPress keypressed;
  setTextColor(defaultColor);
  menuList.addPoint(&list);
  disableScrolling();

  while (true) {

    while (!_kbhit()) { 
      // wait for input from user
      if (consoleResized()) {
        disableScrolling();
        clearConsole();
        DrawHolePage();
        TUI::drawList(3, 1, &menuList, 3, 20);
      }
    }
    keypressed = waitKeyPress();
    if (keypressed.arrow != ARROW_NONE) {
      switch (keypressed.arrow) {
      case ARROW_DOWN:
        menuList.setCurserPos(menuList.getCurserPos() + 1);
        break;
      case ARROW_LEFT:
        break;
      case ARROW_RIGHT:
        break;
      case ARROW_UP: 
        menuList.setCurserPos(menuList.getCurserPos() - 1);
        break;
      default:
        break;
      }
    }
    else {
      // normal key handler

    }
    

    TUI::drawList(3, 1, &menuList, 3, 25);
  }

  return 0;
}