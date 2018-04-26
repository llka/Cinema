#pragma once
#include "stdafx.h"
#include "Film.h"
#include "FilmDao.h"

#include <iostream>
#include <fstream>
#include <sstream>   
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

class FilmLogic
{
private: FilmDao filmDao;

public:

	Film findByTitle(string title);
	vector<Film> findByPriceLessThen(double max);
	vector<Film> findByPriceBetween(double min, double max);
	vector<Film> findByDescription(string description);
	vector<Film> findByYear(int year);
	vector<Film> findByYearBetween(int min, int max);
	vector<Film> findByCountry(string country);


	FilmLogic();
	~FilmLogic();

};

