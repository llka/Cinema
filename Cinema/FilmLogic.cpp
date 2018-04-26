#include "stdafx.h"
#include "FilmLogic.h"
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


Film FilmLogic::findByTitle(string title)
{
	vector<Film> allFilms = filmDao.getAll();
	for (size_t i = 0; i < allFilms.size(); i++)
	{
		if (title == allFilms[i].getTitle()) {
			return allFilms[i];
		}
	}
	Film film = Film(-1, "[ERROR]", "[ERROR]", -1, "[ERROR]", -1, -1, -1);
	cout << "[ERROR] No film with title = " << title << "!" << endl;
	return film;
}

vector<Film> FilmLogic::findByPriceLessThen(double max)
{
	vector<Film> allFilms = filmDao.getAll();
	vector<Film> result;
	for (size_t i = 0; i < allFilms.size(); i++)
	{
		if (allFilms[i].getTicketCost() <= max) {
			result.push_back(allFilms[i]);
		}
	}
	if (result.size() < 1) {
		cout << "[INFO] No films found." << endl;
	}
	return result;
}

vector<Film> FilmLogic::findByPriceBetween(double min, double max)
{
	vector<Film> allFilms = filmDao.getAll();
	vector<Film> result;
	for (size_t i = 0; i < allFilms.size(); i++)
	{
		if (min <= allFilms[i].getTicketCost() <= max) {
			result.push_back(allFilms[i]);
		}
	}
	if (result.size() < 1) {
		cout << "[INFO] No films found." << endl;
	}
	return result;
}

vector<Film> FilmLogic::findByDescription(string description1)
{
	vector<Film> allFilms = filmDao.getAll();
	vector<Film> result;
	for (size_t i = 0; i < allFilms.size(); i++)
	{
		if (allFilms[i].getCountry() == description1) {
			result.push_back(allFilms[i]);
		}
	}
	if (result.size() < 1) {
		cout << "[INFO] No films found." << endl;
	}
	return result;
}

vector<Film> FilmLogic::findByYear(int year1)
{
	vector<Film> allFilms = filmDao.getAll();
	vector<Film> result;
	for (size_t i = 0; i < allFilms.size(); i++)
	{
		if (allFilms[i].getYear() == year1) {
			result.push_back(allFilms[i]);
		}
	}
	if (result.size() < 1) {
		cout << "[INFO] No films found." << endl;
	}
	return result;
}

vector<Film> FilmLogic::findByYearBetween(int min, int max)
{
	vector<Film> allFilms = filmDao.getAll();
	vector<Film> result;
	for (size_t i = 0; i < allFilms.size(); i++)
	{
		if (min <= allFilms[i].getYear() <= max) {
			result.push_back(allFilms[i]);
		}
	}
	if (result.size() < 1) {
		cout << "[INFO] No films found." << endl;
	}
	return result;
}

vector<Film> FilmLogic::findByCountry(string country1)
{
	vector<Film> allFilms = filmDao.getAll();
	vector<Film> result;
	for (size_t i = 0; i < allFilms.size(); i++)
	{
		if (allFilms[i].getCountry() == country1) {
			result.push_back(allFilms[i]);
		}
	}
	if (result.size() < 1) {
		cout << "[INFO] No films found." << endl;
	}
	return result;
}

FilmLogic::FilmLogic()
{
	filmDao = FilmDao();
}


FilmLogic::~FilmLogic()
{
}

