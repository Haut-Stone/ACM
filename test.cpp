/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-22 11:12:17
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-29 23:28:25
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

//
//今天是新春大作战专场
//
const int N = 10;
char myMap[N][N];
int colUsed[N];
int n, k;
int ans;

void dfs(int row, int k)
{
    if(k==0){
        ans++;
        return;
    }
    for(int i=row;i<n;i++){
        for(int j=0;j<n;j++){
            if(myMap[i][j] == '.' || colUsed[j] == 1) continue;
            colUsed[j] = 1;
            dfs(i+1, k-1);
            colUsed[j] = 0;
        }
    }
}

int main()
{
    while(cin>>n>>k &&(n!=-1 && k!=-1)){
        getchar();
        ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>myMap[i][j];
            }
            getchar();
        }
        dfs(0, k);
        cout<<ans<<endl;
    }
    return 0;
}