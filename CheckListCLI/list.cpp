#include "list.h"
/*
* implementation of list.h
*/

MenuList* MenuList::addPoint(std::string* Point) {
	return addPoint({ Point });
}

MenuList* MenuList::addPoint(MenuPointList* PointList) {
	return addPoint(PointList, (uint32_t)_PointList.size());
}

MenuList* MenuList::addPoint(std::string* Point, uint32_t position) {
	return addPoint({ Point }, position);
}

MenuList* MenuList::addPoint(MenuPointList* PointList, uint32_t position) {
	if (position >= _CursorPosition) {
		_CursorPosition += _PointList.size() - position;
	}

	for (size_t i = 0; i < PointList->size(); i++) {
		_PointList.insert(_PointList.begin() + position + i, PointList->at(i));
	}
	return this;
}

bool MenuList::setCurserPos(uint32_t pos) {
	// check bounds 
	if (pos > _PointList.size() - 1) return false;
	_CursorPosition = pos;
	return true;
}

uint32_t MenuList::getCurserPos() {
	return _CursorPosition;
}

SerialisedList MenuList::serialiseList(uint32_t numOfElements, size_t lengthStr, size_t xOffset) {
	std::string str = "";
	uint32_t startPos = 0;
	MenuPointList list = {};
	if (numOfElements == 0) {
		return { {}, _CursorPosition };
	}

	if (numOfElements < _CursorPosition) {
		// calculate startPos for PointList
		startPos = _CursorPosition - numOfElements;
	}

	for (size_t i = 0; i <= numOfElements; i++) {
		if (i + startPos > _PointList.size() - 1) {
			str.insert(str.length(), lengthStr, ' ');
			list.push_back(str);
			str = "";
			continue;
		}

		str.insert(str.length(), xOffset, ' ');

		if (_PointList.at(i + startPos).length() > lengthStr) {
			str += _PointList.at(i + startPos).substr(0, lengthStr - 3);
			str += "...";
		}
		else {
			str += _PointList.at(i + startPos);
			str.insert(str.length(),lengthStr - str.length(), ' ');
		}
		list.push_back(str);
		str = "";
	}
	return { list, _CursorPosition - startPos };
}

bool MenuList::editPoint(uint32_t pos, std::string newStr) {
	if (pos > _PointList.size()) return false;
	_PointList.at(pos) = newStr;
	return true;
}

bool MenuList::removePoint(uint32_t pos) {
	if (pos > _PointList.size()) return false;

	if (_CursorPosition > pos) {
		_CursorPosition--;
	}
	_PointList.erase(_PointList.begin() + pos);
	return true;
}