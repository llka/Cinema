#pragma once
#include "stdafx.h"
#include "Cinema.h"
#include "CinemaDao.h"

#include <iostream>
#include <fstream>
#include <sstream>   
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

class CinemaLogic
{
private: CinemaDao cinemaDao;
public:

	vector<Cinema> findByPlacesMoreThan(int min);
	vector<Cinema> findByTitle(string title1);

	CinemaLogic();
	~CinemaLogic();
};

