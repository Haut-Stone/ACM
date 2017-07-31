/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-28 19:01:10
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-31 17:23:18
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
using namespace std;

const int N = 100;

int iNext[N];

void getNext(char pattern[], int m)
{
	int j = -1;
	iNext[0] = -1;
	for(int i=1;i<m;i++){
		while(j != -1 && pattern[i] != pattern[j+1]){
			j = iNext[j];
		}
		if(pattern[i] == pattern[j+1]){
			j++;
		}
		iNext[i] = j;
	}
}

int kmp(char text[], int n, char pattern[], int m)
{
	int ans = 0;
	int j = -1;
	getNext(pattern, m);

	for(int i=0;i<n;i++){
		while(j != -1 && text[i] != pattern[j+1]){
			j = iNext[j];
		}
		if(text[i] == pattern[j+1]){
			j++;
		}
		if(j == m-1){
			ans++;
		}
	}
	return ans;
}

int main(void)
{
	char text[N];
	char pattern[N];

	while(scanf("%s", text) && text[0] != '#'){
		scanf("%s", pattern);
		int n = strlen(text);
		int m = strlen(pattern);
		int ans = kmp(text, n, pattern, m);
		printf("%d\n", ans);
	}
	return 0;
}