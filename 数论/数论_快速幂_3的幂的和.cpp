/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-09 19:31:36
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-09 19:32:36
*/


//与斐波那契数列不同的是，初始的矩阵数值不一样
//https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1013

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

const int MOD = 1e9+7;
struct Matrix
{
	long long ma[2][2];
};

Matrix mul(Matrix A, Matrix B)
{
	Matrix C;
	C.ma[0][0] = C.ma[0][1] = C.ma[1][0] = C.ma[1][1] = 0;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				C.ma[i][j] = (C.ma[i][j] + A.ma[i][k]*B.ma[k][j]) % MOD;
			}
		}
	}
	return C;
}

Matrix powerMod(Matrix A, long long n)
{
	Matrix B;
	B.ma[0][0] = B.ma[1][1] = 1;
	B.ma[0][1] = B.ma[1][0] = 0;
	while(n){
		if(n & 1){
			B = mul(B, A);
		}
		A = mul(A, A);
		n >>= 1;
	}
	return B;
}

int main(void)
{
	long long n;
	while(~scanf("%lld", &n) && n != -1){
		Matrix A;
		A.ma[0][0] = 3;
		A.ma[0][1] = 1;
		A.ma[1][0] = 0;
		A.ma[1][1] = 1;
		Matrix ans = powerMod(A, n);
		printf("%lld\n", (ans.ma[0][1] + ans.ma[0][0]) % MOD);
	}
	return 0;
}
