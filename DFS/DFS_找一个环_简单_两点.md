## 题意

福克斯在玩一款手机解迷游戏，这个游戏叫做”两点”。基础级别的时候是在一个n×m单元上玩的。像这样：

![](https://img.51nod.com/upload/000FBEBD/08D26811337C62460000000000000003.jpeg)

每一个单元有包含一个有色点。我们将用不同的大写字母来表示不同的颜色。
这个游戏的关键是要找出一个包含同一颜色的环。比如上图中4个蓝点，形成了一个环。你现在就要找一个满足一下条件的环
- 至少包含4个点，且所有的点是同一种颜色。
- 环上的所有点如上图一样按顺序首尾相连。

## 样例输入

```cpp
3 4     //行数， 列数 {2->50}
AAAA    //每行每列的字母 {A->Z}
ABCA
AAAA
3 4     //行数， 列数 {2->50}
AAAA    //每行每列的字母 {A->Z}
ABCA
AADA
```

## 样例输出

```cpp
Yes     //有环Yes， 无环No
No
```
## 思路

比较简单的一道搜索题，只要找到一个环就好了，枚举所有点为起点，然后进行深搜，搜到起点就说明有环，然后返回。有一种很特殊的情况有超时的风险，就是所有的点字母都相同，这样就会产生搜索的最坏情况。为了解决这种情况，只要找到一个环，flag只要为1，就结束所有的dfs函数。

## code

```cpp
const int N = 55;
const int INF = 0x3f3f3f3f;

char rawMap[N][N];
int iMap[N][N];
int vis[N][N];
int dic[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int beginX, beginY;
int flag, colorNow;
int n, m;

void dfs(int x, int y, int dep, int prex, int prey)
{
    if(x == beginX && y == beginY && dep >= 4){
        flag = true;
        return;
    }
    if(flag == true) return;
    for(int i=0;i<4;i++){
        int dx = x + dic[i][0];
        int dy = y + dic[i][1];
        if(dx >= 1 && dx <= n && dy >= 1 && dy <= m && iMap[dx][dy] == colorNow){
            if(dx == beginX && dy == beginY  && (dx != prex || dy != prey)){
                dfs(dx, dy, dep+1, x, y);
            }else if(!vis[dx][dy] && (dx != prex || dy != prey)){
                vis[dx][dy] = 1;
                dfs(dx, dy, dep+1, x, y);
                vis[dx][dy] = 0;
            }
        }
    }
}

int main(void)
{
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i=0;i<n;i++){
            scanf("%s", rawMap[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                iMap[i+1][j+1] = rawMap[i][j] - 'A' + 1;
            }
        }
        flag = false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                memset(vis, 0, sizeof(vis));
                beginX = i;
                beginY = j;
                colorNow = iMap[i][j];
                vis[i][j] = 1;
                dfs(i, j, 0, -1, -1);
                if(flag) break;
            }
            if(flag) break;
        }
        if(flag){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
}
```