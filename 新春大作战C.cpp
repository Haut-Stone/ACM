/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-28 17:44:49
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-28 23:08:03
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

//http://codeforces.com/problemset/problem/611/C

const int N = 505;
char s[N][N];
int num[N][N];
int A[N][N];
int B[N][N];
int h,w;

int main(void)
{
	cin>>h>>w;
	for(int i=1;i<=h;i++){
		scanf("%s", s[i]+1);
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(s[i][j] == '.'){
				num[i][j] = 1;
			}else{
				num[i][j] = 0;
			}
		}
	}
	//以上是普通处理。。
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(num[i][j] && num[i][j+1]){
				A[i][j] = A[i][j-1] + 1;
			}else{
				A[i][j] = A[i][j-1];
			}
		}
	}
	//以上是。。不知道什么东西。。
	//这就是前缀和吗？
	//mark一下，明天来解决。。
	for(int i=1;i<=w;i++){
		for(int j=1;j<=h;j++){
			if(num[j][i] && num[j+1][i]){
				B[j][i] = B[j-1][i] + 1;
			}else{
				B[j][i] = B[j-1][i];
			}
		}
	}
	int q;
	cin>>q;
	while(q--){
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int ans = 0;
		for(int i=x1;i<=x2;i++){
			ans+=A[i][y2-1]-A[i][y1-1];
		}
		for(int i=y1;i<=y2;i++){
			ans+=B[x2-1][i]-B[x1-1][i];
		}
		printf("%d\n", ans);
	}
    return 0;
}