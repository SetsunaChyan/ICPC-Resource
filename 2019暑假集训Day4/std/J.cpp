#include<bits/stdc++.h>
using namespace std;
int i,j,n;
long long dp[1001];//dp数组存储第i个数的组成种数
bool b[1001];//b数组判断是否为素数
void prime(){
    for(i=2;i<=500;i++)
        if(!b[i])
            for(j=2;i*j<=1000;j++)
                b[i*j]=1;
}//筛法
int main()
{   prime();//预处理，筛出素数
    cin>>n;//输入
    //完全背包经典代码
    dp[0]=1;//边界值：当取数和为0时值为1
    for(i=2;i<=n;i++)//循环每个数取或不取
        if(!b[i])//是素数才能考虑是否能取
        for(j=i;j<=n;j++)//从i开始到n,因为你要得到的数肯定不小于取的数
            dp[j]+=dp[j-i];////取这个素数，则减去这个素数方案数累加到总方案数
    cout<<dp[n];//输出n的方案数
    return 0;
}