#include "ccolor.h"

std::ostream & black(std::ostream & blk)
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, 0);														//ustawia kolor z Enuma

	return blk;
}

std::ostream & blue(std::ostream & b)
{

	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, 1);

	return b;
}

std::ostream & green(std::ostream & g)
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, 2);

	return g;
}

std::ostream & aqua(std::ostream & a)
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, 3);

	return a;
}

std::ostream & red(std::ostream & r)
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, 4);

	return r;
}

std::ostream & purple(std::ostream & p)
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, 5);

	return p;
}

std::ostream & yellow(std::ostream & y)
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, 6);

	return y;
}

std::ostream & grey(std::ostream & gry)
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, 8);

	return gry;
}


std::ostream & white(std::ostream & w)
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, 15);

	return w;
}


////////////////////////////////////////////////////////////////////////////////////////////////////


std::ostream & defcolor(std::ostream & defaultkolor)
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO x;
	GetConsoleScreenBufferInfo(hc, &x);
	SetConsoleTextAttribute(hc, 0x7);

	return defaultkolor;
}
