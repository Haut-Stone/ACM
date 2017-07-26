/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-26 18:00:08
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-26 19:27:06
*/

//http://vj.sdutacm.org/contest/view.action?cid=62953#problem/G
//并查集，一种全新数据结构

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <stack>
using namespace std;

const int N = 1e5 +10;

int n;
int father[N];
bool have[N];
long long ans[N];
long long value[N];
int destroyIndex[N];
long long rootValue[N];

int find(int x)
{
	if(father[x] == x){//如果这个点的父亲就是本身，即到达根部
		return x;
	}else{
		return father[x] = find(father[x]);//查找上父亲的父亲元素，追根溯源。
	}
	return 0;
}

void init()
{
	for(int i=1;i<=n;i++){
		father[i] = i;
	}
	memset(have, false, sizeof(have));
	return;
}

int main(void)
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>value[i];
	}
	for(int i=1;i<=n;i++){
		cin>>destroyIndex[i];
	}
	init();
	ans[n] = 0;//全部破坏后的值当然为零。
	for(int i=n;i>1;i--){
		int solo = destroyIndex[i];
		rootValue[solo] = value[solo];
		if(have[solo-1]){
			int root1 = find(solo), root2 = find(solo-1);
			father[root1] = root2;
			rootValue[root2] += rootValue[root1];
		}
		if(have[solo+1]){
			int root1 = find(solo), root2 = find(solo+1);
			father[root1] = root2;
			rootValue[root2] += rootValue[root1];
		}
		ans[i-1] = max(rootValue[find(solo)], ans[i]);//这里也有一点疑问
		have[solo] = true;
	}
	for(int i=1;i<=n;i++){
		printf("%lld\n", ans[i]);	
	}
    return 0;
}