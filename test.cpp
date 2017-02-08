/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-22 11:12:17
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-02-08 11:19:50
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    int digit1, digit2;
    int a[100],b[100];
    int i, j, k, sum = 0;
    scanf("%d %d", &digit1, &digit2);
    for(i = 0; i < digit1; i++){
        scanf("%d", &a[i]);
    }
    for(j = 0; j < digit2; j++){
        scanf("%d", &b[j]);
    }
    for(i = 0;i < digit1;i++){
        if(b[0] == a[i]){
            k = i;
            i++;
            for(j = 1;j < digit2;j++,i++){
                if(b[j]==a[i]){
                    sum++;
                }   
                else{
                    break;
                }
            }
        }
        if(j == digit2)
        break;
    }
    if(j == digit2 && sum != 0)
        printf("%d\n",k);
    else
    printf("No Answer\n");
    return 0;
}