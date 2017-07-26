/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-09 22:02:48
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-09 22:03:04
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int main(void)
{
    string s;
    long long k;
    long long ans = 0;
    long long num = 0;
    cin>>s>>k;
    for(long long i=s.size()-1;i>=0;i--){
        if(s[i] == '0'){
            num++;
            if(num == k){
                break;
            }
        }else{
            ans++;
        }
    }
    if(num == k){
        printf("%lld\n", ans);
    }else{
        printf("%lu\n", s.size()-1);
    }
    return 0;
}