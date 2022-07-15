#include <iostream>

#include "CArr.h"
using namespace std;
class CTest
{
private:
	int a;
	
public:
	CTest()
		:a(10)
	{

	}
};
template<typename T>
T Add(T a, T b)
{
	return a + b;
}
int main()
{
	// 구조체 --> 클래스

	// 객체지향 언어 특징
	// 1. 캡슐화
	// 기능을 수행하기 위해 필요한 멤버 선언, 묶음, 은닉성
	// 멤버 함수들

	// 2. 상속

	// 3. 다형성

	// 4. 추상화

	// C++ 동적 할당 new, delete

	CTest* pTest = new CTest;
	delete pTest;

	CArr<float> carr;
	carr.push_back(10);
	carr.push_back(20);
	carr.push_back(30);

	float fData = carr[1];
	carr[1] = 100;

	//함수 템플릿
	int i = Add<int>(2, 3);
	//테스트
	return 0;
}