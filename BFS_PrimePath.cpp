/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-02 15:24:33
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-07 22:10:23
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
	//用于判定1000-maxN范围内的素数
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
	Q.push(a);//将原始数加入队列
	vis[a] = 1;//标记这个数已经被用过

	while(Q.size()){//队列非空的情况下
		a = Q.front();
		Q.pop();
		if(a == b) return vis[a]-1;//如果？？
		int t = 1000;
		for(int i=0;i<4;i++){
			q = turn(a, i);//改变各位的数字为0
			for(int k=0;k<10;k++){
				int j = q+k*t;//用q加上1000->9000
				if(prime[j] == 1 && vis[j] == 0){
					Q.push(j);
					vis[j] = vis[a] + 1;//步数增加
				}
			}
			t /= 10;//t的位阶改变。
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
		prime[i] = initPrime(i);//首先先把素数全部找出来
	}

	scanf("%d", &n);
	while(n--){
		scanf("%d%d", &a, &b);//原始数，和目标数
		ans = bfs(a, b);//bfs过程返回步数
		if(ans == -1){
			printf("Impossible\n");
		}else{
			printf("%d\n", ans);
		}
	}
    return 0;
}