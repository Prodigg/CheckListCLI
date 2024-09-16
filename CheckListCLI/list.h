#pragma once
#include <string>
#include <vector>
/* 
* This file is for the list class used to display menu points
*/

typedef std::vector<std::string> MenuPointList;

struct SerialisedList {
	MenuPointList list = {};
	uint32_t curserPos = 0;
};


class MenuList {
public:
	/// <summary>
	/// appends point at the end
	/// </summary>
	/// <param name="Point"></param>
	/// <returns></returns>
	MenuList* addPoint(std::string* Point);

	/// <summary>
	/// appends multible points at the end
	/// </summary>
	/// <param name="PointList"></param>
	/// <returns></returns>
	MenuList* addPoint(MenuPointList* PointList);

	/// <summary>
	/// adds point at position and pushes points after that back
	/// </summary>
	/// <param name="Point"></param>
	/// <param name="position"></param>
	/// <returns></returns>
	MenuList* addPoint(std::string* Point, uint32_t position);

	/// <summary>
	/// adds points starting at position and pushes points after that back
	/// </summary>
	/// <param name="PointList"></param>
	/// <param name="position"></param>
	/// <returns></returns>
	MenuList* addPoint(MenuPointList* PointList, uint32_t position);

	/// <summary>
	/// sets position of curser
	/// </summary>
	/// <param name="pos"></param>
	/// <returns></returns>
	bool setCurserPos(uint32_t pos);

	/// <summary>
	/// gets position of cursor
	/// </summary>
	/// <returns></returns>
	uint32_t getCurserPos();

	/// <summary>
	/// serialises list in respect of num of elements and string length
	/// </summary>
	/// <param name="numOfElements"></param>
	/// <param name="lengthStr"></param>
	/// <param name="xOffset"></param>
	/// <returns></returns>
	SerialisedList serialiseList(uint32_t numOfElements, size_t lengthStr, size_t xOffset = 0);

	/// <summary>
	/// edits a menu Point
	/// </summary>
	/// <param name="pos"></param>
	/// <param name="newStr"></param>
	/// <returns></returns>
	bool editPoint(uint32_t pos, std::string newStr);

	/// <summary>
	/// removes a menu point
	/// </summary>
	/// <param name="pos"></param>
	/// <returns></returns>
	bool removePoint(uint32_t pos);

private:
	MenuPointList _PointList = {};
	uint32_t _CursorPosition = 0;
};

