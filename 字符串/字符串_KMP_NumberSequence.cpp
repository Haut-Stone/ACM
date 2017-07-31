/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-31 16:48:09
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-31 16:48:50
*/

//HDU 1711
//KMP的一道裸题

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

const int N = 11000;
int iNext[N];

void getNext(int b[], int m)
{
	int j = -1;
	iNext[0] = -1;
	for(int i=1;i<m;i++){
		while(j != -1 && b[i] != b[j+1]){
			j = iNext[j];
		}
		if(b[i] == b[j+1]){
			j++;
		}
		iNext[i] = j;
	}
}

int kmp(int a[], int b[], int n, int m)
{
	int ans = 0;
	int j = -1;
	getNext(b, m);
	for(int i=0;i<n;i++){
		while(j != -1 && a[i] != b[j+1]){
			j = iNext[j];
		}
		if(a[i] == b[j+1]){
			if(i > ans) ans = i;
			j++;
		}
		if(j == m - 1){
			return ans - m + 2;
		}
	}
	return -1;
}

int main(void)
{
	int T;
	int n, m;
	int a[N];
	int b[N];
	scanf("%d", &T);
	while(~scanf("%d%d", &n, &m)){
		for(int i=0;i<n;i++){
			scanf("%d", &a[i]);
		}
		for(int i=0;i<m;i++){
			scanf("%d", &b[i]);
		}
		int ans = kmp(a, b, n, m);
		printf("%d\n", ans);
	}
}