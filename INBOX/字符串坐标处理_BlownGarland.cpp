/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-15 18:39:05
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-15 18:40:13
*/

//http://vj.sdutacm.org/contest/view.action?cid=62932#problem/C
//见证%的力量！！

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int N = 200;

char a[N];
int c[N];
int d[N];
int green;
int red;
int blue;
int yellow;

int main(void)
{   
	scanf("%s", a);
	for(int i=0;i<strlen(a);i++){
		//这个方法简直是神作！！
		if(a[i] == '!'){
			c[i%4]++;
		}else{
			d[a[i]] = i%4;
		}
	}
	printf("%d %d %d %d\n", c[d['R']], c[d['B']], c[d['Y']], c[d['G']]);
	return 0;

}