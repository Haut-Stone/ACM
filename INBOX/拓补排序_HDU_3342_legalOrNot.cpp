/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-20 16:33:06
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-20 17:30:54
*/

//这应该算是一道模版题吧。。挺简单的
//

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

const int N = 510;
const int INF = 99999999;

int vertexs;
int edges;
int iMap[N][N];
int degree[2*N];
int side[2*N];
int u, v;

void init()
{
	memset(iMap, 0, sizeof(iMap));
	memset(degree , 0, sizeof(degree));
}

void topologySorting()
{
	int min = INF;
	int cnt = 0;

	for(int i=1;i<=vertexs;i++){
		for(int j=1;j<=vertexs;j++){
			if(degree[j] == 0){
				min = j;
				break;
			}else{
				min = INF;
			}
		}
		if(min == INF){//如果有环的话
			printf("NO\n");
			return;
		}
		side[cnt++] = min;
		degree[min] = -1;//删掉该点
		for(int v=1;v<=vertexs;v++){
			if(iMap[min][v]) degree[v]--;
		}
	}
	printf("YES\n");
}

int main(void)
{
	// INPUT_TEST;
	while(scanf("%d%d", &vertexs, &edges) != EOF){
		if(vertexs == 0 && edges == 0) break;
		init();

		for(int i=1;i<=edges;i++){
			scanf("%d%d", &u, &v);
			u = u+1;
			v = v+1;
			if(iMap[u][v] == 0){//如果两个点之间没有被联通的话
				iMap[u][v] = 1;
				degree[v]++;//记录前驱的数量
			}
		}
		topologySorting();
	}
    return 0;
}