#pragma once

#include "stdafx.h"
#include "CrudRepository.h"
#include "Cinema.h"

#include <iostream>
#include <fstream>
#include <sstream>   
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

class CinemaDao {
public:
	string FILE = "cinema.txt";
	char DELIMITER = '_';
public:
	vector<Cinema> getAll();
	Cinema getById(int id);

	void create(Cinema entity);

	void update(Cinema entity);

	void deleteById(int id);
	void deleteAll();

	CinemaDao();
	~CinemaDao();
};

