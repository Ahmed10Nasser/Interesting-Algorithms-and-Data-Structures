/// Ahmed Nasser Mohamed
/// 16/07/2020

/*
--Description : store elements with pointer(s) for linkage
--Operations wiht Time complexity : pushFront O(1) - popFront O(1) - pushBack O(1) - 
                                    popBack O(n) single pointer or O(1) double pointer - 
                                    addAfter O(1) - addBefore O(n) single pointer or O(1) double pointer - 
                                    findNode O(n)
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=30+5, M=600+5, MOD=1e9+7, OO=0x3f3f3f3f;

struct node
{
    int data;
    node *next;
};


class linkedList
{
    private:
        node *head,*tail;
    public:
        linkedList()
        {
            head=tail=NULL;
        }
        void pushFront(int value)
        {
            node *newNode=new node;
            newNode->data=value;
            newNode->next=head;
            head=newNode;
            if(tail==NULL)
                tail=newNode;
        }
        int getFront()
        {
            return head->data;
        }
        void PopFront()
        {
            if(head==NULL)
                cout<<"EMPTY LIST!\n";
            else
            {
                head=head->next;
                if(head==NULL)
                    tail=NULL;
            }
        }
        void pushBack(int value)
        {
            node *newNode= new node;
            newNode->data=value;
            newNode->next=NULL;
            if(head==NULL)
                head=tail=newNode;
            else
            {
                tail->next=newNode;
                tail=newNode;
            }
        }
        int getBack()
        {
            return tail->data;
        }
        void popBack()
        {
            if(head==NULL)
                cout<<"EMPTY LIST!\n";
            else if(head==tail)
                head=tail=NULL;
            else
            {
                node *temp=head;
                while(temp->next->next!=NULL)
                    temp=temp->next;
                temp->next=NULL;
                tail=temp;
            }
        }
        void addAfter(node *Node, int value)
        {
            node *newNode= new node;
            newNode->data=value;
            newNode->next=Node->next;
            Node->next=newNode;
            if(Node==tail)
                tail=newNode;
        }
        void addBefore(node *Node, int value)
        {
            if(Node==head)
                pushFront(value);
            else
            {
                node *temp=head;
                while(temp->next!=Node)
                    temp=temp->next;
                addAfter(temp,value);
            }
        }
        node* findNode(int value)
        {
            node *temp=head;
            while(temp!=NULL)
            {
                if(temp->data==value)
                    return temp;
                temp=temp->next;
            }
            return NULL;
        }
        bool isEmpty()
        {
            return head==NULL;
        }
        void printList()
        {
            node *temp=head;
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<"\n";
        }

};



int main()
{
//    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);


    return 0;
}
