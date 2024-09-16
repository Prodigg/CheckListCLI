#pragma once
#include "TerminalInterface.h"
#include "CheckList.h"
#include "list.h"
/*
* This File handels the Text User Interface
*/

namespace TUI_CONFIG {
	std::string TUI_Title = "TestTitle";
}

namespace TUI {
	void DrawTitle(std::string title) {
		int with = getTerminalSize().x;
		int topCord = getTerminalSize().y;
		CursorGoTo(0, 0);
		int TitleStartPos = (with / 2) - (title.length() / 2);

		setTextColor(0, 7); // white backround text black

		for (size_t i = 0; i < with; i++) {
			if (i >= TitleStartPos && i < TitleStartPos + title.length()) {
				std::cout << title.at(i - TitleStartPos);
			}
			else std::cout << " ";
		}

		setTextColor(defaultColor);	// reset

	}

	void drawList(size_t xPos, size_t yPos, MenuList* list, uint32_t numOfElements, size_t strLength) {
		SerialisedList PointList = list->serialiseList(numOfElements, strLength);
		for (size_t i = 0; i < PointList.list.size(); i++) {
			CursorGoTo(xPos, yPos + i);
			if (i == PointList.curserPos) setTextColor(0, 7);
			else setTextColor(defaultColor);

			std::cout << PointList.list.at(i);
		}
		return;
	}

	void editPoint(size_t xPos, size_t yPos, MenuList* list, uint32_t numOfElements, size_t strLength) {
		// adds a menu at the bottom
		int with = getTerminalSize().x;
		int bottomCord = getTerminalSize().y;
		CursorGoTo(0, bottomCord);
	}

}




void DrawHolePage() {
	TUI::DrawTitle("TestTitle");
}

void DisplayList() {
	
}