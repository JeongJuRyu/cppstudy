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
	/*vector<int> vecInt;
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
		if (*veciter % 2 == 0)
		{
			veciter = vecInt.erase(veciter);
		}
		else
		{
			veciter++;
		}
	}
	for (int i = 0; i < vecInt.size(); i++)
	{
		cout << vecInt[i] << endl;
	}*/

	// ===================
	// list iterator test
	// ===================

	
	CList<int> mylist;

	mylist.push_back(100);
	mylist.push_back(300);
	mylist.push_back(400);

	CList<int>::iterator listiter = mylist.begin();
	++listiter;
	mylist.insert(listiter, 200);
	for (listiter = mylist.begin(); listiter != mylist.end(); ++listiter)
	{
		cout << *listiter << endl;
	}

	
	return 0;

}

