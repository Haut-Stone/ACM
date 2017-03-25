/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-25 12:15:21
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-25 12:36:51
*/

//http://vj.sdutacm.org/contest/view.action?cid=62953#problem/C
//运用了二分的思想，递归。

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int N = 2e5 + 10;
char a[N];
char b[N];
int len;

int dfs(char *a, char *b ,int len)
{
	if(len % 2 != 0){//如果为奇数
		for(int i=0;i<len;i++){
			if(a[i] != b[i]) return 0;
		}
		return 1;
	}else{
		if((dfs(a, b, len/2) && dfs(a+len/2, b+len/2, len/2)) || (dfs(a, b+len/2, len/2) && dfs(a+len/2, b, len/2))){//进行比较
			return 1;
		}else{
			return 0;
		}
	}
}

int main(void)
{	
	cin>>a>>b;
	len = strlen(a);
	if(dfs(a, b, len)){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
    return 0;
}