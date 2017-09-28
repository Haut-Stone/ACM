/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-09-28 14:49:21
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-09-28 14:50:33
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int N = 210;

int dp[N][N];
int iMap[N][N];
int total[N];

//于是就转换成了最大子列和问题
int maxSubArray(int a[], int n)
{
	int thisSum, maxSum;
	int i;
	thisSum = maxSum = 0;
	for(i=0;i<n;i++){
		thisSum += a[i];//累加
		if(thisSum > maxSum){
			maxSum = thisSum;//更新结果
		}else if(thisSum < 0){
			thisSum = 0;//如果有负的则抛弃掉
		}
	}
	return maxSum;
}

//将不同行的数值全部加在一起
int maxSumInMatrix(int n)
{
	memset(total, 0, sizeof(total));
	int max_n = iMap[0][0];
	int iMax = iMap[0][0];
	for(int i=0;i<n;i++){
		memset(total, 0, sizeof(total));
		for(int j=i;j<n;j++){
			for(int k=0;k<n;k++){
				total[k] += iMap[j][k];
			}
			max_n = maxSubArray(total, n);
			if(iMax < max_n){
				iMax = max_n;
			}
		}
	}
	return iMax;
}

int main(void)
{
	int n;
	while(~scanf("%d", &n)){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d", &iMap[i][j]);
			}
		}
		printf("%d\n", maxSumInMatrix(n));
	}
	return 0;
}
