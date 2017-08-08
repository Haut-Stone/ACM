/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-07 10:55:55
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-07 11:49:28
*/

//第一次做状压DP,照着秦学长的博客写的
//http://blog.csdn.net/ssimple_y/article/details/52016250
//HDU 1074

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

const int N = 110;
const int INF = 99999999;

int n, binaryN;
int deadline[N];
int needTime[N];
int nowTime[N];
int pre[N];
char subjectName[20][N];
int dp[N];

void outPut(int n)
{
	if(!n) return;
	outPut(n-(1<<pre[n]));
	printf("%s\n", subjectName[pre[n]]);
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%s%d%d", subjectName[i], &deadline[i], &needTime[i]);
		}
		binaryN = 1<<n;//所有作业都做完时的二进制表示
		
		for(int i=1;i<binaryN;i++){//遍历所有作业的完成状态
			dp[i] = INF;
			for(int j=n-1;j>=0;j--){//从左到右假设这个作业新完成
				int subjectNow = 1<<j;
				if((subjectNow&i) == 0) continue;//如果遍历的状态里这个作业没有完成，就直接跳过
				int deductionPoints = nowTime[i-subjectNow] + needTime[j] - deadline[j];
				if(deductionPoints < 0){
					deductionPoints = 0;
				}
				if(dp[i] > dp[i - subjectNow] + deductionPoints){//如果这个作业没有完成时的状态的总罚分，比现在小就更新。
					dp[i] = dp[i - subjectNow] + deductionPoints;
					nowTime[i] = nowTime[i - subjectNow] + needTime[j];
					pre[i] = j;
				}
			}
		}
		printf("%d\n", dp[binaryN-1]);
		outPut(binaryN - 1);
	}
}