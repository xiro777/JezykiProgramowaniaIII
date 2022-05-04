#include "ppm.h"
#include <set>
#include <iostream>



ppm::ppm()
{

}

ppm::ppm(const std::string & nazwa) : obraz(nazwa)
{

}

ppm::~ppm()
{

}

ppm::ppm(const ppm & k)
{
	this->wiersz = k.wiersz;
	this->kolumna = k.kolumna;
	this->zakreskoloru = k.zakreskoloru;
	this->pixel = k.pixel;
	this->typ = k.typ;
}

ppm & ppm ::operator=(const ppm & porow)
{
	if (this != &porow)
	{
		this->wiersz = porow.wiersz;
		this->kolumna = porow.kolumna;
		this->zakreskoloru = porow.zakreskoloru;
		this->pixel = porow.pixel;
		this->typ = porow.typ;
	}
	return *this;
}

int ppm::liczunik()
{
	int *tymczasowaTab = new int[kolumna*wiersz];													

	int i = 1;

	std::set < int > zbior;

	while (tymczasowaTab[i] != '\0')
	{
		tymczasowaTab[i] = ((pixel[i].r << 16) + pixel[i].g << 8 + pixel[i].b);
		zbior.insert(tymczasowaTab[i]);
		i++;
	}

	int wynik = zbior.size();
	return wynik;
}