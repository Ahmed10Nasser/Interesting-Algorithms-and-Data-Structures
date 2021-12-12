/// Ahmed Nasser Mohamed
/// 09/07/2020

/*
--Problem description : sort a given sequence of N elements.
--Solution :  1- Use divide and conquer technique
              2- divide a sequence into two small sequences
              3- merge the two small sequences in a sorted way
--Time complexity : O(N*log(N))
*/

#include<bits/stdc++.h>
using namespace std;
 
void merge(int l, int md, int r, vector<int>& arr){
  vector<int>L,R;
  for(int i=l; i<=md; i++) L.push_back(arr[i]);
  for(int i=md+1; i<=r; i++) R.push_back(arr[i]);
  L.push_back(INT_MAX);
  R.push_back(INT_MAX);
  int lp=0, rp=0;
  for(int i=l; i<=r; i++){
    if(L[lp]<=R[rp]) arr[i]=L[lp++];
    else arr[i]=R[rp++];
  }
}
 
void mergeSort(int l, int r, vector<int>& arr){
  if(l>=r) return;
  int md=(l+r)/2;
  mergeSort(l,md,arr);
  mergeSort(md+1,r,arr);
  merge(l,md,r,arr);
}
 
int main(){
int n;
cin>>n;
vector<int>arr(n);
for(int &x : arr) cin>>x;
mergeSort(0,n-1,arr);
for(int x : arr) cout<<x<<' ';
cout<<'\n';
  return 0;
}
