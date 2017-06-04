/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-06-03 12:15:58
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-06-03 15:04:23
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

const int N = 25;

long long number[N];
bool isNegative[N];
long long book[2000000];
int last;
long long sum;
long long tempSum;
long long k;
long long tempK;
long long AllCircleNumber;

int n;
long long solo;

int solve()
{
	int ans = 0;

	for(int i=0;i<n;i++){
		AllCircleNumber *= 2;
	}

	while(k < AllCircleNumber){

		tempK = k;
		int cnt = 0;
		while(tempK){
			int temp = tempK % 2;
			tempK = tempK / 2;
			isNegative[cnt++] = temp;
		}

		tempSum = 0;
		for(int i=0;i<n;i++){
			if(isNegative[i]){
				tempSum -= number[i];
			}else{
				tempSum += number[i];
			}
		}

		bool haveSameNumber = false;
		for(int i=0;i<last;i++){
			if(book[i] == tempSum){
				haveSameNumber = true;
				break;
			}
		}
		if(!haveSameNumber){
			book[last++] = tempSum;
			ans++;
		}
		k++;
	}
	return ans;
}

void init()
{
	memset(isNegative, 0, sizeof(isNegative));
	AllCircleNumber = 1;
	k = 0;
	last = 0;
}

int main(void)
{
	while(~scanf("%d", &n)){
		init();
		for(int i=0;i<n;i++){
			scanf("%lld", &solo);
			number[i] = abs(solo);
		}
		printf("%d\n", solve());

		// for(int i=0;i<last;i++){
		// 	printf("%lld ", book[i]);
		// }
		// printf("\n");
	}
}