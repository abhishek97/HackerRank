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
#include<set>
#include<sstream>
#include<ctime>
#include <stack>
#include <iomanip>
#include <cassert>
#include<cmath>


using namespace std;


#define PB push_back
#define i64 long long
#define FOR(i,a,b) for(i=(a);i<(b);++i)
#define FORE(i,a,b) for(i=(a);i<=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define SZ(v) ((v).size())
#define LD long double
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VLD vector<LD>
#define MSET(x,y) memset((x),(y),sizeof(x))
#define SZOF(x) sizeof((x))
#define VVI vector< VI >
#define PII pair< int,int >
#define VPII vector< PII >
#define MP make_pair
#define PIPII pair<int, PII >
#define PIPIPII pair< int, PIPII >
#define u64 unsigned i64
#define Vi64 vector<i64>
#define Vu64 vector<u64>

#define MAXN 111
char barr[MAXN];
int arr[MAXN];
int lenn;

void MAIN()
{

    int cases;
    int ans;
    int summ[26];
    int ct;
    int i,j;
    int k;
    int x,y;


    scanf("%d",&cases);

    while(cases--)
    {
        ans=0;
        scanf("%s",barr);
        lenn=strlen(barr);
        for(i=0;i<lenn;++i)
        {
            arr[i]=barr[i]-'a';
        }
        for(i=0;i<lenn;++i)
        {
            for(j=i+1;j<lenn;++j)
            {
                MSET(summ,0);
                ct=26;
                for(k=0;k+j<lenn;++k)
                {
                    x=i+k;
                    y=j+k;

                    if(arr[x]!=arr[y])
                    {
                        if(summ[arr[x]]==0)
                        {
                            --ct;
                        }

                        if(summ[arr[y]]==0)
                        {
                            --ct;
                        }

                        ++summ[arr[x]];
                        --summ[arr[y]];

                        if(summ[arr[x]]==0)
                        {
                            ++ct;
                        }

                        if(summ[arr[y]]==0)
                        {
                            ++ct;
                        }
                    }

                    if(ct==26)
                    {
                        ++ans;
                    }


                }
            }
        }


        printf("%d\n",ans);

    }

}

int main()
{
    freopen("Text/Sherlock and Anagrams.txt","r",stdin);

    MAIN();
    return 0;
}




