#include "stdafx.h"
#include "Schedule.h"
#include <iostream>

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

void Schedule::write(Schedule entity) {}

DatabaseEntity Schedule::read() {
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
