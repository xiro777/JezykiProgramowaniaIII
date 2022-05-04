///////////////////////////////////////////////////////////////////////////////////////////////
//
//Klasa: color.h
//Opis: klasa przechowywujaca kolory dla danego pixela
//Autor: Kacper Morawski
//Data Utworzenia: 10.12.2018r.
//Data edytowania: 22.01.2019r.
//
///////////////////////////////////////////////////////////////////////////////////////////////



#if !defined (color_h)
#define color_h

#include <fstream>


class color
{
public:
	color();																//konstruktor bezparametrowy
	color(short x, short y, short z);										//konstruktor parametrowy
	color(const color & k);													//konstruktor kopiujacy
	~color();																//destruktor

	color & operator=(const color & porow);									//przeciazenie operatora przyrownania dla klasy color
	friend std::ofstream & operator <<(std::ofstream & o, const color & k);	//przeciazenie operatora << dla klasy color
	bool friend operator < (const color & o, const color & k);				// przeciazenie operatora mniejszosci 

	short getR() const;														//metoda pozyskujaca skladowy kolor red
	short getG() const;														//metoda pozyskujaca skladowy kolor green														
	short getB() const;														//metoda pozyskujaca skladowy kolor	blue


	short r, g, b;	//skladowe klasy kolor
};

#endif