#include <iostream>

#include "CList.h"
#include "CArr.h"

#include <vector>
#include <list>

using std::cout;
using std::vector;
using std::list;
using std::endl;

namespace MYSPACE
{
	int g;
}
void MyEndL()
{
	wprintf(L"\n");

}
class CMyOStream
{
public:
	CMyOStream& operator << (int _idata)
	{
		printf("%d", _idata);
		return *this;
	}
	CMyOStream& operator << (const wchar_t* _pString)
	{
		wprintf(L"%s", _pString);
		return *this;
	}
	CMyOStream& operator << (void(*_pFunc)(void) ){
		_pFunc();
		return *this;
	}
};
int main()
{
	vector<int> vecInt;
	CArr<int> myvector;
	myvector.push_back(1);
	myvector.push_back(2);
	myvector.push_back(3);

	CArr<int>::iterator myiter = myvector.begin();

	myiter = myvector.erase(myiter);

	int k = *myiter;
	
	vecInt.clear();
	// 1~10을 벡터에 입력
	for (int i = 0; i < 11; ++i)
	{
		vecInt.push_back(i + 1);
	}
	
	//1~5만 제거
	vector<int>::iterator veciter;
	veciter = vecInt.begin();
	for (; veciter != vecInt.end();)
	{
		if (1 <= *veciter && 5 >= *veciter)
		{
			veciter = vecInt.erase(veciter);
		}
		else veciter++;
	}
	for (int i = 0; i < vecInt.size(); i++)
	{
		cout << vecInt[i] << endl;
	}
	return 0;

}

