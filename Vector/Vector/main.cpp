// ** Vector ver 0.9.1

#include <iostream>

using namespace std;

/*

	// ** 1. ������ �߰�(���ο� ���� Ȯ��)
	// ** 2. ������ ����
	// ** 3. �����͸� ���� �� �� �ִ� ������ ũ��
	// ** 4. ���� ���ԵǾ� �ִ� ������ ����
	// ** 5. �����̳��� ���� ����
	// ** 6. �����̳��� ���� ����

*/


// ������ ����
int Size = 0;

// �ִ� ���� ����
int capacity = 0;

// �����̳�
int* Vector = nullptr;

// ���漱��
// �����̳��� ������ ��ġ�� ���� �߰�
void push_back(const int& _Value);

// �����̳��� ������ ��ġ�� �ִ� ���� ����
void pop_back();

int front();
int back();

void erase(const int& _where);


int main(void)
{
	// ** ���� Ƚ����ŭ ��ȿ��
	for (int i = 0; i < 10; ++i)
		push_back(i * 100 + 100);
	
	pop_back();

	push_back(10000);

	cout << endl << front() << endl;
	cout << back() << endl;

	erase(3);
	
	// ���
	for (int i = 0; i < Size; ++i)
		cout << "Velue: " << Vector[i] << endl;
	cout << "Size: " << Size << endl;
	cout << "capacity: " << capacity << endl << endl;

	
	return 0;
}


void push_back(const int& _Value)
{

	if (capacity <= Size)
	{
		capacity += (capacity <= 3) ? 1 : capacity >> 1;


		int* Temp = new int[capacity + 1];

		

		for (int i = 0; i < capacity; ++i)
			Temp[i] = NULL;


		for (int i = 0; i < Size; ++i)
			Temp[i] = Vector[i];

		
		if (Vector)
		{
			delete Vector;
			Vector = nullptr;

		}

		Temp[Size] = _Value;
		
		Vector = Temp;

	}

	else
		Vector[Size] = _Value;
	

	++Size;
	Vector[capacity] = NULL;

	cout << "Value: " << _Value << endl;
	cout << "Size: " << Size << endl;
	cout << "capacity: " << capacity << endl << endl;

	
}

void pop_back()
{
	--Size;
}

int front()
{
	return Vector[0];
}

int back()
{
	return Vector[Size-1];

}

void erase(const int& _where)
{
	// Ư�� ��ġ�� �ִ� ���Ҹ� ���� �ϰ� ����.

	--Size;
	for (int i = _where + (-1); i < Size; ++i)
		Vector[i] = Vector[i + 1];
	
}	

// �μ�Ʈ �Լ��� ���� Ư�� ��ġ�� �����͸� ������ �� �ִ� �Լ� �����

#pragma region 22.05.27
// =============22.05.27=========================
/*
	char str1[2][5]
	{
		{'A','B','C','D','E'},
		{'F','G','H','I','J'}
	};

	char* str2[2] =
	{
		{(char*)"ABCD"},
		{(char*)"EFGH"}
	};

	for (int i = 0; i < 5; ++i)
		cout << (*str1)[i];

	cout << endl;

	printf_s("%s\n", str2[0]);

*/

#pragma endregion

#pragma region 22.06.02
//============22.06.02========

// 0 0000000 = 0
// 0 0000001 = 1
// 0 0000010 = 2
// 0 0000011 = 3
// 0 0000100 = 4
// 0 0000101 = 5
// 0 0000110 = 6
// 0 0000111 = 7
// 0 0001000 = 8
// 0 0001001 = 9
// 0 0001010 = 10
// 0 0001011 = 11
// 0 0001100 = 12
// 0 0001101 = 13
// 0 0001110 = 14
// 0 0001111 = 15
// 0 0010000 = 16
// .
// .
// .
// .
// .
// .
// 
// 0 1111111 = 127
// 1 0000000




//   00010000 = 16
// - 00000110 = 6
//---------------
// (16 - 6 == 16 + (-6))

// ** 2�� ���� ����
// 0 0 0 0 0 1 1 0 = 6
// 1 1 1 1 1 1 1 1 
//-------------------
// 1 1 1 1 1 0 0 1
// 11111001 + 1
//-----------------
// 11111010 = -6
// 
//   00010000 = 16
// + 11111010 = -6
//-----------------
//   00001010
//   00001010 = 10

	/*
		// ** ��� ǥ���� �ִ밪���� +1�� ���ϸ� ����� ���ñ�?

		char n = 127;
		n += 1;
		printf_s("%d", n);
		*/



		/*
		// ** +����� -������ ������ �� ȿ�����ϱ�?
		char n = 16;

		n -= 6;
		//n += -6;

		printf_s("%d", n);
		*/



		/*
		// ** �����⸦ �ؾ� �� ������ * ��� ��ü�� �� ������ Ȯ���غ���
		int n = 1920 / 2;
		// int n = 1920 * 0.5f;

		printf_s("%d", n);

		// ** �Ʒ��� ���� ����Ʈ �����ڷ� ����Ҽ� ������ Ȯ���غ���.
		//printf_s("%d", n >> 1);
		*/


		/*
		//const int MAX = 16;
		int Vector[16];

		int length = 10;

		for (int i = 0; i < length; ++i)
			cout << Vector[i] << endl;
		*/


		/*
		// ** �迭�� 0�� �ƴ� �����θ� �ʱ�ȭ�� �����ϴ�.
		// ** �迭�� ��������θ� �ʱ�ȭ�� �����ϴ�.

		// ** �Ʒ��� ���� ����Ѵٸ� �� ������ ������ �� �ִ�.

		int Size = 0;
		int iter = 0;
		int* Vector = new int[Size];

		Vector[iter];
		*/


		/*
				// ** �迭�� �ƴ����� �迭 ó�� ����� �� �ִ�.
		int Size = 10;
		int iter = 0;
		int* Vector = new int[Size];

		for (int i = 0; i < Size; ++i)
			Vector[i] = i;

		for (int i = 0; i < 11; ++i)
			cout << Vector[iter++] << endl;

		*/

#pragma endregion

