/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-04 13:27:38
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-04 23:02:52
*/

//http://poj.org/problem?id=3614
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

typedef pair<int, int> P;
const int N = 2555;

int C, L;
P cow[N];
P bot[N];
priority_queue<int , vector<int > , greater<int> > q;

int main(void)
{
	// INPUT_TEST;

	scanf("%d%d", &C, &L);
	for(int i=0;i<C;i++){
		scanf("%d%d", &cow[i].first, &cow[i].second);
	}
	for(int i=0;i<L;i++){
		scanf("%d%d", &bot[i].first, &bot[i].second);
	}
	sort(cow, cow + C);
	sort(bot, bot + L);
	int j = 0;
	int ans = 0;
	for(int i=0;i<L;i++){//枚举所有种类的防晒霜
		while(j < C && cow[j].first <= bot[i].first){
			q.push(cow[j].second);//将奶牛可以承受的最大值加入优先队列
			j++;
		}
		while(!q.empty() && bot[i].second){
			int x = q.top();
			q.pop();
			if(x < bot[i].first) continue;
			ans++;
			bot[i].second--;//每用一个防晒霜的数量减少一个
		}
	}
	printf("%d\n", ans);
    return 0;
}