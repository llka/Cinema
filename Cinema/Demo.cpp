// Cinema.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"

#include "DatabaseEntity.h"
#include "Film.h"
#include "Cinema.h"
#include "Calendar.h"
#include "Date.h"
#include "Schedule.h"
#include "Time.h"

#include "FilmDao.h"
#include "CinemaDao.h"
#include "ScheduleDao.h"

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <list>
#include <Windows.h>
#include <conio.h>

#define N 2

using namespace std;

int main()
{
	/*
		все фильмы по всем дням
		поиск фильма по
			цена
			название
			день
	*/

	cout << "Demo" << endl;

	ScheduleDao scheduleDao;
	CinemaDao cinemaDao;
	FilmDao filmDao;

	vector<Film> films;
	vector<Cinema> cinemas;
	cout << "all" << endl;
	films = filmDao.getAll();
	for (auto film = films.begin(); film != films.end(); film++) {
		if (film->getFilmId() > 0) {
			cout << *film << endl;
		}
	}

	cout << "2" << endl;
	cout << filmDao.getById(2) << endl;

	/*Film newFilm;
	cin >> newFilm;
	filmDao.create(newFilm);

	cout << "all" << endl;
	films = filmDao.getAll();
	for (auto film = films.begin(); film != films.end(); film++) {
		if (film->getFilmId() > 0) {
			cout << *film << endl;
		}
	}*/
	
	//filmDao.deleteAll();

	cout << "all" << endl;
	films = filmDao.getAll();
	for (auto film = films.begin(); film != films.end(); film++) {
		if (film->getFilmId() > 0) {
			cout << *film << endl;
		}
	}

	cout << "All cinemas" << endl;
	cinemas = cinemaDao.getAll();
	for (auto cinema = cinemas.begin(); cinema != cinemas.end(); cinema++) {
		if (cinema->getCinemaId() > 0) {
			cout << *cinema << endl;
		}
	}

	Cinema newCinema;
	cout << "new" << endl;
	cin >> newCinema;
	cinemaDao.create(newCinema);

	cout << "All cinemas" << endl;
	cinemas = cinemaDao.getAll();
	for (auto cinema = cinemas.begin(); cinema != cinemas.end(); cinema++) {
		if (cinema->getCinemaId() > 0) {
			cout << *cinema << endl;
		}
	}

	_getch();
    return 0;
}

