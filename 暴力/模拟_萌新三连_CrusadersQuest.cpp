/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-31 22:56:51
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-31 22:57:02
*/

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#define INPUT_TEST freopen("/home/parallels/Desktop/INPUT", "r", stdin)
using namespace std;

const int N = 1010;

char a[N];
char temp1[N];

int main(void)
{
//    INPUT_TEST;
    int t;
    scanf("%d", &t);
    while(t--){
        memset(a, '\0', sizeof(a));
        memset(temp1, '\0', sizeof(temp1));
        scanf("%s", a);
        int flag = false;
        int len  =strlen(a);
        int pos = 0;
        for(int i=1;i<len-1;i++){
            if(a[i-1] == a[i] && a[i] == a[i+1]){
                 flag = true;
                 pos = i;
            }
        }
        //have first super
        if(flag){
            for(int i=pos-1;i<=len-3;i++){
                a[i] = a[i+3];
            }
            int flag2 = false;
            int len2 = strlen(a);
            for(int i=1;i<len2-1;i++){
                if(a[i-1] == a[i] && a[i] == a[i+1]) flag2 = true;
            }
            if(flag2){
                printf("3\n");
            }else{
                printf("2\n");
            }
        }else{
            strcpy(temp1, a);
            len = strlen(temp1);
            int flag = false;
            for(int i=0;i<len;i++){
                if(temp1[i] == 'a'){
                    for(int j=i;j<len;j++){
                        temp1[j] = temp1[j+1];
                    }
                    len--;
                    i--;
                }
            }
            for(int i=1;i<len-1;i++){
                if(temp1[i-1] == temp1[i] && temp1[i] == temp1[i+1]) flag = true;
            }
            if(flag){
                printf("2\n");
                continue;
            }
            strcpy(temp1, a);
            len = strlen(temp1);
            flag = false;
            for(int i=0;i<len;i++){
                if(temp1[i] == 'g'){
                    for(int j=i;j<len;j++){
                        temp1[j] = temp1[j+1];
                    }
                    len--;
                    i--;
                }
            }
            for(int i=1;i<len-1;i++){
                if(temp1[i-1] == temp1[i] && temp1[i] == temp1[i+1]) flag = true;
            }
            if(flag){
                printf("2\n");
                continue;
            }
            strcpy(temp1, a);
            len = strlen(temp1);
            flag = false;
            for(int i=0;i<len;i++){
                if(temp1[i] == 'o'){
                    for(int j=i;j<len;j++){
                        temp1[j] = temp1[j+1];
                    }
                    len--;
                    i--;
                }
            }
            for(int i=1;i<len-1;i++){
                if(temp1[i-1] == temp1[i] && temp1[i] == temp1[i+1]) flag = true;
            }
            if(flag){
                printf("2\n");
            }else{
                printf("1\n");
            }
        }
    }
}
