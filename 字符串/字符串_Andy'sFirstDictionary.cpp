/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-28 19:45:09
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-28 19:45:45
*/

//https://cn.vjudge.net/problem/UVA-10815
//这个方法真的是浅显易懂啊

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

char solo;
char str[10010];
vector<string> dis;

int main(void)
{
	int pos = 0;
	while(~(solo = getchar())){
		if(isalpha(solo)){
			str[pos++] = tolower(solo);
		}else if(pos != 0){
			str[pos] = '\0';
			dis.push_back(str);
			pos = 0;
		}
	}
	sort(dis.begin(), dis.end());
	for(int i=0;i<dis.size();i++){
		if(i == 0 || dis[i] != dis[i-1]){
			cout<<dis[i]<<endl;
		}
	}
}