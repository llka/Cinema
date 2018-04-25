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
	double rating;
	double ticketCost;
public:
	Film( );
	Film(int filmId1, string title1, string description1, double rating1, double ticketCost1);
	Film(Film * film);
	~Film( );

	void setFilmId(int id);
	void setTitle(string title1);
	void setDescription(string description1);
	void setRating(double rating1);
	void setTicketCost(double ticketCost1);

	int getFilmId( );
	string getTitle( );
	string getDescription();
	double getRating();
	double getTicketCost( );

	void  write(Film entity);
	DatabaseEntity  read();

	friend  ostream &operator<< (ostream &stream, Film film);
	friend  istream &operator>> (istream &stream, Film &film);
};

