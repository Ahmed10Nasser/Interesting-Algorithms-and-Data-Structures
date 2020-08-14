/// Ahmed Nasser Mohamed
/// 09/08/2020

/*
--Description : AVL tree is a balanced binary search tree that can perform all operations in O(log(n))
--Operations : Insert - Search - Delete - Range
--Time complexity : O(log(n))
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=1e5+5, MOD=1e9+7, OO=0x3f3f3f3f;

struct node{
    int data,height;
    node *parent,*left,*right;
};


class AVL
{
    private:
        node *root;
        node* LeftDescendant(node* Node)
        {
            if(Node->left==NULL)
                return Node;
            return LeftDescendant(Node->left);
        }
        node* RightAncestor(node *Node)
        {
            if(Node->parent==NULL || Node->data < Node->parent->data)
                return Node->parent;
            return RightAncestor(Node->parent);
        }
        node* Find(int Data, node *Root)    /// If the node is found, the function returns the node itself
        {                                   /// else the function returns its future parent
            if(Root->data==Data)
                return Root;
            if(Root->data > Data && Root->left!=NULL)
                return Find(Data, Root->left);
            if(Root->data < Data && Root->right!=NULL)
                return Find(Data, Root->right);
            return Root;
        }
        node* Next(node *Node)      /// The function returns the first node greater than given node
        {                           /// The function may return NULL is the given node is the greatest one
            if(Node->right!=NULL)
                return LeftDescendant(Node->right);
            return RightAncestor(Node);
        }
        int Height(node *Node)
        {
            if(Node==NULL)
                return 0;
            if(Node->left==NULL && Node->right==NULL)
                return Node->height=1;
            return Node->height=1+max(Height(Node->left),Height(Node->right));
        }
        void RotateRight(node *X)
        {
            node *P=X->parent;
            node *Y=X->left;
            node *B=Y->right;
            Y->parent=P;
            if(P==NULL)
                root=Y;
            else if(P->left==X)
                P->left=Y;
            else
                P->right=Y;
            X->parent=Y;
            Y->right=X;
            if(B!=NULL)
                B->parent=X;
            X->left=B;
        }
        void RotateLeft(node *X)
        {
            node *P=X->parent;
            node *Y=X->right;
            node *B=Y->left;
            Y->parent=P;
            if(P==NULL)
                root=Y;
            else if(P->left==X)
                P->left=Y;
            else
                P->right=Y;
            X->parent=Y;
            Y->left=X;
            if(B!=NULL)
                B->parent=X;
            X->right=B;

        }
        void Rebalance(node *Node)
        {
            int ln,rn,lm,rm;
            node *P=Node->parent;
            ln=(Node->left==NULL)? 0 : Node->left->height;
            rn=(Node->right==NULL)? 0 : Node->right->height;
            if(ln>rn+1)
            {
                node *M=Node->left;
                lm=(M->left==NULL)? 0 : M->left->height;
                rm=(M->right==NULL)? 0 : M->right->height;
                if(rm>lm)
                    RotateLeft(M);
                RotateRight(Node);
                Height(root);
            }
            ln=(Node->left==NULL)? 0 : Node->left->height;
            rn=(Node->right==NULL)? 0 : Node->right->height;
            if(rn>ln+1)
            {
                node *M=Node->right;
                lm=(M->left==NULL)? 0 : M->left->height;
                rm=(M->right==NULL)? 0 : M->right->height;
                if(lm>rm)
                    RotateRight(M);
                RotateLeft(Node);
                Height(root);
            }
            if(P!=NULL)
                Rebalance(P);
        }

    public:
        AVL()
        {
            root=NULL;
        }
        node* GetRoot()
        {
            if(root==NULL)
                cout<<"\nEMPTY AVL TREE!\n";
            return root;
        }
        bool Search(int Data)
        {
            if(root==NULL)
                return 0;
            node *Node=Find(Data, root);
            if(Node->data==Data)
                return 1;
            return 0;
        }
        vector<int> Range(int x, int y)
        {
            vector<int> ret;
            if(root==NULL)
                return ret;
            node *Node=Find(x,root);
            while(Node!=NULL && Node->data <= y)
            {
                if(Node->data >= x)
                    ret.push_back(Node->data);
                Node=Next(Node);
            }
            return ret;
        }
        void Insert(int Data)
        {
            if(root==NULL)
            {
                node *newNode=new node;
                newNode->data=Data;
                newNode->parent=newNode->left=newNode->right=NULL;
                newNode->height=1;
                root=newNode;
                return;
            }
            node *P=Find(Data, root);
            if(P->data==Data)
                return;
            node *newNode=new node;
            newNode->data=Data;
            newNode->parent=P;
            newNode->left=newNode->right=NULL;
            if(P->data > Data)
                P->left=newNode;
            else
                P->right=newNode;
            Height(root);
            Rebalance(newNode);
        }
        void Delete(int Data)
        {
            if(root==NULL)
                return;
            node *Node=Find(Data, root);
            if(Node->data!=Data)
                return;
            node *P;
            if(Node->right==NULL)
            {
                P=Node->parent;
                node *L=Node->left;
                if(P==NULL)
                    root=L;
                else if(P->right==Node)
                    P->right=L;
                else
                    P->left=L;
                if(L!=NULL)
                    L->parent=P;
                delete Node;
            }
            else
            {
                node *X=Next(Node);
                Node->data=X->data;
                P=X->parent;
                node *R=X->right;
                if(P->right==X)
                    P->right=R;
                else
                    P->left=R;
                if(R!=NULL)
                    R->parent=P;
                delete X;
            }
            Height(root);
            if(P!=NULL)
                Rebalance(P);
        }
        void printAVL(node *Root, string indent, bool last)
        {
            if (Root!=NULL)
            {
                cout<<indent;
                if(last)
                {
                    cout<<"R----";
                    indent+="   ";
                }
                else
                {
                    cout<<"L----";
                    indent+="|  ";
                }
                cout<<Root->data<<endl;
                printAVL(Root->left, indent, 0);
                printAVL(Root->right, indent, 1);
          }
}

};



int main()
{
    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);

    return 0;
}
