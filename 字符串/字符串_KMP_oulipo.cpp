/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-31 20:25:23
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-31 20:25:32
*/

//
//

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

const int N = 1000100;
int iNext[N];

void getNext(char pattern[], int m)
{
	int j = -1;
	iNext[0] = -1;

	for(int i=1;i<m;i++){
		while(j!=-1 && pattern[i]!=pattern[j+1]){
			j = iNext[j];
		}
		if(pattern[i] == pattern[j+1]){
			j++;
		}
		iNext[i] = j;
	}
}

int kmp(char pattern[], char text[], int n, int m)
{
	int ans = 0;
	int j = -1;
	getNext(pattern, m);

	for(int i=0;i<n;i++){
		while(j!=-1 && text[i]!=pattern[j+1]){
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
	int T;
	char pattern[N];
	char text[N];
	scanf("%d", &T);
	while(T--){
		scanf("%s%s", pattern, text);
		int n = strlen(text);
		int m = strlen(pattern);
		int ans = kmp(pattern, text, n, m);
		printf("%d\n", ans);
	}
	return 0;
}