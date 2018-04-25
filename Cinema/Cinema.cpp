#include "stdafx.h"
#include "Cinema.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <list>
#include <Windows.h>
#include <conio.h>


using namespace std;

Cinema::Cinema( ) {}

Cinema::Cinema(int id, string title1, int places) {
	cinemaId = id;
	title = title1;
	placesCount = places;
}

Cinema::Cinema(Cinema * cinema) {
	cinemaId = cinema->cinemaId;
	title = cinema->title;
	placesCount = cinema->placesCount;
}

Cinema::~Cinema( ) {}

void Cinema::setCinemaId(int id) {
	cinemaId = id;
}

void Cinema::setTitle(string title1) {
	title = title1;
}

void Cinema::setPlacesCount(int places) {
	placesCount = places;
}

int Cinema::getCinemaId( ) {
	return cinemaId;
}

string Cinema::getTitle( ) {
	return title;
}

int Cinema::getPlacesCount( ) {
	return placesCount;
}

void Cinema::write(string fileName) {
	ofstream fout(fileName, ios::app);
	fout << " , " << cinemaId << " , " << title << " , " << placesCount << " . "<< endl;
}

DatabaseEntity Cinema::read(string fileName) {
	ifstream fin(fileName);
	Cinema cinema;
	fin >> cinema.cinemaId >> cinema.title >> cinema.placesCount;
	return cinema;
}

ostream & operator<<(ostream & stream, Cinema cinema) {
	stream << "Cinema{ id=" << cinema.cinemaId << ", title=" << cinema.title << ", places=" << cinema.placesCount << "}" << endl;
	return stream;
}

istream & operator>>(istream & stream, Cinema & cinema) {
	cout << "Input cinema" << endl;
	cout << "cinemaId :" << endl;
	stream >> cinema.cinemaId;
	cout << "title :" << endl;
	stream >> cinema.title;
	cout << "places count :" << endl;
	stream >> cinema.placesCount;
	cout <<  endl;
	return stream;
}
