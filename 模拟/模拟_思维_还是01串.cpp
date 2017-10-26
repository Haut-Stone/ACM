/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-26 07:50:58
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-26 07:52:05
*/


#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;


const int N = 1000000;
char a[N];

int main(void)
{
    int ans = 0;
    while(scanf("%s", &a) != EOF){
        ans = 0;
        
        //output the sum of 1 in this string
        for(int i=0;i<strlen(a);i++){
            if(a[i] == '1'){
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}