/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2016 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-04 12:11:47
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-04 13:07:48
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;


int main(void)
{
	int N;
	int solo;
	int ans = 0;

	scanf("%d", &N);
	while(N--){
		scanf("%d", &solo);
		ans ^= solo;
		//Xor
		//异或运算真是一个神奇的东西。。在做这道题的时候，无意中翻到了一位物理大神的博客。。http://www.physixfan.com/archives/563
		//天才的世界果然与我不同。。。
		//同时Xor,还可以用来解决硬盘数据恢复，从n对数中找到单独的数的题目。。即用以上方法，将所有数异或。。。
		//厉害了。。大神收下膝盖
		//
	}
	if (ans == 0) {
        printf("B\n");
    } else {
        printf("A\n");
    }
    return 0;
}