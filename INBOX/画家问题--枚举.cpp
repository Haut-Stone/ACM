/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-24 11:54:11
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-09-28 13:54:40
*/

//改了好多次终于改对了

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int N = 40;

int sum;
int raw[N][N];
int press[N][N];
char iMap[N][N];

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

bool successOrNot(int size)
{
	for(int i=1;i<=size;i++){
		if((raw[size][i] + press[size][i] + press[size][i-1] + press[size][i+1] + press[size-1][i])%2 == 0){
			return false;
		}
	}
	return true;
}
int myEnum(int size)
{
	for(int i=1;i<=size;i++){
		press[1][i] = 0;
	}
	int flag = pow(2, size);
	int temp;
	int re = 10e6;
	//开始枚举所有的情况
	for(int i=1;i<=flag;i++){
		temp = i-1;
		sum = 0;
		memset(press, 0, sizeof(press));
		for(int j=1;j<=size;j++){
			if(temp%2 != 0){
				sum++;
			}
			press[1][j] = temp%2;
			temp = temp / 2;
		}
//		printf("%d%d%d%d%d\n", press[1][1], press[1][2], press[1][3], press[1][4], press[1][5]);
		//第一行的值已经改好了
		judgeRestLine(size);
		bool iYesOrNot = successOrNot(size);
		if(iYesOrNot == true && sum < re){
			re = sum;
		}
	}
	return re;
}

int main(void)
{
	int size;
	while(~scanf("%d", &size)){
		for(int i=0;i<size;i++){
			scanf("%s", iMap[i]);
		}
		for(int i=0;i<=size;i++){
			for(int j=0;j<=size;j++){
				if(iMap[i][j] == 'y'){
					raw[i+1][j+1] = 1;
				}else{
					raw[i+1][j+1] = 0;
				}
			}
		}
		//到此为止数据读入部分完毕
		
		int iMin = myEnum(size);
		if(iMin == 10e6){
			printf("inf\n");
		}else{
			printf("%d\n", iMin);
		}
	}
	return 0;
}
