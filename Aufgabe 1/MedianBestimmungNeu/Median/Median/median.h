#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class median
{
public:
	median();
	~median();
	void einlesen();
	int medianBerechnung();
private:
	void vertausche(int&, int&);
	int spalteAuf(int, int, int);

	int laenge = 0;
	int werte[250000];
	int k;
};

