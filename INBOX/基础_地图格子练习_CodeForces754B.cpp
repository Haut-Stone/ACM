/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-15 22:04:31
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-28 19:31:17
*/

//http://vj.sdutacm.org/contest/view.action?cid=62932#problem/E
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int N = 200;

char Imap[N][N];
int flag;

int searchMap(int x, int y)
{
	if(Imap[x+1][y+1] == 'x' && Imap[x-1][y-1] == 'x') return 1;
	if(Imap[x+1][y-1] == 'x' && Imap[x-1][y+1] == 'x') return 1;
	if(Imap[x+1][y] == 'x' && Imap[x-1][y] == 'x') return 1;
	if(Imap[x][y+1] == 'x' && Imap[x][y-1] == 'x') return 1;
	if(Imap[x-1][y-1] == 'x' && Imap[x-2][y-2] == 'x') return 1;
	if(Imap[x-1][y] == 'x' && Imap[x-2][y] == 'x') return 1;
	if(Imap[x-1][y+1] == 'x' && Imap[x-2][y+2] == 'x') return 1;
	if(Imap[x][y+1] == 'x' && Imap[x][y+2] == 'x') return 1;
	if(Imap[x+1][y+1] == 'x' && Imap[x+2][y+2] == 'x') return 1;
	if(Imap[x+1][y] == 'x' && Imap[x+2][y] == 'x') return 1;
	if(Imap[x+1][y-1] == 'x' && Imap[x+2][y-2] == 'x') return 1;
	if(Imap[x][y-1] == 'x' && Imap[x][y-2] == 'x') return 1;
	return 0;
}

int main(void)
{   
	for(int i=3;i<7;i++){
		for(int j=3;j<7;j++){
			scanf("%c", &Imap[i][j]);
		}
		getchar();
	}
	for(int i=3;i<7;i++){
		for(int j=3;j<7;j++){
			if(Imap[i][j] == '.'){
				flag = searchMap(i, j);
				if(flag) break;
			}
		}
		if(flag) break;
	}
	if(flag){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;
}