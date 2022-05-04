#include <iostream>
#include "ppm.h"
#include "freqcounter.h"
#include <set>
#include <ctime>

int main()
{
	//OBLICZANIE FREQUENCY DLA CHAROW
	freqcounter <char> fc_ch;
	std::multiset<char> znak;
	//std::fstream plik("biblia-en.txt", std::ios::in);
	//std::fstream plik("biblia-it.txt", std::ios::in);
	std::fstream plik("biblia-pl_ksiega_rdzaju.txt", std::ios::in);
	//std::fstream plik("biblia-pl_ksiega_rdzaju_3.txt", std::ios::in);

	char tymczasowaC;
	while (!plik.eof())
	{
		plik >> tymczasowaC;
		znak.insert(tymczasowaC);
	}
	plik.close();

	for (auto it = znak.begin(); it != znak.end(); it++)
	{
		fc_ch.addData(*it);
	}
	fc_ch.create();
	///////////////////////////////////////////////////////////////////////////

		//OBLICZANIE FREQUENCY DLA RANDA

	freqcounter<int> fc_i;
	srand(time(NULL));

	int i = 0;
	while (i != 1000000)
	{
		fc_i.addData(rand() % 1000);
		i++;
	}
	fc_i.create();

	//////////////////////////////////////////////////////////////////////////

		//OBLICZANIE FREQUENCY DLA STRINGA

	freqcounter<std::string> fc_s;
	std::multiset<std::string> slowo;
	std::fstream plik2("biblia-it.txt", std::ios::in);
	//std::fstream plik2("biblia-en.txt", std::ios::in);
	//std::fstream plik2("biblia-pl_ksiega_rdzaju.txt", std::ios::in);
	//std::fstream plik2("biblia-pl_ksiega_rdzaju_3.txt", std::ios::in);

	std::string tymczasowaS;

	while (!plik2.eof())
	{
		plik2 >> tymczasowaS;
		slowo.insert(tymczasowaS);
	}
	plik2.close();

	for (auto it = slowo.begin(); it != slowo.end(); it++)
	{
		fc_s.addData(*it);
	}
	fc_s.create();

	////////////////////////////////////////////////////////////////////////////

		//OBLICZANIE FREQUENCY KOLOROW W OBRAZIE
	freqcounter<color> fc_c;
	obraz* obraz1 = new ppm("Lena.ppm");

	for (int i = 0; i < obraz1->getWielkosc(); i++)
	{
		fc_c.addData(obraz1->getPixel(i));
	}
	fc_c.create();

	delete[] obraz1;
	///////////////////////////////////////////////////////////////////////////

	return 0;

}