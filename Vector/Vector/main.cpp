#include <iostream>

using namespace std;

int main(void)
{
	int str1[2][5]
	{
		{'A','B','C','D','E'},
		{'F','G','H','I','J'}
	};

	for (int i = 0; i < 5; i++)
		cout << (*str1)[i];

	cout << endl;

	return 0;
}