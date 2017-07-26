/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-27 12:23:38
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-27 22:42:04
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <string>
#include <iterator>
#include <numeric>
#include <list>
#include <queue>
using namespace std;

bool Comp(const int &a, const int &b){
	return a>b;
}


int main(void)
{
#if 0 	
	//这段代码用来展现C++ STL 的威力
	//用来对字符串排序，和去重。
	//66666
	set<string> coll((istream_iterator<string>(cin)), (istream_iterator<string>()));
	copy(coll.begin(), coll.end(), ostream_iterator<string>(cout, "\n"));
#endif

#if 0
	//迭代器不就是代替是i的替代品嘛
	vector<int> v;
	for(int i=0;i<10;i++){
		v.push_back(i);
	}
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout<<*it<<" ";
	}
	cout<<endl;
#endif

#if 0
	//测试累加函数accumulate
	vector<int> v;
	for(int i=0;i<10;i++){
		v.push_back(i);//在末尾加上i
	}
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	cout<<accumulate(v.begin(), v.end(), 0)<<endl;
#endif 

#if 0
	//可变长数组
	vector<int> v;
	v.push_back(3);//尾部插入
	v.push_back(2);
	v.push_back(1);
	v.push_back(0);
	cout<<"下标"<<v[3]<<endl;
	cout<<"迭代器"<<endl;
	for(std::vector<int>::iterator it=v.begin(); it!=v.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	v.insert(v.begin(), 111);//在第一个元素之前插入111  insert begin+n是在第n个元素之前插入
	v.insert(v.end(), 222); //在最后一个元素之后插入222 insert end + n 是在n个元素之后插入

	for(vector<int>::iterator i=v.begin();i!=v.end();i++){
		cout<<*i<<" ";
	}
	cout<<endl;

	std::vector<int> arr(10);
	for(int i=0;i<10;i++){
		arr[i] = i;
	
	for(std::vector<int>::iterator i=arr.begin(); i!=arr.end(); i++){
		cout<<*i<<" ";
	}
	cout<<endl;
	//删除 同insert
	arr.erase(arr.begin());

	for(std::vector<int>::iterator i=arr.begin();i!=arr.end();i++){
		cout<<*i<<" ";
	}
	cout<<endl;

	arr.erase(arr.begin(), arr.begin()+5);

	for(vector<int>::iterator i = arr.begin();i!= arr.end();++i){
	    cout << *i << " " ;
	}
	cout << endl ;
#endif

#if 0
	//数组反转函数
	std::vector<int> v;
	for(int i=0;i<10;i++){
		v.push_back(i);
	}

	for(std::vector<int>::iterator it=v.begin();it!=v.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;

	reverse(v.begin(), v.end());

	for(std::vector<int>::iterator i=v.begin();i!=v.end();i++){
		cout<<*i<<" ";
	}
	cout<<endl;
#endif

#if 0
	//排序函数，这个就不多说了
	std::vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(55);
	v.push_back(-1);
	v.push_back(0);
	v.push_back(23);
	v.push_back(42);
	v.push_back(4);
	v.push_back(547);

	sort(v.begin(), v.end(),Comp);

#endif

#if 0
	//字符串数据类型
	string s1;
	s1 = "hello";

	string s2;
	char s[1024];
	//scanf 输入速度比cin快的多
	//scanf 是C函数，不可以输入string
	scanf("%s", s);
	s2 = s;//可以直接相等复制了。

	cout<<s1<<endl;
	cout<<s2<<endl;
	cout<<s1+s2<<endl;
	s2.append("123");
	s2 += 'a';
#endif

#if 0
	//字符串的删除操作
	string s;
	s = "0123456789";
	cout<<s<<endl;

	string::iterator it = s.begin();

	s.erase(it+3);
	cout<<s<<endl;

	s = "0123456789";
	s.erase(it+1, it+4);
	cout<<s<<endl;

	s.clear();
	cout<<"clear :"<<endl;
#endif

#if 0
	//set结构
	//
	set<int> v;
	v.insert(1);
	v.insert(3);
	v.insert(5);
	v.insert(2);
	v.insert(4);
	v.insert(3);

	//中序遍历 升序遍历
	for(set<int>::iterator it=v.begin();it!=v.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;

	for(set<int>::reverse_iterator rit=v.rbegin();rit!=v.rend();rit++){
		cout<<*rit<<" ";
	}
	cout<<endl;
#endif

#if 0
	//map就是字典
	std::map<string, double> m;
	m["li"] = 123.4;
	m["wang"] = 23.1;
	m["zhang"] = -21.9;
	m["abc"] = 12.1;
	for(map<string, double>::iterator it=m.begin();it!=m.end();it++){
		cout<<(*it).first<<":"<<(*it).second<<endl;
	}
	cout<<endl;
#endif

#if 0
	//用map实现数字分离
	std::map<char, int> m;

	m['0'] = 0;
	m['1'] = 1;
	m['2'] = 2;
	m['3'] = 3;
	m['4'] = 4;
	m['5'] = 5;
	m['6'] = 6;
	m['7'] = 7;
	m['8'] = 8;
	m['9'] = 9;

	/*
         等价于
         for(int i = 0; i < 10; ++i)
         {
             m['0' + i] = i;
         }
     */
    
    string sa;
    sa = "9876543210";
    int sum = 0;
    for(int i=0;i<sa.length();i++){
    	sum += m[sa[i]];
    }
    cout<<sum<<endl;
#endif

#if 0
	//map number->string
	std::map<int, char> m;

	for(int i=0;i<10;i++){
		m[i] = '0' + i;
	}

	int n=7;

	string out = "the number is :";
	cout<< out + m[n] <<endl;
#endif

#if 0
	//list
	list<int> i;
	i.push_back(1);
	i.push_front(2);
	i.sort();
	for(list<int>::iterator it=i.begin();it!=i.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	i.pop_front();
	i.pop_back();
#endif

#if 0
	//栈
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	cout<<s.size()<<endl;

	while(s.empty() != true){
		cout<<s.top()<<endl;
		s.pop();
	}
#endif

#if 0
	//队列
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	cout<<q.size()<<endl;

	while(q.empty() != true){
		cout<<q.front()<<endl;
		q.pop();
	}
#endif

#if 0
	//优先队列
	priority_queue<int> pq;
	pq.push(1);
	pq.push(3);
	pq.push(2);
	pq.push(8);
	pq.push(9);
	pq.push(0);

	cout<<"size :"<<pq.size()<<endl;

	while(pq.empty() != true){
		cout<<pq.top()<<endl;
		pq.pop();
	}
	//重载操作符合set的重载相同。
#endif

    return 0;
}