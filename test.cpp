/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-22 11:12:17
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-12 22:31:46
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
using namespace std;
  
#define INPUT_TEST freopen("in.txt", "r", stdin)

int a, b, c;
int ans;

int main(void)
{
    INPUT_TEST;
    int T;
    cin>>T;
    while(T--){
        cin>>a>>b>>c;
        a/=2;
        c/=4;
        ans = a + b - c;
        printf("%d\n", ans);
    }
}