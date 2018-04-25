#include "stdafx.h"
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

Film::Film( ) {}

Film::Film(int filmId1, string title1, string description1, double rating1, double ticketCost1) {
	filmId = filmId1;
	title = title1;
	description = description1;
	rating = rating1;
	ticketCost = ticketCost1;
}
Film::Film(Film * film) {
	filmId = film->filmId;
	title = film->title;
	description = film->description;
	rating = film->rating;
	ticketCost = film->ticketCost;
}
Film::~Film( ) {}

void Film::setFilmId(int id) {
	filmId = id;
}

void Film::setTitle(string title1) {
	title = title1;
}

void Film::setDescription(string description1) {
	description = description1;
}

void Film::setRating(double rating1) {
	rating = rating1;
}

void Film::setTicketCost(double ticketCost1) {
	ticketCost = ticketCost1;
}

int Film::getFilmId( ) {
	return filmId;
}

string Film::getTitle( ) {
	return title;
}

string Film::getDescription( ) {
	return description;
}

double Film::getRating( ) {
	return rating;
}

double Film::getTicketCost( ) {
	return ticketCost;
}

void Film::write(string fileName) {
	ofstream fout(fileName, ios::app);
	char delimiter = '_';
	fout << filmId << delimiter << title << delimiter << description << delimiter << rating << delimiter << ticketCost << endl;
}

DatabaseEntity Film::read(string fileName) {
	char delimiter = '_';

	ifstream fin(fileName);
	Film film;

	for (string line; getline(fin, line); )
	{
		cout << "filmLine = " << line << endl;
		istringstream iss(line);
		string element;
		vector<string> elements;
		while (getline(iss, element, delimiter))
		{
			elements.push_back(element);
			cout << "element " << element << endl;
		}
	}
	return film;
}

ostream & operator<<(ostream & stream, Film film) {
	stream << "Film{ id=" << film.filmId << ", title=" << film.title << ", description=" << film.description << ", rating=" << film.rating << ", ticket costs " << film.ticketCost << "$}" << endl;
	return stream;
}

istream & operator>>(istream & stream, Film & film) {
	cout << "Input film" << endl;
	cout << "film id:" << endl;
	stream >> film.filmId;
	cout << "title:" << endl;
	stream >> film.title;
	cout << "description:" << endl;
	stream >> film.description;
	cout << "rating:" << endl;
	stream >> film.rating;
	cout << "ticket cost:" << endl;
	stream >> film.ticketCost;
	cout << endl;
	return stream;
}
