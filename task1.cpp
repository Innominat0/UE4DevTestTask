#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

string stringChanger(string &str)
{
	string result = "";
	
	map<char, int> chrCount;

	transform(str.begin(), str.end(), str.begin(),
		[](unsigned char c) { return tolower(c); });

	for (int i = 0; i < str.length(); i++)
	{
		chrCount[str[i]] += 1;
	}

	for (int i = 0; i < str.length(); i++)
	{
		if (chrCount[str[i]] == 1)
		{
			result += '(';
		}
		else
		{
			result += ')';
		}
	}

	return result;
}

int main()
{
	string test1 = "din";
	string test2 = "recede";
	string test3 = "Success";
	string test4 = "(( @";

	string res1 = stringChanger(test1);
	string res2 = stringChanger(test2);
	string res3 = stringChanger(test3);
	string res4 = stringChanger(test4);

	cout << endl;
	cout << test1 << " -- " << res1 << endl;
	cout << test2 << " -- " << res2 << endl;
	cout << test3 << " -- " << res3 << endl;
	cout << test4 << " -- " << res4 << endl;
}

/*
"din"      =>  "((("
"recede"   =>  "()()()"
"Success"  =>  ")())())"
"(( @"     =>  "))(("
*/