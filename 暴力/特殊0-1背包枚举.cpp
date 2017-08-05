/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-05 11:02:36
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-05 11:03:39
*/

//http://172.18.66.54:50015/JudgeOnline/problem.php?id=1279
//这题dp的话，空间存不下。用限制条件进行枚举
//mdzz

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

long long n;
long long maxCapacity;
long long A[N], B[N], C[N], D[N];
int counterA, counterB, counterC, counterD;
int w1, w;

int main(void)
{
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%lld%lld", &n, &maxCapacity);
		scanf("%d%lld", &w1, &A[++counterA]);
		for(int i=2;i<=n;i++){
			scanf("%d", &w);
			if(w == w1){
				scanf("%lld", &A[++counterA]);
			}
			if(w == w1 + 1){
				scanf("%lld", &B[++counterB]);
			}
			if(w == w1 + 2){
				scanf("%lld", &C[++counterC]);
			}
			if(w == w1 + 3){
				scanf("%lld", &D[++counterD]);
			}
			sort(A+1, A+counterA+1, greater<int>());
			sort(B+1, B+counterB+1, greater<int>());
			sort(C+1, C+counterC+1, greater<int>());
			sort(D+1, D+counterD+1, greater<int>());
			A[0] = B[0] = C[0] = D[0] = 0;
			for(int i=2;i<=counterA;i++){
				A[i] += A[i-1];
			}
			for(int i=2;i<=counterB;i++){
				B[i] += B[i-1];
			}
			for(int i=2;i<=counterC;i++){
				C[i] += C[i-1];
			}
			for(int i=2;i<=counterD;i++){
				D[i] += D[i-1];
			}
			long long ans = 0;
			for(int i=0;i<=counterA;i++){
				for(int j=0;j<=counterB;j++){
					for(int k=0;k<=counterC;k++){
						for(int l=0;l<=counterD;l++){
							long long sum = i*w1 + j*(w1+1) + k*(w1+2) + l*(w1+3);
							if(sum <= maxCapacity){
								ans = max(ans, A[i] + B[j] + C[k] + D[l]);
							}
						}
					}
				}
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}