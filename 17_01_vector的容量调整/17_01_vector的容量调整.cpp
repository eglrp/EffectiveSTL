// 17_01_vector的容量调整.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{

	vector<int> ivec1 = { 1,2,3,4,5 };


	cout << ivec1.capacity() << endl; //5
	ivec1.push_back(10);
	cout << ivec1.capacity() << endl;//7

	ivec1.reserve(10);
	cout << ivec1.capacity() << endl;//10

	ivec1.reserve(6);
	cout << ivec1.capacity() << endl;//10  reverse不能调小

	vector<int>(ivec1).swap(ivec1);  //通过这种建立一个临时对象的方法，拷贝一次元素，调整vector的容量

	cout << ivec1.capacity() << endl;//6,此方法可以调整


	//string也是类似的

	system("pause");
    return 0;
}

