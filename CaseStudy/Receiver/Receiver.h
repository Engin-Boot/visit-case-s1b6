#include<iostream>
#include<vector>
#include<string>
#include <sstream>
using namespace std;

class InputData
{
	int id=0;
	int hrs=0;
	int min=0;
	int sec=0;
	int day_of_week=0;
	int day_of_month;
	int month;
	int year;
	int footfall_count=0;
	float hourlyAverage=0;
	float dailyAverage=0;
	int PeakDailyFootfall=0;
	public:
		InputData() {}
		InputData(int i,int h,int min,int s,int d, int dt, int m, int y, int c);
		InputData(int dt, int m, int y, int c, float avg); 
		//InputData(int id, int day_of_week, int day_of_month, int month, int year, int footfall_count, float dailyAverage);
		//InputData(int id, int day_of_week, int day_of_month, int month, int year, int footfall_count, int PeakDailyFootfall);
		vector<InputData> ReadData();
		vector<InputData> storeInputData(vector<InputData> footFallData, const string row);
		/*vector<InputData> */ void avgFootfallPerHour(vector<InputData> footFallData); 

};

InputData::InputData(int i, int h, int min, int s, int d, int dt, int m, int y, int c) :id(i), hrs(h),min(min),sec(s), day_of_week(d), day_of_month(d), month(m), year(y), footfall_count(c) {}
InputData::InputData(int dt, int m, int y, int c, float avg ):day_of_month(dt), month(m), year(y), footfall_count(c), hourlyAverage(avg) {}

vector<InputData> InputData::ReadData()
{
	cout << "Inside Read data";
	vector<InputData> footFallData;
	string row;
	//string s = ReadInputFileAndPrint(FileName);
	getline(cin, row);  //column headings

	while (getline(cin, row))
	{
		//stringstream s(row);
		footFallData=storeInputData(footFallData,row);
	}
	return footFallData;
}

vector<InputData>  InputData::storeInputData(vector<InputData> footFallData, const string row)
{
	cout << "Inside store data";
	vector<int> Record;
	string entry;
	stringstream rowdata(row);
	while (getline(rowdata,entry ,','))
	{
		cout<<stoi(entry);
		Record.push_back(stoi(entry));
	}

	InputData Iobj(Record[0], Record[1], Record[2], Record[3], Record[4], Record[5], Record[6], Record[7], Record[8]);
	footFallData.push_back(Iobj);
	return footFallData;
}

void InputData::avgFootfallPerHour(vector<InputData> footFallData)
{
	cout << "Inside avg footfall data";
	int sum = 0,i=0;
	InputData Iobj(footFallData[0].day_of_month,footFallData[0].month,footFallData[0].year,footFallData[0].footfall_count, footFallData[0].hourlyAverage);
	cout << typeid(footFallData.size()).name();
	while(i<footFallData.size())
	{
		if (Iobj.day_of_month == footFallData[i].day_of_month)
		{
			sum += footFallData[i].footfall_count;
			i++;
		}
		else
			break;
	}
	footFallData[0].hourlyAverage = float(sum) / 6;
	cout << Iobj.hourlyAverage;
	//return footFallData;
}
