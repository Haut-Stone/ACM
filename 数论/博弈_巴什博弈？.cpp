/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-09-02 13:32:26
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-09-02 13:32:58
*/

//这东西。。不做评论了，没意思
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

int main(void){
	long long a, b, n;
	while(~scanf("%lld%lld%lld", &n, &a, &b)){
		if(n <= a-1){
			printf("YES\n");
		}else{
			n -= a;
			n %= (a+b);
			if(n <= a-1){
				printf("NO\n");
			}else{
				printf("YES\n");
			}
		}
	}
	return 0;
}