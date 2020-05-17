#pragma once

#include "config.h"

class Menu
{
public:
	Menu();
	~Menu();

	void draw();

	void setup(Handle* handle,Num* num);


private:
	Handle* handle;
	Num* num;
};

