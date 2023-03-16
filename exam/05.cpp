#include<iostream>
#include<string>
using namespace std;
string s1, s2;
int main()
{
	cin >> s1 >> s2;
	bool match(int s1_loc, int s2_loc);
	if (match(0, 0))
		cout << "matched";
	else
		cout << "not matched";
	return 0;
}
bool match(int s1_loc, int s2_loc)
{
	if (s1_loc >= s1.size())return true;
	if (s1[s1_loc] == '?' || s1[s1_loc] == s2[s2_loc])
		return match(s1_loc + 1, s2_loc + 1);
	else if (s1[s1_loc] == '*')
	{
		int flag = 0;
		for (int i = s2_loc; i <= s2.size(); ++i)
			flag += match(s1_loc + 1, i);
		return flag;
	}
	else
		return false;
}