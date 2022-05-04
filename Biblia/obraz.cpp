#include "obraz.h"
#include <iostream>


obraz::obraz():
	wiersz(0)
	,kolumna(0)
	,pixel(NULL)
	,typ("niezdefiniowany")
	,plik("niezdefiniowany")
	,zakreskoloru(0)
{

}

obraz::obraz(const std::string & nazwa) : plik(nazwa)
{

	if (!plik.is_open())
	{
		std::cerr << "Plik nie moze zostac zaladowany";

	}
	else
	{

		plik >> typ;															//pobiera pierwsza linie
		//Brak wpisywania komentarza z obrazu
		plik >> wiersz;															//pobiera linie z wierszem
		plik >> kolumna;														//pobiera linie z kolumna
		plik >> zakreskoloru;													//pobiera linie z zakresem z pliku

		pixel = new color[kolumna*wiersz];										//tworzy tablice pixel

		int tymczasowa = 0;

		while (tymczasowa != (kolumna*wiersz))									//sprawdza czy zmienna rozni sie od wielkosci
		{

			plik >> (pixel[tymczasowa].r);										//zczytuje pierwszy kolor r
			plik >> (pixel[tymczasowa].g);										//zczytuje pierwszy kolor g	
			plik >> (pixel[tymczasowa].b);										//zczytuje pierwszy kolor b

			tymczasowa++;
		}

	}
	plik.close();
}

obraz::~obraz()
{
	delete[]pixel;
}

obraz::obraz(const obraz & k)
{
	this->wiersz = k.wiersz;
	this->kolumna = k.kolumna;
	this->zakreskoloru = k.zakreskoloru;
	this->pixel = k.pixel;
	this->typ = k.typ;
}

obraz & obraz ::operator=(const obraz & porow)
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

int obraz::getWiersz() const
{
	return wiersz;
}

int obraz::getKolumna() const
{
	return kolumna;
}

std::string obraz::getTyp() const
{
	return typ;
}

int obraz::getZakresKoloru() const
{
	return zakreskoloru;
}

int obraz::getWielkosc() const
{
	return (kolumna*wiersz);
}

color obraz::getPixel(int x) const
{
	return pixel[x];
}

void obraz::setKolumna(int k)
{
	this->kolumna = k;
}

void obraz::setWiersz(int w)
{
	this->wiersz = w;
}

void obraz::setTyp(const std::string & t)
{
	this->typ = t;
}

void obraz::setZakresKoloru(int zk)
{
	this->zakreskoloru = zk;
}