///////////////////////////////////////////////////////////////////////////////////////////////
//
//Klasa: freqcounter.h
//Opis: klasa szablonowa liczaca czestoliwosc wystepowania elementow w pliku
//Autor: Kacper Morawski
//Data Utworzenia: 21.01.2019r.
//Data edytowania: 22.01.2019r.
//
///////////////////////////////////////////////////////////////////////////////////////////////

#if !defined (freqcounter_h)
#define freqcounter_h

#include <fstream>
#include <map>
#include <string>

template <typename T>

class freqcounter
{
public:
	freqcounter();														//konstruktor bezparametrowy
	freqcounter(const T & k);											//konstruktor kopiujacy
	~freqcounter();														//destruktor

	void create();														//metoda tworzaca plik i wpisujaca do niego wyniki
	void addData(T data);												//metoda dodajaca dane do kontenera (mapy)
	bool pusty() const;													//metoda sprawdzajaca czy mapa jest pusta
	int getRozmiar() const;												//metoda zwracajaca rozmiar mapy
	void czyscMape();													//metoda czyszczaca mape

protected:
	std::map<const T, int> freqmap;


};

//cpp


template <typename T>
inline freqcounter<T>::freqcounter()
{

}


template <typename T>
inline freqcounter<T>::freqcounter(const T & k)	:
	freqmap( k.freqmap )
{

}


template <typename T>
inline freqcounter<T>::~freqcounter()
{

}


template <typename T>
inline void freqcounter<T>::create()
{
	std::cerr << " Podaj nazwe pliku do jakiego zapisac wyniki: ";
	std::string tymczasowa;
	std::cin >> tymczasowa;
	std::ofstream plik(tymczasowa);

	for (std::pair<const T, int>& x : freqmap)
	{
		plik << x.first << "   wystapilo razy: " << x.second << std::endl;
	}
	plik.close();
}


template <typename T>
inline void freqcounter<T>::addData(T data)
{
	freqmap[data]++;
}


template <typename T>
inline bool freqcounter<T>::pusty() const
{
	if (freqmap.empty())
	{
		return true;	
	}
	else
	{
		return false;
	}
}


template <typename T>
inline int freqcounter<T>::getRozmiar() const
{
	return freqmap.size();
}


template <typename T>
inline void freqcounter<T>::czyscMape()
{
	freqmap.clear();
}

#endif