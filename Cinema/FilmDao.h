#pragma once
#include "stdafx.h"
#include "CrudRepository.h"
#include "Film.h"

#include <iostream>
#include <fstream>
#include <sstream>   
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;


class FilmDao{
public:
	string FILE = "film.txt";
	char DELIMITER = '_';
public:
	vector<Film> getAll();
	Film getById(int id);

	void create(Film entity);

	void update(Film entity);

	void deleteById(int id);
	void deleteAll();
	FilmDao();
	~FilmDao();
};

