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

#include "FilmLogic.h"
#include "CinemaLogic.h"
#include "ScheduleLogic.h"

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

#define MENU_LAYER_0 1000
#define MENU_LAYER_1 10

#define FILM 1
#define CINEMA 2
#define SCHEDULE 3


#define GET_ALL 1
#define GET_BY_ID 2
#define FIND_BY_TITLE 3
#define FIND_BY_PRICE_LESS_THEN 4
#define FIND_BY_PRICE_BETWEEN 5
#define FIND_BY_GENRE 6
#define FIND_BY_YEAR 7
#define FIND_BY_YEAR_BETWEEN 8
#define FIND_BY_COUNTRY 9
#define FIND_BY_AVAILABLE_PLACES_COUNT_MORE_THEN 10

#define CREATE 11

#define UPDATE 12

#define DELETE_BY_ID 13
#define DELETE_ALL 14



using namespace std;

void rukalico();
int menu_0() {
	int desision = -1;
	int k = 0;
	while (desision <= 0 || desision >= 4) {
		if (k > 1) {
			cout << "Fucking idiot, What the fuck do you think you're doing?" << endl;
		}
		if (k > 3) {
			rukalico();
		}
		cout << "-------------------------------Menu-----------------------------" << endl;
		cout << "Press " << FILM << " to access Films menu." << endl;
		cout << "Press " << CINEMA << " to access Cinemas menu." << endl;
		cout << "Press " << SCHEDULE << " to access Schedule menu." << endl;
		cout << "----------------------------------------------------------------" << endl;
		k++;
		cin >> desision;
	}
	return desision * MENU_LAYER_0;
}

int menu_1_film() {
	int desision = -1;
	while (desision <= 0 || desision >= 15) {
		cout << "-------------------------Films Menu-----------------------------" << endl;
		cout << "Press " << GET_ALL << " to get all films" << endl;
		cout << "Press " << GET_BY_ID << " to get film by id" << endl;
		cout << "Press " << FIND_BY_TITLE << " to find film by title " << endl;
		cout << "Press " << FIND_BY_PRICE_LESS_THEN << " to find films which ticket costs less then " << endl;
		cout << "Press " << FIND_BY_PRICE_BETWEEN << " to find films which ticket costs between" << endl;
		cout << "Press " << FIND_BY_GENRE << " to find films by genre " << endl;
		cout << "Press " << FIND_BY_YEAR << " to find films by year" << endl;
		cout << "Press " << FIND_BY_YEAR_BETWEEN << " to find films by year between" << endl;
		cout << "Press " << FIND_BY_COUNTRY << " to find films by country" << endl;
		cout << "Press " << CREATE << " to create new film entity" << endl;
		cout << "Press " << UPDATE << " to update film information" << endl;
		cout << "Press " << DELETE_BY_ID << " to delete film by id " << endl;
		cout << "Press " << DELETE_ALL << " to delete all films " << endl;
		cout << "----------------------------------------------------------------" << endl;
		cin >> desision;
	}
	return desision * MENU_LAYER_1 + FILM * MENU_LAYER_0;
}

int menu_1_cinema() {
	int desision = -1;
	while (desision <= 0 || desision >= 15) {
		cout << "--------------------------Cinemas Menu--------------------------" << endl;
		cout << "Press " << GET_ALL << " to get all cinemas" << endl;
		cout << "Press " << GET_BY_ID << " to get cinema by id" << endl;
		cout << "Press " << FIND_BY_TITLE << " to find cinema by title" << endl;
		cout << "Press " << FIND_BY_AVAILABLE_PLACES_COUNT_MORE_THEN << " to find cinema by available places" << endl;
		cout << "Press " << CREATE << " to create new cinema" << endl;
		cout << "Press " << UPDATE << " to update info about cinema" << endl;
		cout << "Press " << DELETE_BY_ID << " to delete cinema by id" << endl;
		cout << "Press " << DELETE_ALL << " to delete all cinemas" << endl;
		cout << "----------------------------------------------------------------" << endl;
		cin >> desision;
	}
	return desision * MENU_LAYER_1 + CINEMA * MENU_LAYER_0;
}

