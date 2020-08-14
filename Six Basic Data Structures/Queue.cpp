/// Ahmed Nasser Mohamed
/// 16/07/2020

/*
--Description : store elements with FIFO method (First In First Out)
--Operations wiht Time complexity : enqueue O(1) - dequeue O(1)
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=5, M=600+5, MOD=1e9+7, OO=0x3f3f3f3f;

struct node
{
    int data;
    node *next;
};

class Queue
{
    private:
        node *head, *tail;
    public:
        Queue()
        {
            head=tail=NULL;
        }
        void enqueue(int value)
        {
            node *newNode=new node;
            newNode->data=value;
            if(head==NULL)
                head=tail=newNode;
            else
            {
                tail->next=newNode;
                tail=newNode;
            }
        }
        int Front()
        {
            return head->data;
        }
        void dequeue()
        {
            if(head==NULL)
                cout<<"EMPTY QUEUE!\n";
            else
            {
                head=head->next;
                if(head==NULL)
                    tail=NULL;
            }
        }
        bool isEmpty()
        {
            return head==NULL;
        }
};





class Queue2
{
    private:
        int arr[N],r,w;
    public:
        Queue2()
        {
            memset(arr, 0, sizeof arr);
            r=w=0;
        }
        void enqueue(int value)
        {
            if((w+1)%N==r)
                cout<<"NO SPACE!\n";
            else
            {
                arr[w++]=value;
                w%=N;
            }
        }
        int Front()
        {
            return arr[r];
        }
        void dequeue()
        {
            if(r==w)
                cout<<"EMPTY QUEUE!\n";
            else
            {
                arr[r++]=0;
                r%=N;
            }
        }
        bool isEmpty()
        {
            return r==w;
        }
};

int main()
{
//    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);

    return 0;
}
