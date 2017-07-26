/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-13 14:36:24
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-13 15:41:01
*/

//POJ 3264
//不过这种解法貌似并没有用到线段树
//http://blog.csdn.net/niushuai666/article/details/7401403

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

const int N = 50005;
int FMAX[N][20], FMIN[N][20];

void RMQ(int n)
{
	for(int j=1;j!=20;j++){
		for(int i=1;i<=n;i++){
			if(i +(1<<j) - 1 <= n){
				FMAX[i][j] = max(FMAX[i][j-1], FMAX[i+(1<<(j-1))][j-1]);
				FMIN[i][j] = min(FMIN[i][j-1], FMIN[i+(1<<(j-1))][j-1]);
			}
		}
	}
}

int main(void)
{
	int num, query;
	int a, b;
	while(~scanf("%d %d", &num, &query)){
		for(int i=1;i<=num;i++){
			scanf("%d", &FMAX[i][0]);
			FMIN[i][0] = FMAX[i][0];
		}
		RMQ(num);
		while(query--){
			scanf("%d%d", &a, &b);
			int k =(int)(log(b-a+1.0)/log(2.0));
			int maxsum = max(FMAX[a][k], FMAX[b-(1<<k)+1][k]);
			int minsum = min(FMIN[a][k], FMIN[b-(1<<k)+1][k]);
			printf("%d\n", maxsum - minsum);
		}
	}
	return 0;
}