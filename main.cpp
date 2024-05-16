#include <iostream>
#include "argparser.h"

int main(int argc, char **argv) {
	alignas(8) char membuf[4] = { };
	for (int arg_index = 0; arg_index < argc; arg_index++) {
		Argument arg = Argument(argv[arg_index]);
		std::cout << "Argument " << int(arg_index) << std::endl;
		int arglen = arg.length();
		std::cout << "    ";
		std::cout << "Length: " << int(arglen) << std::endl;
		int arg_name_len = arg.name_length();
		std::cout << "    ";
		std::cout << "Name length: " << int(arg_name_len) << std::endl;
		int arg_val_len = arg.value_length();
		std::cout << "    ";
		std::cout << "Value length: " << int(arg_val_len) << std::endl;
		if (arg.name_write(membuf, sizeof(membuf)) > 0) {
			std::cout << "    ";
			std::cout << "Name: " << membuf << std::endl;
		}
		if (arg.value_write(membuf, sizeof(membuf)) > 0) {
			std::cout << "    ";
			std::cout << "Value: " << membuf << std::endl;
		}
		std::cout << std::endl << std::endl;
	}
	return 0;
}
