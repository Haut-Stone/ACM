/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-31 12:49:25
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-31 14:03:35
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
using namespace std;

const int N = 1e5;

char Imap[N][N];
int row, col;
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};


struct Node
{
	int x;
	int y;
	int steps;
};


void prim()
{

}

int bfs(int x, int y)
{
	return 0;
}

void read()
{
	scanf("%d %d", &col, &row);//这里别人都说数据有问题。有多余的空格。
	for(int i=1;i<=row;i++){
		scanf("%s", Imap[i]);
	}

}

int main(void)
{
	int T;
	cin>>T;
	while(T--){
		read();
	}

    return 0;
}