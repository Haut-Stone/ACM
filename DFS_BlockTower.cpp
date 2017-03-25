/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-25 13:37:03
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-25 20:45:37
*/

//http://vj.sdutacm.org/contest/view.action?cid=62953#problem/F
//这道题完全自己手撸出来的

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int N = 600;
char Imap[N][N];
int vis[N][N];
int n, m;
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Node
{
	char op;
	int x;
	int y;
}solo;

vector<Node>ans;

void dfs(int x, int y,int flag)
{
	if(Imap[x][y] == '#' || vis[x][y]) return;
	if(x < 0 || y < 0 || x >= n || y >= m) return;

	vis[x][y] = 1;

	for(int i=0;i<4;i++){
		int dx = x + direction[i][0];
		int dy = y + direction[i][1];
		dfs(dx, dy, 1);
	}

	if(flag){
		solo.op = 'D';
		solo.x = x;
		solo.y = y;
		ans.push_back(solo);
		solo.op = 'R';
		ans.push_back(solo);
		Imap[x][y] = 'R';
	}
	return;
}

int main(void)
{
	cin>>n>>m;
	//数据读入,初始化
	for(int i=0;i<n;i++){
		scanf("%s", Imap[i]);
	}
	//先全部盖起蓝房子
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(Imap[i][j] == '.'){
				Imap[i][j] = 'B';
				solo.op = 'B';
				solo.x = i;
				solo.y = j;
				ans.push_back(solo);
			}
		}
	}
	//搜索部分
	for(int i=0;i<n;i++){//这里虽然有两个循环，但实际上执行的次数很少，复杂度并不高。
		for(int j=0;j<m;j++){
			if(Imap[i][j] == 'B'){
				dfs(i, j,0);
			}
		}
	}
	//输出部分
	printf("%d\n", ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%c %d %d\n", ans[i].op, ans[i].x+1, ans[i].y+1);
	}
    return 0;
}