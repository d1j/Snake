#include <iostream>
#include <windows.h>
#include <vector>
#include "variklis.h"
#include "funkcijos.h"
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std;

#define KB_UP 72
#define KB_LEFT 75
#define KB_DOWN 80
#define KB_RIGHT 77


variklis::variklis (int length, int width)
	:ilgis(length), plotis(width)
{
}

void variklis::matmenuSet(int length, int width)
{
	ilgis = length; plotis = width;
}

void variklis::setBody(char head, char body, char butt)
{
	galva.simb = head;
	galva.x = 3;
	galva.y = 2;

	uodega.simb = butt;
	uodega.x = 2;
	uodega.y = 2;


	kunas.push_back(uodega);
	kunas.push_back(galva);

	kunoSimb = body;
	
}

void variklis::lentaSet(char edge, char inner, char apple)
{
	sonai = edge;
	vidus = inner;
	obolys = apple;
}

void variklis::generuoklis()
{
	srand((unsigned int)time(NULL));
	bool power = true;
	int x, y;

	while (power)
	{
		x = rand() % (ilgis - 2) + 1;
		y = rand() % (plotis - 2) + 1;

		for (unsigned i = 0; i < kunas.size(); i++)
		{
			if (kunas[i].x != x && kunas[i].y != y)
			{
				power = false;
			}
		}
	}

	obuolys.x = x;
	obuolys.y = y;
	obuolys.simb = obolys;

}

void variklis::sukurimas()
{
	for (int i = 0; i < plotis; i++)
	{
		for (int j = 0; j < ilgis; j++)
		{
			if (i == galva.y && j == galva.x)
			{
				lenta[i][j] = galva.simb;
			}
			else if (i == uodega.y && j == uodega.x)
			{
				lenta[i][j] = uodega.simb;
			}
			else if (i == obuolys.y && j == obuolys.x)
			{
				lenta[i][j] = obuolys.simb;
			}
			else if (i == 0 || i + 1 == plotis || j == 0 || j + 1 == ilgis)
			{
				lenta[i][j] = sonai;
			}
			else
				lenta[i][j] = vidus;
		}
	}
}

void variklis::spausdinimas()
{
	for (int i = 0; i < plotis; i++)
	{
		for (int j = 0; j < ilgis; j++)
		{
			std::cout << lenta[i][j];
		}
		std::cout << endl;
	}
}

//kryptis kuria juda gyvatele
//1 - virsus
//2 - apacia
//3 - kaire
//4 - desine
bool variklis::tikrinimasOb(int direct)
{
	switch (direct)
	{
	case 1:
		if (kunas.back().x == obuolys.x && kunas.back().y - 1 == obuolys.y)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 2:
		if (kunas.back().x == obuolys.x && kunas.back().y + 1 == obuolys.y)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 3:
		if (kunas.back().x - 1 == obuolys.x && kunas.back().y == obuolys.y)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 4:
		if (kunas.back().x + 1 == obuolys.x && kunas.back().y == obuolys.y)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	default:
		return false;
		break;

	}
}

//kryptis kuria juda gyvatele
//1 - virsus
//2 - apacia
//3 - kaire
//4 - desine
bool variklis::tikrinimasCol(int direct)
{
	bool graza = false;

	switch (direct)
	{
	case 1:
		if (kunas.back().y == 0)
		{
			graza = true;
		}
		else if (1)
		{
			for (unsigned int i = 0; i < kunas.size() - 1; i++)
			{
				if (kunas.back().x == kunas[i].x && kunas.back().y == kunas[i].y)
				{
					graza = true;
				}
			}
		}
		break;
	case 2:
		if (kunas.back().y == plotis - 1)
		{
			graza = true;
		}
		else if (1)
		{
			for (unsigned int i = 0; i < kunas.size() - 1; i++)
			{
				if (kunas.back().x == kunas[i].x && kunas.back().y == kunas[i].y)
				{
					graza = true;
				}
			}
		}
		break;
	case 3:
		if (kunas.back().x == 0)
		{
			graza = true;
		}
		else if (1)
		{
			for (unsigned int i = 0; i < kunas.size() - 1; i++)
			{
				if (kunas.back().x == kunas[i].x && kunas.back().y == kunas[i].y)
				{
					graza = true;
				}
			}
		}
		break;
	case 4:
		if (kunas.back().x == ilgis - 1)
		{
			graza = true;
		}
		else if (1)
		{
			for (unsigned int i = 0; i < kunas.size() - 1; i++)
			{
				if (kunas.back().x == kunas[i].x && kunas.back().y == kunas[i].y)
				{
					graza = true;
				}
			}
		}
		break;
	default:
		break;
	}

	return graza;

}

