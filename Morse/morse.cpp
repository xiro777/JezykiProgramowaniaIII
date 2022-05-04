#include "morse.h"

// KONSTURKTORY //

morse::morse()													//konstruktor bezparametrowy ustawiajacy wlasnosci na 0
{
	_frequency = 0;
	_dottime = 0;
	_dashtime = 0;
	_pause = 0;
	_spacepause = 0;
	_charpause = 0;
}

morse::morse(const morse & kopiujacy)							//kontruktor kopiujacy ktory kopiuje wlasnosci morse do nowego objektu 'kopiujacy'
{
	_frequency = kopiujacy._frequency;
	_dottime = kopiujacy._dottime;
	_dashtime = kopiujacy._dashtime;
	_pause = kopiujacy._pause;
	_spacepause = kopiujacy._spacepause;
	_charpause = kopiujacy._charpause;

}

morse::~morse()													//destruktor nic nie robiacy
{

}

// SETTERY //

void morse::setFrequency(int frequency)							//ustawia czestotliwosc
{
	_frequency = frequency;
}

void morse::setDotTime(int dottime)								//ustawia czas kropki
{
	_dottime = dottime;
}

void morse::setDashTime(int dashtime)							//ustawia czas kreski
{
	_dashtime = dashtime;
}

void morse::setPause(int pause)									//ustawia ustawia pause po kazdej kropce i kresce
{
	_pause = pause;
}

void morse::setSpacePause(int spacepause)						//ustawia pauze jako spacje
{
	_spacepause = spacepause;
}

void morse::setCharPause(int charpause)							//ustawia pauze po kazdym znaku
{
	_charpause = charpause;
}


//GETTERY//


const int morse::getFrequency()									//zwraca czestotliwosc
{
	return _frequency;
}

const int morse::getDotTime()									//zwraca czas kropki
{
	return _dottime;
}

const int morse::getDashTime()									//zwraca czas kreski
{
	return  _dashtime;
}

const int morse::getPause()										//zwraca pauze po kazdym piknieciu
{
	return _pause;
}

const int morse::getSpacePause()								//zwraca pauze na spacji
{
	return _spacepause;
}

const int morse::getCharPause()									//zwraca pauze po kazdym znaku
{		
	return _charpause;
}

//OPERATORY//

morse & morse::operator=(const morse & porownanie)		
{
	if (this != &porownanie)									//dopoki if nie bedzie poza adresem objektu przypisuje wartosci do nowego objektu
	{
		this->_frequency = porownanie._frequency;
		this->_pause = porownanie._pause;
		this->_dottime = porownanie._dottime;
		this->_dashtime = porownanie._dashtime;
		this->_charpause = porownanie._charpause;
	}
	return *this;												
}

void operator<<(morse& t, const char *tab)					
{
	int nr_znak = 0;
	while (tab[nr_znak] != '\0')								//while ktory powtarza sie do momentu znaku konca tablicy		
	{
		int dlugosc = 0;

		std::string znak_tab = "";								//tworzenie pustego stringa
		znak_tab = converter ( tab [ nr_znak ] );				//przypisanie do stringa wartoœci zwróconej z funkcji converter
		dlugosc = znak_tab.length();							//przypisanie d³ugoœci stringa do zmiennej dlugosc
		

		for (int i = 0; i < dlugosc; i++)						//pêtla która przechodzi po kolei po ka¿dym zwróconym znaku przez funkcjê
		{

			if ( znak_tab [ i ] == '-' )						//sprawdza czy wartosc w stringu to '_' jesli tak pika kreske
			{
				Beep ( t._frequency, t._dashtime );				//pikanie kreski
				Sleep ( t._pause );								//pauza po kresce
			}
			else if ( znak_tab [ i ] == '.' )					//sprawdzanie czy wartosc w stringu to '.' jesli tak pika kropke
			{
				Beep( t._frequency, t._dottime );				//pikanie kropki
				Sleep( t._pause );								//pauza po kropce
			}
			else												//jeœli nie natrafi ani na '_' ani na '.' pika pauze jako spacje
			{
				Sleep( t._spacepause );							//pauza spacji
			}
		}

		Sleep(t._charpause);									//pauza po zakonczeniu kazdego znaku
		nr_znak ++;												//zwiêkszenie nr_znak o 1 ktore pozwala na sprawdzenie kolejnego znaku stringa
	}

}

morse morse::operator<<(const long longg)
{
	int dlugosc_long = 0;														//zmienna do przechowania dlugosci liczby z longa
	int dlugosc_tab_converter = 0;												//zmienna do przechowania dlugosci numeru znaku 

		std::string znak_tab_long = "";											//pusty string
		znak_tab_long = std::to_string ( longg );								//przekazanie liczby z longa do stringa
		dlugosc_long = znak_tab_long.length();									//przypisanie dlugosci tablicy z liczba long do dlugosc_long
		char *tablica = new char [ dlugosc_long ];								//tworzenie nowej tablicy dynamicznej do przypisania pojedynczych znakow longa do tablicy


		for (int j = 0; j < dlugosc_long; j++)
		{
			tablica [ j ] = znak_tab_long [ j ];								//for przypisujacy liczbe z longa do tablicy po dlugosci tego longa
		}

		for (int i = 0; i < dlugosc_long; i++)									//for idacy po kazdym elemencie longa w celu stworzenia nowego stringa i przypisanie kazdemu znakowi znak z morsa
		{
			std::string znak_tab_converter = "";								//pusty string
			znak_tab_converter = converter ( tablica [ i ] );					//przypisanie do stringa znakow w alfabecie morsa
			dlugosc_tab_converter = znak_tab_converter.length();				//sprawdzenie dlugosci tego stringa
			for (int k = 0; k < dlugosc_tab_converter; k++)						//for ktory pika kreski, kropki i pauzy dla kazdego znaku z morse'a
			{

				if (znak_tab_converter [ k ] == '-')							//jesli znak tablicy bedzie '_' bedzie pikac kreske
				{
					Beep(_frequency, _dashtime);								//pikanie kreski
					Sleep(_pause);												//pauza po kresce
				}
				else if (znak_tab_converter [ k ] == '.')						//jesli znak tablicy bedzie '.' bedzie pikac kropke
				{
					Beep(_frequency, _dottime);									//pikanie kropki
					Sleep(_pause);												//pauza po kropce
				}
				Sleep(_charpause);												//pauza po znaku 
			}
		}
		delete[] tablica;														//usuniecie tablicy dynamicznej 
	return *this;
}

