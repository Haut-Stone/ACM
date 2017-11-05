/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-11-01 11:47:44
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-11-01 11:48:18
*/

#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define INPUT_TEST freopen("/home/parallels/Desktop/INPUT", "r", stdin)
using namespace std;

const double eps = 1e-8;
const int N = 5050;
const int INF = 0x3f3f3f3f;

struct Node
{
    double x;
    double y;
    double dis;
}a[N];

int ans[N];

int main(void)
{
//    INPUT_TEST;
    int T;
    int n;
    double R, r;

    scanf("%d", &T);
    while(T--){
        scanf("%d%lf%lf", &n, &R, &r);

        double ansr;
        if(R >= 2*r){
            ansr = R - 2*r;
        }else{
            ansr = 2*r - R;
        }

        double maxn = INF;
        int cnt = 0;
        bool inSmallCircle = false;
        for(int i=1;i<=n;i++){
            scanf("%lf%lf", &a[i].x, &a[i].y);
            a[i].dis = sqrt(a[i].x*a[i].x + a[i].y*a[i].y);
            if(a[i].dis < maxn) maxn = a[i].dis;
            if(a[i].dis <= ansr){
                inSmallCircle = true;
                ans[cnt++] = i;
            }
        }

        if(inSmallCircle){
            printf("%d\n%d", cnt, ans[0]);
            for(int i=1;i<cnt;i++){
                printf(" %d", ans[i]);
            }
            printf("\n");
        }else{
            int cnt = 0;
            for(int i=1;i<=n;i++){
                if(fabs(a[i].dis - maxn) < eps){
                    ans[cnt++] = i;
                }
            }
            printf("%d\n%d", cnt, ans[0]);
            for(int i=1;i<cnt;i++){
                printf(" %d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
