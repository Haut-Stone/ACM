/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-25 20:49:39
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-26 17:41:54
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int N = 310;

int Imap[N][N];
int n, m, k;

int main(void)
{
	cin>>n>>m>>k;
	int t = n*m - (k-1) * 2;
	int x = 1;
	int y = 1;


	printf("%d", t);
	while(t--){
		printf(" %d %d", x, y);
		Imap[x][y] = 1;

		if(y+1 <= m && !Imap[x][y+1]){
			y++;
		}else if(y-1 >= 1 && !Imap[x][y-1]){
			y--;
		}else{
			x++;
		}
	}
	k--;
	while(k--){
		printf("\n2");
		t = 2;
		while(t--){
			printf(" %d %d", x, y);
			Imap[x][y] = 1;
			if(y + 1 <= m && !Imap[x][y+1]){
				y++;
			}else if(y-1 >= 1 && !Imap[x][y-1]){
				y--;
			}else{
				x++;
			}
		}
	}
	printf("\n");
    return 0;
}