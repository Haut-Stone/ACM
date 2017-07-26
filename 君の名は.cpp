/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-06-03 12:15:58
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-07-26 10:42:09
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

const int N = 100020;
const int M = 27;
const int BASE = 1e9 + 7;

char str[N];

int num[M][N];
int mapping[M];
int sum[M];
int lenIsNot1[M];
int power[N];
int n, maxLen;

bool cmp(int a, int b)
{
	for(int i=maxLen-1;i>=0;i--){
		if(num[a][i] != num[b][i]){
			return num[a][i] < num[b][i];
		}
	}
	return 0;
}

int main(void)
{
	power[0] = 1;
	for(int i=1;i<N;i++){
		power[i] = (long long)power[i-1] * 26 % BASE;
	}
	int cas = 1;
	while(~scanf("%d", &n)){
		memset(num, 0, sizeof(num));
		memset(sum, 0, sizeof(sum));
		memset(lenIsNot1, 0, sizeof(lenIsNot1));

		maxLen = 0;
		for(int i=0;i<n;i++){
			scanf("%s", str);
			int len = (int)strlen(str);
			if(len > 1){
				lenIsNot1[str[0] - 'a'] = 1;
			}
			reverse(str, str+len);
			for(int j=0;j<len;j++){
				num[str[j] - 'a'][j]++;
				sum[str[j] - 'a'] += power[j];
				if(sum[str[j] - 'a'] >= BASE){
					sum[str[j] - 'a'] -= BASE;
				}
			}
			maxLen = max(maxLen, len);
		}

		for(int i=0;i<26;i++){
			for(int j=0;j<maxLen;j++){
				num[i][j+1] += num[i][j] / 26;
				num[i][j] %= 26;
			}
			while(num[i][maxLen]){
				num[i][maxLen+1] += num[i][maxLen] / 26;
				num[i][maxLen] %= 26;
				maxLen++; 
			}
			mapping[i] = i;
		}

		sort(mapping, mapping+26, cmp);

		int zero = -1;
		for(int i=0;i<26;i++){
			if(!lenIsNot1[mapping[i]]){
				zero = mapping[i];
				break;
			}	
		}

		int res = 0;
		int x = 25;
		for(int i=25;i>=0;i--){
			if(mapping[i] != zero){
				res += (long long)(x--) * sum[mapping[i]] % BASE;
				res %= BASE;
			}
		}
		printf("Case #%d: %d\n", cas++, res);
	}
	return 0;
}

/*
const int N = 100020;
const int BASE = 1e9 + 7;

char str[N];
int num[27][N];
int noToBeZero[27];
int imap[27];
int power[N];
int sum[N];
int cas = 1;
int n, maxLen;

//imap[25] 对应的是权值最大的字符
bool cmp(int a, int b)
{
	for(int i=maxLen-1;i>=0;i--){
		if(num[a][i] != num[b][i]){
			return num[a][i] < num[b][i];
		}
	}
	return 0;
}

//制造26的次方
void initPower()
{
	power[0] = 1;
	for(int i=1;i<N;i++){
		power[i] = (long long)power[i-1] * 26 % BASE;
	}
}

//数组初始化位0
void initToZero()
{
	memset(num, 0, sizeof(num));
	memset(sum, 0, sizeof(sum));
	memset(noToBeZero, 0 ,sizeof(noToBeZero));
}

//分析字符
void analysisStr()
{
	maxLen = 0;
	for(int i=0;i<n;i++){
		scanf("%s", str);
		int len = (int)strlen(str);
		if(len > 1){
			noToBeZero[str[0] - 'a'] = 1;
		}

		//总和字符的权重
		reverse(str, str + len);
		for(int j=0;j<len;j++){
			num[str[j] - 'a'][j]++;
			sum[str[j] - 'a'] += power[j];
			if(sum[str[j] - 'a'] >= BASE){
				sum[str[j] - 'a'] -= BASE;
			}
		}
		maxLen = max(maxLen, len);
	}

	//进位
	for(int i=0;i<26;i++){
		for(int j=0;j<maxLen;j++){
			num[i][j+1] += num[i][j] / 26;
			num[i][j] = num[i][j] % 26;
		}
		while(num[i][maxLen]){
			num[i][maxLen+1] += num[i][maxLen] / 26;
			num[i][maxLen] = num[i][maxLen] % 26;
			maxLen++;
		}
		imap[i] = i;
	}

	sort(imap, imap+26, cmp);

	int zero = -1;
	for(int i=0;i<26;i++){
		if(!noToBeZero[imap[i]]){
			zero = imap[i];
			break;
		}
	}

	int res = 0;
	int x = 25;
	for(int i=25;i>=0;i--){
		if(imap[i] != zero){
			res += (long long) (x--) * sum[imap[i]] % BASE;
			res = res % BASE;
		}
	}
	printf("Case #%d: %d\n", cas++, res);
}

int main(void)
{
	initPower();
	while(~scanf("%d", &n)){
		initToZero();
		analysisStr();
	}
}

 */