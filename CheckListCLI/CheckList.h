#pragma once
/*
* Has all functions for a checklist
*/

#include <iostream>
#include <string>
#include <vector>

struct CheckListElement {
	std::string Description = "";
	bool isDone = false;
};

std::vector<CheckListElement> CheckListVector;

namespace CheckListNamespace {
	std::string returnCheckBox(bool isChecked) {
		if (isChecked) return "[X]";
		return "[ ]";
	}
}

void checklistSave() {
	std::cout << "unimplemented\n";
	return;
}

void checklistLoad() {
	std::cout << "unimplemented\n";
	return;
}

void ckeckListAdd() {
	using namespace std;
	string inputbuffer = "";
	cout << "Type new Point\n";
	cin >> inputbuffer;

	CheckListVector.push_back({ inputbuffer, false });
	cout << "Element sucsessfully added. Element No. " << CheckListVector.size() << "\n";
	return;
}

void checkListPrint() {
	using namespace std;
	cout << "CheckList: \n";
	if (CheckListVector.size() == 0) {
		cout << "No elements\n";
		return;
	}

	for (size_t i = 0; i < CheckListVector.size(); i++) {
		cout << i << ". " << CheckListNamespace::returnCheckBox(CheckListVector.at(i).isDone);
		cout << "    " << CheckListVector.at(i).Description << "\n";
	}
	return;
}

void checkListRemove() {
	using namespace std;
	int inputbuffer = 0;

	if (CheckListVector.size() == 0) {
		cout << "No element to remove\n";
		return;
	}

	cout << "Enter Point Number to remove: \n";
	try {
		cin >> inputbuffer;
	} catch (const std::exception&) {
		cout << "ERROR: input isn't a Number\n";
		return;
	}

	if (inputbuffer < 0 || inputbuffer > CheckListVector.size()) {
		cout << "ERROR: number out of bounds\n";
		return;
	}

	CheckListVector.erase(CheckListVector.begin() + inputbuffer);
	cout << "Errased Element No. " << inputbuffer << "\n";
	return;
}

void checkListToggle() {
	using namespace std;
	int Numinputbuffer = 0;

	if (CheckListVector.size() == 0) {
		cout << "No element to Toggle\n";
		return;
	}

	cout << "Enter Point Number to Toggle: \n";
	try {
		cin >> Numinputbuffer;
	}
	catch (const std::exception&) {
		cout << "ERROR: input isn't a Number\n";
		return;
	}

	if (Numinputbuffer < 0 || Numinputbuffer > CheckListVector.size()) {
		cout << "ERROR: number out of bounds\n";
		return;
	}

	CheckListVector.at(Numinputbuffer).isDone = !CheckListVector.at(Numinputbuffer).isDone;
	
	cout << "Toggled point No. " << Numinputbuffer << " to " << (CheckListVector.at(Numinputbuffer).isDone ? "true" : "false") << "\n";
	return;
}

void checkListEdit() {
	using namespace std;
	int inputbuffer = 0;

	if (CheckListVector.size() == 0) {
		cout << "No element to edit\n";
		return;
	}

	string inputTextBuffer = "";
	cout << "Enter point number: \n";
	try {
		cin >> inputbuffer;
	}
	catch (const std::exception&) {
		cout << "ERROR: input isn't a Number\n";
		return;
	}

	if (inputbuffer < 0 || inputbuffer > CheckListVector.size()) {
		cout << "ERROR: number out of bounds\n";
		return;
	}

	cout << "Old Point: " << CheckListVector.at(inputbuffer).Description << "\n";
	cout << "Enter New Point: \n";
	cin >> inputTextBuffer;
	CheckListVector.at(inputbuffer).Description = inputTextBuffer;
	cout << "Changed point succsessfully\n";
	return;
}