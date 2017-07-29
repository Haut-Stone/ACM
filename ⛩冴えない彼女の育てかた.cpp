/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-28 19:01:10
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-29 21:15:01
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
#define lid (id<<1)
#define rid (id<<1|1)
#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;

const int N = 1050;

int iMap[N][N];

int S;
int X, Y, A;
int L, B, R, T;
int n;

int lowbit(int x)
{
	return x&(-x);
}

void add(int x, int y, int val)
{	
	for(int i=1;i<=S;i+=lowbit(i)){
		for(int j=1;j<=S;j+=lowbit(j)){
			iMap[i][j] += val;
		}
	}
}

int query(int x, int y)
{
	int ans = 0;
	for(int i=x;i>=0;i-=lowbit(i)){
		for(int j=y;j>=0;j-=lowbit(j)){
			ans += iMap[i][j];
		}
	}
	return ans;
}


int main(void)
{
	int op;
	memset(iMap, 0, sizeof(iMap));
	while(scanf("%d", &op) && op != 3){
		if(op == 0){
			scanf("%d", &S);
		}else if(op == 1){
			scanf("%d%d%d", &X, &Y, &A);
			X++;Y++;
			add(X, Y, A);
		}else if(op == 2){
			scanf("%d%d%d%d", &L, &B, &R, &T);
			L++;B++;R++;T++;
			printf("%d\n", query(R, T) - query(R, B-1) - query(L-1, T) + query(L-1, B-1));
		}
	}
	return 0;
}