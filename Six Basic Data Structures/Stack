/// Ahmed Nasser Mohamed
/// 16/07/2020

/*
--Description : store elements with LIFO method (Last In First Out)
--Operations wiht Time complexity : Push O(1) - Pop O(1)
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


class Stack
{
    private:
        node *head;
    public:
        Stack()
        {
            head=NULL;
        }
        void push(int value)
        {
            node *newNode= new node;
            newNode->data=value;
            newNode->next=head;
            head=newNode;
        }
        int top()
        {
            return head->data;
        }
        bool isEmpy()
        {
            return head==NULL;
        }
        void pop()
        {
            if(head==NULL)
                cout<<"EMPTY STACK!\n";
            else
                head=head->next;
        }
};



class Stack2
{
    private:
        int arr[N],ls;
    public:
        Stack2()
        {
            memset(arr, 0, sizeof arr);
            ls=-1;
        }
        void push(int value)
        {
            if(ls<N-1)
                arr[++ls]=value;
            else
                cout<<"NO SPACE!\n";
        }
        int top()
        {
            return arr[ls];
        }
        void pop()
        {
            if(ls==-1)
                cout<<"EMPTY STACK!\n";
            else
                arr[ls--]=0;
        }
        bool isEmpty()
        {
            return ls==-1;
        }

};

int main()
{
//    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);

    return 0;
}
