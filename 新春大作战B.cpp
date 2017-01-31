/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-28 17:05:11
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-29 12:10:28
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

//直接暴力是会超时的，所以要，用dfs
//其实这道题是枚举
//深搜是用来完成枚举的一种手段
//之前的枚举之所以会超时，是因为他枚举了所有的数字，之后的深搜不超时是因为他直接枚举的是符合条件的二进制数。
//题目见网址
//http://codeforces.com/problemset/problem/611/B

long long front;
long long back;
long long ans = 0;

void dfs(long long x, int flag)
{
	if(x>back) return;
	if(x>=front && x<=back && flag == 1){
		ans++;
	}
	if(flag==0) dfs(x*2, 1);
	dfs(x*2+1, flag);
}

int main(void)
{
	cin>>front>>back;
	dfs(1, 0);
	cout<<ans<<endl;
    return 0;
}