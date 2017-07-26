/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-30 18:35:12
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-30 18:47:26
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
using namespace std;

#define INPUT_TEST freopen("in.txt", "r", stdin)
const int INF = 99999999;

char str[30];
int num[15];

int main(void)
{
	// INPUT_TEST;

	int t;
	cin>>t;
	getchar();
	while(t--){
		gets(str);
		int len = strlen(str);
		int k = 0;
		for(int i=0;i<len;i++){
			if(str[i] >= '0' && str[i] <= '9'){
				num[k++] = str[i] - '0';
			}
		}
		//只有两个数时
		if(k == 2){
			printf("%d\n", num[1] - num[0]);
			continue;
		}

		//这里用全排列跳过？？
		while(num[0] == 0){
			next_permutation(num, num + k);
		}

		int ans = INF;
		do
		{
			//分割为两个数
			int mid = (k + 1) / 2;
			if(num[mid]){
				int a = 0;
				int b = 0;
				for(int i=0;i<mid;i++){
					a = a * 10 + num[i];
				}
				for(int i=mid;i<k;i++){
					b = b * 10 + num[i];
				}
				ans = min(ans, abs(a-b));
			}
		} while (next_permutation(num, num + k));
		printf("%d\n", ans);
	}
    return 0;
}