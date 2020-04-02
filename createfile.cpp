#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
	/* Check number of arguments */
	if(argc < 3)
	{
		cout << "Error: At least 2 arguments are required." << endl;
		exit(0);
	}
	else if(argc > 4)
	{
		cout << "Error: Too many arguments." << endl;
		exit(0);
	}
	
	/* Get values of arguments */
	char file[100], size_arg[5], numsys[10];
	strcpy(file, argv[1]);
	strcpy(size_arg, argv[2]);
	if(argc == 4)
	{
		strcpy(numsys, argv[3]);
	}
	
	/* Separate size unit and numeric value */
	char size[4], unit;
	for(int i=0;size_arg[i] != '\0';i++)
	{
		if(isdigit(size_arg[i]))
		{
			size[i] = size_arg[i];
		}
		else
		{
			unit = size_arg[i];
		}
	}

	/* Get multiplier based on number system */
	int multiplier = 1;
	if(strcmp(numsys, "binary") == 0 || argc == 3) // argc == 3 => default number system (binary)
	{
		switch(unit)
		{
			case 'B': multiplier = 1; break;
			case 'K': multiplier = 1024; break;
			case 'M': multiplier = 1048576; break;
			case 'G': multiplier = 1073741824; break;
			default: cout << "Invalid size unit." << endl; exit(0);
		}
	}
	else if(strcmp(numsys, "decimal") == 0)
	{
		switch(unit)
		{
			case 'B': multiplier = 1; break;
			case 'K': multiplier = 1000; break;
			case 'M': multiplier = 1000000; break;
			case 'G': multiplier = 1000000000; break;
			default: cout << "Invalid size unit." << endl; exit(0);
		}
	}
	else
	{
		cout << "Invalid number system." << endl;
		exit(0);
	}
	
	/* Create the file */
	long long int bytes = (long long int)(atoi(size)) * (long long int)multiplier;
	fstream f1(file, ios::out);
	for(long long int i=0;i<bytes;i++)
	{
		f1 << "*";
	}
	f1.close();
	cout << "File created." << endl;
	return 0;
}