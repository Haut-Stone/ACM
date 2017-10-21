/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-19 20:45:56
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-19 21:33:13
*/

//很巧妙的运用排序标记的一道题，最后从尾部扫描一遍的过程十分的神奇。
//这道题也可以用单调栈来写， 但是在大数据的时候，两个栈来回颠倒的花费太多，会超时
//https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1272
//http://blog.csdn.net/f_zyj/article/details/52184928

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
#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;


const int N = 110000;

struct Node
{
	int id;
	int v;
}node[N];

bool cmp(const Node &a, const Node &b)
{
	if(a.v == b.v){
		return a.id < b.id;
	}
	return a.v < b.v;
}

int main(void)
{
	int n;
	int book[N];
	memset(book, 0, sizeof(book));

	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &node[i].v);
		node[i].id = i;
	}
	
	sort(node+1, node+1+n, cmp);
	
	int flag = 1;
	int dis = 0;
	for(int i=n;i>1;i--){
		if(dis < node[i].id - flag){
			dis  = node[i].id - flag;
		}
		book[node[i].id] = 1;
		if(node[i].id == flag){
			while(book[flag]){
				flag++;
			}
		}
	}
	
	printf("%d\n", dis);
}