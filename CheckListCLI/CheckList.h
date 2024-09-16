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

class CheckList {
public:
	void checklistSave() {
		std::cout << "unimplemented\n";
		return;
	}

	void checklistLoad() {
		std::cout << "unimplemented\n";
		return;
	}

	bool ckeckListAdd(std::string newElementName) {
		using namespace std;

		if (newElementName == "") return false;

		CheckListVector.push_back({ newElementName, false });
		return true;
	}

	CheckListElement checkListGet(int PointIndex) {
		using namespace std;
		if (CheckListVector.size() == 0) {
			return {"", false};
		}

		return CheckListVector.at(PointIndex);
	}

	bool checkListRemove(int PointIndex) {
		using namespace std;

		if (CheckListVector.size() == 0) {
			return false;
		}

		if (PointIndex < 0 || PointIndex > CheckListVector.size()) {
			return false;
		}

		CheckListVector.erase(CheckListVector.begin() + PointIndex);
		return true;
	}

	bool checkListToggle(int Pointindex, bool Done) {
		using namespace std;

		if (CheckListVector.size() == 0) {
			return false;
		}

		if (Pointindex < 0 || Pointindex > CheckListVector.size()) {
			return false;
		}

		CheckListVector.at(Pointindex).isDone = Done;
		
		return true;
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

private:
	std::vector<CheckListElement> CheckListVector;
	std::string returnCheckBox(bool isChecked) {
		if (isChecked) return "[X]";
		return "[ ]";
	}
};