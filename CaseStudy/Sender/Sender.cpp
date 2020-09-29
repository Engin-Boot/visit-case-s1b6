#include<iostream>
#include<string>
#include"Sender.h"
using namespace std;
 
int main()
{
	string FileName = "CaseStudy/FootFallData.csv";
	string s=ReadInputFileAndPrint(FileName);
	if (s != "File read and printed on console successfully") //else prints file data
		cout << s;
  	return 0;
}
