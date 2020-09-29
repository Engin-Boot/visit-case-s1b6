#include<iostream>
#include<string>
#include"Receiver.h"
using namespace std;

int main()
{	
	InputData I;
	vector<InputData> v=I.ReadData();
	I.avgFootfallPerHour(v);
	//getchar();
	return 0;
}
