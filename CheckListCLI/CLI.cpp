#include "CLI.h"

bool CLI::ExecuteOption(std::string str) {
	// check for options 
	for (size_t i = 0; i < Options->size(); i++) {
		if (isStrEqual(Options->at(i).OptionID, str)) {
			// call function
			Options->at(i).function();
			return true;
		}
	}

	return false;
}

bool CLI::isStrEqual(std::string str1, std::string str2) {
	if (str1.length() != str2.length()) return false;

	for (size_t i = 0; i < str1.length(); i++) {
		if (str1.at(i) != str2.at(i)) return false;
	}

	return true;
}

void CLI::printOptions(std::ostream* stream) {
	for (size_t i = 0; i < Options->size(); i++) {
		*stream << Options->at(i).OptionID << ": " << Options->at(i).OptionDescription << "\n";
	}
}

CLI::CLI(CLIOptions* Options) : Options(Options) {

}