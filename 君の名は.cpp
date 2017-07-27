/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-06-03 12:15:58
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-07-27 18:16:50
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

const int N = 2100;
const int INF = 99999999;

int dp[N][N];
int fee[N];
int stringLen;
int charNum;
int addFee;
int delFee;
char str[N];
char temp[N];

int main(void)
{
	while(~scanf("%d%d", &charNum, &stringLen)){
		scanf("%s", str);
		for(int i=0;i<charNum;i++){
			scanf("%s%d%d", temp, &addFee, &delFee);
			fee[(int)temp[0]] = min(addFee, delFee);
		}
		memset(dp, 0, sizeof(dp));
		for(int k=1;k<=stringLen;k++){
			for(int i=0, j=k;j<stringLen;i++, j++){
				dp[i][j] = INF;
				if(str[i] == str[j]){
					dp[i][j] = dp[i+1][j-1];
				}else{
					dp[i][j] = min(dp[i][j], dp[i+1][j] + fee[(int)str[i]]);
					dp[i][j] = min(dp[i][j], dp[i][j-1] + fee[(int)str[j]]);
				}
			}
		}
		printf("%d\n", dp[0][stringLen-1]);
	}
	return 0;
}