morse morse::operator<<(const double doublee)
{
	int dlugosc_double = 0;														//zmienna do przechowania dlugosci liczby z double					
	int dlugosc_tab_converter = 0;												//zmienna do przechowania dlugosci numeru znaku 

	std::string znak_tab_double = "";											//pusty string
	znak_tab_double = std::to_string( doublee );								//przekazanie liczby z double do stringa
	dlugosc_double = znak_tab_double.length();									//przypisanie dlugosci tablicy z liczba long do dlugosc_double
	char *tablica = new char[ dlugosc_double ];									//tworzenie nowej tablicy dynamicznej do przypisania pojedynczych znakow double do tablicy


	for (int j = 0; j < dlugosc_double; j++)
	{
		tablica [ j ] = znak_tab_double [ j ];									//for przypisujacy liczbe z double do tablicy po dlugosci tego double
	}

	for (int i = 0; i < dlugosc_double; i++)									//for idacy po kazdym elemencie double w celu stworzenia nowego stringa i przypisanie kazdemu znakowi znak z morsa
	{
		std::string znak_tab_converter = "";									//pusty string
		znak_tab_converter = converter ( tablica [ i ] );						//przypisanie do stringa znakow w alfabecie morsa
		dlugosc_tab_converter = znak_tab_converter.length();					//sprawdzenie dlugosci tego stringa
		for (int k = 0; k < dlugosc_tab_converter; k++)							//for ktory pika kreski, kropki i pauzy dla kazdego znaku z morse'a
		{

			if (znak_tab_converter [ k ] == '-')								//jesli znak tablicy bedzie '_' bedzie pikac kreske
			{
				Beep(_frequency, _dashtime);									//pikanie kreski
				Sleep(_pause);													//pauza po kresce
			}
			else if (znak_tab_converter [ k ] == '.')							//jesli znak tablicy bedzie '.' bedzie pikac kropke
			{
				Beep(_frequency, _dottime);										//pikanie kropki
				Sleep(_pause);													//pauza po kropce
			}
			Sleep(_charpause);
		}
	}
	delete[] tablica;															//usuniecie tablicy dynamicznej
	return *this;
}


//ALFABET W STRINGU//


std::string converter ( char nr_converter )						//string zawierajacy casy z kazda litera/cyfra/kropka oraz jego zwracaniem w alfabecie morsa
{
	switch ( nr_converter )
	{

	// ALFABET //

	case 'a': case 'A':
		return ".-";											
	case 'b': case 'B':
		return "-...";
	case 'c': case 'C':
		return "-.-.";
	case 'd': case 'D':
		return "-..";
	case 'e': case 'E':
		return ".";
	case 'f': case'F':
		return "..-.";
	case 'g': case'G':
		return"--.";
	case 'h': case'H':
		return"....";
	case 'i': case'I':
		return"..";
	case 'j': case'J':
		return".---";
	case 'k': case'K':
		return"-.-";
	case 'l': case'L':
		return".-..";
	case 'm': case'M':
		return"--";
	case 'n': case'N':
		return"-.";
	case 'o': case'O':
		return"---";
	case 'p': case'P':
		return".--.";
	case 'q': case'Q':
		return"--.-";
	case 'r': case'R':
		return".-.";
	case 's': case'S':
		return"...";
	case 't': case'T':
		return"-";
	case 'u': case'U':
		return"..-";
	case 'v': case'V':
		return"...-";
	case 'w': case'W':
		return".--";
	case 'x': case'X':
		return"-..-";
	case 'y': case'Y':
		return"-.--";
	case 'z': case'Z':
		return"--..";

	//CYFRY//

	case '1':
		return".----";
	case '2':
		return"..---";
	case '3':
		return"...--";
	case '4':
		return"....-";
	case '5':
		return".....";
	case '6':
		return"-....";
	case '7':
		return"--...";
	case '8':
		return"---..";
	case '9':
		return"----.";
	case '0':
		return"-----";

	//ZNAKI SPECJALNE//

	case ' ':													
		return " ";
	case '.':
		return ".-.-.-";
	case ',':
		return "--..--";
	case '_':
		return ".-..-.";
	case ':':
		return "---...";
	case ';':
		return "-.-.-.";
	case '?':
		return ".-.-.";
	case '/':
		return "-..-.";
	case '(':
		return "-.--.";
	case ')':
		return "-.--.-";
	case '=':
		return "-...-";
	case '@':
		return ".--.-.";

	}
}

