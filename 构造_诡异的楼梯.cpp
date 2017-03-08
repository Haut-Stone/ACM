/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-08 17:36:07
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-08 18:16:50
*/

//http://vj.sdutacm.org/contest/view.action?cid=62917#problem/H
//数组构造，其实就是用一个字符数组模拟一个茶包序列。。


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int N = 100010;

int main(void)
{
	int n, k;
	int a, b;
	char myString[N];
	char green = 'G';
	char black = 'B';

	scanf("%d%d%d%d", &n, &k, &a, &b);
	if(a>b){
		swap(green, black);
		swap(a, b);
	}
	memset(myString, black, sizeof(myString));
	for(int i=k;i<n;i+=k+1){
		if(a == 0){
			printf("NO\n");
			return 0;
		}
		myString[i] = green;
		a--;
	}
	for(int i=0;i<n && a>0;i++){
		if(myString[i] == green || (i>0 && myString[i-1] == green) || (i+1<n && myString[i+1] == green)) continue;
		myString[i] = green;
		a--;
	}
	for(int i=0;i<n;i++){
		printf("%c", myString[i]);
	}
    return 0;
}