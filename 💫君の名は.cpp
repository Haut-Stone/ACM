/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-06-03 12:15:58
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-07-29 21:12:24
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
#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;

const int N = 100;

int a[9] = {0,5,3,7,9,6,4,1,2};
int iMap[N][N];
int S = 8;
int X, Y, A;
int L, B, R, T;
int n = 8;

int lowbit(int x)
{
	return x&(-x);
}

void add(int x, int y, int val)
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
	for(int k=1;k<=n;k++){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=k;j++){
				add(i, j, a[k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		int ans = qurey(i, i);
		printf("%d\n", ans);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=k;j++){
				printf("%-3d ", iMap[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("%d\n", qurey(2, 2));
	return 0;
}