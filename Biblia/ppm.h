///////////////////////////////////////////////////////////////////////////////////////////////
//
//Klasa: ppm.h
//Opis: Klasa liczaca unikalne kolory w obrazie o rozszerzeniu ppm
//Autor: Kacper Morawski
//Data Utworzenia: 10.12.2018r.
//Data edytowania: 22.01.2019r.
//
///////////////////////////////////////////////////////////////////////////////////////////////


#if !defined (ppm_h)
#define ppm_h

#include "obraz.h"

class ppm : public obraz
{
public:
	ppm();										//konstruktor bezparametrowy
	ppm(const std::string & nazwa);				//konstruktor parametrowy
	ppm(const ppm &k);							//konstruktor kopiujacy
	~ppm();										//destruktor

	ppm & operator =(const ppm & porow);		//przeciazenie operatora = dla klasy ppm

	int liczunik();								//metoda zliczajaca ilosc unikalnych kolorow dla klasy ppm
};

#endif