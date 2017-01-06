/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2016 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-05 17:00:04
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-06 17:44:02
*/
//暴力水过
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;


int main(void)
{
	int ans = 0;
	int solo = 0;
	int head, tail;
	char str[1010];
	int mark;
	scanf("%s", str);
	for(int i=0;i<=strlen(str);i++){
		for(int j=i;j<=strlen(str);j++){
			head = i;
			tail = j;
			mark = 0;
			solo = 0;
			while(head <= tail){
				if(str[head] == str[tail]){
					if(head == tail){
						solo++;
					}else{
						solo+=2;
					}
				}else{
					mark = 1;
					break;
				}
				head++;
				tail--;
			}
			if(solo > ans && mark == 0){
				ans = solo;
			}
		}
	}
	printf("%d", ans);
    return 0;
}