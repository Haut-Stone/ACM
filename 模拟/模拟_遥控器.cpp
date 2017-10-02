/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-09-29 17:58:11
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-09-29 18:04:14
*/

//错了好多次，居然是最大值的锅，真JB
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <stack>
#include <vector>
using namespace std;

const int M = 30;
const int INF = 0x3f3f3f3f;

int keys[M];
int up, down;

int shortPath(int now, int tar)
{
	if(now == tar){
		return 0;
	}else{
		if(tar/10 == 0){
			if(keys[tar]){
				return 1;
			}else{
				return INF;
			}
		}else{
			if(keys[tar/10] && keys[tar%10] && keys[10]){
				return 3;
			}else{
				return INF;
			}
		}
	}
}

int longPath(int now, int tar)
{
	int a = INF, b = INF;
	if(up){
		if(now > tar){
			a = tar - now + 100;
		}else{
			a = tar - now;
		}
	}
	if(down){
		if(now < tar){
			b = now - tar + 100;
		}else{
			b = now - tar;
		}
	}
	return min(a, b);
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while(T--){
		int raw, tar;
		int ans = INF;
		scanf("%d%d%d%d", &keys[1], &keys[2], &keys[3], &up);
		scanf("%d%d%d%d", &keys[4], &keys[5], &keys[6], &down);
		scanf("%d%d%d", &keys[7], &keys[8], &keys[9]);
		scanf("%d%d", &keys[10], &keys[0]);
		scanf("%d%d", &raw, &tar);
		for(int i=0;i<=99;i++){
			ans = min(ans, shortPath(raw, i) + longPath(i, tar));
		}
		if(ans == INF){
			printf("%d\n", -1);
		}else{
			printf("%d\n", ans);
		}
	}
}

