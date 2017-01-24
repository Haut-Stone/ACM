/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-24 11:54:11
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-24 17:24:44
*/

//答案对了，但是RE不知为何。。。。
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int N = 100;

int sum;
int raw[N][N];
int press[N][N];

int judgeRestLine(int size)
{
	for(int i=2;i<=size;i++){
		for(int j=1;j<=size;j++){
			press[i][j] = (raw[i-1][j] + press[i-1][j] + press[i-1][j-1] + press[i-1][j+1] + press[i-2][j] + 1)%2;
			if(press[i][j] == 1) sum++;
		}
	}
	return 0;
}

int successOrNot(int size)
{
	for(int i=1;i<=size;i++){
		if((raw[size][i] + press[size][i] + press[size][i-1] + press[size][i+1] + press[size-1][i])%2 == 0){
			return 0;
		}
	}
	return 1;
}
int myEnum(int size)
{
	for(int i=1;i<=size;i++){
		press[1][i] = 0;
	}
	int flag = pow(2, size);
	int temp;
	int min;
	//开始枚举所有的情况
	for(int i=1;i<=flag;i++){
		temp = i-1;
		sum = 0;
		min = 10e6;
		memset(press, 0, sizeof(press));
		for(int j=1;j<=size;j++){
			if(temp%2 != 0){
				sum++;
			}
			press[1][j] = temp%2;
			temp = temp / 2;
		}
		//第一行的值已经改好了
		judgeRestLine(size);
		int yesOrNot = successOrNot(size);
		if(yesOrNot && sum < min){
			min = sum;
		}
	}
	return min;
}

int main(void)
{
	int T;
	int size;
	char simbol;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &size);
		getchar();
		for(int i=1;i<=size;i++){
			for(int j=1;j<=size;j++){
				scanf("%c", &simbol);
				if(simbol == 'y'){
					raw[i][j] = 1;
				}else{
					raw[i][j] = 0;
				}
			}
			getchar();
		}
		//到此为止数据读入部分完毕
		
		int min = myEnum(size);
		if(min == 10e6){
			printf("inf\n");
		}else{
			printf("%d\n", min);
		}
	}
    return 0;
}