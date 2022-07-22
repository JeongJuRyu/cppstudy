#include <iostream>
#include <set>
#include <map>

#include <string>

using std::map;
using std::make_pair;
using std::set;

using std::wstring;
#define MAN 1
#define WOMAN 2

using std::wcout;
using std::endl;
struct tStdInfo
{
	wchar_t szName[20];
	unsigned char age;
	unsigned char gender;

	tStdInfo()
		:szName{}
		, age(0)
		, gender(0)
	{
	}
	tStdInfo(const wchar_t* _pName, unsigned char _age, unsigned char _gender)
		:szName{}
		, age(_age)
		, gender(_gender)
	{
		wcscpy_s(szName, _pName);
	}
};

class MyClass
{
	int a;
public:
	bool operator < (const MyClass& _other) const
	{
		if (a < _other.a)
			return true;
		else
			return false;
	}
	bool operator > (const MyClass& _other) const
	{
		return !(*this < _other);
	}
};
int main()
{
	// 이진탐색트리
	// 1. 이진탐색을 사용할 수 있게 고안된 이진트리
	// 2. 데이터 입력, 삭제, 탐색 시 O(logN) 효율
	// 3. 트리 밸런스가 유지되지 않으면, 최악의 경우 O(N)
	//    따라서, 자가균형 기능이 필요(AVL, RED/BLACK 트리)

	set<int> setInt;

	setInt.insert(100);
	setInt.insert(50);
	setInt.insert(150);
	
	const wchar_t* pStr = L"문자열";
	wchar_t szArr[100] = L"abdef";

	map<const wchar_t* , tStdInfo> mapData;

	tStdInfo info(L"홍길동", 18, MAN);
	tStdInfo info2(L"이지혜", 25, WOMAN);
	
	mapData.insert(make_pair(L"홍길동", info));
	mapData.insert(make_pair(L"이지혜", info2));
	// 주소값으로 비교를 하기 때문에, 문자열 사전순으로 관리하지는 않는다.
	map<const wchar_t*, tStdInfo>::iterator mapiter = mapData.find(L"이지혜");
	
	_wsetlocale(LC_ALL, L"korean");
	if (mapiter == mapData.end())
	{
		wcout << L"데이터를 찾을 수 없다." << endl;
	}
	else
	{
		wcout << L"이름 : " << mapiter->second.szName << endl;
		wcout << L"나이 : " << mapiter->second.age << endl;
		wcout << L"성별 : ";
		if (MAN == mapiter->second.gender)
		{
			wcout << L"남자" << endl;
		}
		else if (WOMAN == mapiter->second.gender)
		{
			wcout << L"여자" << endl;
		}
		
	}
	
	map<MyClass, tStdInfo> mapStdInfo;
	mapStdInfo.insert(make_pair(MyClass(), tStdInfo()));
	// 내부적으로 동적 할당을 통해서 문자열을 내부적으로 가진다.
	// 즉 문자열 포인터처럼 읽기 전용 메모리의 문자열 리터럴의 주소를 가지는 게 아닌
	// 직접 동적 할당한 영역에서 문자열을 관리한다.
	wstring str;
	str = L"abcdef";
	str += L"hijk";
	str += L"lmnop";
	str[1] = L'c';
	return 0;
}