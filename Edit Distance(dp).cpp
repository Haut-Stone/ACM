
//
//  main.c
//  Edit Distance(dp)
//
//  Created by Jack Lee on 2016/11/29.
//  Copyright © 2016年 SJH. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    char line1[1010];
    char line2[1010];
    int dp[1010][1010];
    int n,m;
    
    gets(line1);
    gets(line2);
    
    n = (int)strlen(line1);
    m = (int)strlen(line2);
    
    for(int i=1;i<=n;i++){
        dp[i][0] = i;
    }
    for(int i=1;i<=m;i++){
        dp[0][i] = i;
    }
    dp[0][0] = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int insertion = dp[i][j-1] + 1;
            int deletetion = dp[i-1][j] + 1;
            int replace = dp[i-1][j-1] + (line1[i-1] == line2[j-1] ? 0:1);
            dp[i][j] = min(replace, min(insertion, deletetion));
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;
}