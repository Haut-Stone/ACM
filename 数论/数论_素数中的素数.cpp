/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-10 20:10:05
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-10 20:10:50
*/

//素数筛练习水题
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

const int MAX_SIZE = 1e6 + 10;
void init(bool prime[]);
int Index[MAX_SIZE];

int main()
{
	bool prime[MAX_SIZE];
	memset(prime, 1, MAX_SIZE);
	init(prime);
	int indexNumber = 1;
	memset(Index, 0, sizeof(Index));
	for(int i=0;i<MAX_SIZE;i++){
		if(prime[i]){
			Index[i] = indexNumber++;
		}
	}
	int n;
	while(scanf("%d", &n) != EOF){
		for(int i=n;i<=MAX_SIZE;i++){
			if(prime[i] && prime[Index[i]]){
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}

void init(bool prime[])
{
	prime[0] = prime[1] = 0;
	prime[2] = 1;
	for(int i=3;i<=MAX_SIZE;i++){
		prime[i] = i%2 == 0 ? 0:1;
	}
	for(int i=3; i<=sqrt(MAX_SIZE);i++){
		if(prime[i]){
			for(int j=i*i;j<=MAX_SIZE;j+=i*2){
				prime[j] = 0;
			}
		}
	}
}