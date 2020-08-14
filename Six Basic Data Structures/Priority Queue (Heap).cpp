/// Ahmed Nasser Mohamed
/// 29/07/2020

/*
--Description : store elements in a complete binary tree (max/min heap)
--Operations wiht Time complexity : Push O(log(n)) - Pop O(log(n)) - remove O(log(n)) - change O(log(n))
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=5, M=17+5, MOD=1e9+7, OO=0x3f3f3f3f;

class priorityQueue
{
    private:
        int arr[N],sz;
        int parent(int i)
        {
            return i/2;
        }

        int leftChild(int i)
        {
            return i*2;
        }

        int rightChild(int i)
        {
            return i*2+1;
        }

        void siftUp(int i)
        {
            while(i>1 && arr[parent(i)]<arr[i])
            {
                swap(arr[parent(i)],arr[i]);
                i=parent(i);
            }
        }

        void siftDown(int i)
        {
            int mxi=i;
            int l=leftChild(i);
            if(l<=sz && arr[l]>arr[mxi])
                mxi=l;
            int r=rightChild(i);
            if(r<=sz && arr[r]>arr[mxi])
                mxi=r;
            if(mxi!=i)
            {
                swap(arr[i],arr[mxi]);
                siftDown(mxi);
            }
        }
    public:
        priorityQueue()
        {
            memset(arr, 0, sizeof arr);
            sz=0;
        }
        void push(int p)
        {
            if(sz==N-1)
                cout<<"NO SPACE!\n";
            else
            {
                arr[++sz]=p;
                siftUp(sz);
            }
        }
        void pop()
        {
            if(sz==0)
                cout<<"EMPTY PRIORITY QUEUE!\n";
            else
            {
                arr[1]=arr[sz--];
                siftDown(1);
            }
        }
        int top()
        {
            return arr[1];
        }
        bool isEmpty()
        {
            return sz==0;
        }
        int getSize()
        {
            return sz;
        }
        void Remove(int i)
        {
            arr[i]=OO;
            siftUp(i);
            pop();
        }
        void change(int i, int p)
        {
            int oldp=arr[i];
            arr[i]=p;
            if(p>oldp)
                siftUp(i);
            else
                siftDown(i);
        }
};



int main()
{
//    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);

    return 0;
}
