/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-09 21:53:52
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-09 21:55:45
*/

//嗯，很好的一道题，可是就是不太明白为什么要排序。
//http://blog.csdn.net/f_zyj/article/details/52089537

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

const int N = 50010;// 50010

struct Node
{
	long long sum;
	int pos;
}node[N];

int n;

bool cmp(Node a, Node b)
{
	if(a.sum == b.sum){
		return a.pos > b.pos;
	}
	return a.sum < b.sum;
}

int main(void)
{
	long long sum = 0;
	long long temp;
	long long res = 0;
	bool flag = false;
	
	node[0].pos = 0;
	node[0].sum = 0;
	
	scanf("%d", &n);
	
	for(int i=1;i<=n;i++){
		scanf("%lld", &temp);
		sum += temp;
		node[i].pos = i;
		node[i].sum = sum;
	}
	
	sort(node, node+n+1, cmp);
	
	for(int i=1;i<=n;i++){
		if(node[i].pos > node[i-1].pos && node[i].sum > node[i-1].sum){
			if(!flag){
				flag = true;
				res = node[i].sum - node[i-1].sum;
			}else{
				res = min(res, node[i].sum - node[i-1].sum);
			}
		}
	}
	printf("%lld", res);
	return 0;
}
