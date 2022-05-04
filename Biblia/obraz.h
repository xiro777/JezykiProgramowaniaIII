///////////////////////////////////////////////////////////////////////////////////////////////
//
//Klasa: obraz.h
//Opis: Czyta dane na temat obrazu z pliku / operuje na nich
//Autor: Kacper Morawski
//Data Utworzenia: 10.12.2018r.
//Data edytowania: 22.01.2019r.
//
///////////////////////////////////////////////////////////////////////////////////////////////




#if !defined (obraz_h)
#define obraz_h

#include <string>
#include <fstream>
#include "color.h"

class obraz
{
public:
	obraz();										//konstruktor bezparametrowy
	obraz(const std::string & nazwa);				//konstruktor parametrowy
	obraz(const obraz & k);							//konstruktor kopiujacy
	virtual ~obraz();								//wirutalny destruktor

	obraz & operator = (const obraz & porow);		//operator przyrównania
	virtual int liczunik() = 0;						//metoda wirtualna  liczaca unikalne kolory

	int getWiersz() const;							//getter pozycji wiersza
	int getKolumna() const;							//getter pozycji kolumny
	int getWielkosc() const;						//getter ilosci kolorow
	std::string getTyp() const;						//getter typu koloru
	int getZakresKoloru() const;					//getter pobierajacy maksymalna wartosc dla koloru rgb
	color getPixel(int x) const;					//metoda pozyskujaca pixel

	void setWiersz(int w);							//setter wierszy
	void setKolumna(int k);							//setter kolumn
	void setTyp(const std::string & t);				//setter typu obrazu
	void setZakresKoloru(int zk);					//setter maksymalnej wartosci dla koloru rgb

protected:
	int wiersz;
	int kolumna;
	std::string typ;
	std::fstream plik;
	int zakreskoloru;
	color* pixel;
};

#endif