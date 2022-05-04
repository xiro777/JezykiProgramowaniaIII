#include "color.h"



color::color() :
	r(0)
	, g(0)
	, b(0)
{

}

color::color(short x, short y, short z) :
	r(x)
	, g(y)
	, b(z)
{

}

color::color(const color & k) :
	r(k.r)
	, g(k.g)
	, b(k.b)
{

}

color::~color()
{
}

color & color ::operator=(const color & porow)
{
	if (this != &porow)
	{
		this->r= porow.r;
		this->g= porow.g;
		this->b = porow.b;
	}
	return *this;
}

std::ofstream & operator <<(std::ofstream & o, const color & k)
{
	o << k.r << k.g << k.b;
	return o;
}

short color::getR() const
{
	return r;
}

short color::getG() const
{
	return g;
}

short color::getB() const
{
	return b;
}

bool operator <(const color & o, const color & k)
{
	if ((o.r + o.g + o.b) < (k.r + k.g + k.g))
	{
		return true;
	}
	else
	{
		return false;
	}
}