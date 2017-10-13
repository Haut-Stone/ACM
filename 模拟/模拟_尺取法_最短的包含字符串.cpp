/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-13 22:29:55
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-13 22:30:44
*/

//类似于白书上的模拟蠕虫法.
//https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1127

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

const int N = 100010;
const int INF = 0x3f3f3f3f;

int book[27];
char str[N];
int iStart;
int iEnd;

int main(void)
{
	scanf("%s", str);
	int len = (int)strlen(str);
	int ans = INF;
	
	iStart = 0;
	iEnd = 0;
	
	memset(book, 0, sizeof(book));
	
	while(iEnd < len){
		book[str[iEnd] - 'A']++;
		iEnd++;
		bool flag = true;
		for(int i=0;i<26;i++){
			if(book[i] == 0){
				flag = false;
			}
		}
		if(flag){
			ans = min(ans, iEnd - iStart);
			bool flag2 = true;
			while(flag2){
				book[str[iStart] - 'A']--;
				iStart++;
				for(int i=0;i<26;i++){
					if(book[i] == 0){
						flag2 = false;
					}
				}
				if(flag2){
					ans = min(ans, iEnd - iStart);
				}else{
					break;
				}
			}
		}
	}
	if(ans == INF){
		printf("No Solution\n");
	}else{
		printf("%d\n", ans);
	}
	return 0;
}
