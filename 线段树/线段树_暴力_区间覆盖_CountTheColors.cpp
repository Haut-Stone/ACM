/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-13 15:58:53
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-13 17:18:10
*/

//ZOJ 1610
//直接暴力就可以过。。。不需要任何的技术的一道水题。

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int N = 8005;
int color[N], cnt[N];
int start, dest, i_color, n;

int main(void)
{
	while(~scanf("%d", &n)){
		memset(color, -1, sizeof(color));
		memset(cnt, 0, sizeof(cnt));
		for(int i=0;i<n;i++){
			scanf("%d%d%d", &start, &dest, &i_color);
			for(int j=start;j<dest;j++){
				color[j] = i_color;//染色
			}
		}
		if(color[0] != -1){
			cnt[color[0]]++;
		}
		for(int i=1;i<N;i++){
			if(color[i] != -1 && color[i] != color[i-1]){
				cnt[color[i]]++;
			}
		}
		for(int i=0;i<N;i++){
			if(cnt[i] != 0){
				printf("%d %d\n", i, cnt[i]);
			}
		}
		printf("\n");
	}
	return 0;
}