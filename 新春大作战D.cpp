/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-28 17:51:01
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-28 18:00:28
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

//这题就是纯数学。。。

int main(void)
{
	int n;
	while(~scanf("%d",&n))
        printf("%d\n",n%2?0:(n/2-1)/2);
    return 0;
}