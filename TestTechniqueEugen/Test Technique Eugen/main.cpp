#include <iostream>
#include <vector>


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

int main(int argc, char** argv)
{
    if (argc >= 2)
    {
        std::string str = argv[1];
        std::vector<std::string> vec = split(str, " ");
        std::vector<std::string>::iterator it;
        for (it = vec.begin(); it != vec.end(); ++it)
        {
            std::cout << *it << " ";
            it = vec.end() - 1;
            std::cout << *it;
        }
    }
	return (0);
}