#include "Data.hpp"

Data::Data(int &newX, int &newY)
{
	x = newX;
	y = newY;
}

Data::~Data()
{

}

int Data::getX()
{
	return (x);
}

int Data::getY()
{
	return (y);
}