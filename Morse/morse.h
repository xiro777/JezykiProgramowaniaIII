/*
	Klasa: Alfabet Morse'a
	Opis: Program majacy na celu convertowanie tekstu/cyfr na alfabet morsa, ktory pika znaki
	Autor: Kacper Morawski
	Data Utworzenia: 29.10.2018r.
	Data edytowania: 18.11.2018r.

*/



#ifndef _morse_h
#define _morse_h


#include <Windows.h>
#include <string>

class morse
{

	int _frequency, _dottime, _dashtime, _pause, _spacepause, _charpause;


public:
	morse();																			//konsturktor parametrowy
	morse(const morse &kopiujacy);														//konstruktor kopiujacy
	~morse();																			//destruktor

	void setFrequency(int _frequency);													//settery ustawiajace wlasnosci morse
	void setDotTime(int _dottime);														//^
	void setDashTime(int _dashtime);													//^
	void setPause(int _pause);															//^
	void setSpacePause(int _spacepause);												//^
	void setCharPause(int _charpause);													//^


	const int getFrequency();															//gettery morse
	const int getDotTime();																//^
	const int getDashTime();															//^
	const int getPause();																//^
	const int getSpacePause();															//^
	const int getCharPause();															//^
	

	morse & operator = (const morse &objekt);											//operator przypisania
	friend void operator << (morse& t, const char *tab);							    //operator przesuniecia bitowego przekszta³caj¹cy tekst na morse'a
	morse operator << (const long longg);												//operator przesuniecia bitowego przeksztalcajacy liczbe z longa na morse'a					
	morse operator << (const double doublee);											//operator przesuniecia bitowego przeksztalcajacy liczbe z double na morse'a


};


std::string converter(char nr_converter);												//funckja string zawierajaca alfabet morsa
#endif