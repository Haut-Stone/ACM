/*
一道以判断奇偶为思路的题。可以吧100视为0.5， 吧200视为1.
 */
/*
题目描述

The Christmas Eve is coming,so simple has bought n apples for his two friends. Now he wants to divide all the apples between the friends. Each apple weights 100 grams or 200 grams.Of course Simple doesn't want to make any of his friend unhappy. Therefore the total weight of the apples given to his friends must be equal. But unfortunately Simple doesn't have a knife,so he cannot split any apple into some parts. Please, tell him: is it possible to divide all the apples in a fair way between his friends?

输入
The first T indicates there are T groups of date.

The first line of every group contains an integer n (1 <=n <= 100) — the number of apples. The second line contains n integers w1, w2, ..., wn (wi = 100or wi = 200), where wi is the weight of the i-th apple.

输出
In a single line print "YES" (without the quotes) if it is possible to divide all the apples between his friends. Otherwise print "NO" (without the quotes).

样例输入
2
3
100 200 100
4
100 100 100 200

样例输出
YES
NO
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	int n;
	int solo;
	int sum1;
	int sum2;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		sum2 = 0;
		sum1 = 0;
		for(int i=0;i<n;i++){
			scanf("%d", &solo);
			if(solo == 100) sum1++;
			if(solo == 200) sum2++;
		}
		if(sum1 == 0){
			if(sum2 % 2 == 0){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}else if(sum2 == 0){
			if(sum1 % 2 == 0){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}else{
			if(sum1 % 2 == 0){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}	
	return 0;
}