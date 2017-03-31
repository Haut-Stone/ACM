/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-29 20:40:24
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-31 13:43:27
*/

//https://vjudge.net/contest/156294?#problem
//最小生成树专题。
//这道题是纯粹的最小生成树问题，相当于模版题
//该代码是这道题的Kruskal写法

/*
Kruskal算法的基本思想
假设WN=(V,{E})是一个含有n个顶点的连通网，则按照克鲁斯卡尔算法构造最小生成树的过程为：
先构造一个只含n个顶点，而边集为空的子图，
若将该子图中各个顶点看成是各棵树上的根结点，则它是一个含有n棵树的一个森林。
之后，从网的边集E中选取一条权值最小的边，若该条边的两个顶点分属不同的树，则将其加入子图，
也就是说，将这两个顶点分别所在的两棵树合成一棵树；
反之，若该条边的两个顶点已落在同一棵树上，则不可取，而应该取下一条权值最小的边再试之。
依次类推，直至森林中只有一棵树，也即子图中含有n-1条边为止。
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
	if(parents[x] == x){//到达根结点的时候
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
			print(n);
			int y = find(Imap[i].end);
			print(n);
			if(x != y){//如果两个点的根不相同
				ans += Imap[i].value;
				parents[y] = x;//这里将谁作为根都是无所谓的，因为不用考虑退化的情况。
			}
		}	
		cout<<ans<<endl;
	}	
    return 0;
}