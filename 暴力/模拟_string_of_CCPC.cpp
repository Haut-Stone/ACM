/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-31 22:55:46
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-31 22:56:14
*/

//kmp暴力艹出来就好了
//

using namespace std;

const int N = 300100;

int my_next[N];

void getNext(char str[], int len)
{
    int j = -1;
    my_next[0] = -1;
    for(int i=1;i<len;i++){
        while(j != -1 && str[i] != str[j+1]){
            j = my_next[j];
        }
        if(str[i] == str[j+1]){
            j++;
        }
        my_next[i] = j;
    }
}

int kmp(char text[], char pattern[])
{
    int ans = 0;
    int n = (int)strlen(text);
    int m = (int)strlen(pattern);
    getNext(pattern, m);
    int j = -1;
    for(int i=0;i<n;i++){
        while(j != -1 && text[i] != pattern[j+1]){
            j = my_next[j];
        }
        if(text[i] == pattern[j+1]){
            j++;
        }
        if(j == m-1){
            ans++;
        }
    }
    return ans;
}

int main(void)
{
    int T;
    int n;
    char text[N];
    char pattern[N] = "CCPC";
    char CPC[N] = "CPC";
    char CCP[N] = "CCP";
    char CCCPC[N] = "CCCPC";
    char CCC[N] = "CCC";

    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        scanf("%s", text);
        int numOfCCPC = kmp(text, pattern);
        int numOfCPC = kmp(text, CPC);
        int numOfCCP = kmp(text, CCP);
        int numOfCCCPC = kmp(text, CCCPC);
        int numOfCCC = kmp(text, CCC);

        if(numOfCCPC != numOfCPC || numOfCCPC != numOfCCP){
            cout<<numOfCCPC+1<<endl;
            continue;
        }else{
            if(numOfCCCPC != numOfCCC){
                cout<<numOfCCPC+1<<endl;
                continue;
            }else{
                cout<<numOfCCPC<<endl;
                continue;
            }
        }
    }
    return 0;
}
