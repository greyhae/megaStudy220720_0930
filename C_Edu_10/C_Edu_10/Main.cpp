/*
* Chapter 10 : 배열과 포인터
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>

int main(void)
{
	// ** 배열과 포인터의 관계
	{
		// ** 배열 선언 및 초기화
		int Array[8] = { 0 };

		// ** 초기화
		for (int i = 0; i < 8; ++i)
			Array[i] = i + 1;

		printf("[일반 출력]\n");

		for (int i = 0; i < 8; ++i)
			printf("%d\n", Array[i]);
		printf("\n");


		printf("[포인터를 사용한 출력]\n");

		// ** 배열은 인덱스(대괄호 [])가 없는 상태로 주소반환 연산자 없이
		int* iter = Array;

		for (int i = 0; i < 8; ++i)
			printf("%d\n", *(iter + i));
		printf("\n");
	}

	{
		int Array[8] = { 0 };

		// ** 문제
		printf("[포인터를 사용한 출력으로 발생할 수 있는 문제]\n");

		int* iter = Array;

		for (int i = 0; i < 100; ++i)
			printf("%d\n", *(iter + i));
		printf("\n");
	}


	// ** 로또 번호를 생성하는 프로그램
	/*
	int Number[5][6] = {
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
	}
	*/

	int Number[5][6];

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			srand((i + 1) * (j + 1) * rand());
			Number[i][j] = rand() % 45 + 1;
		}
	}

	// ** 버블 정렬
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			for (int k = (j + 1); k < 6; ++k)
			{
				if (Number[i][j] > Number[i][k])
				{
					int Temp = Number[i][j];
					Number[i][j] = Number[i][k];
					Number[i][k] = Temp;
				}
			}
		}
	}

	// ** 선택 정렬
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			int Select = j;
			for (int k = (j + 1); k < 6; ++k)
			{
				if (Number[i][Select] > Number[i][k])
					Select = k;

			}
			int Temp = Number[i][j];
			Number[i][j] = Number[i][Select];
			Number[i][Select] = Temp;
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		printf("%02d. ", i + 1);
		for (int j = 0; j < 6; ++j)
			printf("%02d ", Number[i][j]);
		printf("\n");
	}

	return 0;
}