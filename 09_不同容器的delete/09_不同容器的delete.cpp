// 09_不同容器的delete.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <list>
#include <set>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	//1.vector,string,deque
	vector<int> v1 = { 7 ,1, 9, 2, 0, 7, 7, 3, 4, 6, 8, 5, 7, 7 };
	auto first_need_delete = remove(v1.begin(), v1.end(), 7); //remove 删除指定的元素，但是会向前移位,最后的不受影响，返回指向不受影响的第一个(多余的第一个，因此在erase)
	//after remove: 1, 9, 2, 0, 3, 4, 6, 8, 5 ，6,8,5，7, 7（把所有满足条件的，等于7的删除，不是真删除，把不是7的向前移动，返回第一个需要erase的iterator，这里就是6）
	v1.erase(first_need_delete, v1.end());
	//after erase:1 9 2 0 3 4 6 8 5

	//remove移动所有不删除的元素到容器的开头，返回指向第一个需要erase的元素

	//简写为:
	//v1.erase(remove(v1.begin(), v1.end(), 1), v1.end());

	//2.list
	list<int> iList = { 1,2,3,4,55,23,2,3,312,1 };
	iList.remove(3);

	//3.关联容器
	set<int> iSet = { 1,2,3,4,5 };
	iSet.erase(2);


	//带条件的删除
	//1.vector,string,deque
	vector<int> v2 = { 7 ,1, 9, 2, 0, 7, 7, 3, 4, 6, 8, 5, 7, 7 };
	v2.erase(remove_if(v2.begin(), v2.end(), [](int a) { return a > 6; }), v2.end());

	//2.list
	list<int> iList1 = { 1,2,3,4,55,23,2,3,312,1 };
	iList1.remove_if([](int a) { return a > 4; });

	//3.关联容器
	set<int> iSet1 = { 1,2,3,4,5 };
	for (auto it = iSet1.begin(); it != iSet1.end();)
	{
		if (*it == 3)
			iSet1.erase(it++); //删除后当前iterator就已经失效了，所以不能再去++，必须先拿到一个副本
		else
			++it;
	}


	//需要做点什么其他事的情况
	//1.vector,string,deque
	vector<int> v3 = { 7 ,1, 9, 2, 0, 7, 7, 3, 4, 6, 8, 5, 7, 7 };
	for (auto it = v3.begin(); it != v3.end();)
	{
		if (*it == 7) //删除后，当前元素后面所有的it都失效，必须重新赋值，erase返回删除元素之后第一个元素
		{
			it = v3.erase(it);
			//dosomething
		}
		else
			++it;
	}

	//2.list(采用和vector类似的就行了)

	//3.关联容器,和3.一样，erase后递增(副本)就行了


	system("pause");
	return 0;
}

