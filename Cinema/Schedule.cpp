#include "stdafx.h"
#include "Schedule.h"
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

Schedule::Schedule( ) {}

Schedule::Schedule(int id, Date date1, Time time1, int cinemaId1, int filmId1, int availablePlacesCount1) {
	scheduleId = id;
	date = date1;
	time = time1;
	cinemaId = cinemaId1;
	filmId = filmId1;
	availablePlacesCount = availablePlacesCount1;
}

Schedule::Schedule(Schedule * schedule) {
	scheduleId = schedule->scheduleId;
	date = schedule->date;
	time = schedule->time;
	cinemaId = schedule->cinemaId;
	filmId = schedule->filmId;
	availablePlacesCount = schedule->availablePlacesCount;
}

Schedule::~Schedule( ) {}

void Schedule::write( string fileName) {
	ofstream fout(fileName, ios::app);
	fout << " , " << date.day << " , " << date.month <<
		" , " << date.year << " , " << time.hour << " , " << time.minutes
		<< " , " << cinemaId << " , " << filmId
		<< " , " << availablePlacesCount << "." << endl;
}

DatabaseEntity Schedule::read(string fileName) {
	ifstream fin(fileName);
	Schedule shedule;
	fin >> shedule.date.day >> shedule.date.month >> shedule.date.year >> shedule.time.hour >> shedule.time.minutes
		>> shedule.cinemaId >> shedule.filmId
		>> shedule.availablePlacesCount;
	return DatabaseEntity( );
}

ostream & operator<<(ostream & stream, Schedule shedule) {
	string hh = to_string(shedule.time.hour);
	string mm = to_string(shedule.time.minutes);
	if (shedule.time.minutes == 0) {
		mm = "00";
	}
	if (shedule.time.hour == 0) {
		hh = "00";
	}
	stream << "Schedule{ date=" << shedule.date.day << "." << shedule.date.month <<
		"." << shedule.date.year << ", time=" << hh << ":" << mm
		<< ", cinemaId=" << shedule.cinemaId << ", filmId=" << shedule.filmId
		<< ", tickets available= " << shedule.availablePlacesCount << "}" << endl;
	return stream;
}

istream & operator>>(istream & stream, Schedule & shedule) {
	cout << "Input shedule" << endl;
	cout << "day :" << endl;
	stream >> shedule.date.day;
	cout << "month :" << endl;
	stream >>  shedule.date.month;
	cout << "year :" << endl;
	stream >> shedule.date.year;
	cout << "hour :" << endl;
	stream >> shedule.time.hour;
	cout << "minutes :" << endl;
	stream >> shedule.time.minutes;
	cout << "cinema Id :" << endl;
	stream >> shedule.cinemaId;
	cout << "film Id :" << endl;
	stream >> shedule.filmId;
	cout << "availablePlacesCount :" << endl;
	stream >> shedule.availablePlacesCount;
	return stream;
}
