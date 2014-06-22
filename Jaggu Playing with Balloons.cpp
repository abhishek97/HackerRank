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


#define gc getchar
//#define gc getchar_unlocked

inline int readPosInt()
{
    int ret=0;
    char c;
    c=gc();

    while(c<'0' || c>'9')
    {
        //scanf("%c",&c);
        c=gc();
    }

    while(c>='0' && c<='9')
    {
        ret=ret*10+(c-'0');
        c=gc();
    }

    return ret;
}

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

#define MAXN 1000000

i64 buckets[MAXN+1];

inline i64 read(int idx)
{

    i64 ret=0;

    while(idx>0)
    {

        ret+=buckets[idx];
        idx=idx-(idx&(-idx));
        //printf("RSS\n");
    }

    return ret;
}

inline i64 read(int x,int y)
{
    return (read(y)-read(x-1));
}

inline void up_pos(int idx,int val)
{
    while(idx<=MAXN)
    {
        buckets[idx]+=val;
        idx+=(idx&(-idx));
    }
}


inline void update(int pos,int M,int pluss)
{
    int backk,i,j,s,in;
    for(i=1;i<=50;++i)
    {
        backk=pos;

        //for(j=1;j<=1000;++j)
        //{
            up_pos(pos,M);
            //in=__builtin_popcount(pos);

            while(true)
            {
                s=pos+(pos&(-pos));
                //in = __builtin_popcount(s);
                pos=s;
                if(pos>MAXN)
                {
                    break;
                }
                up_pos(pos,M);
            }

            pos=pos-MAXN;
        //}




        //{
            up_pos(pos,999*M);
            //in=__builtin_popcount(pos);

            while(true)
            {
                s=pos+(pos&(-pos));
                //in = __builtin_popcount(s);
                pos=s;
                if(pos>MAXN)
                {
                    break;
                }
                up_pos(pos,999*M);
            }

            pos=pos-MAXN;
        //}





        pos=backk+pluss;

        if(pos>MAXN)
        {
            pos-=MAXN;
        }
    }
}

int main()
{
    freopen("Text/Jaggu Playing with Balloons.txt","r",stdin);
    int i,ti,j;
    int poss,mm,plusss,pos1,pos2,q;
    char c;
    MSET(buckets,0);

    //scanf("%d\n",&q);
    //cin>>q;
    q=readPosInt();

    //printf("%d\n",q);
    while(q--)
    {
        //scanf("%c",&c);
        cin>>c;
        //printf("%c\n",c);

        if(c=='U')
        {
            //scanf("%d %d %d\n",&poss,&mm,&plusss);
            //cin>>poss>>mm>>plusss;
            poss=readPosInt();
            mm=readPosInt();
            plusss=readPosInt();
            //printf("%d %d %d\n",poss,mm,plusss);
            update(poss,mm,plusss);
        }
        else
        {
            //printf("DD\n");
            //scanf("%d %d",&pos1,&pos2);
            //cin>>pos1>>pos2;
            pos1=readPosInt();
            pos2=readPosInt();
            //printf("%d %d\n",pos1,pos2);
            printf("%lld\n",read(pos1,pos2));
        }
    }

    //double dd=log2((long double)(MAXN));
    //printf("%lf\t%d\n",dd,1<<20);

    return 0;
}

