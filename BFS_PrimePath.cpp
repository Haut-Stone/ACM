/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-02 15:24:33
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-02 19:43:29
*/

//http://vj.sdutacm.org/contest/view.action?cid=62898#problem/B

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>
#include <vector>
using namespace std;

const int maxN = 100000;
int prime[maxN];

//把素数表先打出来

int initPrime(int n)
{
	int k = sqrt(n);
	for(int i=2;i<=k;i++){
		if(n%i == 0) return 0;
	}
	return 1;
}

int turn(int n, int k)
{
	char s[10] = {0};
	sprintf(s, "%d", n);
    s[k] = '0';
    sscanf(s, "%d", &n);
    return n;
}

int bfs(int a, int b)
{
	int vis[maxN] = {0};//踪迹数组
	int q;
	queue<int>Q;
	Q.push(a);
	vis[a] = 1;

	while(Q.size()){
		a = Q.front();
		Q.pop();
		if(a == b) return vis[a]-1;
		int t = 1000;
		for(int i=0;i<4;i++){
			q = turn(a, i);//改变各位的数字为0
			for(int k=0;k<10;k++){
				int j = q+k*t;
				if(prime[j] == 1 && vis[j] == 0){
					Q.push(j);
					vis[j] = vis[a] + 1;
				}
			}
			t /= 10;
		}
	}	
	return -1;
}
int main(void)
{
	int n;
	int a, b;
	int ans;

	for(int i=1000;i<maxN;i++){
		prime[i] = initPrime(i);
	}

	scanf("%d", &n);
	while(n--){
		scanf("%d%d", &a, &b);
		ans = bfs(a, b);
		if(ans == -1){
			printf("Impossible\n");
		}else{
			printf("%d\n", ans);
		}
	}
    return 0;
}