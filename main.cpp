#include <iostream>
using namespace std;

int Search(const string& sample, const string& txt);

bool IsKPeriodic(const string& text, int k)
{
	if (k < 1)
	{
		return false;
	}
	string sample = text.substr(0, k);
	int search = Search(sample, text);
	
	if (search * k == text.length())
	{
		return true;
	}
	return false;
}

bool IsKPeriodic(const string& text, int k);

int main()
{
	setlocale(LC_ALL, "rus");
	string text = "abcabcabcabc";
	int k = 3;

	if (IsKPeriodic(text, k))
	{
	cout << " 'дю' " << endl;
	}
	else
	{
	cout << " 'мер' " << endl;
	}

	return 0;
}