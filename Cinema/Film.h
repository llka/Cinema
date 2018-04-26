#pragma once
#include "DatabaseEntity.h"
#include <string>

using namespace std;

class Film:
	public DatabaseEntity {
private:
	int filmId;
	string title;
	string description;
	int year;
	string country;
	int durationInMinutes;
	double rating;
	double ticketCost;
public:
	Film( );
	Film(int filmId1, string title1, string description1,int year1, string country1, int duration,  double rating1, double ticketCost1);
	Film(Film * film);
	~Film( );

	void setFilmId(int id);
	void setTitle(string title1);
	void setDescription(string description1);
	void setRating(double rating1);
	void setTicketCost(double ticketCost1);
	void setYear(int year1);
	void setCountry(string country1);
	void setDurationInMinutes(int minutes);

	int getFilmId( );
	string getTitle( );
	string getDescription();
	double getRating();
	double getTicketCost( );
	int getYear();
	string getCountry();
	int getDurationInMinutes();

	void  write(string fileName);
	DatabaseEntity  read(string fileName);

	friend  ostream &operator<< (ostream &stream, Film film);
	friend  istream &operator>> (istream &stream, Film &film);
};

