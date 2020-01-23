#include <iostream>
#include <string>
#include <vector>
#include "Data.hpp"


//Split a string into a vector of strings
std::vector<std::string> split(const std::string& str, const std::string& regex)
{
    std::vector<std::string> vec;
    size_t prev_pos = 0, pos = 0;
    while ((pos = str.find(regex, pos)) != std::string::npos)
    {
        std::string substr(str.substr(prev_pos, pos - prev_pos));
        vec.emplace_back(substr);
        pos += regex.size();
        prev_pos = pos;
    }
    vec.emplace_back(str.substr(prev_pos, pos - prev_pos));
    return vec;
}


//Create a vector of data holding all the numbers from the input
std::vector<Data> getPositions(std::vector<std::string>& vec)
{
    std::vector<Data> vecData;
    std::string temp;
    std::vector<std::string> tempVec;
    int x = 0;
    int y = 0;
    for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        temp = *it;
        temp = temp.substr(1, temp.size() - 2); // Getting only the numbers and their separator
        tempVec = split(temp, ";"); // Separating the numbers into two separate strings
        x = std::stoi(tempVec[0]); // Get the first number as an int
        y = std::stoi(tempVec[1]); // Get the second number as an int
        Data data(x, y); // Create a Data variable using the two numbers
        vecData.emplace_back(data);
    }
    return (vecData);
}

int main(int argc, char** argv)
{
    if (argc >= 2)
    {
        std::string str = argv[1];
        std::vector<std::string> vec = split(str, " ");
        std::vector<Data> vecData = getPositions(vec);
        std::cout << "(" << vecData[0].getX() << ";" << vecData[0].getY() << ")";
        std::vector<Data>::iterator it = vecData.begin() + 1;
        while (it != vecData.end())
        {
            if (it + 1 != vecData.end())
            {
                std::vector<Data>::iterator next = it + 1;
                if (it->getY() != next->getY())
                    std::cout << " " << "(" << it->getX() << ";" << it->getY() << ")";
                else if (it->getY() > (it - 1)->getY())
                    std::cout << " " << "(" << it->getX() << ";" << it->getY() << ")";
            }
            else
                std::cout << " " << "(" << it->getX() << ";" << it->getY() << ")";
            ++it;
        }
    }
	return (0);
}