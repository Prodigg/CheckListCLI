#include <iostream>
#include "CLI.h"
#include "CheckList.h"


CLIOptions CMDoptions = {
	// func ptr				| ID | Description
	{ checkListPrint,		"0", "Print CheckList" },
	{ checkListToggle,	"1", "Toggle Point"		 },
	{ ckeckListAdd,			"2", "Add Point"			 },
	{ checkListRemove,	"3", "Remove Point"    },
	{ checkListEdit,		"4", "Edit Point"			 }
};

int main() {
	using namespace std;

	CLI CLITerminal(&CMDoptions);
	std::string inputBuffer = "";

	cout << "Welcome to CheckListCLI\n";
	while (true) {
		cout << "\n\n";
		CLITerminal.printOptions(&cout);
		cout << "Enter Command: ";
		cin >> inputBuffer;
		system("cls");
		if (!CLITerminal.ExecuteOption(inputBuffer)) {
			cout << "ERROR: no known command.\n";
		}
	}
}