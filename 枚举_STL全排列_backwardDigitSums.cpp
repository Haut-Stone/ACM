/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-30 21:12:10
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-30 21:18:10
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

#define INPUT_TEST freopen("in.txt", "r", stdin)

int n;
int sum;
int a[10][10];

int main(void)
{
	// INPUT_TEST;

	while(~scanf("%d %d", &n, &sum)){
		int input[10] = {1,2,3,4,5,6,7,8,9,10};
		do
		{
			for(int j=0;j<n;j++){
				a[0][j] =  input[j];
			}

			for(int i=1;i<n;i++){
				for(int j=0;j<n-i;j++){
					a[i][j] = a[i-1][j] + a[i-1][j+1];
				}
			}

			if(a[n-1][0] == sum){
				break;
			}

		} while (next_permutation(input, input + n));

		for(int i=0;i<n;i++){
			if(i != 0){
				printf(" ");
			}
			printf("%d", input[i]);
		}
		printf("\n");
	}
    return 0;
}