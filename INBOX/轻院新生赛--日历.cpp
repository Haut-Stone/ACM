/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2016 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2016-12-24 21:37:44
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2016-12-26 12:49:59
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define N 15
using namespace std;


int main(void)
{
    int year;
    int month;
    int myMonth[N] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int mark2015[N] = {0, 4, 7, 7, 3, 5, 1, 3, 6, 2, 4, 7, 2};
    int mark2016[N] = {0, 5, 1, 2, 5, 7, 3, 5, 1, 4, 6, 2, 4};
    int mark2017[N] = {0, 7, 3, 3, 6, 1, 4, 6, 2, 5, 7, 3, 5};
    int mark2018[N] = {0, 1, 4, 4, 7, 2, 5, 7, 3, 6, 1, 4, 6};
    while (scanf("%d-%d", &year , &month) != EOF) {
            if(year == 2016){
                myMonth[2] = 29;
            }else{
                myMonth[2] = 28;
            }
            if(year == 2015){
                for(int i=0;i<(mark2015[month]-1);i++){
                    printf("   ");
                }
                for(int i=1;i<=myMonth[month];i++){
                    if((mark2015[month] + i-1) % 7 == 0){
                        printf("%2d\n", i);
                    }else if(i != myMonth[month]){
                        printf("%2d ", i);
                    }else{
                        printf("%2d\n", i);
                    }
                }
                printf("\n");
            }
            if(year == 2016){
                for(int i=0;i<(mark2016[month]-1);i++){
                    printf("   ");
                }
                for(int i=1;i<=myMonth[month];i++){
                    if((mark2016[month] + i-1) % 7 == 0){
                        printf("%2d\n", i);
                    }else if(i != myMonth[month]){
                        printf("%2d ", i);
                    }else{
                        printf("%2d\n", i);
                    }
                }
                printf("\n");
            }
            if(year == 2017){
                for(int i=0;i<(mark2017[month]-1);i++){
                    printf("   ");
                }
                for(int i=1;i<=myMonth[month];i++){
                    if((mark2017[month] + i-1) % 7 == 0){
                        printf("%2d\n", i);
                    }else if(i != myMonth[month]){
                        printf("%2d ", i);
                    }else{
                        printf("%2d\n", i);
                    }
                }
                printf("\n");
            }
            if(year == 2018){
                for(int i=0;i<(mark2018[month]-1);i++){
                    printf("   ");
                }
                for(int i=1;i<=myMonth[month];i++){
                    if((mark2018[month] + i-1) % 7 == 0){
                        printf("%2d\n", i);
                    }else if(i != myMonth[month]){
                        printf("%2d ", i);
                    }else{
                        printf("%2d\n", i);
                    }
                }
                printf("\n");
            }
        }
    return 0;
}