bool variklis::judejimas(int direct, int xPos, int yPos)
{
	if (tikrinimasOb(direct))
	{
		kunas.push_back(obuolys);
		kunas.back().simb = galva.simb;
		ob.refreshXY(kunas.back().x, kunas.back().y);
		std::cout << kunas.back().simb;

		kunas[kunas.size() - 2].simb = kunoSimb;
		ob.refreshXY(kunas[kunas.size() - 2].x, kunas[kunas.size() - 2].y);
		std::cout << kunas[kunas.size() - 2].simb;

		generuoklis();
		ob.refreshXY(obuolys.x, obuolys.y);
		std::cout << obuolys.simb;
	}
	else 
	{
		for (unsigned int i = kunas.size(); i > 0; i--)
		{
			//perkeliama gyvateles pradzia    VEIKIA
			if (i == kunas.size())
			{
				papildomas = kunas[i - 1];
				kunas[i - 1].x += xPos;
				kunas[i - 1].y += yPos;

				/*ob.refreshXY(kunas[i - 1].x, kunas[i - 1].y);
				std::cout << kunas[i - 1].simb;*/
			}
			//perkeliamas gyvateles galas
			else if (i - 1 == 0)
			{
				//jei kunas is dvieju daliu sudarytas VEIKIA
				if (kunas.size() == 2)
				{
					ob.refreshXY(kunas[i - 1].x, kunas[i - 1].y);
					std::cout << vidus;

					kunas[i - 1].x = papildomas.x;
					kunas[i - 1].y = papildomas.y;

					/*ob.refreshXY(kunas[i - 1].x, kunas[i - 1].y);
					std::cout << kunas[i - 1].simb;*/
				}
				else  // KLAUSIMAS AR VEIKIA
				{
					ob.refreshXY(kunas[i - 1].x, kunas[i - 1].y);
					std::cout << vidus;

					kunas[i - 1].x = papildomas.x;
					kunas[i - 1].y = papildomas.y;

					/*ob.refreshXY(kunas[i - 1].x, kunas[i - 1].y);
					std::cout << kunas[i - 1].simb;*/
				}


			}
			//perkeliamas gyvateles vidurys //KLAUSIMAS AR VEIKIA
			else
			{
				papildomesnis.x = kunas[i - 1].x;
				papildomesnis.y = kunas[i - 1].y;

				kunas[i - 1].x = papildomas.x;
				kunas[i - 1].y = papildomas.y;

				papildomas.x = papildomesnis.x;
				papildomas.y = papildomesnis.y;

				/*ob.refreshXY(kunas[i - 1].x, kunas[i - 1].y);
				std::cout << kunas[i - 1].simb;*/


			}
		}

		if (tikrinimasCol(direct))
		{
			return false;
		}
		
			kunas[kunas.size() - 2].simb = kunoSimb;
			ob.refreshXY(kunas[kunas.size() - 2].x, kunas[kunas.size() - 2].y);
			std::cout << kunas[kunas.size() - 2].simb;

			kunas.front().simb = uodega.simb;
			ob.refreshXY(kunas.front().x, kunas.front().y);
			std::cout << uodega.simb;

			kunas.back().simb = galva.simb;
			ob.refreshXY(kunas.back().x, kunas.back().y);
			std::cout << galva.simb;

	}
	
	return true;
}

void variklis::zaidimas(int sunkumas)
{
	int paskutineKryp = KB_RIGHT, kryptis = KB_RIGHT;
	bool power = true;
	int key;
	int timer(0);

	while (power)
	{
		if (_kbhit())
		{
			key = _getch();

			switch (key)
			{
			case KB_UP:
				if (paskutineKryp != KB_DOWN)
				{
					kryptis = KB_UP;
					paskutineKryp = KB_UP;
				}
				break;
			case KB_DOWN:
				if (paskutineKryp != KB_UP)
				{
					kryptis = KB_DOWN;
					paskutineKryp = KB_DOWN;
				}
				break;
			case KB_LEFT:
				if (paskutineKryp != KB_RIGHT)
				{
					kryptis = KB_LEFT;
					paskutineKryp = KB_LEFT;
				}
				break;
			case KB_RIGHT:
				if (paskutineKryp != KB_LEFT)
				{
					kryptis = KB_RIGHT;
					paskutineKryp = KB_RIGHT;
				}
				break;
			default:
				break;
			}
		}

		if (timer == sunkumas)
		{
			switch (kryptis)
			{
			case KB_UP:
				power = judejimas(1, 0, -1);
				break;
			case KB_DOWN:
				power = judejimas(2, 0, 1);
				break;
			case KB_LEFT:
				power = judejimas(3, -1, 0);
				break;
			case KB_RIGHT:
				power = judejimas(4, 1, 0);
				break;
			default:
				break;
			}
			timer = 0;
		}

		timer++;
	}
	kunas.clear();
}

