/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-01-22 11:12:17
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-07-27 12:55:24
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

const int N = 1000010;
char str1[N];
char str2[N];
int sameNum;
int difNum;
int ans1;
int ans2;
int flag;

int main(void)
{
	int n;
	int rightA;
	int rightB;
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &n, &rightA, &rightB);
		flag = 0;
		scanf("%s%s", str1, str2);
		for(int i=0;i<n;i++){
			if(str1[i] == str2[i]){
				sameNum++;
			}else{
				difNum++;
			}
		}
		//ab君错i道	
		for(int i=0;i<=difNum;i++){
			int wNumBase1 = sameNum + i;
			int wNumBase2 = i;
			for(int j=1;j<=difNum-i;j++){
				ans1 = wNumBase1 + j;
				ans2 = wNumBase1 + (difNum - i) - j;

				int ans11 = wNumBase2 + j;
				int ans22 = wNumBase2 + (difNum - i) - j;

				if((ans1 == (n - rightA) && ans2 == (n - rightB)) || (ans11 == (n - rightA) && (n-rightB) == ans22)){
					flag = 1;
					break;
				}
			}
			if(flag) break;
		}
		if(flag){
			printf("Not lying\n");
		}else{
			printf("Lying\n");
		}
	}
	return 0;
}