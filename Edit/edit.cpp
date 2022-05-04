#include "Edit.h"


/////////////////////////////////////////////////////////////////////////////////////////////////

Edit::Edit() : length(10), tekst("TEST"), c{ 0 },
tekstcolor(Edit::White), backgcolor(Edit::Blue)
{
}


Edit::Edit(short x, short y, int dlugosc, std::string, Color textcolor, Color backcolor) :
	length(dlugosc), tekst(tekst), c{ x,y }, tekstcolor(tekstcolor), backgcolor(backgcolor)
{

}


Edit::Edit(Edit & kopiujacy)						//kopiuje zmienne do obiektu "kopiujacy"
{
	this->length = kopiujacy.length;
	this->tekst = kopiujacy.tekst;
	this->tekstcolor = kopiujacy.tekstcolor;
	this->backgcolor = kopiujacy.backgcolor;
	this->c = kopiujacy.c;
}

Edit Edit::operator=(const Edit & A)				//operator =
{
	this->length = A.length;
	this->tekst = A.tekst;
	this->tekstcolor = A.tekstcolor;
	this->backgcolor = A.backgcolor;
	this->c = A.c;

	return *this;
}



Edit::~Edit()										//destruktor nic nie robiacy
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void Edit::setPosition(int x, int y)				// ustawia pozycje x, y
{
	c.X = x;
	c.Y = y;
}


void Edit::setLenght(int dlu)						// ustawiwa dlugosc tekstu
{
	this->length = dlu;
}


void Edit::setText(std::string txt)					// ustawia tekst
{
	this->tekst = txt;
}


void Edit::setTextColor(Color kolor_txt)			//ustawiwa kolor tekstu
{
	this->tekstcolor = kolor_txt;
}


void Edit::setBackgroundColor(Color back_kolor)		//ustawia kolor tla
{
	this->backgcolor = back_kolor;
}


COORD Edit::getPosition()							//pobiera pozycje 
{
	return this->c;
}


///////////////////////////////////////////////////////////////////////////////////////////////////


int Edit::getLength()								//pobiera dlugosc
{
	return this->length;
}


std::string Edit::getText()							//pobiera tekst
{
	return this->tekst;
}


int Edit::getTextColor()							//pobiera kolor tekstu
{
	return this->tekstcolor;
}


int Edit::getBackgroundColor()						//pobiera kolor tla
{
	return this->backgcolor;
}


///////////////////////////////////////////////////////////////////////////////////////////////////

void Edit::display()								//metoda wyswietlajaca textboxa
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, tekstcolor + (backgcolor * 16));	//ustawia atrybuty textboxa
	SetConsoleCursorPosition(hc, c);								//ustawia pozycje kursora 
	std::cout << tekst.substr(0, length);							//ustawia maksymalny wyswietlnay tekst czyli od 0 znaku do lenght
}


void Edit::userText()												//przekazuje kontrole nad konsola uzytkowikowi
{
	bool ext = false;												
	int tymczasowa;													//zmienna wykorzystywana do przypiasania cechy w if'ach

	do
	{
		tymczasowa = _getch();										//zbiera wartosc z klawiatury i przechowuje w ASCII

		if (tymczasowa == 13)										//enter wyrzucajacy tekst na textboxa
		{	
			ext = true;
			display();
		}
		else if (tymczasowa == 32)									//spacja 				
		{
			tekst.push_back(tymczasowa);
			display();
		}
		else if (tymczasowa == 75)									//strzalki 
		{
			if (tekst.size() >= 1)
			{
				tekst.erase(tekst.size() - 1, 1);
				display();
			}

		}
		else if ((tymczasowa >= 48 && tymczasowa) <= 57 || (tymczasowa >= 65 && tymczasowa <= 90) ||	
			(tymczasowa >= 97 && tymczasowa <= 122))				//pozwala wypisywac znaki z klawiatury na textbox
		{
			if (tekst.size() < length)								//sprawdza czy wypisany znak bedzie dluzszy od dozwolonej dlugosci
			{
				tekst.push_back(tymczasowa);						//wyrzuca znak do textboxa
				display();
			}
		}
	} while (ext != true);

}