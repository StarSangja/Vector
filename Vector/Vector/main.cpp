// ** Vector ver 0.9.1

#include <iostream>

using namespace std;

/*

	// ** 1. 데이터 추가(새로운 공간 확보)
	// ** 2. 데이터 삭제
	// ** 3. 데이터를 실행 할 수 있는 공간의 크기
	// ** 4. 현재 삽입되어 있는 원소의 갯수
	// ** 5. 컨테이너의 시작 지점
	// ** 6. 컨테이너의 종료 지점

*/


// 원소의 개수
int Size = 0;

// 최대 수용 개수
int capacity = 0;

// 컨테이너
int* Vector = nullptr;

// 전방선언
// 컨테이너의 마지막 위치에 값을 추가
void push_back(const int& _Value);

// 컨테이너의 마지막 위치에 있는 값을 삭제
void pop_back();

int front();
int back();

void erase(const int& _where);


int main(void)
{
	// ** 누적 횟수만큼 비효율
	for (int i = 0; i < 10; ++i)
		push_back(i * 100 + 100);
	
	pop_back();

	push_back(10000);

	cout << endl << front() << endl;
	cout << back() << endl;

	erase(3);
	
	// 출력
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
	// 특정 위치에 있는 원소를 삭제 하고 정렬.

	--Size;
	for (int i = _where + (-1); i < Size; ++i)
		Vector[i] = Vector[i + 1];
	
}	

// 인설트 함수를 만들어서 특정 위치에 데이터를 삽입할 수 있는 함수 만들기

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

// ** 2의 보수 시작
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
		// ** 양수 표현의 최대값에서 +1을 더하면 어떤값이 나올까?

		char n = 127;
		n += 1;
		printf_s("%d", n);
		*/



		/*
		// ** +연산과 -연산중 무엇이 더 효율적일까?
		char n = 16;

		n -= 6;
		//n += -6;

		printf_s("%d", n);
		*/



		/*
		// ** 나누기를 해야 할 때에는 * 기로 대체할 수 있을지 확인해보고
		int n = 1920 / 2;
		// int n = 1920 * 0.5f;

		printf_s("%d", n);

		// ** 아래와 같이 쉬프트 연산자로 사용할수 있을지 확인해보자.
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
		// ** 배열은 0이 아닌 값으로만 초기화가 가능하다.
		// ** 배열은 상수값으로만 초기화가 가능하다.

		// ** 아래와 같이 사용한다면 위 조건은 무시할 수 있다.

		int Size = 0;
		int iter = 0;
		int* Vector = new int[Size];

		Vector[iter];
		*/


		/*
				// ** 배열은 아니지만 배열 처럼 사용할 수 있다.
		int Size = 10;
		int iter = 0;
		int* Vector = new int[Size];

		for (int i = 0; i < Size; ++i)
			Vector[i] = i;

		for (int i = 0; i < 11; ++i)
			cout << Vector[iter++] << endl;

		*/

#pragma endregion

