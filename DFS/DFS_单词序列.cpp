/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-09-28 13:10:21
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-09-28 17:51:55
*/

//简单dfs
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 20;
const int INF = 0x3f3f3f3f;

char stringSet[40][N];
char beginString[N];
char endString[N];
int ans, cnt;
bool vis[N];

int makediff(char a[N], char b[N])
{
	int len = (int)strlen(b);
	int diff = 0;
	for(int j=0;j<len;j++){
		if(a[j] != b[j]){
			diff++;
		}
	}
	return diff;
}


void dfs(int dep, char now[N], char tar[N])
{
//	printf("dep: %d now: %s    tar:%s\n", dep, now, tar);
	int difff = makediff(now, tar);
	if(difff == 1){
		ans = min(ans, dep+1);
		return;
	}
	
	for(int i=0;i<cnt;i++){
		int diff = makediff(now, stringSet[i]);
		if(diff == 1 && vis[i] == 0){
			vis[i] = 1;
			dfs(dep+1, stringSet[i], tar);
			vis[i] = 0;
		}
	}
}

int main(void)
{
	while(~scanf("%s%s", beginString, endString)){
		memset(vis, 0 ,sizeof(vis));
		cnt = 0;
		ans = INF;
		while(~scanf("%s", stringSet[cnt])){
			cnt++;
		}
		dfs(1, beginString, endString);
		if(ans == INF){
			printf("0\n");
		}else{
			printf("%d\n", ans);
		}
	}
	return 0;
}

