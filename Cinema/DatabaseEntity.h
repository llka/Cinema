#pragma once
class DatabaseEntity {
public:
	void virtual write(DatabaseEntity entity);
	DatabaseEntity virtual read();
	DatabaseEntity( );
	~DatabaseEntity( );
};

