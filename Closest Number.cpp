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

#define EPS 0

int solve(int a,int b,int x)
{
    long double ab=0;

    if(a==1)
    {
        ab=1;
    }
    else if(b==0)
    {
        ab=1;
    }
    else if(b==1)
    {
        ab=a;
    }
    else if(b==-1)
    {
        ab=1.0/(long double)a;
    }
    else if(b<0)
    {
        ab=0;
    }
    else
    {
        ab=(long double)pow((long double)a,(long double)b);
    }

    i64 ret1=(i64)((ab/(long double)x))*(i64)x;
    i64 ret2=ret1+x;
    i64 ret;

    if(((long double)(ret1+ret2)/2.0)>=(ab+EPS))
    {
        ret=ret1;
    }
    else
    {
        ret=ret2;
    }

    if(ab<0.5)
    {
        ret=0;
    }

    return (int)ret;
}

int main()
{
    freopen("Text/Closest Number.txt","r",stdin);

    int cases,a,b,x;

    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d %d %d",&a,&b,&x);
        //printf("%d\t%d\t%d\n",a,b,x);
        printf("%d\n",solve(a,b,x));
    }

    return 0;
}

