/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-14 20:56:57
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-14 20:58:07
*/

//一道二分图匹配的裸题，只要分清楚是课程匹配学生就行了。
//http://blog.csdn.net/niushuai666/article/details/7025768

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

int iMap[N][N];//表示第j个学生喜欢第i个课程
bool vis[N];
int links[N];
int studentsGroups;
int courses;
int ans;

bool dfs(int x)
{
	for(int y=1;y<=studentsGroups;y++){
		if(iMap[x][y] && !vis[y]){
			vis[y] = 1;
			if(links[y] == 0 || dfs(links[y])){
				links[y] = x;
				return true;
			}
		}	
	}
	return false;
}

void search()
{
	ans = 0;
	memset(links, 0, sizeof(links));
	for(int x=1;x<=courses;x++){
		memset(vis, 0, sizeof(vis));
		if(dfs(x)){
			ans++;
		}
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &courses, &studentsGroups);
		memset(iMap, 0, sizeof(iMap));
		for(int i=1;i<=courses;i++){
			int studentNum;
			scanf("%d", &studentNum);
			for(int j=1;j<=studentNum;j++){
				int solo;
				scanf("%d", &solo);
				iMap[i][solo] = 1;
			}
		}
		search();
		if(ans == courses){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}