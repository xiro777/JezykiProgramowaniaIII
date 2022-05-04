/*
Klasa: ccolor
Opis: Deklaruje kazdy manipulatory kolorow tekstu, przywracajace podstawowy kolor oraz ustawiajacy kolor
Autor: Kacper Morawski
Data Utworzenia: 26.11.2018r.
Data edytowania: 09.12.2018r.

*/



#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <Windows.h>
#include <iomanip>

//Manipulatory Kolorow

std::ostream & blue(std::ostream & b);						//manipulator dla koloru niebieskiego
std::ostream & green(std::ostream & g);						//manipulator dla koloru zielonego
std::ostream & red(std::ostream & r);						//manipulator dla koloru czerwonego
std::ostream & white(std::ostream & w);						//manipulator dla koloru bialego
std::ostream & black(std::ostream & blk);					//manipulator dla koloru czarnego
std::ostream & grey(std::ostream & gry);					//manipulator dla koloru szarego
std::ostream & aqua(std::ostream & a);						//manipulator dla koloru blekitnego
std::ostream & purple(std::ostream & p);					//manipulator dla koloru fioletowego
std::ostream & yellow(std::ostream & y);					//manipulator dla koloru zoltego

std::ostream & defcolor(std::ostream & defaultkolor);		//manipulator przywracajacy podstawowy kolor

#endif