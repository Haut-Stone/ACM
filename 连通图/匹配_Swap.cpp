/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-15 10:38:08
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-15 10:42:01
*/

//HDU 2819
//就是匹配后，再尝试交换，就可以了。
//http://acm.hdu.edu.cn/showproblem.php?pid=2819
//http://blog.csdn.net/laojiu_/article/details/52371117

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

int iMap[N][N];
int links[N];
bool vis[N];
int n;

bool dfs(int x)
{
	for(int y=1;y<=n;y++){
		if(iMap[x][y] && !vis[y]){
			vis[y] = true;
			if(links[y] == 0 || dfs(links[y])){
				links[y] = x;
				return true;
			}
		}
	}
	return false;
}

int search()
{
	int ans = 0;
	memset(links, 0, sizeof(links));
	for(int x=1;x<=n;x++){
		memset(vis, false, sizeof(vis));
		if(dfs(x)){
			ans++;
		}
	}
	return ans;
}

int main(void)
{
	while(~scanf("%d", &n)){
		memset(iMap, 0, sizeof(iMap));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d", &iMap[i][j]);
			}
		}
		if(search() < n){
			printf("-1\n");
		}else{
			int count = 0;
			int l[N], r[N];
			for(int i=1;i<=n;i++){
				if(i != links[i]){//匹配不在对角线的话
					for(int j=1;j<=n;j++){
						if(i == links[j]){//找一个在对角线的匹配点，进行交换
							l[count] = i;
							r[count++] = j;
							swap(links[i], links[j]);
							break;
						}
					}
				}
			}
			printf("%d\n", count);
			for(int i=0;i<count;i++){
				printf("C %d %d\n", l[i], r[i]);
			}
		}
	}
	return 0;
}