#pragma once
#include "stdafx.h"

#include "DatabaseEntity.h"
#include <iostream>
#include <fstream>
#include <sstream>   
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;


class CrudRepository
{
public:
	vector<DatabaseEntity> virtual getAll();
	DatabaseEntity virtual getById(int id);

	void virtual create(DatabaseEntity entity);

	void virtual update(DatabaseEntity entity);

	void virtual deleteById(int id);
	void virtual deleteAll();

	CrudRepository();
	~CrudRepository();
};

