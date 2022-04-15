/****************************************************
 *						Problem 13					*
 * https://leetcode.com/problems/roman-to-integer/  *
 ****************************************************/

#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int ans = 0;
		std::unordered_map<char, unsigned short int> map
		{
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000}
		};
		for (auto it = s.begin(); it != s.end(); ++it)
		{
			if ((it != (s.end() - 1)) && (map.find(*it)->second < map.find(it[1])->second))
			{
				ans += map.find(it[1])->second - map.find(*it)->second;
				++it;
			}
			else
			{
				ans += map.find(*it)->second;
			}
		}
		return ans;
	}
};

int main()
{
	Solution s;
	std::string str;
	std::cin >> str;
	std::cout << s.romanToInt(str);
	return 0;
}