#include <iostream>

struct tMy
{

};
class CMy
{
	
public:
	CMy()
		:m_i(100)
		,m_f(1000)
	{
	}
	// 소멸자
	~CMy()
	{

	}
private:
	int m_i;
	int m_f;
	
public:
	void SetInt(int i)
	{
		this->m_i = i;
	}
};
int main()
{
	// C++ 클래스 특징
	// 접근제한 지정자
	// 클래스 내의 멤버변수 or 멤버함수의 접근 레벨
	// 
	// 생성자, 소멸자
	// 객체 생성, 소멸 시 자동으로 호출
	// 직접 만들지 않으면 기본 생성자, 기본 소멸자가 만들어짐

	// 멤버함수
	// 해당 클래스가 사용하는 전용 함수
	// 해당 클래스의 객체가 필요함
	// 멤버함수를 객체를 통해서 호출하면,
	CMy c;
	c.SetInt(1);
	return 0;

	CMy c2;
	c2.SetInt(2);

	CMy c3;
	c3.SetInt(1000);
}