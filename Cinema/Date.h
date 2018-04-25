#pragma once
#include <iostream>

using namespace std;

class Date {
public:
	int day;
	int month;
	int year;
public:
	Date( );
	Date(int day1, int month1, int year1);
	Date(Date * date );
	~Date( );

	friend  ostream &operator<< (ostream &stream, Date date);
};

