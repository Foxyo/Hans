#include "map.h"

std::map<std::string, unsigned int, case_insensitive_cmp> frequencytable(
    const std::vector<std::string>& text)
{
    std::map<std::string, unsigned int, case_insensitive_cmp> _map;
    // int c = 0;
    for (auto i = text.begin(); i != text.end(); i++)
    {
        _map[*i] += 1;
        // std::cout << text.at(c) << ' ';
        // c++;
        // std::cout << _map[*i] << std::endl;
    }
    return _map;
}

std::ostream& operator<<(
    std::ostream& stream, const std::map<std::string, unsigned int, case_insensitive_cmp>& freq)
{
    for (const auto& pair : freq)
        stream << pair.first << " => " << pair.second << "\n";
    return stream;
}

std::vector<std::string> readfile(std::istream& input)
{
    std::vector<std::string> vect;
    std::string word;
    char c;

    while (input.get(c))
    {
        if (isspace(c) || ispunct(c))
        {
            if (!word.empty())
            {
                vect.push_back(std::move(word));
                word.clear();
            }
        }
        else
            word += static_cast<char>(c);
    }

    if (!word.empty())
        vect.push_back(std::move(word));

    return vect;
}

void frequent_word(std::map<std::string, unsigned int, case_insensitive_cmp>& m)
{
    int a = 0;
    std::string s;
    for (const auto& pair : m)
    {
        if (pair.second > a)
        {
            a = pair.second;
            s = pair.first;
        }
    }
    if (a <= 0)
        std::cout << "Are you sure there are any words?";
    else
        std::cout << s << " => " << a << "\n";
}
