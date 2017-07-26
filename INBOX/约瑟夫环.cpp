/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2016 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-16 14:34:48
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-16 15:07:08
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

int book[100010];

//约瑟夫环，模拟方法,貌似是对的，但是大的数据过不了
int main(void)
{
    int n = 0;
    int k = 0;
    int ans = 0;
    memset(book, 0, 100010);
    scanf("%d %d", &n, &k);
    int flag = n;
    int counter = 1;
    while(flag){
        for(int i=0;i<n;i++){
            if(book[i] == 0){
                if(flag == 1){
                    ans = i;
                    flag = 0;
                    break;
                }
                if(counter%k == 0){
                    book[i] = 1;
                    flag--;
                }
                counter++;
            }
        }
    }
    printf("%d\n", ans+1);
    return 0;
}