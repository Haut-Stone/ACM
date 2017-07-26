/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-16 14:49:42
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-16 15:03:12
*/

//http://vj.sdutacm.org/contest/view.action?cid=62932#problem/D
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int N = 10000;
int track[N];
int a[N];
int b[N];
int anotherTrack[N];

int main(void)
{
	int barrierNumber;
	int length;
	cin>>barrierNumber>>length;
	for(int i=0;i<barrierNumber;i++){
		scanf("%d", &a[i]);
		track[a[i]] = 1;
	}
	for(int i=0;i<barrierNumber;i++){
		scanf("%d", &b[i]);
	}
	for(int i=0;i<length;i++){
		memset(anotherTrack, 0, sizeof(anotherTrack));
		int solo = i;
		for(int j=0;j<barrierNumber;j++){
			anotherTrack[(solo + b[j])%length] = 1;//对数组进行循环处理，这个式子是吧环转换成数组的核心。
		}
		int flag = 1;
		for(int k=0;k<length;k++){
			if(track[k] != anotherTrack[k]){
				flag = 0;
				break;
			}
		}
		if(flag == 1){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
    return 0;
}