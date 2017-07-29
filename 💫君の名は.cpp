/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-06-03 12:15:58
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-07-29 10:59:37
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

map<int, int> mapping;
int n, k;
int solo;
//int a[N];

int main(void)
{
	while(~scanf("%d%d", &n, &k)){
		mapping.clear();
		for(int i=0;i<n;i++){
			scanf("%d", &solo);
			mapping[solo] = mapping[solo] + 1;
		}
		if(k == 0 || n == 0){
			printf("0\n");
			continue;
		}
//		sort(a, a+n);
//		int cnt = 0;
//		for(int i=0;i<n;i++){
//			if(a[i] == a[i+1]){
//				cnt++;
//			}else{
//				cnt++;
//				if(cnt % k != 0){
//					printf("%d", a[i]-1);
//					break;
//				}else{
//					cnt = 0;
//				}
//			}
//		}
		if(mapping.size() == 1) continue;
		for(map<int, int>::iterator it=mapping.begin();it!=mapping.end();it++){
			if(it->second % k != 0){
				printf("%d\n", it->first);
				break;	
			}
		}
	}
	return 0;
}