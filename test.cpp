/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-22 11:12:17
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-28 23:33:42
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

const int N = 101;
//
//今天是新春大作战专场
//

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
	dfs(x*2+1, flag);//这应该是尾递归吧。
}
int main()
{
	cin>>front>>back;
	dfs(1, 0);
	cout<<ans<<endl;
	return 0;
}