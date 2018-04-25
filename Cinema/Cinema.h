#pragma once
#include "DatabaseEntity.h"
#include <string>

using namespace std;

class Cinema:
	public DatabaseEntity {
private:
	int cinemaId;
	string title;
	int placesCount;
public:
	Cinema();
	Cinema(int id, string title, int places);
	Cinema(Cinema *cinema);
	~Cinema( );

	void setCinemaId(int id);
	void setTitle(string title);
	void setPlacesCount(int places);

	int getCinemaId( );
	string getTitle( );
	int getPlacesCount( );

	void  write(Cinema entity);
	DatabaseEntity  read();

	friend  ostream &operator<< (ostream &stream, Cinema cinema);
	friend  istream &operator>> (istream &stream, Cinema &cinema);
};

