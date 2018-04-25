#include "stdafx.h"
#include "CinemaDao.h"
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


vector<Cinema> CinemaDao::getAll()
{
	vector<Cinema> cinemas;
	ifstream fin(FILE);
	string::size_type sz;     // alias of size_t

	for (string line; getline(fin, line); )
	{
		Cinema cinema;
		istringstream iss(line);
		string element;
		int i = 0;
		while (getline(iss, element, DELIMITER))
		{
			switch (i)
			{
			case 0:
				cinema.setCinemaId(stoi(element));
				break;
			case 1:
				cinema.setTitle(element);
				break;
			case 2:
				cinema.setPlacesCount(stoi(element));
				break;
			default:
				break;
			}
			i++;
		}
		cinemas.push_back(cinema);
	}
	return cinemas;
}

Cinema CinemaDao::getById(int id)
{
	vector<Cinema> allCinemas = getAll();
	for (size_t i = 0; i < allCinemas.size(); i++)
	{
		if (id == allCinemas[i].getCinemaId()) {
			return allCinemas[i];
		}
	}
	Cinema cinema = Cinema(-1, "[ERROR]", -1);
	cout << "[ERROR] No cinema with id = " << id << "!" << endl;
	return cinema;
}

void CinemaDao::create(Cinema entity)
{
	ofstream fout(FILE, ios::app);
	fout << endl;
	fout << entity.getCinemaId() << DELIMITER << entity.getTitle() << DELIMITER << entity .getPlacesCount();
}

void CinemaDao::update(Cinema entity)
{
	int id = entity.getCinemaId();
	vector<Cinema> allCinemasNew;
	vector<Cinema> allCinemas = getAll();
	for (size_t i = 0; i < allCinemas.size(); i++)
	{
		if (id == allCinemas[i].getCinemaId()) {
			allCinemasNew.push_back(entity);
		}
		else {
			allCinemasNew.push_back(allCinemas[i]);
		}
	}
	deleteAll();
	for (size_t i = 0; i < allCinemasNew.size(); i++)
	{
		create(allCinemasNew[i]);
	}
}

void CinemaDao::deleteById(int id)
{
	vector<Cinema> allCinemasNew;
	vector<Cinema> allCinemas = getAll();
	for (size_t i = 0; i < allCinemas.size(); i++)
	{
		if (id != allCinemas[i].getCinemaId() && allCinemas[i].getCinemaId() > 0) {
			allCinemasNew.push_back(allCinemas[i]);
		}
	}
	deleteAll();
	for (size_t i = 0; i < allCinemasNew.size(); i++)
	{
		create(allCinemasNew[i]);
	}
}

void CinemaDao::deleteAll()
{
	ofstream fout(FILE);
	fout << endl;
}

CinemaDao::CinemaDao()
{
}


CinemaDao::~CinemaDao()
{
}
