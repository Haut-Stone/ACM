/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-01-22 11:12:17
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-05-24 13:52:26
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
const int INF = (1<<20);


int u, v, w;

int edgeNumber;




void init()
{
	edgeNumber = vertexNumber * (vertexNumber - 1) / 2;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i == j){
				Imap[i][j] = 0;
			}else{
				Imap[i][j] = INF;
			}
		}
	}
}

void read()
{
	for(int i=0;i<edgeNumber;i++){
		scanf("%d%d%d", &u, &v, &w);
		Imap[u-1][v-1] = Imap[v-1][u-1] = w;
	}
}

int main(void)
{
	// INPUT_TEST;

	while(cin>>vertexNumber){
		if(vertexNumber == 0) break;
		init();
		read();
		printf("%d\n", prim());
	}
	return 0;
}