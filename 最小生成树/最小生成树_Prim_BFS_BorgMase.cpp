/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-31 12:49:25
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-23 19:27:01
*/
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

const int N = 300;
const int SIZE = 51;
const int INF = (1<<20);

char charMap[SIZE][SIZE];
int vexter[SIZE][SIZE];//记录该点是不是节点，是第几个节点。

int Imap[N][N];//用来存边的关系，由于数据的原因，顶点最多只有一百多个
int minCost[N];
bool vis[N];
int vertexNumber;

int num;
int row, col;
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Node
{
	int x;
	int y;
	int steps;
};

//这是这道题的难点，就是用bfs来搜索最短路径，从而建立节点间边的关系
int bfs(int beginX, int beginY)
{
	int book[N][N];
	memset(book, 0 ,sizeof(book));
	queue<Node> Q;

	Node solo;
	solo.x = beginX;
	solo.y = beginY;
	solo.steps = 0;

	Q.push(solo);
	book[solo.x][solo.y] = 1;

	while(!Q.empty()){
		solo = Q.front();
		Q.pop();
		
		//如果找到了另外一个顶点,构建边的关系
		if(vexter[solo.x][solo.y]){
			Imap[vexter[solo.x][solo.y]-1][vexter[beginX][beginY]-1] = solo.steps;
			Imap[vexter[beginX][beginY]-1][vexter[solo.x][solo.y]-1] = solo.steps;
		}

		for(int i=0;i<4;i++){
			int dx = solo.x + direction[i][0];
			int dy = solo.y + direction[i][1];
			//如果该点合法	，加入队列
			if(dx >= 0 && dy >= 0 && dx <= row && dy <= col && !book[dx][dy] && charMap[dx][dy] != '#'){
				Node temp;
				temp.x = dx;
				temp.y = dy;
				temp.steps = solo.steps + 1;
				book[temp.x][temp.y] = 1;
				Q.push(temp);
			}
		}
	}
	return 0;
}

int prim()
{
	vertexNumber = num-1;
	for(int i=0;i<vertexNumber;i++){
		minCost[i] = Imap[0][i];
		vis[i] = false;//初始话顶点为未被访问。
	}

	minCost[0] = 0;//第一个点到自己的距离为0.
	int ans = 0;
	
	while(true){

		int minDis = INF;
		int minPos = 0;

		for(int j=0;j<vertexNumber;j++){
			if(minCost[j] < minDis && !vis[j]){//搜索到当前点的最短距离
				minDis = minCost[j];
				minPos = j;
			}
		}

		if(minDis == INF) break;//如果所有的点都被找过

		vis[minPos] = 1;
		ans += minDis;
		for(int j=0;j<vertexNumber;j++){
			//将已搜索过的点视为一个整体,更新整体的值。
			if(!vis[j] && minCost[j] > Imap[minPos][j]){
				minCost[j] = Imap[minPos][j];
			}
		}
	}
	return ans;
}

void read()
{
	scanf("%d %d", &col, &row);//这里别人都说数据有问题。有多余的空格。
	char useless[N];
	gets(useless);
	for(int i=0;i<row;i++){
		gets(charMap[i]);
		for(int j=0;j<col;j++){
			if(charMap[i][j] == 'A' || charMap[i][j] == 'S'){
				vexter[i][j] = num;//对节点进行编号，这一步是很重要的
				num++;
			}
		}
	}
}

void init()
{
	memset(vexter, 0, sizeof(vexter));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i == j){
				Imap[i][j] = 0;
			}else{
				Imap[i][j] = INF;
			}
		}
	}
	num = 1;
}

int main(void)
{
	// INPUT_TEST;

	int T;
	cin>>T;
	while(T--){
		init();
		read();
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				if(vexter[i][j]){
					bfs(i, j);//构造边的关系
				}
			}
		}
		//查看边的关系
		// for(int i=0;i<10;i++){
		// 	for(int j=0;j<10;j++){
		// 		printf("%d ", Imap[i][j]);
		// 	}
		// 	printf("\n");
		// }
		cout<<prim()<<endl;
	}
	return 0;
}