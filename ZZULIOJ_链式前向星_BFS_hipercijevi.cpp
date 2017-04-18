/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-16 17:52:22
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-18 15:56:32
*/

//这道题就是专门用来卡时间的。坑的点就在于要用链式前向星。
//https://acm.zzuli.edu.cn/zzuliacm/problem.php?id=2130

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

const int N = 200005;

//输入外挂函数
// inline int read()
// {
// 	int x=0,f=1;char ch=getchar();
// 	while(ch<'0'||ch>'9'){
// 		if(ch=='-')f=-1;ch=getchar();
// 	}
// 	while(ch>='0'&&ch<='9'){
// 		x=x*10+ch-'0';ch=getchar();
// 	}
// 	return x*f;
// }

struct Node//节点
{
	int x;
	int steps;
};

struct edge//链式前向星
{
	int to;
	int next;
}edges[N*10];

int head[N];
int vis[N];

int cnt;
int points;
int tubes;
int pointsOfEveryTube;
int ans;
int beginX, endX;

void add_edge(int u, int v)
{
	edges[cnt].to = v;
	edges[cnt].next = head[u];
	head[u] = cnt++;
}

int bfs(int beginX, int endX, int points)
{
	queue <Node> Q;
	Node temp, solo;

	solo.x = beginX;
	solo.steps = 0;
	vis[solo.x] = 1;
	Q.push(solo);
	while(!Q.empty()){
		solo = Q.front();
		Q.pop();

		if(solo.x == endX) return (solo.steps)/2 + 1;
		int u = solo.x;

		for(int i=head[u];~i;i=edges[i].next){//这句话用来按顺序遍历所有的点。
			int pos = edges[i].to;
			if(!vis[pos]){
				temp.x = pos;
				temp.steps = solo.steps + 1;
				vis[temp.x] = 1;
				Q.push(temp);
			}
		}
	}
	return -1;
}


void init()
{
	for(int i=0;i<=points+tubes;++i){//初始化
        head[i]=-1;
        vis[i]=0;
    }
    cnt = 0; 

   	beginX = 1;
   	endX = points;
}

int main(void)
{
	// INPUT_TEST;
	int T;
	int num;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &points, &pointsOfEveryTube, &tubes);
		init();
		for(int i=1;i<=tubes;i++){
			int newPoint = points + i;//为管子建立新的节点
			for(int j=1;j<=pointsOfEveryTube;j++){
				scanf("%d", &num);
				// num = read();这个外挂，直接减少0.3秒。不明觉历
				add_edge(newPoint, num);//连接代表管子的新顶点。因为是无向边，所以要连两次。
				add_edge(num, newPoint);
			}
		}
		ans = bfs(beginX, endX, points);
		printf("%d\n", ans);
	}
	return 0;
}


