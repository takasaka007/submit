#pragma once

#include "config.h"


class Finish
{
public:
	Finish();
	~Finish();

	void draw();
	void setup(Handle* handle, Num* num);
private:
	Handle* handle;
	Num* num;



};