int menu_1_schedule() {
	int desision = -1;
	while (desision <= 0 || desision >= 15) {
		cout << "-------------------------Schedule Menu--------------------------" << endl;
		cout << "Press " << GET_ALL << " to get all scedules" << endl;
		cout << "Press " << GET_BY_ID << " to schedule by id" << endl;
		/*cout << "Press " << FIND_BY_TITLE << " to " << endl;
		cout << "Press " << FIND_BY_PRICE_LESS_THEN << " to " << endl;
		cout << "Press " << FIND_BY_PRICE_BETWEEN << " to " << endl;
		cout << "Press " << FIND_BY_GENRE << " to " << endl;
		cout << "Press " << FIND_BY_YEAR << " to " << endl;
		cout << "Press " << FIND_BY_YEAR_BETWEEN << " to " << endl;
		cout << "Press " << FIND_BY_COUNTRY << " to " << endl;
		cout << "Press " << FIND_BY_AVAILABLE_PLACES_COUNT_MORE_THEN << " to " << endl;*/
		cout << "Press " << CREATE << " to create new schedule" << endl;
		cout << "Press " << UPDATE << " to update info about existing schedule" << endl;
		cout << "Press " << DELETE_ALL << " to delete all schedules " << endl;
		cout << "----------------------------------------------------------------" << endl;
		cin >> desision;
	}
	return desision * MENU_LAYER_1 + SCHEDULE * MENU_LAYER_0;
}


