//** STL_Vector v0.2
#include <iostream>
#include <vector>

using namespace std;


int main(void)
{
	int MAX = 50;

	vector<int> vecNumbers;


	// ** 입력
	for (int i = 0; i < 10; ++i)
	{
		vecNumbers.push_back(10 * i);

		//cout << "capacity : " << vecNumbers.capacity() << endl;
		//cout << "size : " << vecNumbers.size() << endl << endl;
	}






	/*
	// ** 가장 앞에 있는 [원소를 반환]
	vecNumbers.front();

	// ** 가장 뒤에 있는 [원소를 반환]
	vecNumbers.back();

	// ** 시작점을 가르키는 [반복자]
	vecNumbers.begin();

	// ** 종료 지점을 가르키는 [반복자]
	vecNumbers.end();
	*/




	/*
	for (int i = 0; i < vecNumbers.size(); ++i)
		cout << vecNumbers[i] << endl;

	for (vector<int>::iterator iter = vecNumbers.begin();
		iter != vecNumbers.end(); ++iter)
		cout << (*iter) << endl;

	for (auto iter = vecNumbers.begin();
		iter != vecNumbers.end(); ++iter)
		cout << (*iter) << endl;
	*/






	/*
	int Array[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

	int* iterator = Array;

	for (int i = 0; i < 16; ++i)
		cout << Array[i] << endl;

	for (int i = 0; i < 16; ++i)
		//cout << *(iterator + i) << endl;
		cout << *(iterator++) << endl;
	*/






	/*
	for (auto iter = vecNumbers.begin(); iter != vecNumbers.end(); )
	{
		if ((*iter) > MAX)
			iter = vecNumbers.erase(iter);
		else
			++iter;
	}

	for (auto iter = vecNumbers.begin(); iter != vecNumbers.end(); ++iter)
	{
		cout << (*iter) << endl;
	}
	*/


	return 0;
}

