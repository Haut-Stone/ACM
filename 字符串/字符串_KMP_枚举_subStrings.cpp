/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-01 18:47:07
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-01 18:48:34
*/

//HDU 1238
//暴力枚举字符串，然后正序匹配再倒序匹配。

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

const int N = 200;
const int INF = 99999999;
char strings[N][N];

int iNext[N];


void getNext(char pattern[], int n)
{
	int j = -1;
	iNext[0] = -1;
	
	for(int i=1;i<n;i++){
		while(j != -1 && pattern[i] != pattern[j+1]){
			j = iNext[j];
		}
		if(pattern[i] == pattern[j+1]){
			j++;
		}
		iNext[i] = j;
	}
}

bool kmp(char text[], char pattern[])
{
	int textLen = (int)strlen(text);
	int patternLen = (int)strlen(pattern);
	getNext(pattern, patternLen);
	
	int j = -1;
	
	for(int i=0;i<textLen;i++){
		while(j != -1 && text[i] != pattern[j+1]){
			j = iNext[j];
		}
		if(text[i] == pattern[j+1]){
			j++;
		}
		if(j == patternLen - 1){
			return true;
		}
	}
	return false;
}

int main(void)
{
	int T;
	int n;
	int minLen;
	int minPos;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		int maxAns = 0;
		minLen = INF;
		minPos = INF;
		for(int i=0;i<n;i++){
			scanf("%s", strings[i]);
			if(strlen(strings[i]) < minLen){
				minLen = (int)strlen(strings[i]);
				minPos = i;
			}
		}
		for(int i=0;i<minLen;i++){
			for(int j=i+1;j<=minLen;j++){
				char pattern[N];
				char patternBack[N];
				int cnt = 0;
				int cnt2 = 0;
				for(int k=i;k<j;k++){
					pattern[cnt++] = strings[minPos][k];
				}
				for(int k=j-1;k>=i;k--){
					patternBack[cnt2++] = strings[minPos][k];
				}
				pattern[cnt] = '\0';
				patternBack[cnt2] = '\0';
				int ans = 0;
				for(int k=0;k<n;k++){
					if(kmp(strings[k], pattern) || kmp(strings[k], patternBack)){
						ans++;
					}
				}
				if(ans == n){
					if(j - i > maxAns) maxAns = j-i;
				}
			}
		}
		printf("%d\n", maxAns);
	}
	return 0;
}