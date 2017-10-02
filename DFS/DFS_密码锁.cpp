/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-09-29 20:13:43
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-09-29 20:14:32
*/

//又是一个蜜汁错了半天的题，因为temp数组开了全局，在递归过程中被改变了，导致一只出错。
//= =服了

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <stack>
#include <vector>
using namespace std;

const int N = 20;
const int INF = 0x3f3f3f3f;

char iMap[N];

int ans;

void dfs(int dep, char now[N])
{
	if(dep > 5) return;
	bool reachTarget = true;
	for(int i=0;i<9;i++){
		if(i+1 != now[i] - '0'){
			reachTarget = false;
		}
	}
	
	if(reachTarget) ans = min(ans, dep);
	for(int i=1;i<=3;i++){
		
		char temp[N];
		char temp2[N];
		strcpy(temp, now);
		strcpy(temp2, now);
		
		for(int j=1;j<=2;j++){
			int last = i*3-1;
			char buffer = temp[last];
			temp[last] = temp[last-1];
			temp[last-1] = temp[last-2];
			temp[last-2] = buffer;
			dfs(dep+1, temp);
		}
		for(int j=1;j<=2;j++){
			int last = 5+i;
			char buffer = temp2[last];
			temp2[last] = temp2[last-3];
			temp2[last-3] = temp2[last-6];
			temp2[last-6] = buffer;
			dfs(dep+1, temp2);
		}
	}
}

int main(void)
{
	while(~scanf("%s", iMap)){
		ans = INF;
		dfs(0, iMap);
		if(ans == INF){
			printf("impossible\n");
		}else{
			printf("%d\n", ans);
		}
	}
	return 0;
}
