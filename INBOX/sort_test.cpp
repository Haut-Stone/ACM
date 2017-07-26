
//
//  main.c
//  sort()练习
//
//  Created by Jack Lee on 2016/11/29.
//  Copyright © 2016年 SJH. All rights reserved.
//
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;


struct rule1{
	bool operator()(const int &a1, const int &a2)
	{
		return a1%10 > a2%10;
	}
};

int main()
{
	int a[] = {1, 23, 23, 12, 432, 35, 435,2,22,32,42,13,64,472,7378,3,84,28,3668,73,63,5,56,5};
	sort(a, a+24);
	for(int i=0;i<24;i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	sort(a, a+24,greater<int>());
	for(int i=0;i<24;i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	sort(a, a+24,rule1());
	for(int i=0;i<24;i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}