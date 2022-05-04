/*
Klasa: Edit
Opis: Deklaracja getterow, setterow oraz wszystkich funkcji potrzebnych do obslugi konsoli
Autor: Kacper Morawski
Data Utworzenia: 26.11.2018r.
Data edytowania: 09.12.2018r.

*/


#ifndef EDIT_H
#define EDIT_H

#include <Windows.h>
#include <string> 
#include <iostream>
#include <conio.h>

class Edit
{
public:

	enum Color											//Enumerator kolorow
	{
		Black = 0,
		Gray = 8,
		Blue = 1,
		Green = 2,
		Aqua = 3,
		Red = 4,
		Purple = 5,
		Yellow = 6,
		White = 15,
	};

	///////////////////////////////////////////////////////////////////////////////////////////////////

	Edit();												//Konstruktor bezparametrowy
	Edit(short x, short y, int dlugosc, std::string tekst, Color tekstcolor, Color backgcolor);
	//Konstuktor parametrowy ^^
	Edit(Edit & kopiujacy);								//Konstruktor kopiujacy
	Edit operator =(const Edit &A);						//operator =
	~Edit();											//Dekstruktor nic nie robiacy

	//SETTERY//////////////////////////////////////////////////////////////////////////////////////////

	void setPosition(int x, int y);						//Setter pozycji textboxa			
	void setLenght(int dlu);							//Setter dlugosci tekstu w textboxie
	void setText(std::string txt);						//Setter tekst textboxa
	void setTextColor(Color kolor_txt);					//Setter kolor tekstu textboxa
	void setBackgroundColor(Color back_kolor);			//Setter koloru tla textboxa

	///////////////////////////////////////////////////////////////////////////////////////////////////

	void display();										//Metoda wyswietlajaca textboxa
	void userText();									//Metoda pozwalajaca przejac kontrole nad textboxem

	//GETTERY//////////////////////////////////////////////////////////////////////////////////////////

	COORD getPosition();								//Getter pozycji textboxa
	int getLength();									//Getter dlugosci tekstu w textboxie
	std::string getText();								//Getter pobierajacy tekst
	int getTextColor();									//Getter pobierajacy kolor tekstu
	int getBackgroundColor();							//Getter koloru tla w textboxie

///////////////////////////////////////////////////////////////////////////////////////////////////////
private:
	COORD c;
	unsigned int length;
	std::string tekst;
	Color tekstcolor;
	Color backgcolor;

};

#endif
