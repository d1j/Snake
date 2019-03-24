#pragma once
#include <iostream>
#include <vector>
#include "variklis.h"
#include "funkcijos.h"


class variklis
{
public:
	struct koord
	{
		int x;
		int y;
		char simb;
	};
	variklis(int, int);
	bool judejimas(int, int xPos = 0, int yPos = 0);
	void sukurimas();
	void spausdinimas();
	void setBody(char, char, char);
	void generuoklis();
	bool tikrinimasOb(int);
	bool tikrinimasCol(int);
	void zaidimas(int);
	void matmenuSet(int, int);
	void lentaSet(char, char, char);
	int getY();

private:
	funkcijos ob;

	//lenta
	int ilgis, plotis;
	char lenta[22][60];

	//galvos ir uodegos koordinates
	koord galva, uodega, papildomas, papildomesnis, obuolys;
	char kunoSimb, sonai, vidus, obolys;
	

	//kryptis kuria juda gyvatele
	//1 - virsus
	//2 - apacia
	//3 - kaire
	//4 - desine
	int kryptis = 4;

	//Gyvateles kunas lenteleje
	std::vector<koord> kunas;

};
