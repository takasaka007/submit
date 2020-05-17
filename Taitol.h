#pragma once
#include "config.h"


class Taitol
{
public:
	Taitol();
	~Taitol();

	void draw();
	void setup(Handle* handle,Num* num);
private:
	Handle* handle;
	Num* num;

};

