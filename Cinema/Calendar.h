#pragma once
#include "stdafx.h"
#include "DatabaseEntity.h"
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

class Calendar:
	public DatabaseEntity {
private:

public:
	void write( string fileName);
	DatabaseEntity read(string fileName);

	Calendar( );
	~Calendar( );
};

