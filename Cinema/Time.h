#pragma once
#include "DatabaseEntity.h"
#include <string>

using namespace std;

class Time {
public:
	int hour;
	int minutes;
public:
	Time( );
	Time(int hour1, int minutes1);
	Time(Time * time);
	~Time( );

	friend  ostream &operator<< (ostream &stream, Time time);
	friend  istream &operator>> (istream &stream, Time &Time);
};

