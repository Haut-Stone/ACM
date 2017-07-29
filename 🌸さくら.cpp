/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-01-22 11:12:17
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-07-29 09:39:02
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

// const int N = 110;

// map<int, int> mapping;
// int n, k;
// int solo;

// int main(void)
// {
// 	while(~scanf("%d%d", &n, &k)){
// 		mapping.clear();
// 		for(int i=0;i<n;i++){
// 			scanf("%d", &solo);
// 			mapping[solo] = mapping[solo] + 1;
// 		}
// 		for(map<int, int>::iterator it=mapping.begin();it!=mapping.end();it++){
// 			if(it->second % n == 0){
// 				printf("%d\n", it->first);
// 			}
// 		}
// 	}
// 	return 0;
// }

const int N = 1000010;
map<int, int> mapping;
int n, k;
int solo;
int a[N];

int main(void)
{
	while(~scanf("%d%d", &n, &k)){
		if(k == 0 || n == 0){
			continue;
		}
//		mapping.clear();
		for(int i=0;i<n;i++){
			scanf("%d", &a[i]);
			a[i]++;
//			mapping[solo] = mapping[solo] + 1;
		}
		sort(a, a+n);
		int cnt = 0;
		for(int i=0;i<n;i++){
			if(a[i] == a[i+1]){
				cnt++;
			}else{
				cnt++;
				if(cnt % k != 0){
					printf("%d", a[i]-1);
					break;
				}else{
					cnt = 0;
				}
			}
		}
//		for(map<int, int>::iterator it=mapping.begin();it!=mapping.end();it++){
//			if(it->second % k != 0){
//				printf("%d\n", it->first);
//			}
//		}
	}
	return 0;
}