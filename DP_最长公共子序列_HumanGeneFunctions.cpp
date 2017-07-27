/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-27 08:55:22
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-27 08:56:50
*/

//POJ/HDU 1080
//最长公共子序列的思想求解

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

int dp[N][N];
char a[N];
char b[N];
int  match[N][N];

int lenA, lenB;

void init()
{
	match['A']['A']=match['C']['C']=match['G']['G']=match['T']['T']=5;
	match['A']['C']=match['C']['A']=match['A']['T']=match['T']['A']=-1;
	match[' ']['T']=match['T'][' ']=-1;
	match['A']['G']=match['G']['A']=match['C']['T']=match['T']['C']=-2;
	match['G']['T']=match['T']['G']=match['G'][' ']=match[' ']['G']=-2;
	match['A'][' ']=match[' ']['A']=match['C']['G']=match['G']['C']=-3;
	match['C'][' ']=match[' ']['C']=-4;
}

int main(void)
{
	init();
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d %s", &lenA, a+1);
		scanf("%d %s", &lenB, b+1);

		dp[0][0] = 0;
		for(int i=1;i<=lenA;i++){
			dp[i][0] = dp[i-1][0] + match[a[i]][' '];
		}

		for(int i=1;i<=lenB;i++){
			dp[0][i] = dp[0][i-1] + match[' '][b[i]];
		}

		for(int i=1;i<=lenA;i++){
			for(int j=1;j<=lenB;j++){
				dp[i][j] = max(dp[i-1][j] + match[a[i]][' '], dp[i][j-1] + match[' '][b[j]]);
				dp[i][j] = max(dp[i][j], dp[i-1][j-1] + match[a[i]][b[j]]);
			}
		}

		printf("%d\n", dp[lenA][lenB]);
	}
	return 0;
}