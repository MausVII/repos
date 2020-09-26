#include "InputManager.h"

bool question(std::string question)
{
	std::string buffer = "";
	std::cout << "\n" << question << "	";
	while (buffer == "") {
		std::cin >> buffer;
		std::transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);
		if (buffer != "yes" && buffer != "no") {
			std::cout << "\nPlease answer with either yes or no.\n";
			buffer = "";
		}
	}

	if (buffer == "yes") {
		return true;
	}
	else {
		return false;
	}
}

