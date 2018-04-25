#include "stdafx.h"
#include "Date.h"
#include <iostream>
#include <string>

using namespace std;


Date::Date( ) {}

Date::Date(int day1, int month1, int year1) {
	if (0 < day1 <= 31 && 0 < month1 <= 12) {
		int day = day1;
		int month = month1;
		int year = year1;
	} else {
		cout << " Date Exception: invalid input " << endl;
		int day = 1;
		int month = 1;
		int year = 2018;
	}
}

Date::Date(Date * date) {
	int day = date->day;
	int month = date->month;
	int year = date->year;
}

Date::~Date( ) {}

ostream & operator<<(ostream & stream, Date date) {
	stream << "Date{ " << date.day << "." << date.month << "." << date.year << " }" << endl;
	return stream;
}
