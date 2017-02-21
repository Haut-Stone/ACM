/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-02-21 20:22:09
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-02-21 20:44:06
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int N = 10000;
 struct Node{
	double left;
	double right;
};	

int n;
int T;
int d;
Node s[N];


bool cmp(Node a, Node b)
{
	return a.left < b.left;
}

int solve()
{
	int ans;
	double now;
	sort(s, s+n, cmp);
	ans = 1;
	now = s[0].right;
	for(int i=1;i<n;i++){
		if(s[i].left <= now){
			now = min(now, s[i].right);
		}else{
			ans++;
			now = s[i].right;
		}
	}
	return ans;
}

int main(void)
{
	int x, y;
	bool flag;
	T = 0;
	while(1){
		T++;
		scanf("%d%d", &n, &d);
		if(n == 0 && d == 0) break;
		flag = true;
		for(int i=0;i<n;i++){
			scanf("%d%d", &x, &y);
			if(y > d){
				flag = false;
			}else{
				s[i].left = x - sqrt(d*d - y*y);
				s[i].right = x + sqrt(d*d - y*y);
			} 
		}
		if(flag){
			printf("Case %d: %d\n", T, solve());
		}else{
			printf("Case %d: -1\n", T);
		}
	}
    return 0;
}