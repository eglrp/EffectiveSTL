// 20_01_指针的容器指定比较类型.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


struct StringPrtLess:binary_function<const string*, const string *, bool>
{
public:
	bool operator()(const string *ps1, const string *ps2)const
	{
		return *ps1 < *ps2;
	}
};

template<class _Ty = void>
struct PtrLess
{	// functor for operator<
	//typedef _Ty first_argument_type;
	//typedef _Ty second_argument_type;
	//typedef bool result_type;

	constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const
	{	// apply operator< to operands
		return (*_Left < *_Right);
	}
};


struct DereferenceLess
{	
	template<class T>
	constexpr bool operator()(const T _Left, const T _Right) const
	{	// apply operator< to operands
		return (*_Left < *_Right);
	}
};


int main()
{



	set<string*, StringPrtLess> v = {
			new string("aaa"),
			new string("baa"),
			new string("aca"),
			new string("acd")
	};

	for_each(v.begin(), v.end(), [](string *ps) {cout << *ps << endl; });//调用自己定义的比较类实现从小到大排序


	set<string*, PtrLess<string *>> v1 = {
		new string("aaa"),
		new string("baa"),
		new string("aca"),
		new string("acd")
	};
	//这种方法是从VS的源文件里面拷出来的，也可以
	for_each(v1.begin(), v1.end(), [](string *ps) {cout << *ps << endl; });

	set<string*, DereferenceLess> v2 = {
		new string("aaa"),
		new string("baa"),
		new string("aca"),
		new string("acd")
	};
	//另一种方法，模板拿到了类内部，使用的时候就不需要再指定类型了
	for_each(v2.begin(), v2.end(), [](string *ps) {cout << *ps << endl; });


	

	system("pause");
	return 0;
}