int main()
{
	/*
		Посик:
			поиск фильма по:
				id
				название
				цена до
				цена между
				жанру
				году
				году между
				стране
			поиск кинотеатра по:
				id
				название
				кол-во свободных место больше чем

		Действия с данными:
			фильм, кинотеатр, расписание:
				посмотреть все записи
				посмотреть одну запись (одна строка в txt соответствует одному объекту фильма/кинотеатра/расписания)
				добавить одну запись
				изменить одну запись
				удалить одну запись
				удалить все записи
			
	*/

	cout << "Demo" << endl;

	ScheduleDao scheduleDao;
	CinemaDao cinemaDao;
	FilmDao filmDao;

	ScheduleLogic scheduleLogic;
	CinemaLogic cinemaLogic;
	FilmLogic filmLogic;

	vector<Film> films;
	vector<Cinema> cinemas;
	vector<Schedule> schedules;


	/* Menu */
	int desision_0 = -1;
	int desision_1 = -1;
	while (true) {
		desision_0 = menu_0();

		cout << "des 0 " << desision_0 << endl;

		switch (desision_0) {
		case FILM * MENU_LAYER_0:
			desision_1 = menu_1_film();
			break;
		case CINEMA * MENU_LAYER_0:
			 desision_1 = menu_1_cinema();
			break;
		case SCHEDULE * MENU_LAYER_0:
			desision_1 = menu_1_schedule();
			break;
		default:
			desision_0 = menu_0();
			break;
		}

		switch (desision_1) {
			case FILM * MENU_LAYER_0 + MENU_LAYER_1 * GET_ALL:
				{
					cout << "all films" << endl;
					films = filmDao.getAll();
					for (auto o = films.begin(); o != films.end(); o++) {
						cout << *o << endl;
					}
				}
				break;
			case FILM * MENU_LAYER_0 + MENU_LAYER_1 * GET_BY_ID:
				{
					int id = -1;
					cout << "Input film id:" << endl;
					cin >> id;
					if (filmDao.getById(id).getFilmId() > 0) {
						cout << filmDao.getById(id) << endl;
					}
				}
				break;
			case FILM * MENU_LAYER_0 + MENU_LAYER_1 * FIND_BY_TITLE:
				{
					cout << "Input title" << endl;
					string title1;
					getline(cin >> std::ws, title1);
					if (filmLogic.findByTitle(title1).getFilmId() > 0) {
						cout << filmLogic.findByTitle(title1) << endl;
					}
				}
				break;
			case FILM * MENU_LAYER_0 + MENU_LAYER_1 * FIND_BY_PRICE_LESS_THEN:{
				double d = -1;
				cout << "Input max price" << endl;
				cin >> d;
				films = filmLogic.findByPriceLessThen(d);
				for (auto o = films.begin(); o != films.end(); o++) {
					cout << *o << endl;
				}
				}
				break;
			case FILM * MENU_LAYER_0 + MENU_LAYER_1 * FIND_BY_PRICE_BETWEEN:
				{
				double d = -1;
				double d2 = -1;
				cout << "Input min price" << endl;
				cin >> d;
				cout << "Input max price" << endl;
				cin >> d2;
				films = filmLogic.findByPriceBetween(d, d2);
				for (auto o = films.begin(); o != films.end(); o++) {
					cout << *o << endl;
				}
				}
				break;
			case FILM * MENU_LAYER_0 + MENU_LAYER_1 * FIND_BY_GENRE:{
				string g = "";
				cout << "Input genre" << endl;
				getline(cin >> std::ws, g);
				films = filmLogic.findByDescription(g);
				for (auto o = films.begin(); o != films.end(); o++) {
					cout << *o << endl;
				}
				}
				break;
			case FILM * MENU_LAYER_0 + MENU_LAYER_1 * FIND_BY_YEAR:{
				int y = -1;
				cout << "Input year" << endl;
				cin >> y;
				films = filmLogic.findByYear(y);
				for (auto o = films.begin(); o != films.end(); o++) {
					cout << *o << endl;
				}
				}
				break;
			case FILM * MENU_LAYER_0 + MENU_LAYER_1 * FIND_BY_YEAR_BETWEEN:{
				int y = -1;
				int y2 = -1;
				cout << "Input min year" << endl;
				cin >> y;
				cout << "Input max year" << endl;
				cin >> y2;
				films = filmLogic.findByYearBetween(y, y2);
					for (auto o = films.begin(); o != films.end(); o++) {
						cout << *o << endl;
					}
				}
				break;
			case FILM * MENU_LAYER_0 + MENU_LAYER_1 * FIND_BY_COUNTRY:{
				string g = "";
				cout << "Input country" << endl;
				getline(cin >> std::ws, g);
				films = filmLogic.findByCountry(g);
					for (auto o = films.begin(); o != films.end(); o++) {
						cout << *o << endl;
					}
				}
				break;
			case FILM * MENU_LAYER_0 + MENU_LAYER_1 * CREATE: {
				Film film;
				cin >> film;
				filmDao.create(film);
				}
				break;
			case FILM * MENU_LAYER_0 + MENU_LAYER_1 * UPDATE: {
				Film film;
				cin >> film;
				filmDao.update(film);
				}
				break;
			case FILM * MENU_LAYER_0 + MENU_LAYER_1 * DELETE_BY_ID: {
				int i = -1;
				cout << "Input id" << endl;
				filmDao.deleteById(i);
				}
				break;
			case FILM * MENU_LAYER_0 + MENU_LAYER_1 * DELETE_ALL: {
				filmDao.deleteAll();
				}
				break;
		}
		cout << endl;
		cout << endl;
	}
	/*
	cout << "all films" << endl;
	films = filmDao.getAll();
	for (auto film = films.begin(); film != films.end(); film++) {
		if (film->getFilmId() > 0) {
			cout << *film << endl;
		}
	}

	cout << "2" << endl;
	cout << filmDao.getById(2) << endl;


	cout << "All cinemas" << endl;
	cinemas = cinemaDao.getAll();
	for (auto cinema = cinemas.begin(); cinema != cinemas.end(); cinema++) {
			cout << *cinema << endl;
	}

	/*Cinema newCinema;
	cout << "new" << endl;
	cin >> newCinema;
	cinemaDao.create(newCinema);

	cout << "All cinemas" << endl;
	cinemas = cinemaDao.getAll();
	for (auto cinema = cinemas.begin(); cinema != cinemas.end(); cinema++) {
		if (cinema->getCinemaId() > 0) {
			cout << *cinema << endl;
		}
	}*/

	/*Schedule newSchedule;
	cin >> newSchedule;
	scheduleDao.create(newSchedule);*/
	/*
	cout << "All schedules" << endl;
	schedules = scheduleDao.getAll();
	for (auto o = schedules.begin(); o != schedules.end(); o++) {
		cout << *o << endl;
	}*/



	_getch();
    return 0;
}

