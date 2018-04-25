#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

class DatabaseEntity {
public:
	/*write object in file*/
	void virtual write(string fileName);
	DatabaseEntity virtual read(string fileName);

	DatabaseEntity( );
	~DatabaseEntity( );
};

