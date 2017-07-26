/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-26 17:04:42
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-26 17:05:32
*/

//POJ 3267
//这道题当时算是明白了。希望以后还能记住

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

const int N = 700;

int strLen;
int dicNum;
char dict[N][N];
char str[N];
int dp[N];

int main(void)
{
	while(~scanf("%d%d", &dicNum, &strLen)){
		scanf("%s", str);
		for(int i=0;i<dicNum;i++){
			scanf("%s", dict[i]);
		}
		dp[strLen] = 0;
		for(int i=strLen-1;i>=0;i--){
			dp[i] = dp[i+1] + 1;
			for(int j=0;j<dicNum;j++){
				int len = strlen(dict[j]);
				if(dict[j][0] == str[i] && len <= strLen-i){
					int strPin = i;
					int dictPin = 0;
					while(strPin < strLen){
						if(dict[j][dictPin] == str[strPin]){
							strPin++;
							dictPin++;
						}else{
							strPin++;
						}

						if(dictPin == len){
							dp[i] = min(dp[i], dp[strPin] + (strPin - i) - len);
						}
					}
				}
			}
		}

		printf("%d\n", dp[0]);
	}
	return 0;
}