// ** Vector ver 0.10

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


// ���� ������ ����
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

// ** ���� ���ʿ� �ִ� ����
int front();

// ** ���� ���ʿ� �ִ� ����
int back();

// ** _Where�� ��ġ�� ������ ����
void erase(const int& _where);

// ** _Where�� ��ġ�� _Value �߰�
void insert(const int& _where, const int& _Value);

int main(void)
{
	// ** �� �߰�
	for (int i = 0; i < 10; ++i)
		push_back(i + 1);
	
	insert(5, 10);

	// ���
	for (int i = 0; i < Size; ++i)
		cout << "Velue: " << Vector[i] << endl;
	cout << "Size: " << Size << endl;
	cout << "capacity: " << capacity << endl << endl;

	
	return 0;
}

// ** Call by reference �� ���� ���۷���
void push_back(const int& _Value)
{
	// ** ���� ���̻� ������ �� �ִ�  ������ ���ٸ�...
	if (capacity <= Size)
	{
		// ** ���� ���뷮�� 4���� �۴ٸ� 1�� �����ϰ� 
		// ** ���� ���뷮�� 4���� ũ�ų� ���ٸ� 1/2 ��ŭ �߰���
		capacity += (capacity <= 3) ? 1 : capacity >> 1;

		// ** �ӽ� ����Ҹ� ����
		int* Temp = new int[capacity + 1];
			
		// ** ������ ������ �ʱ�ȭ ��.
		for (int i = 0; i < capacity; ++i)
			Temp[i] = NULL;

		// ** ������ �ִ� ���� ����.
		for (int i = 0; i < Size; ++i)
			Temp[i] = Vector[i];

		// ** ������ ���� ����.
		if (Vector)
		{
			delete Vector;
			Vector = nullptr;

		}

		// ** �ӽ��� ��(�ش��ּ�)�� �����ؿ�.
		Temp[Size] = _Value;
		
		// ** �ӽ��� �ּҰ��� �����ص� ���� 
		// ** �߰��� ���ο� ���� �ٽ�
		// ** ���������� ����Ǿ� �ִ� Vector �� ������
		Vector = Temp;

	}

	else
		// ** ������ ��ġ�� �� �߰�.
		Vector[Size] = _Value;
	
	// ** ���� ������ �ִ밪 ����.
	++Size;
	
	
}

void pop_back()
{
	// ** ���� ������ �ִ밪 ����.
	--Size;
}

int front()
{
	// ** 0��° ���� ��ȯ
	return Vector[0];
}

int back()
{
	// ** ������ ���� ��ȯ
	return Vector[Size-1];

}

void erase(const int& _where)
{
	// ** ���� ������ �ִ밪 ����
	--Size;

	// ** ������
	for (int i = _where + (-1); i < Size; ++i)
		Vector[i] = Vector[i + 1];
	
}
void insert(const int& _where, const int& _Value)
{
	
	if (capacity <= Size)
		capacity += (capacity <= 3) ? 1 : capacity >> 1;

		// ** �ӽ� �����
		int* Temp = new int[capacity + 1];

		// ** �ʱ�ȭ
		for (int i = 0; i < capacity; ++i)
			Temp[i] = NULL;

		// ** �ش� ��ġ ������ ���� ����.
		for (int i = 0; i < _where; ++i)
			Temp[i] = Vector[i];

		// ** �ش� ��ġ�� �� ����/
		Temp[_where] = _Value;
		++Size;

		// ** �ش� ��ġ ������ ���� ����
		for (int i = _where + 1; i < Size; ++i)
			Temp[i] = Vector[i - 1];

		if (Vector)
		{
			delete Vector;
			Vector = nullptr;
		}

		Vector = Temp;
		
		else
		{
		Vector[Size] = _Value;
		}

}




#pragma region �迭
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

#pragma region 2�� ����
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

