<p align="center">
  <a href="http://shallweitalk.com">
    <img src="https://raw.githubusercontent.com/Haut-Stone/ACM/master/photos/me.png" width=220 height=220>
  </a>
  <h3 align="center">Stone</h3>
<!--   <p align="center">
  <span style="color: #D96045">Write</span>
  <span style="color: #449AD8">The</span> 
  <span style="color: #64C271">Code,</span>
  <span style="color: #EDC233">Change</span>
  <span style="color: #449AD8">The</span>
  <span style="color: #D96045">World.</span>
    <br>
  </p> -->
  <p align="center">
    <a href="http://shallweitalk.com">
      <img src="https://raw.githubusercontent.com/Haut-Stone/ACM/master/photos/CodeChangeWorld.png" width=300 height=40>
    </a>
  </p>
</p>
<br>

## 题目

>[这里是题目哦](http://acm.hdu.edu.cn/showproblem.php?pid=1074)

## 题解

>[这里是题解哦](http://blog.csdn.net/SSimpLe_Y/article/category/6294106)

## 代码

```cpp
const int N = 110;
const int INF = 99999999;

int n, binaryN;
int deadline[N];
int needTime[N];
int nowTime[N];
int pre[N];
char subjectName[20][N];
int dp[N];

void outPut(int n)
{
    if(!n) return;
    outPut(n-(1<<pre[n]));
    printf("%s\n", subjectName[pre[n]]);
}

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%s%d%d", subjectName[i], &deadline[i], &needTime[i]);
        }
        binaryN = 1<<n;//所有作业都做完时的二进制表示
        
        for(int i=1;i<binaryN;i++){//遍历所有作业的完成状态
            dp[i] = INF;
            for(int j=n-1;j>=0;j--){//从左到右假设这个作业新完成
                int subjectNow = 1<<j;
                if((subjectNow&i) == 0) continue;//如果遍历的状态里这个作业没有完成，就直接跳过
                int deductionPoints = nowTime[i-subjectNow] + needTime[j] - deadline[j];
                if(deductionPoints < 0){
                    deductionPoints = 0;
                }
                if(dp[i] > dp[i - subjectNow] + deductionPoints){//如果这个作业没有完成时的状态的总罚分，比现在小就更新。
                    dp[i] = dp[i - subjectNow] + deductionPoints;
                    nowTime[i] = nowTime[i - subjectNow] + needTime[j];
                    pre[i] = j;
                }
            }
        }
        printf("%d\n", dp[binaryN-1]);
        outPut(binaryN - 1);
    }
}
```

## 思路

这题在学长的题解里说的蛮清楚了，就是用二进制来压缩状态，至于其中的二进制和十进制的转换，只要脑子里面转过来
弯就可以了。可是这个弯不太好转，这个的话还是看经验的多少了。

![](https://raw.githubusercontent.com/Haut-Stone/ACM/master/photos/prprpr.png)

## 总结

	wait...... 