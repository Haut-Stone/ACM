/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-04 20:46:48
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-07 13:44:46
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

const int N = 1000010;
const int INF = 99999999;

int dp[N];
int deadline[N];
char subName[20][N];
int feeTime[N];
int lastTime[N];
int pre[N];
int n, m;

void outPut(int x)
{
	if(!x) return;
	outPut(x-(1<<pre[x]));
	printf("%s\n", subName[pre[x]]);
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%s%d%d", subName[i], &deadline[i], &feeTime[i]);
		}
		m = 1<<n;
		for(int i=1;i<m;i++){
			dp[i] = INF;
			for(int j=n-1;j>=0;j--){
				int subNow = 1<<j;
				if((subNow&i) == 0) continue;
				int reducePoint = lastTime[i-subNow]+feeTime[j]-deadline[j];
				if(reducePoint < 0){
					reducePoint = 0;
				}
				if(dp[i] > dp[i-subNow] + reducePoint){
					dp[i] = dp[i-subNow] + reducePoint;
					lastTime[i] = lastTime[i-subNow] + feeTime[j];
					pre[i] = j;
				}
			}
		}
		printf("%d\n", dp[m-1]);
		outPut(m-1);
	}
	return 0;
}