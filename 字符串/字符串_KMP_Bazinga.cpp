/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-14 17:15:38
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-14 17:15:52
*/


//2015 ACM 沈阳
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
#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;

const int N = 550;
int my_next[2010];
char strs[N][2010];
int book[N];
bool flag;
int ans;
int cnt;

void getNext(char str[], int len)
{
	int j = -1;
	my_next[0] = -1;
	for(int i=1;i<len;i++){
		while(j != -1 && str[i] != str[j+1]){
			j = my_next[j];
		}
		if(str[i] == str[j+1]){
			j++;
		}
		my_next[i] = j;
	}
}

bool kmp(char text[], char pattern[])
{
	int n = (int)strlen(text);
	int m = (int)strlen(pattern);
	getNext(pattern, m);
	int j = -1;
	for(int i=0;i<n;i++){
		while(j != -1 && text[i] != pattern[j+1]){
			j = my_next[j];
		}
		if(text[i] == pattern[j+1]){
			j++;
		}
		if(j == m-1){//出现匹配，则存在
			return true;//是否存在
		}
	}
	return false;
}

int main(void)
{
	int T;
	int n;
	int cas = 1;
	
	scanf("%d", &T);
	while(T--){
		cnt = 1;
		memset(book, 0 , sizeof(book));
		scanf("%d", &n);
		flag = true;
		for(int i=1;i<=n;i++){
			scanf("%s", strs[i]);
		}
		if(n == 1){
			printf("Case #%d: %d\n", cas++, -1);
			continue;
		}
		ans = -1;
		for(int i=2;i<=n;i++){
			//如果匹配失败
			if(!kmp(strs[i], strs[i-1])){
				book[cnt++] = i-1;
				ans = max(ans, i);
				flag = false;
			}else{
				for(int j=cnt;j>=0;j--){
					if(!kmp(strs[i], strs[book[j]])){
						ans = max(ans, i);
						flag = false;
						break;
					}
				}
			}
		}
		if(!flag){
			printf("Case #%d: %d\n", cas++, ans);
		}else{
			printf("Case #%d: %d\n", cas++, -1);
		}
	}
	return 0;
}
