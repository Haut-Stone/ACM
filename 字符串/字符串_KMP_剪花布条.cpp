/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-31 17:22:44
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-31 17:26:00
*/

//HDU 2087
//KMP的基础题，少做了一行下标增加的改变

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

const int N = 1100;

int iNext[N];

void getNext(char pattern[], int m)
{
	int j = -1;
	iNext[0] = -1;
	for(int i=1;i<m;i++){
		while(j != -1 && pattern[i] != pattern[j+1]){//这就是一个自身不断匹配的过程
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
	int lastPos = 0;
	int j = -1;
	getNext(pattern, m);
	for(int i=0;i<n;i++){
		while(j != -1 && text[i] != pattern[j+1]){
			j = iNext[j];
		}
		if(text[i] == pattern[j+1]){
			if(i > lastPos) lastPos = i;
			j++;
		}
		if(j == m-1){
			i += m - 1;
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
		int n = (int)strlen(text);
		int m = (int)strlen(pattern);
		int ans = kmp(text, n, pattern, m);
		printf("%d\n", ans);
	}
	return 0;
}