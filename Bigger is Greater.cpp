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



int main()
{
    freopen("Text/Bigger is Greater.txt","r",stdin);

    int cases;

    scanf("%d",&cases);

    int arr[101];
    char buff[105];
    int len;

    while(cases--)
    {

        scanf("%s",buff);
        len=strlen(buff);

        for(int i=0;i<len;++i)
        {
            arr[i]=buff[i]-'a';
            //arr[i]=i+1;
        }



        if(next_permutation(arr,arr+len))
        {
            //printf("DD\n");
            for(int i=0;i<len;++i)
            {
                printf("%c",arr[i]+'a');
            }
            printf("\n");
        }
        else
        {
            printf("no answer\n");
        }
    }


    return 0;
}


