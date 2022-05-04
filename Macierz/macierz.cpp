#include "macierz.h"

macierz::macierz()
{
	ilosc_kolumn = 2;
	ilosc_wierszy = 2;
	// ustawienie wielkosci macierzy poprzez ilosc wierszy oraz kolumn
	wartosc = new double*[ilosc_wierszy];
	for (int i = 0; i < ilosc_wierszy; i++)
	{
		wartosc[i] = new double[ilosc_kolumn];
	}
	//tworzenie tablicy dwuwymiarowej ktorej wymiarami jest ilosc kolumn oraz wierszy 
	for (int i = 0; i < ilosc_wierszy; i++)
	{
		for (int j = 0; j < ilosc_kolumn; j++)
		{
			wartosc[i][j] = 0;
		}
	}
	//wyzerowanie tablicy
	
}

macierz::~macierz()
{
		for (int i = 0; i < ilosc_kolumn; i++)
		{
			delete wartosc[i];
		}
		delete[] wartosc;
		//destruktor usuwaj¹cy wartosci z tablicy oraz cala tablice 
}

void macierz::view()
{
	for (int i = 0; i < ilosc_wierszy; i++)
	{
		for (int j = 0; j < ilosc_kolumn; j++)
		{
			std::cout << wartosc[i][j] << " ";
		}
		std::cout << std::endl;
	}
	//funkcja pomocnicza do wyswietlania macierzy, ktora wyswietla kazda wartosc poszczgolnego wiersza i kolumny macierzy
}

void macierz::set(int k, int w, double wynik)
{
	this->wartosc[k][w] = wynik;
	//metoda ustala wartosc dla macierzy w ktorej k - ilosc kolumn, w - ilosc wierszy
}

macierz::macierz(const macierz & A)
{
	this->ilosc_kolumn = A.ilosc_kolumn;
	this->ilosc_wierszy = A.ilosc_wierszy;

	this->wartosc = new double*[A.ilosc_wierszy];
	for (int i = 0; i < A.ilosc_wierszy; i++)
	{
		this->wartosc[i] = new double[A.ilosc_kolumn];
		// tworzy tablice dwuwymiarowa 2x2 
	} 
		for (int i = 0; i < A.ilosc_wierszy; i++)
		{
			for (int j = 0; j < A.ilosc_kolumn; j++)
				//petle sprawdzaja wszystkie elementy tablicy
			{
				this->wartosc[i][j] = A.wartosc[i][j];	
				//petle zapisujace wartosci kolumn i wierszy do drugiej tablicy
			}
		}

}


macierz & macierz::operator=(const macierz &Z)
{

		for (int j = 0; j < ilosc_wierszy; j++)
		{
			for (int i = 0; i < ilosc_kolumn; i++)
			{
				this->wartosc[i][j] = Z.wartosc[i][j];
				//przypisuje do obiektu Z wartosci tablicy
			}
		}

	return *this;
	//zwraca tablice wartosc

}

const macierz macierz::operator*(const macierz & M)
{
	macierz B;
	//zmienna w ktorej przechowywana bedzie tablica
	for (int i = 0; i < ilosc_wierszy; i++)
	{
		for (int j = 0; j < ilosc_kolumn; j++)
		{
			for (int k = 0; k < ilosc_wierszy; k++)
			{
				B.wartosc[i][j] += wartosc[i][k] * M.wartosc[k][j];
				//mnozenie macierzy i dodawanie obiektu B
			}
		}
	}
	return B;
	//zwraca obiekt B
}

bool macierz::operator==(const macierz & P)
{
	for (int i = 0; i < ilosc_wierszy; i++)
	{
		for (int j = 0; j < ilosc_kolumn; j++)
			//sprawdza kazdy element tablicy
		{
			if (wartosc[i][j] != P.wartosc[i][j])
				//warunek jesli wartosci w macierzach sie nie zgadzaja wyswietla false
			{
				return false;
			}
		}
	}
	return true;
	// jesli wszystko jest takie samo true


}