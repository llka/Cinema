
#include "stdafx.h"
#include "ScheduleDao.h"
#include "Schedule.h"
#include "Date.h"
#include "Time.h"

#include <iostream>
#include <fstream>
#include <sstream>   
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

vector<Schedule> ScheduleDao::getAll()
{
	vector<Schedule> all;
	ifstream fin(FILE);
	string::size_type sz;     // alias of size_t

	for (string line; getline(fin, line); )
	{
		Schedule schedule;
		istringstream iss(line);
		string element;
		int argumentPlace = 0;
		while (getline(iss, element, DELIMITER))
		{
			Date date1;
			Time time1;
			switch (argumentPlace)
			{
			case 0:
				schedule.scheduleId = stoi(element);
				break;
			case 1:
				date1.day = stoi(element);
				break;
			case 2:
				date1.month = stoi(element);
				break;
			case 3:
				date1.year = stoi(element);
				schedule.date = date1;
				break;
			case 4:
				time1.hour = stoi(element);
				break;
			case 5:
				time1.minutes = stoi(element);
				schedule.time = time1;
				break;
			case 6:
				schedule.cinemaId = stoi(element);
				break;
			case 7:
				schedule.filmId = stoi(element);
				break;
			case 8:
				schedule.availablePlacesCount = stoi(element);
			default:
				break;
			}
			argumentPlace++;
		}
		if (schedule.scheduleId > -1) {
			all.push_back(schedule);
		}
	}
	return all;
}

Schedule ScheduleDao::getById(int id)
{
	vector<Schedule> all = getAll();
	for (size_t i = 0; i < all.size(); i++)
	{
		if (id == all[i].scheduleId) {
			return all[i];
		}
	}
	Schedule empty = Schedule(-1, Date(1, 1, 1), Time(1, 1), -1, -1, -1);
	cout << "[ERROR] No schedule with id = " << id << "!" << endl;
	return empty;
}

void ScheduleDao::create(Schedule entity)
{
	entity.scheduleId = scheduleIdAutoIncrement;
	scheduleIdAutoIncrement += 1;
	ofstream fout(FILE, ios::app);
	fout << endl;
	fout << entity.scheduleId << DELIMITER
		<< entity.date.day << DELIMITER
		<< entity.date.month << DELIMITER
		<< entity.date.year << DELIMITER
		<< entity.time.hour << DELIMITER
		<< entity.time.minutes << DELIMITER
		<< entity.cinemaId << DELIMITER
		<< entity.filmId << DELIMITER
		<< entity.availablePlacesCount;
	
}

void ScheduleDao::update(Schedule entity)
{
	int id = entity.scheduleId;
	vector<Schedule> allNew;
	vector<Schedule> all = getAll();
	for (size_t i = 0; i < all.size(); i++)
	{
		if (id == all[i].scheduleId) {
			allNew.push_back(entity);
		}
		else {
			allNew.push_back(all[i]);
		}
	}
	deleteAll();
	for (size_t i = 0; i < allNew.size(); i++)
	{
		create(allNew[i]);
	}
}

void ScheduleDao::deleteById(int id)
{
	vector<Schedule> allNew;
	vector<Schedule> all = getAll();
	for (size_t i = 0; i < all.size(); i++)
	{
		if (id != all[i].scheduleId) {
			allNew.push_back(all[i]);
		}
	}
	deleteAll();
	for (size_t i = 0; i < allNew.size(); i++)
	{
		create(allNew[i]);
	}
}

void ScheduleDao::deleteAll()
{
	ofstream fout(FILE);
	fout << endl;
	scheduleIdAutoIncrement = 1;
}

ScheduleDao::ScheduleDao()
{
	scheduleIdAutoIncrement = 100;
}


ScheduleDao::~ScheduleDao()
{
}
