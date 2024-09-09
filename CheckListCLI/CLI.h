#pragma once
/*
	This file is responsable for the CLI
*/

#include <string>
#include <vector>
#include <iostream>

struct CLIOption {
	void(*function)();
	std::string OptionID = "";
	std::string OptionDescription = "";
};

typedef std::vector<CLIOption> CLIOptions;

class CLI {
public:
	CLI(CLIOptions* Options);
	void printOptions(std::ostream* stream);
	bool ExecuteOption(std::string str);

protected:
	bool isStrEqual(std::string str1, std::string str2);

private:
	CLIOptions* Options;
};
