#pragma once
#include "Nustatymai.h"
#include "Funkcijos.h"
#include "variklis.h"
#include <iostream>

class Nustatymai
{
public:
	Nustatymai();
	void meniu();
	void play();
	void settings();
	void lentosKonf();
	void gyvatesKonf();
private:
	int ilgis = 60, plotis = 22;
	char galva = 1, kunas = 3, uodega = 2;
	int sunkumas = 5;
	char isore = '#', vidus = '.', obuolys = '@';
	funkcijos fun;

};

