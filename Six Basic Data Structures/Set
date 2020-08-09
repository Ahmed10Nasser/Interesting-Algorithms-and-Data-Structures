/// Ahmed Nasser Mohamed
/// 5/08/2020

/*
--Description : store elements in a hash table
--Operations wiht Time complexity : Find O(1) - Remove O(1) - Add O(1)
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=10, M=1000, MOD=1e9+7, OO=0x3f3f3f3f;

int const maxVal=2e5;


class Set
{
    private:
        list<int>arr[M];
        int p,a,b;
        bool isPrime(ll n)
        {
            for(ll i=2; i*i<=n; i++)
                if(n%i==0)
                    return 0;
            return 1;
        }
        int random(int mn, int mx)
        {
           static bool first=true;
           if(first)
           {
              srand(time(NULL));
              first=false;
           }
           return mn+rand()%((mx+1)-mn);
        }
        int Hash(int x)
        {
            return ((a*x+b)%p)%M;
        }
    public:
        Set()
        {
            p=-1;
            for(int i=maxVal+1; p==-1; i++)
                if(isPrime(i))
                    p=i;
            a=random(1,p-1);
            b=random(0,p-1);
        }
        bool Find(int x)
        {
            int ind=Hash(x);
            for(list<int>::iterator it=arr[ind].begin(); it != arr[ind].end(); ++it)
                if(*it==x)
                    return 1;
            return 0;
        }
        void Remove(int x)
        {
            int ind=Hash(x);
            for(list<int>::iterator it=arr[ind].begin(); it != arr[ind].end(); ++it)
            {
                if(*it==x)
                {
                    arr[ind].erase(it);
                    return;
                }
            }
        }
        void Add(int x)
        {
            int ind=Hash(x);
            for(list<int>::iterator it=arr[ind].begin(); it != arr[ind].end(); ++it)
                if(*it==x)
                    return;
            arr[ind].push_back(x);
        }

};







int main()
{
//    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);

    return 0;
}
