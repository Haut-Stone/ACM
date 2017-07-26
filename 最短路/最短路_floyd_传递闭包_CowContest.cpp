/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-28 11:01:22
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-31 22:08:07
*/

//POJ 3660 奶牛排名
//仅作为个人理解 传递闭包： 关系之间具有传递性（例如a> b, b> c, 那么a> c）， 在那些已给出的关系基础上， 通过传递性， 把所有可能的关系都找出来
//也就是说，如果a到b中间有一条有向边，同时b到c也有一条有向边，那么就可以在a到c建一条有向边的关系。


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

const int N = 1010;

int iMap[N][N];//先组织好图再求最短路
int vertexs;
int edges;
int u, v;

void init()
{
	for(int i=1;i<=vertexs;i++){
		for(int j=1;j<=vertexs;j++){
			if(i == j){
				iMap[i][j] = 1;//表示有连接🔗
			}else{
				iMap[i][j] = 0;
			}
		}
	}
}

//求任意两个顶点之间的最短
void floyd()
{
	for(int k=1;k<=vertexs;k++){
		for(int i=1;i<=vertexs;i++){
			for(int j=1;j<=vertexs;j++){
				if(iMap[i][k] == 1 && iMap[k][j] == 1){
					iMap[i][j] = 1;
				}
			}
		}
	}
	return;
}

void read()
{
	for(int i=1;i<=edges;i++){
		scanf("%d%d", &u, &v);
		iMap[u][v] = 1;
	}
}

int main(void)
{
	// INPUT_TEST;

	while(cin>>vertexs>>edges){
		init();
		read();
		floyd();
		int ans = 0;
		for(int i=1;i<=vertexs;i++){
			int du = 0;
			for(int j=1;j<=vertexs;j++){
				if(i == j) continue;//自己和自己的除外
				if(iMap[i][j] == 1 || iMap[j][i] == 1){//记录可以被多少头牛打败， 和可以打败多少头牛的总个数。
					du++;
				}
			}
			if(du == vertexs - 1) ans++;
		}
		printf("%d\n", ans);
	}
    return 0;
}