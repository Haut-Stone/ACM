/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-08-04 20:46:48
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-09-24 13:04:30
 */

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
#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;

const int N = 10100;
const int M = 11;

struct Node
{
	char a[M];
	int num;
	int len;
}num[N];

bool cmp(Node a, Node b)
{
	if(a.len == b.len){
		return a.num < b.num;
	}
	
	int lenMin = a.len > b.len ? b.len : a.len;
	
	for(int i=0;i<lenMin;i++){
		if(a.a[i] != b.a[i]){
			return a.a[i] < b.a[i];
		}
	}
	
	if(a.len > b.len){
		int i = 0;
		while(a.a[lenMin] == a.a[i]){
			lenMin++;
			i++;
		}
		if(lenMin == a.len){
			return a.a[1] > a.a[0];
		}
		return a.a[lenMin] < a.a[i];
	}else{
		int i = 0;
		while(b.a[lenMin] == b.a[i]){
			lenMin++;
			i++;
		}
		if(lenMin == b.len){
			return b.a[1] < b.a[0];
		}
		return !(b.a[lenMin] < b.a[i]);
	}
}

int main(void)
{
	int n;
	cin>>n;
	
	int len = 0;
	for(int i=0;i<n;i++){
		scanf("%s", num[i].a);
		num[i].num = atoi(num[i].a);
		num[i].len = (int)strlen(num[i].a);
		len += num[i].len;
	}
	sort(num, num+n, cmp);
	
	int flag = 0;
	for(int i=0;i<n;i++){
		if(flag + num[i].len < 1000){
			flag += num[i].len;
			cout<<num[i].a;
		}else{
			for(int j=0;j<num[i].len;j++){
				cout<<num[i].a[j];
				if(++flag == 1000){
					cout<<'\n';
					flag = num[i].len - j - 1;
					printf("%s", num[i].a + j + 1);
					break;
				}
			}
		}
	}
	return 0;
}
