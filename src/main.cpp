#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <ranges> // g++ -std=c++20
#include <vector>
#include <map>

int main()
{
    std::map<std::string, int> word_count;
    std::fstream f("TEXT.txt");
    std::string line;
    while (std::getline(f, line))
    {
        auto split = line | std::views::split(' ');
        for (auto m : split)
        {
            auto str = std::string(m.begin(), m.end());

            if (word_count.find(str) != word_count.end())
            {
                word_count[str] += 1;
            }
            else {
                word_count[str] = 1;
            }
        }
    }
    std::vector<std::pair<std::string, int>> str_Table;

    for (auto& val : word_count)
    {
        str_Table.push_back(val);
    }
  
    std::ranges::sort(str_Table, [](auto&& v1, auto&& v2) { return v1.second < v2.second; });

    for (auto& pr : str_Table)
    {
        std::cout << pr.first << "[" << pr.second << "]" << '\n';
    }
}
