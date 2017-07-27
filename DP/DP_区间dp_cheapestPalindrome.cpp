/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-03 22:38:39
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-27 11:55:18
*/

//POJ 3280
//给出一个由m中字母组成的长度为n的串，给出m种字母添加和删除花费的代价，求让给出的串变成回文串的代价。

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
using namespace std;

#define INPUT_TEST freopen("in.txt", "r", stdin)

const int N = 3000;
const int INF = 99999999;

int dp[N][N];//dp[i][j]表示区间i到j变成回文的最小代价
int add[200];
string str;
int len;
int numberOfchar;
int addFee;
int delFee;
char soloChar;

int main(void)
{
	INPUT_TEST;

	while(~scanf("%d%d", &numberOfchar, &len)){
		cin>>str;
		for(int i=0;i<numberOfchar;i++){
			cin>>soloChar>>addFee>>delFee;
			add[(int)soloChar] = min(addFee, delFee);//简化了之后求最小值的过程
		}
		memset(dp, 0, sizeof(dp));
		for(int k=1;k<str.size();k++){//不同长度的串
			for(int i=0,j=k;j<str.size();i++,j++){
				dp[i][j] = INF;
				if(str[i] == str[j]){
					dp[i][j] = dp[i+1][j-1];
				}else{
					dp[i][j] = min(dp[i+1][j] + add[(int)str[i]], dp[i][j]);
					dp[i][j] = min(dp[i][j-1] + add[(int)str[j]], dp[i][j]);
				}
			}
		}
		printf("%d\n", dp[0][str.size() - 1]);
	}
    return 0;
}