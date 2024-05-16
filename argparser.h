#ifndef ARGPARSER_H_
#define ARGPARSER_H_

class Argument {
	const char *argument_str;
public:
	Argument(const char *argstr) {
		argument_str = argstr;
	}
	int length() {
		int retval = 0;
		if (argument_str == 0)
			goto end;
		while (argument_str[retval] != 0x00)
			retval++;
		end: return retval;
	}
	int name_length() {
		int retval = 0;
		int iterator = 0;
		int arglen = length();
		if (arglen == 0)
			goto end;
		while (iterator < arglen) {
			if (argument_str[iterator] == '=')
				break;
			retval++;
			iterator++;
		}
		end: return retval;
	}
	int value_length() {
		int retval = length() - name_length() - 1;
		return retval;
	}
	int name_write(char *outputmem, int outputmem_len) {
		int namelen = name_length();
		int outputlen = namelen + 1;
		if (outputlen < 2) {
			outputlen = 0;
			goto end;
		}
		if (outputmem_len < outputlen)
			outputlen = outputmem_len;
		for (int i = 0; i < (outputlen - 1); i++) {
			outputmem[i] = argument_str[i];
		}
		outputmem[outputlen - 1] = 0x00;
		end: return outputlen;
	}
	int value_write(char *outputmem, int outputmem_len) {
		int namelen = name_length();
		int vallen = value_length();
		int outputlen = vallen + 1;
		if (outputlen < 2) {
			outputlen = 0;
			goto end;
		}
		if (outputmem_len < outputlen)
			outputlen = outputmem_len;
		for (int i = 0; i < (outputlen - 1); i++) {
			outputmem[i] = argument_str[namelen + 1 + i];
		}
		outputmem[outputlen - 1] = 0x00;
		end: return outputlen;
	}

};

#endif /* ARGPARSER_H_ */
