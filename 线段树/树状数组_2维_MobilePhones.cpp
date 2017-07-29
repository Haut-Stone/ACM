/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-29 18:11:39
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-29 21:01:53
*/

//树状数组其实就是只可以计算从1->i的线段树。通过区间相减的方式得出所需要的值
//

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

const int N = 1050;

int iMap[N][N];
int S;
int X, Y, A;
int L, B, R, T;
int t, n;

int lowbit(int x)
{
	return x&(-x);
}

void add(int x, int y, int val)//更新的话其实还是单点更新。
{
	for(int i=x;i<=S;i+=lowbit(i)){
		for(int j=y;j<=S;j+=lowbit(j)){
			iMap[i][j] += val;
		}
	}
}

int qurey(int x, int y)
{
	int ans = 0;
	for(int i=x;i>0;i-=lowbit(i)){
		for(int j=y;j>0;j-=lowbit(j)){
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
			printf("%d\n", qurey(R, T) - qurey(R, B-1) - qurey(L-1, T) + qurey(L-1, B-1));
		}
	}
	return 0;
}