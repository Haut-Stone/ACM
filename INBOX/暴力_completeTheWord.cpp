/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-16 13:15:09
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-16 13:43:00
*/

//http://vj.sdutacm.org/contest/view.action?cid=62932#problem/H
//移框法
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int N = 100010;
char a[N];
int book[30];
bool flag;

int main(void)
{
	scanf("%s", a);
	int len = (int)strlen(a);
	if(len < 26){//初始的长度判断
		printf("-1\n");
		return 0;
	}
	bool ans = false;
	for(int i=0;i<len-25;i++){//框的个数
		memset(book, 0, sizeof(book));
		flag = true;
		for(int j=i;j<i+26;j++){//长度为26的单位框的搜索过程
			if(a[j] == '?'){
				continue;
			}
			book[a[j] - 'A']++;
			if(book[a[j] - 'A'] >= 2){
				flag = false;
				break;
			}
		}
		if(flag){
			ans = true;
			for(int j=i;j<i+26;j++){//单位框中的填数过程
				if(a[j] == '?'){
					for(int k=0;k<26;k++){
						if(book[k] == 0){
							book[k] = 1;
							a[j] = 'A' + k;
							break;
						}
					}
				}
			}
			break;
		}
	}
	if(ans){
		for(int i=0;i<len;i++){
			if(a[i] == '?'){
				a[i] = 'A';
			}
		}
		printf("%s\n", a);
	}else{
		printf("-1\n");
	}
    return 0;
}