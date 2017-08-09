/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-09 20:40:05
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-09 20:45:47
*/

//这题来是用dp做的，让而这个dfs的写法异常的优雅
//http://cxsjsxmooc.openjudge.cn/2017t2summerw5/4/
//http://blog.csdn.net/morgan_xww/article/details/5596030

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

const int N = 202;

char str1[N];
char str2[N];
char targetStr[N*2];

bool dfs(int x, int y)
{
	if(x == -1 && y == -1){
		return true;
	}
	if(x >= 0 && str1[x] == targetStr[x+y+1]){
		if(dfs(x-1, y)){
			return true;
		}
	}
	if(y >= 0 && str2[y] == targetStr[x+y+1]){
		if(dfs(x, y-1)){
			return true;
		}
	}
	return false;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%s %s %s", str1, str2, targetStr);
		int len1 = (int)strlen(str1);
		int len2 = (int)strlen(str2);
		if(dfs(len1-1, len2-1)){
			printf("Data set %d: yes\n", i);
		}else{
			printf("Data set %d: no\n", i);
		}
	}
}
