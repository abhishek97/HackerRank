#include <cstdio>
#include <algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include <complex>
#include <iostream>
#include <valarray>
#include<cstring>
#include<queue>
#include<bitset>
#include<map>

using namespace std;

#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define SZ(v) ((v).size())
#define LD long double
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VLD vector<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI vector< VI >


void prVectInt(VI vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%d\t",vect[i]);
    }

    printf("\n");
}


void prVectString(VS vect)
{
    int i;
    REP(i,vect.size())
    {
        printf("%s\t",vect[i].c_str());
    }

    printf("\n");
}


void arrayToVectorString(string *arr,VS &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}

void arrayToVectorInt(int *arr,VI &vect,int len)
{
    int i;

    REP(i,len)
    {
        vect.PB(arr[i]);
    }
}





int s_bitcount(unsigned int set1)
{
    int ret=0;

    ret=(set1&0x55555555) + ((set1>>1) & 0x55555555);
    ret=(ret&0x33333333) + ((ret>>2) & 0x33333333);
    ret=(ret&0x0F0F0F0F) + ((ret>>4) & 0x0F0F0F0F);
    ret=(ret&0x00FF00FF) + ((ret>>8) & 0x00FF00FF);
    ret=(ret&0x0000FFFF) + ((ret>>16));

    return ret;
}

#define MAXN 2510
#define MAXK 2510
#define MOD 1000000007

i64 dp[MAXN+1][MAXK+1];
i64 st[MAXN+1][MAXK+1];


int main()
{
    freopen("Text/Swap Permutation.txt","r",stdin);
    int i,ti,j;

    int n,k;

    scanf("%d %d",&n,&k);

    st[0][0]=1;

    for(i=1;i<=MAXN;++i)
    {
        st[i][0]=0;

        for(j=1;j<=MAXK;++j)
        {
            st[i][j]+=(st[i-1][j]*(i-1))%MOD;
            st[i][j]%=MOD;
            st[i][j]+=st[i-1][j-1];
            st[i][j]%=MOD;
        }
    }

    dp[0][0]=1;
    dp[1][0]=1;

    for(i=2;i<=MAXN;++i)
    {
        dp[i][0]=1;

        for(j=1;j<=MAXK;++j)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
            dp[i][j]%=MOD;

            if(j>=i)
            {
                dp[i][j]-=dp[i-1][j-i];
            }

            while(dp[i][j]<0)
            {
                dp[i][j]+=MOD;
            }

            dp[i][j]%=MOD;
        }
    }

    if(n==1)
    {
        printf("0 1\n");
        return 0;
    }

    i64 s1=0;

    for(int m=k;m>=0;m-=2)
    {
        s1+=dp[n][m];
        s1%=MOD;
    }

    i64 s2=0;

    for(int i=0;i<=min(k,n);++i)
    {
        s2+=st[n][n-i];
        s2%=MOD;
    }

    printf("%lld %lld\n",s1,s2);

    return 0;
}

