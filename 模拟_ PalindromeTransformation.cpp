/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-25 12:43:36
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-25 13:36:27
*/

//http://vj.sdutacm.org/contest/view.action?cid=62953#problem/E
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
int n;
int position; 
char a[N];
int f[N];
int ans;
int cnt;

int main(void)
{	
	cin>>n>>position;
	cin>>a;
	position -= 1;//用来纠正0的位置问题

	for(int i=0;i<=n/2-1;i++){
		cnt = abs(a[i] - a[n-i-1]);
		if(cnt > 13) cnt = 26-cnt;
		if(cnt) f[i] = cnt;
		ans += cnt;
	}
	//上下的步数已经解决
	if(position > n/2-1) position = n-position-1;//数字的距离计算容易出错

	int len1 = 0;
	int len2 = 0;

	for(int i=0;i<=n/2-1;i++){//贪心,其实蛮简单的，就是走最远的而已。注意总有一个方向需要走两遍
		if(i <= position && position-i > len1 && f[i]) len1 = position - i;
		if(i >= position && i - position > len2 && f[i]) len2 = i - position;
	}
	if( len1 <= len2){
		ans = 2*len1 + len2 + ans;
	}else{
		ans = ans + 2*len2 + len1;
	}
	printf("%d\n", ans);
    return 0;
}