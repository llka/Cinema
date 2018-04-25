#pragma once

#include "stdafx.h"
#include "CrudRepository.h"
#include "Schedule.h"

#include <iostream>
#include <fstream>
#include <sstream>   
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

class ScheduleDao {
public:
	char DELIMITER = '_';
	string FILE = "schedule.txt";
public:
	vector<Schedule> getAll();
	Schedule getById(int id);

	void create(Schedule entity);

	void update(Schedule entity);

	void deleteById(int id);
	void deleteAll();
	ScheduleDao();
	~ScheduleDao();
};

