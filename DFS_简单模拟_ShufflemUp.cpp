/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-08 19:15:08
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-08 19:48:29
*/

//POJ 3087
//这道题貌似是数据比较的弱，直接模拟就好了。用map来标记这个序列之前是否出现过。

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

const int N = 110;

char a[N];
char b[N];
char c[N*2];
char tempC[N*2];

bool haveFind;
int num;
map <string, int> iMap;

int main(void)
{
	int n;
	cin>>n;
	for(int cas=1;cas<=n;cas++){
		haveFind = false;
		num = 0;

		int len;
		cin>>len;
		scanf("%s%s%s", a, b, c);//读取数据
		while(1){
			num++;
			int cnt = 0;
			for(int i=0;i<len;i++){
				tempC[cnt++] = b[i];//洗牌
				tempC[cnt++] = a[i];
			}

			tempC[cnt] = '\0';

			if(strcmp(tempC, c) == 0){//比较
				haveFind = 1;
				break;
			}

			if(iMap.find(tempC) != iMap.end()){
				break;
			}

			iMap[tempC] = 0;
			for(int i=0;i<len;i++){
				a[i] = tempC[i];
				b[i] = tempC[i+len];
			}
		}

		if(haveFind){
			printf("%d %d\n", cas, num);
		}else{
			printf("%d -1\n", cas);
		}
	}
    return 0;
}