void rukalico() {
	cout << "_____________11¶¶¶¶¶¶¶¶¶¶¶¶11 " << endl;
	cout << "___________1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1" << endl;
	cout << "__________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶" << endl;
	cout << "________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶11" << endl;
	cout << "_______¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1" << endl;
	cout << "_____1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶11" << endl;
	cout << "___1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_11" << endl;
	cout << "__1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1" << endl;
	cout << "__¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶11111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_11" << endl;
	cout << "__¶¶¶¶¶¶¶¶¶¶¶¶111¶1____1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶11" << endl;
	cout << "_¶¶¶¶¶¶¶¶¶¶¶1___1_1¶¶¶_¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶11" << endl;
	cout << "1¶¶¶¶¶¶¶¶¶1____11¶¶¶¶¶_¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶" << endl;
	cout << "¶¶¶¶¶¶¶¶¶1____1¶¶¶1____1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶" << endl;
	cout << "¶¶¶¶¶¶¶1______111¶¶1____¶¶¶¶¶¶¶¶¶¶1_1¶¶¶¶¶¶¶¶" << endl;
	cout << "¶¶¶¶¶1_________11¶1_____¶¶¶¶¶¶111¶¶_1¶¶11¶¶¶¶" << endl;
	cout << "1¶¶1_________1¶¶¶_________1111___¶¶1_1¶11¶1" << endl;
	cout << "_____________1¶¶_________11__11__1¶¶_1¶11¶" << endl;
	cout << "_________________________1¶1__¶¶¶1¶¶__111¶" << endl;
	cout << "__________________________1¶1__¶¶¶¶¶1__11¶" << endl;
	cout << "___________________________1¶___1¶¶¶1__¶¶¶" << endl;
	cout << "__________________1_________¶¶1__1¶1__¶¶¶" << endl;
	cout << "________________1¶¶¶¶___11_1¶¶¶__1¶___¶¶" << endl;
	cout << "____11__________¶¶_1¶¶¶¶1__¶¶¶¶__¶¶1_1¶1" << endl;
	cout << "____1¶1________11¶¶1__¶¶¶¶¶¶¶¶¶__1¶1_¶¶" << endl;
	cout << "______1¶¶¶_____1__1¶¶1___1¶¶¶¶1¶__¶¶_¶¶" << endl;
	cout << "________¶¶¶____111__111¶¶_________1¶¶¶¶" << endl;
	cout << "________11¶¶___1111_111¶¶¶1_______1¶¶¶" << endl;
	cout << "__________1¶¶1_111¶¶¶¶¶¶¶¶¶1_1¶¶¶¶¶¶¶¶" << endl;
	cout << "_______1____¶¶¶11¶¶¶¶¶¶11¶¶1_1¶¶¶¶¶¶¶1" << endl;
	cout << "¶1_____1_____¶¶¶¶¶¶¶¶¶1__¶¶__1_1¶¶¶¶¶" << endl;
	cout << "¶¶__________¶¶¶¶¶¶¶11____¶¶1__1¶¶¶¶¶¶" << endl;
	cout << "_11_______1¶¶¶¶¶¶¶¶11____¶¶¶_1¶¶¶¶¶¶¶" << endl;
	cout << "__1¶¶____¶¶¶¶¶¶¶¶¶¶¶¶1___1¶¶¶¶¶¶¶¶¶¶¶" << endl;
	cout << "___¶¶¶_1¶¶¶¶¶¶¶¶¶¶¶¶¶¶____¶¶¶¶¶¶¶¶¶¶¶1" << endl;
	cout << "____1¶1¶¶111¶¶¶¶¶¶¶¶¶¶¶____1¶¶¶¶¶¶¶¶¶1" << endl;
	cout << "______11_1111¶¶¶¶¶¶¶¶¶¶1____¶¶¶¶¶¶¶¶¶¶" << endl;
	cout << "__________111¶11¶¶¶¶¶¶¶¶1___¶¶¶¶¶¶¶¶¶¶1" << endl;
	cout << "__________1_11¶1¶¶¶¶¶¶¶¶¶¶__1¶¶¶¶¶¶¶¶¶¶" << endl;
	cout << "____________11¶¶1¶¶¶¶¶¶¶¶¶1__¶¶¶¶¶¶¶¶¶¶¶" << endl;
	cout << "_____________1_¶11¶¶¶¶¶¶¶¶¶1_¶¶¶¶¶¶¶¶¶¶¶¶" << endl;
}

