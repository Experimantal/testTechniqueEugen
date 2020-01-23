#pragma once
class Data
{
public:
	Data(int &newX, int &newY);
	~Data();
	int getX();
	int getY();
private:
	int x;
	int y;
};

