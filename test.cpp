/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-22 11:12:17
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-25 20:02:09
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 110;

int main()
{
	int n;
	char str[N];
	int index[N];
	scanf("%d", &n);
	getchar();
	while(n--){
		gets(str);
		for(int i=1;i<=strlen(str);i++){
			scanf("%d", &index[i]);
		}
		getchar();
		for(int i=1;i<=strlen(str);i++){
			for(int j=1;j<=strlen(str);j++){
				if(i == index[j]){
					printf("%c", str[j-1]);
				}
			}
		}
		printf("\n");
	}
    return 0;
}