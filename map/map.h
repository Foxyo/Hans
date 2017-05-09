#include <iostream>
#include <map>
#include <vector>
struct case_insensitive_cmp
{
    bool operator()(const std::string& s1, const std::string& s2) const
    {
        char a, b;
        size_t j = std::min(s1.length(), s2.length());
        for (size_t i = 0; i < j; i++)
        {
            a = toupper(s1[i]);
            b = toupper(s2[i]);
            if (a != b)
                return (a < b);
        }
        return (s2.length() > s1.length());
    }
};
struct case_insensitive_hash
{
    size_t operator()(const std::string& s) const
    {
        size_t h = 0;
        for (size_t i = 0; i < s.length(); i++)
        {
            h += toupper(s[i]);
        }
        return h;
    }
};

struct case_insensitive_equality
{
    bool operator()(const std::string& s1, const std::string& s2) const
    {
        if (s1.length() != s2.length())
            return false;
        char a, b;
        for (size_t i = 0; i < s1.length(); i++)
        {
            a = toupper(s1[i]);
            b = toupper(s2[i]);
            if (toupper(a) != toupper(b))
                return false;
        }
        return true;
    }
};

std::map<std::string, unsigned int, case_insensitive_cmp> frequencytable(
    const std::vector<std::string>& text);
std::ostream& operator<<(
    std::ostream& stream, const std::map<std::string, unsigned int, case_insensitive_cmp>& freq);

std::vector<std::string> readfile(std::istream& input);
void frequent_word(std::map<std::string, unsigned int, case_insensitive_cmp>& m);
