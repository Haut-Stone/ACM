/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-29 11:12:40
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-29 11:13:34
*/

//三维的bfs,和龙的那道题差不多。
//https://pta.patest.cn/pta/test/6152/submit

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


int row;
int col;
int num;
int iEps;
int ans;

int iSpace[66][1299][140];
bool book[66][1299][140];
int dir[6][3] = {{0,1,0}, {0,0,1}, {0,-1,0}, {0,0,-1}, {1,0,0}, {-1,0,0}};

struct Node
{
	int x;
	int y;
	int z;
	// 用构造函数，赋值的时候更加方便一些。
	Node(int X, int Y, int Z){
		x = X;
		y = Y;
		z = Z;
	}
};

void read()
{
	cin>>row>>col>>num>>iEps;
	for(int i=0;i<num;i++){
		for(int j=0;j<row;j++){
			for(int v=0;v<col;v++){
				scanf("%d" ,&iSpace[i][j][v]);
			}
		}
	}
}

int bfs(int x, int y, int z)
{	
	Node temp(x, y, z);
	queue<Node> Q;
	Q.push(temp);
	book[x][y][z] = 1;
	int res = 1;

	while(!Q.empty()){
		Node solo = Q.front();
		Q.pop();
		for(int i=0;i<6;i++){
			temp = solo;
			temp.x += dir[i][0];
			temp.y += dir[i][1];
			temp.z += dir[i][2];
			if(temp.x >= 0 && temp.y >= 0 && temp.z >= 0){
				if(iSpace[temp.x][temp.y][temp.z] == 1 && book[temp.x][temp.y][temp.z] == 0){
					book[temp.x][temp.y][temp.z] = 1;
					res++;
					Q.push(temp);
				}
			}
		}
	}
	return res;
}

void init()
{
	memset(book, 0, sizeof(book));
	ans = 0;
}

int main(void)
{
	// INPUT_TEST;
	
	read();
	init();
	
	for(int i=0;i<num;i++){
		for(int j=0;j<row;j++){
			for(int v=0;v<col;v++){
				//如果这个像素是肿瘤，并且这个地方没有被搜索过
				if(iSpace[i][j][v] == 1 && book[i][j][v] == 0){
					int temp = bfs(i, j, v);
					if(temp >= iEps) ans += temp;
				}
			}
		}
	}

	cout<<ans<<endl;
	return 0;
}