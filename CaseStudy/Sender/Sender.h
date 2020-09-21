#include<iostream>
#include<vector>
#include<string.h>
#include<fstream>
#include <sstream>

using namespace std;

//Returns true if entry is a number else false
bool checkEachEntry(string s)
{
	for (unsigned int i = 0; i < s.length(); i++)
	{
		if (isdigit(s[i]) == false)
			return false;
	}	
	return true;
}
// checks if file can be opened or not
bool is_file_open(string FileName)
{
	ifstream f(FileName.c_str());
	return f.good();
}
//Reads input file and converts it into vector structure
vector <vector<string>> ReadInputFile(string FileName)
{
	ifstream csvFile;
	csvFile.open(FileName);
		string line;
		getline(csvFile, line); // skip the 1st line
	
		vector <vector<string>> record;
		while (getline(csvFile, line))
		{
			if (line.empty()) // skip empty lines:
			{
				cout << "empty line!" << endl;
				continue;
			}
			istringstream iss(line);
			string lineStream;
			vector <string> row;
			while (getline(iss, lineStream, ','))
			{
				row.push_back(lineStream);
			}
			record.push_back(row);
		}
		
		csvFile.close();
	
		return record;
}
// checks converted vector data is valid or not
string checkInputData(vector <vector<string>> rec)
{
	bool flag = true;
	for (std::vector<string> vec : rec)
	{
		for (string rowdata : vec)
		{
			if (!checkEachEntry(rowdata))
			{
				flag = false;
				return "File has Invalid Data";
			}	
		}
	}
	if (flag == true)
	{
		return "File has valid data";
	}
	return " ";
}
//prints footfall data on console
void printFootFallData(vector <vector<string>> record)
{
	cout << "id,Hrs,min,sec,day,date,month,year,Count\n";
	cout << "id,Hrs,min,sec,day,date,month,year,Count\n";
	for (std::vector<string> vec : record)
	{
		for (string rowdata : vec)
		{
			cout << rowdata << ",";
		}
		cout << endl;
	}
}
// Reads Input file and prints results on console accordingly 
string ReadInputFileAndPrint(string FileName)
{
	if (is_file_open(FileName))
	{
		vector <vector<string>> record = ReadInputFile(FileName);
		string res = checkInputData(record);
		if (res == "File has valid data")
		{
			printFootFallData(record);
			return "File read and printed on console successfully";
		}
		else
			return "File has some invalid Data";
	}
	else
		return "File does not exist";	
	return " ";
}
