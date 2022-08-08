/*
* Chapter 07 : 함수
*/

#include <stdio.h>

// ** 함수의 전방 선언
int sum(int x, int y);
// ** 전방 선언은 항상 main(void)의 상단에 위치시켜야 한다.

int main(void)
{
	int a = 10, b = 20;
	int result;

	result = sum(a, b);
	printf("result : %d\n", result);

	// ** 영역 표현하는 중괄호 {}를 사용하여, 여러개의 영역을 갖을 수 있다.
	{

	}

	// ** 영역 배부에서의 변수 사용
	{
		// 같은 이름의 변수를 사용
		int x = 10;
		{
			// ** 변수의 이름이 같은 경우 해당 영역 내부에 있는 변수를 우선순위로 정한다.
			int x = 20;

			printf_s("첫번째 : %d\n", x);
		}

		printf_s("두번째 : %d\n", x);

		// ** 1. 문제 : 상위에 있는 변수의 값을 사용할 수 없다.
		// ** 2. 문제 : 변수의 이름이 같기 때문에 변수 사용에 혼란이 생길 수 있다.
	}

	// ** 변수의 존재 기간
	{
		// ** 변수는 선언된 해당 영역이 종료되는 지점까지 사용 가능
		int 변수1 = 10;

		{
			int 변수2 = 20;
			변수1 = 변수2;
			// 변수1 <= 사용 가능
		}
		
		// 변수2 = 30; <= X 사용 불가
	}


	{
		// ** 같은 이름의 변수명을 다른 영역에서 도로 갖을 수 있다.
		int result = sum(a, b);
	}

	return 0;
}

// 함수의 정의
int sum(int x, int y) {
	int temp;

	temp = x + y;

	return temp;
}