/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-27 22:54:36
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-28 14:08:14
*/

//递归都要在当前层次下考虑。不然会很乱的
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

const int N = 100;

int n;
int ans;
char a[N];

void swap(int A, int B)
{	
	char temp;
	temp = a[B];
	a[B] = a[A];
	a[A] = temp;
	return;
}

bool needSwap(int begin, int k)
{
	int flag = 1;
	for(int i=begin;i<k;i++){
		if(a[i] == a[k]){
			flag = 0;
			break;
		}
	}
	return flag;
}


void dfs(int begin, int end)
{
	if(begin == end){
		ans++;
		return;
	}else{
		for(int i=begin;i<=end;i++){
			if(needSwap(begin, i)){
				swap(begin, i);
				dfs(begin+1, end);//进入下一个层次。写递归问题要关注当前的层次
				swap(begin, i);
			}
		}
	}
}

int main(void)
{
	cin>>n;
	scanf("%s", a);
	int len = strlen(a);
	dfs(0, len-1);
	printf("%d\n", ans);
    return 0;
}