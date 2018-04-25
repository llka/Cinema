#pragma once
#include "DatabaseEntity.h"
#include "Date.h"
#include "Time.h"
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

class Schedule:
	public DatabaseEntity {
public:
	Date date;
	Time time;
	int cinemaId;
	int filmId;
	int availablePlacesCount;

	Schedule( );
	Schedule(Date date1, Time time1, int cinemaId1, int filmId1, int availablePlacesCount1);
	Schedule(Schedule *schedule);
	~Schedule( );

	void  write(Schedule entity);
	DatabaseEntity  read();

	friend  ostream &operator<< (ostream &stream, Schedule shedule);
	friend  istream &operator>> (istream &stream, Schedule &shedule);
};

