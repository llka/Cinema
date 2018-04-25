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


string FILE_CINEMA = "cinema.txt";
string FILE_FILM = "film.txt";

ifstream fin(FILE_FILM);
ofstream fout(FILE_FILM);

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

	list<Film> films;
	vector <Film> ::iterator filmsIterator;

	Film filmsInitArray[N];

	for (int i = 0; i < N; i++) {
		cin >> filmsInitArray[i];
		films.push_back(filmsInitArray[i]);
	}

	for (auto film = films.begin(); film != films.end(); film++) {
		cout << *film;
		fout << *film;
	}
	_getch();
    return 0;
}

