// Let Catch provide main():

#define CATCH_CONFIG_MAIN

#include<iostream>
#include<string>
#include"catch.hpp"
#include"../Sender/Sender.h"
using namespace std;

TEST_CASE("When a non exiting file is received by Sender then it prints file does not exist") {
	string FileName="../FootFall.csv";
	string s = ReadInputFileAndPrint(FileName);
	REQUIRE( s== "File does not exist");
}

TEST_CASE("When file received by Sender contains Invalid data then it prints File has some Invalid Data on console") {
	string FileName = "../TestFootfallData.csv";
	string s = ReadInputFileAndPrint(FileName);
	REQUIRE(s == "File has some Invalid Data");
}

TEST_CASE("When file received by Sender contains valid data then it converts CSV data in a vector structure on console") {
	string FileName = "../FootFallData.csv";
	string str = ReadInputFileAndPrint(FileName);
	REQUIRE(str == "File read and printed on console successfully");
}
