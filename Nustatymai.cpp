#include "Nustatymai.h"
#include "Variklis.h"
#include "Funkcijos.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

#define KB_UP 72
#define KB_LEFT 75
#define KB_DOWN 80
#define KB_RIGHT 77
#define ENTER 13

Nustatymai::Nustatymai()
{
}

void Nustatymai::play()
{
	fun.screenCL(4);
	variklis var(ilgis, plotis);
	var.setBody(galva, kunas, uodega);
	var.lentaSet(isore, vidus, obuolys);
	var.generuoklis();
	var.sukurimas();
	var.spausdinimas();
	var.zaidimas(sunkumas*1000);

	Sleep(1000);

	fun.refreshXY(0, plotis);
	cout << "Woops, looks like you lost :(" << endl;
	system("pause");

	fun.screenCL(plotis+2);

	cout << "~~~~~~~~SNAKE~~~~~~~~\n";
	cout << " Play\n";
	cout << " Settings\n";
	cout << " Exit";


}

void Nustatymai::gyvatesKonf()
{
	fun.screenCL(5);
	bool power = true;
	int rodiklis = 1;
	cout << "~~~~~~~~SnakeSettings~~~~~~~~\n";
	cout << " Head symbol"; fun.refreshXY(25, 1); cout << galva << endl;
	cout << " Body symbol\n"; fun.refreshXY(25, 2); cout << kunas << endl;
	cout << " Tail symbol\n"; fun.refreshXY(25, 3); cout << uodega << endl;
	cout << " Back";

	while (power)
	{
		fun.refreshXY(0, rodiklis);

		switch (_getch())
		{
		case KB_UP:
			if (rodiklis == 1)
			{
				rodiklis = 4;
			}
			else
				rodiklis--;
			break;
		case KB_DOWN:
			if (rodiklis == 4)
			{
				rodiklis = 1;
			}
			else
				rodiklis++;
			break;
		case ENTER:
			switch (rodiklis)
			{
			case 1:
				fun.refreshXY(25, 1);
				cout << " ";
				fun.refreshXY(25, 1);

				cin >> galva;
				break;
			case 2:
				fun.refreshXY(25, 2);
				cout << " ";
				fun.refreshXY(25, 2);

				cin >> kunas;
				break;
			case 3: 
				fun.refreshXY(25, 3);
				cout << " ";
				fun.refreshXY(25, 3);

				cin >> uodega;
				break;
			case 4:
				power = false;

				fun.screenCL(5);
				cout << "~~~~~~~~Settings~~~~~~~~\n";
				cout << " Set game board\n";
				cout << " Set Snake\n";
				cout << " Level difficulty"; fun.refreshXY(25, 3); cout << sunkumas << endl;
				cout << " Back";

				break;
			}
		}
	}
}

