/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-31 13:39:55
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-31 17:27:07
*/
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

const int N = 3000;
const int LEN = 55;

int parents[LEN];//因为init函数里用到相同的数，所以要避免幻数的产生(｡･ω･｡)
int ans;

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
	if(parents[x] == x){//到达根结点的时候
		return x;
	}else{
		return parents[x] = find(parents[x]);
	}	
}

//初始化并查集
void init()
{
	for(int i=0;i<LEN;i++){//相当于声明了27个没有叶子的树。
		parents[i] = i;
	}
	return;
}

void read(int n, int &edgeNumber)
{
	//数据的读入
	cin>>edgeNumber;
	for(int i=1;i<=edgeNumber;i++){
		scanf("%d %d %d", &Imap[i].begin, &Imap[i].end, &Imap[i].value);
	}
}

void kruskal(int edgeNumber)
{
	sort(Imap+1, Imap+edgeNumber+1, cmp);
	ans = 0;
	for(int i=0;i<edgeNumber;i++){
		int x = find(Imap[i].begin);
		int y = find(Imap[i].end);
		if(x != y){//如果两个点的根不相同
			ans += Imap[i].value;
			parents[y] = x;//这里将谁作为根都是无所谓的，因为不用考虑退化的情况。
		}
	}	
}

//用来观察并查集的值。
#if 0
void print(int n)	
{
	for(int i=0;i<n;i++){
		printf("%d ", i);
	}
	printf("\n");
	for(int i=0;i<n;i++){
		printf("%d ", parents[i]);
	}
	printf("\n");
}
#endif

int main(void)
{
	int n;
	int edgeNumber;
	while(cin>>n, n){
		init();
		read(n, edgeNumber);
		kruskal(edgeNumber);
		cout<<ans<<endl;
	}	
    return 0;
}