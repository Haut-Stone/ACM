/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-29 20:40:24
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-29 22:39:05
*/

//https://vjudge.net/contest/156294?#problem
//最小生成树专题。
//这道题是纯粹的最小生成树问题，相当于模版题
//该代码是这道题的Kruskal写法

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

const int N = 100;

int parents[27];

struct Node
{
	int begin;
	int end;
	int value;
}Imap[N];

//比较函数
bool cmp(Node a, Node b)
{	
	return a.value < b.value;
}

//并查集的查找
int find(int x)
{
	if(parents[x] == x){
		return x;
	}else{
		return parents[x] = find(parents[x]);
	}	
}

//初始化并查集
void init()
{
	for(int i=0;i<27;i++){//相当于声明了27个没有叶子的树。
		parents[i] = i;
	}
	return;
}

void read(int n, int &k)
{
	//数据的读入
	for(int i=0;i<n-1;i++){
		char beginChar[3];//用来解决空格
		int Number;
		cin>>beginChar>>Number;
		for(int j=0;j<Number;j++,k++){
			char endChar[3];
			int value;
			cin>>endChar>>value;
			Imap[k].begin = beginChar[0] - 'A';
			Imap[k].end = endChar[0] - 'A';
			Imap[k].value = value;
		}
	}
}

int main(void)
{
	int n;
	while(cin>>n, n){
		int k=0;
		init();
		read(n, k);
		sort(Imap, Imap+k, cmp);
		int ans = 0;
		for(int i=0;i<k;i++){
			int x = find(Imap[i].begin);
			int y = find(Imap[i].end);
			if(x != y){//如果两个点的根不相同
				ans += Imap[i].value;
				parents[y] = x;//这里将谁作为根都是无所谓的，因为不用考虑退化的情况。
			}
		}	
		cout<<ans<<endl;
	}	
    return 0;
}