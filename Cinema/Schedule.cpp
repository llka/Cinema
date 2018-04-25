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

Schedule::Schedule(Date date1, Time time1, int cinemaId1, int filmId1, int availablePlacesCount1) {
	date = date1;
	time = time1;
	cinemaId = cinemaId1;
	filmId = filmId1;
	availablePlacesCount = availablePlacesCount1;
}

Schedule::Schedule(Schedule * schedule) {
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
	stream << "Schedule{ date=" << shedule.date.day << "." << shedule.date.month <<
		"." << shedule.date.year << ", time=" << shedule.time.hour << ":" << shedule.time.minutes
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
	cout << "hours :" << endl;
	stream >> shedule.time.hour;
	cout << "minutes :" << endl;
	stream >> shedule.time.minutes;
	cout << "cinemaId :" << endl;
	stream >> shedule.cinemaId;
	cout << "filmId :" << endl;
	stream >> shedule.filmId;
	cout << "availablePlacesCount :" << endl;
	stream >> shedule.availablePlacesCount;
	return stream;
}
