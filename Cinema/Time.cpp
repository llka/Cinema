#include "stdafx.h"
#include "Time.h"
#include <iostream>
#include <string>

using namespace std;

Time::Time( ) {}

Time::Time(int hour1, int minutes1) {
	if (-1 < hour1 <= 24 && -1 < minutes1 <= 59) {
		int hour = hour1;
		int minutes = minutes1;
	} else {
		cout << "Time Eception: invalid input" << endl;
		int hour = 0;
		int minutes = 0;
	}
}

Time::Time(Time * time) {
	hour = time->hour;
	minutes = time->minutes;
}


Time::~Time( ) {}

ostream & operator<<(ostream & stream, Time time) {
	stream << "Time{ " << time.hour << ":" << time.minutes << " }" << endl;
	return stream;
}

istream & operator>>(istream & stream, Time & time) {
	cout << "Input time" << endl;
	cout << "hours:" << endl;
	stream >> time.hour;
	cout << "minutes:" << endl;
	stream >> time.minutes;
	cout << endl;
	return stream;
}
