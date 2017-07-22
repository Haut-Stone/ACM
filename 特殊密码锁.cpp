/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-22 11:26:46
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-22 13:18:42
*/

//一维简单枚举
//这题有点坑爹啊

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

const int N = 100;
char raw[N];
char tar[N];
int ans;
int len;

void touch(int index)
{
	ans++;
	if(index == 0){
		raw[0] = raw[0]=='0' ? '1':'0';
		raw[1] = raw[1]=='0' ? '1':'0';
	}else if(index == len-1){
		raw[len-1] = raw[len-1]=='0' ? '1':'0';
		raw[len-2] = raw[len-2]=='0' ? '1':'0';
	}else{
		for(int i=index-1;i<=index+1;i++){
			raw[i] = raw[i]=='0' ? '1':'0';
		}
	}
	// cout<<endl<<tar<<endl<<raw<<endl;
	// for(int i=0;i<index;i++){
	// 	printf(" ");
	// }
	// printf("^");
}

int solve()
{
	for(int i=0;i<len-1;i++){
		if(raw[i] != tar[i])
			touch(i+1);
	}
	if(strcmp(raw, tar) == 0){
		return ans;
	}else{
		return 1e9;
	}
}

int main(void)
{
	while(~scanf("%s%s", raw, tar)){
		ans = 0;
		len = strlen(raw);
		char temp[N];
		strcpy(temp, raw);
			touch(0);
			int ans1 = solve();
			strcpy(raw, temp);
			ans = 0;
			int ans2 = solve();
			if(ans1 == 1e9 && ans2 == 1e9){
				printf("impossible\n");
			}else{
				printf("%d\n", min(ans2, ans1));
			}
		}
	return 0;
}