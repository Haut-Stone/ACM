//找规律，滴滴2016面试题，亮灯问题
#include <cstdio>
#include <iostream>
#include <cstdlib>

int main(int argc, char const *argv[])
{
    int T;
    int solo;
    int ans;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &solo);
        ans = 0;
        for(int i=1;i<=solo;i++){
            if(i*i < solo){//寻找最大的完全平方数
                ans++;
            }else if(i*i == solo){
                ans++;
                break;
            }else{
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}