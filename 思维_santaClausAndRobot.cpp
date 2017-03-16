/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-16 12:21:56
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-16 12:37:31
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int N = 200010;
char a[N];

int main(void)
{
	int n;
	int ans = 1;
	int n1 = 0;
	int n2 = 0;
	cin>>n;
	scanf("%s", a);
	for(int i=0;i<n;i++){	
		
		if(a[i] == 'L'){
			if(n1 == 1){
				ans++;
				n2 = 0;
			}
			n1 = 2;
		}
		if(a[i] == 'R'){
			if(n1 == 2){
				ans++;
				n2 = 0;
			}
			n1 = 1;
		}
		if(a[i] == 'U'){
			if(n2 == 1){
				ans++;
				n1 = 0;
			}
			n2 = 2;
		}
		if(a[i] == 'D'){
			if(n2 == 2){
				ans++;
				n1 = 0;
			}
			n2 = 1;
		}
	}
	printf("%d\n", ans);
    return 0;
}