void Nustatymai::lentosKonf()
{
	fun.screenCL(5);
	bool power = true;
	int rodiklis = 1;

	cout << "~~~~~~~~BoardSettings~~~~~~~~\n";
	cout << " Lenght"; fun.refreshXY(25, 1); cout << ilgis << endl;
	cout << " Width"; fun.refreshXY(25, 2); cout << plotis << endl;
	cout << " Border symbol"; fun.refreshXY(25, 3); cout << isore << endl;
	cout << " Inside-board symbol"; fun.refreshXY(25, 4); cout << vidus << endl;
	cout << " Apple symbol"; fun.refreshXY(25, 5); cout << obuolys << endl;
	cout << " Back";

	while (power)
	{
		fun.refreshXY(0, rodiklis);

		switch (_getch())
		{
		case KB_UP:
			if (rodiklis == 1)
			{
				rodiklis = 6;
			}
			else
				rodiklis--;
			break;
		case KB_DOWN:
			if (rodiklis == 6)
			{
				rodiklis = 1;
			}
			else
				rodiklis++;
			break;
		case ENTER:
			switch (rodiklis)
			{
			case 1:
				blogai1:
				fun.refreshXY(25, 1);
				cout << "  ";

				fun.refreshXY(0, 8);
				cout << "Length must be between 20 and 60 blocks!!!";

				fun.refreshXY(25, 1);
				cin >> ilgis;

				if (ilgis < 20 || ilgis>60)
				{
					goto blogai1;
				}
				else
				{
					fun.refreshXY(0, 8);
					cout << "                                              ";
				}
				break;
			case 2:
				blogai2:
				fun.refreshXY(25, 2);
				cout << "  ";

				fun.refreshXY(0, 8);
				cout << "Width must be between 12 and 22 blocks!!!";

				fun.refreshXY(25, 2);
				cin >> plotis;

				if (plotis < 12 || plotis > 22)
				{ 
					goto blogai2;
				}
				else
				{
					fun.refreshXY(0, 8);
					cout << "                                              ";
				}
				break;
			case 3:
				fun.refreshXY(25, 3);
				cout << " ";
				fun.refreshXY(25, 3);

				cin >> isore;
				break;
			case 4:
				fun.refreshXY(25, 4);
				cout << " ";
				fun.refreshXY(25, 4);

				cin >> vidus;
				break;
			case 5:
				fun.refreshXY(25, 5);
				cout << " ";
				fun.refreshXY(25, 5);

				cin >> obuolys;
				break;
			case 6:
				power = false;

				fun.screenCL(7);
				cout << "~~~~~~~~Settings~~~~~~~~\n";
				cout << " Set game board\n";
				cout << " Set Snake\n";
				cout << " Level difficulty"; fun.refreshXY(25, 3); cout << sunkumas << endl;
				cout << " Back";

				break;
			}
		default:
			break;
		}
	}
}

void Nustatymai::settings()
{
	fun.screenCL(4);
	bool power = true;
	int rodiklis = 1;

	cout << "~~~~~~~~Settings~~~~~~~~\n";
	cout << " Set game board\n";
	cout << " Set Snake\n";
	cout << " Level difficulty"; fun.refreshXY(25, 3); cout << sunkumas << endl;
	cout << " Back";

	while (power)
	{
		fun.refreshXY(0, rodiklis);

		switch (_getch())
		{
		case KB_UP:
			if (rodiklis == 1)
			{
				rodiklis = 4;
			}
			else
			{
				rodiklis--;
			}
			break;
		case KB_DOWN:
			if (rodiklis == 4)
			{
				rodiklis = 1;
			}
			else
			{
				rodiklis++;
			}
			break;
		case ENTER:
			switch (rodiklis)
			{
			case 1:
				lentosKonf();
				break;
			case 2:
				gyvatesKonf();
				break;
			case 3:
				blogai:
					fun.refreshXY(25, 3);
					cout << "    ";

					fun.refreshXY(0, 8);
					cout << "Difficulty must be from 1 to 10!!!"<<endl;
					cout << "Lower number means higher difficulty!" << endl;

					fun.refreshXY(25, 3);
					cin >> sunkumas;

					if (sunkumas < 1 || sunkumas>10)
					{
						goto blogai;
					}
					else
					{
						fun.refreshXY(0, 8);
						cout << "                                              " << endl;
						cout << "                                              ";
					}
				break;
			case 4:
				power = false;

				fun.screenCL(5);
				cout << "~~~~~~~~SNAKE~~~~~~~~\n";
				cout << " Play\n";
				cout << " Settings\n";
				cout << " Exit";

				break;
			}
			break;
		default:
			break;
		}
	}
}

void Nustatymai::meniu()
{
	system("cls");
	bool power = true;
	int rodiklis = 1;

	cout << "~~~~~~~~SNAKE~~~~~~~~\n";
	cout << " Play\n";
	cout << " Settings\n";
	cout << " Exit";

	while (power)
	{
		fun.refreshXY(0, rodiklis);

		switch (_getch())
		{
		case KB_UP:
			if (rodiklis == 1)
			{
				rodiklis = 3;
			}
			else
			{
				rodiklis -= 1;
			}
			break;
		case KB_DOWN:
			if (rodiklis == 3)
			{
				rodiklis = 1;
			}
			else
			{
				rodiklis += 1;
			}
			break;
		case ENTER:
			switch (rodiklis)
			{
			case 1:
				play();
				break;
			case 2:
				settings();
				break;
			case 3:
				power = false;
				break;
			}
			break;
		default:
			break;
		}
	}
}
