/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-03 20:19:50
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-03 20:24:36
*/

//POJ 3070
//求第n个斐波那契数，是几,矩阵快速幂模版

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

const int MOD = 10000;
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
		A.ma[0][0] = A.ma[0][1] = A.ma[1][0] = 1;
		A.ma[1][1] = 0;
		Matrix ans = powerMod(A, n);
		printf("%lld\n", ans.ma[0][1]);
	}
	return 0;
}