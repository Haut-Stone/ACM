/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-08-04 20:46:48
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-09-24 13:04:30
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
#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;

int main(void)
{
	long long n, k, c;
	while(cin>>n>>k>>c){
		long long ans = k/n*n;
		if(ans >= c){
			printf("%lld\n", c);
		}else{
			ans = (n - k/(k/n+1)) + c;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
