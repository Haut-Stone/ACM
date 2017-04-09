/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-08 15:19:07
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-08 15:31:51
*/

//https://acm.zzuli.edu.cn/zzuliacm/problem.php?id=1881
//并查集的模版题。真的是水的不行的一道题。

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

const int N = 105;

int par[N];//父节点
int n;//主机数量
int m;//线路数量

void init(int n)
{
	for(int i=1;i<=n;i++){
		par[i] = i;
	}
}


int find(int x)
{	
	if(par[x] == x){
		return x;
	}else{
		return par[x] = find(par[x]);//在一次搜索后会优化，将连接直接连到根上。
	}
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x != y) par[y] = x;
}


int main(void)
{
	// INPUT_TEST;
	int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        init(n);
        int u, v;
        while(m--){
        	cin>>u>>v;
        	unite(u, v);
        }
        int sum = 0;
        for(int i=1;i<=n;i++){
        	if(par[i] == i){
        		sum++;
        	}
        }
        printf("%d\n", sum-1);
    }
    return 0;
}