/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2016 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-16 13:24:07
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-16 14:08:09
*/
//欧拉函数
//只过了55%的数据，看来还有的地方又问题，数论的东西太高深，不知道该怎么对付。。。
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;


int process(int solo);

int main(void)
{
	int solo;
	int ans;
	scanf("%d", &solo);
	ans = process(solo);
	printf("%d\n",ans);
    return 0;
}

int process(int solo)
{
	int ans = solo;
	for(int i=2;i*i<=solo;i++){
		if(solo%i == 0){
			ans -= solo/i;
			while(solo%i == 0){
				solo /= i;
			}
		}
	}
	if(solo>1) ans = ans - ans/solo;
	return ans;
}