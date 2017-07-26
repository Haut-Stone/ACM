/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-08 19:54:53
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-08 22:06:43
*/

//FZU 2150
//饿，一道题写了快200行的代码。。。。呵呵

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

const int N = 20;
const int INF = 99999999;

struct Node
{
	int x;
	int y;
	int steps;
};

char iMap[N][N];
int color[N][N];
int vis[N][N];
int colorIndex;
int row, col;
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};


int bfs(int x1, int y1, int x2, int y2, int flag)
{
	queue<Node> Q;
	Node solo, solo2;
	solo.x = x1;
	solo.y = y1;
	solo.steps = 0;
	vis[solo.x][solo.y] = 1;
	Q.push(solo);

	if(flag){
		solo2.x = x2;
		solo2.y = y2;
		solo2.steps = 0;
		vis[solo2.x][solo2.y] = 1;
		Q.push(solo2);
	}

	while(!Q.empty()){
		solo = Q.front();
		Q.pop();
		for(int d=0;d<4;d++){
			int dx = solo.x + direction[d][0];
			int dy = solo.y + direction[d][1];
			if(dx >= 0 && dx < row && dy >= 0 && dy < col && iMap[dx][dy] == '#' && vis[dx][dy] == 0){
				vis[dx][dy] = 1;
				Node temp;
				temp.x = dx;
				temp.y = dy;
				temp.steps = solo.steps + 1;
				Q.push(temp);
			}
		}
	}
	return solo.steps;
}

void colorFul()
{
	colorIndex = 1;

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(color[i][j] == 0 && iMap[i][j] == '#'){
				queue<Node> Q;
				Node solo;
				solo.x = i;
				solo.y = j;
				color[solo.x][solo.y] = colorIndex;
				Q.push(solo);
				while(!Q.empty()){
					solo = Q.front();
					Q.pop();
					for(int d=0;d<4;d++){
						int dx = solo.x + direction[d][0];
						int dy = solo.y + direction[d][1];
						if(dx >= 0 && dx < row && dy >= 0 && dy < col && iMap[dx][dy] == '#' && color[dx][dy] == 0){
							color[dx][dy] = colorIndex;
							Node temp;
							temp.x = dx;
							temp.y = dy;
							Q.push(temp);
						}
					}
				}
				colorIndex++;
			}
		}
	}
	return;
}

void init()
{
	memset(iMap, 0, sizeof(iMap));
	memset(color, 0, sizeof(color));
}

int main(void)
{
	int T;
	cin>>T;
	for(int cas=1;cas<=T;cas++){
		init();
		cin>>row>>col;
		for(int i=0;i<row;i++){
			scanf("%s", iMap[i]);
		}
		colorFul();
		colorIndex--;
		if(colorIndex > 2){
			printf("Case %d: -1\n", cas);
		}else if(colorIndex == 2){
			int minTime1 = INF;
			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
					if(color[i][j] == 1){
						memset(vis, 0, sizeof(vis));
						int temp = bfs(i, j, 0, 0, 0);
						if(temp < minTime1) minTime1 = temp;
					}
				}
			}
			int minTime2 = INF;
			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
					if(color[i][j] == 2){
						memset(vis, 0, sizeof(vis));
						int temp = bfs(i, j, 0, 0, 0);
						if(temp < minTime2) minTime2 = temp;
					}
				}
			}

			int ans;
			if(minTime1 == INF){
				ans = minTime2;
			}else if(minTime2 == INF){
				ans = minTime1;
			}else{
				ans = max(minTime1, minTime2);
			}
			printf("Case %d: %d\n", cas, ans);
		}else{
			int minTime = INF;
			for(int x1=0;x1<row;x1++){
				for(int y1=0;y1<col;y1++){
					for(int x2=0;x2<row;x2++){
						for(int y2=0;y2<col;y2++){
							if(color[x1][y1] == 1 && color[x2][y2] == 1){
								memset(vis, 0, sizeof(vis));
								int temp = bfs(x1, y1, x2, y2, 1);
								if(temp < minTime) minTime = temp;
							}
						}
					}
				}
			}
			printf("Case %d: %d\n", cas, minTime);
		}
	}
    return 0;
}