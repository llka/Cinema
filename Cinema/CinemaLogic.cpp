
#pragma once
#include "stdafx.h"
#include "Cinema.h"
#include "CinemaLogic.h"
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


vector<Cinema> CinemaLogic::findByPlacesMoreThan(int min)
{
	vector<Cinema> allCinemas = cinemaDao.getAll();
	vector<Cinema> result;
	for (size_t i = 0; i < allCinemas.size(); i++)
	{
		if (allCinemas[i].getCinemaId() >= min) {
			result.push_back(allCinemas[i]);
		}
	}
	if (result.size() < 1) {
		cout << "[INFO] No cinemas found." << endl;
	}
	return result;
}

vector<Cinema> CinemaLogic::findByTitle(string title1)
{
	vector<Cinema> allCinemas = cinemaDao.getAll();
	vector<Cinema> result;
	for (size_t i = 0; i < allCinemas.size(); i++)
	{
		if (allCinemas[i].getTitle() == title1) {
			result.push_back(allCinemas[i]);
		}
	}
	if (result.size() < 1) {
		cout << "[INFO] No cinemas found." << endl;
	}
	return result;
}

CinemaLogic::CinemaLogic()
{
	cinemaDao = CinemaDao();
}


CinemaLogic::~CinemaLogic()
{
}
