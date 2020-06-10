/*
题目描述
乔治有一些同样长的小木棍，他把这些木棍随意砍成几段，直到每段的长都不超过5050。

现在，他想把小木棍拼接成原来的样子，但是却忘记了自己开始时有多少根木棍和它们的长度。

给出每段小木棍的长度，编程帮他找出原始木棍的最小可能长度。

输入格式
共二行。

第一行为一个单独的整数N表示砍过以后的小木棍的总数，其中N≤65N≤65

（管理员注：要把超过5050的长度自觉过滤掉，坑了很多人了！）

第二行为NN个用空个隔开的正整数，表示NN根小木棍的长度。

输出格式
一个数，表示要求的原始木棍的最小可能长度
*/

// dfs + 优化

#include <bits/stdc++.h>
using namespace std;

int cnt;
int tmm[70];
int tot;
int maxn;
int minn;

void dfs(int res, int sum, int target, int p){
    if(res == 0){
        cout << target;
        exit(0);
    }
    if(sum == target){
        dfs(res-1, 0, target, maxn);
        return;
    }
    for(int i=p; i>=minn ;i--){
        if(tmm[i]!=0 && (i+sum)<=target) {
            tmm[i]--;
            dfs(res, sum+i, target, i);
            tmm[i]++;
            if(sum==0 || sum+i == target)
                break;
        }
    }
    return;
}

int main(){
    int n;
    cin >> n;
    int tmp;
    while(n--){
        cin >> tmp;
        if(tmp <= 50){
            cnt++;
            tmm[tmp]++;
            tot += tmp;
            maxn = maxn > tmp ? maxn: tmp;
            minn = minn < tmp ? minn: tmp;
        }
    }
    tmp  = tot >> 1;
    for(int i=maxn; i<=tmp; i++){
        if(tot % i == 0){
            dfs(tot/i, 0, i, maxn);
        }
    }
    cout << tot;
    return 0;
}

