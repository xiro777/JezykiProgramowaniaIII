#include "morse.h"
#include <Windows.h>

int main()
{
	morse m;

	m.setFrequency(800);	// czestotliwosc odtwarzania dzwieku
	m.setDotTime(200);		// czas kropki
	m.setDashTime(400);		// czas kreski
	m.setPause(100);		// pauza miedzy . a _ w trakcie morsowania
	m.setSpacePause(400);	// pauza miedzy wyrazami - reakcja na spacje w lancuchu
	m.setCharPause(200);	// pauza po zakonczeniu odtwarzania dzwiêku znaku
	m << "Ala ma kota";

	long i = 0x5A5A5A5A;
	double d = 1.23456789;

	m << i /*<< pause */<< d;

	return 0;
}