#include "pch.h"
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const size_t MAX_SIZE = 256;
const char* separators = "*<>?|\"";

int main()
{
	char text[MAX_SIZE];
	cout << "Enter file name: ";
	fgets(text, MAX_SIZE, stdin);
	char* filename = text;
	filename[strlen(filename) - 1] = '\0';
	while (true) {
		if (strcspn(filename, separators) != strlen(filename))
		 {
			cout << "Wrong format";
			break;
		}

		if (strchr(filename, ':') != nullptr)
			
		{
			if (strcspn(filename, "\\") == 2)
			{
				if (strcspn(filename, ":") == 1)
				{
					if (isalpha(filename[0]));
					else
					{
						cout << "Wrong format";
						break;
					}
				}
				else
				{
					cout << "Wrong format";
					break;
				}
			}
			else
			{
				cout << "Wrong format";
				break;
			}
		}

		if (strrchr(filename, '.') == nullptr)
			strcat(filename, ".txt");

		else {
			char* ext = strrchr(filename, '.');
			for (int i = 1; ext[i] != '\0'; i++)
				*(ext + i) = char(tolower(*(ext + i)));
			if (strncmp(ext, ".txt", 5) != 0) 
			{
				cout << "Wrong format";
				break;
			}
		}

		FILE* file = fopen(filename, "r");
		if (file == nullptr) {
			cout << "Wrong file name";
			break;
		}
		fseek(file, 0, SEEK_END);
		long filesize = ftell(file);

		char* filedata = new char[filesize];
		rewind(file);
		fread(filedata, 1, filesize, file);
		filedata[filesize] = '\0';

		char STR[MAX_SIZE];
		cout << "Enter string: ";
		fgets(STR, MAX_SIZE, stdin);
		char* str = STR;
		*(str + strlen(str) - 1) = '\0';

		int occur = 0;
		while (*filedata != '\0') {
			if (strncmp(filedata, str, strlen(str)) != 0)
				filedata += 1;
			else {
				occur++;
				filedata += 1;
			}
		}
		cout << "Occurance number: " << occur;

		delete[] filedata;
		fclose(file);
		break;
	}
	return 0;
}