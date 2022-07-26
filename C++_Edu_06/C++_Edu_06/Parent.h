#pragma once
#include "Header.h"

class Parent
{
protected:
	string Name;

	// ** [추상 클래스 특징]
	// ** 데이터는 존재할 수 있지만 함수는 순수 가상 함수로만 존재할 수 있다.

	// ** [순수 가상함수의 특징]
	// ** 순수 가상함수가 1개라도 만들어지면, 그 클래스는 추상 클래스로만 사용 가능하다.
	
	// ** [정리]
	// ** 순수 가상함수를 1개라도 만들면..
	// ** 추상클래스 이므로 인스턴스화 불가
	// ** 일반함수 제작 및 사용시 문제가 발생하므로 사용하지 말것!!
public:
	//virtual void Start() = 0;
	//순수 가상함수
	virtual void Start()PURE;
	virtual void Start(int number)PURE;
};