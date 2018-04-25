#include "stdafx.h"
#include "FilmDao.h"
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


vector<Film> FilmDao::getAll()
{
	vector<Film> films;
	ifstream fin(FILE);
	string::size_type sz;     // alias of size_t

	for (string line; getline(fin, line); )
	{
		Film film;
		istringstream iss(line);
		string element;
		int i = 0;
		while (getline(iss, element, DELIMITER))
		{
			switch (i)
			{
			case 0:
				film.setFilmId(stoi(element));
				break;
			case 1:
				film.setTitle(element);
				break;
			case 2:
				film.setDescription(element);
				break;
			case 3:
				film.setRating(stod(element, &sz));
				break;
			case 4:
				film.setTicketCost(stod(element, &sz));
				break;
			default:
				break;
			}
			i++;
		}
		films.push_back(film);
	}
	return films;
}

Film FilmDao::getById(int id)
{
	vector<Film> allFilms = getAll();
	for (size_t i = 0; i < allFilms.size(); i++)
	{
		if (id == allFilms[i].getFilmId()) {
			return allFilms[i];
		}
	}
	Film film = Film(-1, "[ERROR]", "[ERROR]", -1, -1);
	cout << "[ERROR] No film with id = " << id << "!" << endl;
	return film;
}

void FilmDao::create(Film film)
{
	ofstream fout(FILE, ios::app);
	fout << endl;
	fout << film.getFilmId() << DELIMITER << film.getTitle() << DELIMITER << film.getDescription() << DELIMITER << film.getRating() << DELIMITER << film.getTicketCost();
}

void FilmDao::update(Film entity)
{
	int id = entity.getFilmId();
	vector<Film> allFilmsNew;
	vector<Film> allFilms = getAll();
	for (size_t i = 0; i < allFilms.size(); i++)
	{
		if (id == allFilms[i].getFilmId()) {
			allFilmsNew.push_back(entity);
		}
		else {
			allFilmsNew.push_back(allFilms[i]);
		}
	}
	deleteAll();
	for (size_t i = 0; i < allFilmsNew.size(); i++)
	{
		create(allFilmsNew[i]);
	}
}

void FilmDao::deleteById(int id)
{
	vector<Film> allFilmsNew;
	vector<Film> allFilms = getAll();
	for (size_t i = 0; i < allFilms.size(); i++)
	{
		if (id != allFilms[i].getFilmId() && allFilms[i].getFilmId() > 0) {
			allFilmsNew.push_back(allFilms[i]);
		}
	}
	deleteAll();
	for (size_t i = 0; i < allFilmsNew.size(); i++)
	{
		create(allFilmsNew[i]);
	}
}

void FilmDao::deleteAll()
{
	ofstream fout(FILE);
	fout << endl;
}

FilmDao::FilmDao()
{
}


FilmDao::~FilmDao()
{
}
