/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-27 18:58:10
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-27 18:59:01
*/

//暑假集训多校第二场最后一题
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
#define mk make_pair
using namespace std;

const int N = 1e3 + 5;

map< pair<int, int>, bool> M;  
int x[N], y[N], n, ans;

int main() {
	while (scanf("%d", &n) != EOF) {
		ans = 0;
		M.clear();
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", x + i, y + i);
			M[mk(x[i], y[i])] = 1;
			
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int dx = y[j] - y[i];
				int dy = x[i] - x[j];
				int ok = 0; 
				if (M.count(mk(x[i] + dx, y[i] + dy))) ok++;
				if (M.count(mk(x[j] + dx, y[j] + dy))) ok++;
				if (ok == 2) ans++;
				ok = 0;
				if (M.count(mk(x[i] - dx, y[i] - dy))) ok++;
				if (M.count(mk(x[j] - dx, y[j] - dy))) ok++;
				if (ok == 2) ans++;
			}
		}
		printf("%d\n", ans / 4);
	}
} 
