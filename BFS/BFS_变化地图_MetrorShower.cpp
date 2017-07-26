/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-30 17:16:10
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-30 18:13:06
*/

//http://poj.org/problem?id=3669
//这次地图来根据流星降落的时间来初始化。很有意思。

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

#define INPUT_TEST freopen("in.txt", "r", stdin)

const int N = 550;
const int INF = 9999999;

int direction[5][2] = {{-1, 0}, {0, 1}, {1, 0}, {0,-1}, {0, 0}};
int iMap[N][N];
int vis[N][N];
int last;

struct Node
{
	int x;
	int y;
	int t;
	Node(int X, int Y, int Z){
		x = X;
		y = Y;
		t = Z;
	}
	Node(){

	}
}metrors[50004];

bool cmp(const Node &a, const Node &b)
{
	return a.t < b.t;
}

int bfs(int x, int y, int t)
{	
	vis[x][y] = 1;
	queue<Node> Q;
	Node solo(x, y, t);
	Q.push(solo);
	while(!Q.empty()){
		solo = Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			Node temp(solo.x + direction[i][0], solo.y + direction[i][1], solo.t + 1);
			if(temp.x >= 0 && temp.y >= 0 && iMap[temp.x][temp.y] > temp.t && !vis[temp.x][temp.y]){
				vis[temp.x][temp.y] = 1;
				if(iMap[temp.x][temp.y] > last){
					return temp.t;
				}
				Q.push(temp);
			}
		}
	}
	return -1;
}

void init()
{
	memset(vis, 0, sizeof(vis));
	memset(iMap, INF, sizeof(iMap));
}

int main(void)
{
	// INPUT_TEST;

	init();
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d%d%d", &metrors[i].x, &metrors[i].y, &metrors[i].t);
	}
	sort(metrors, metrors+n, cmp);

	last = metrors[n-1].t;//最晚时间

	//流星会影响到附近的5个格子
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			int dx = metrors[i].x + direction[j][0];
			int dy = metrors[i].y + direction[j][1];
			if(dx >= 0 && dy >= 0 && iMap[dx][dy] > metrors[i].t){
				iMap[dx][dy] = metrors[i].t;
			}
		}
	}
	printf("%d\n", bfs(0,0,0));
    return 0;
}