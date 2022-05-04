/*
	Klasa: Macierz
	Opis: Program mno¿¹cy macierze o wymiarze 2x2
	Autor: Kacper Morawski
	Data Utworzenia: 15.10.2018r.
	Data edytowania: 29.10.2018r.

*/

#ifndef  MACIERZ_H_
#define MACIERZ_H_

#include <iostream>

class macierz
{

	int ilosc_kolumn;
	int ilosc_wierszy;
	double **wartosc;

public:
	macierz();
	~macierz();
	void view();										//metoda pomocnicza do wyswietlania macierzy
	void set(int k, int w, double wynik);				//metoda do wstawiania parametrow macierzy
	macierz(const macierz & A);							//konstruktor kopiujacy
	macierz& operator =(const macierz & Z);				//operator przyrownania wartosci macierzy
	const macierz operator *(const macierz &M);			//operator mnozacy macierze
	bool operator ==(const macierz & P);				//przyrownuje macierze do siebie i sprawdza czy sa takie same
};

#endif // ! MACIERZ_H_
