/// Ahmed Nasser Mohamed
/// 29/07/2020

/*
--Problem description : sort a given sequence of N elements.
--Solution :  1- Convert the given sequence into max heap using sift-down technique
              2- iterating n times
              3- for each iteration, take the root of the heap (max element so far) and remove it from the heap
--Time complexity : O(N*log(N))
*/

#include<bits/stdc++.h>
using namespace std;

void siftDown(int i, int heapSz, vector<int>& arr){
    int mxi=i;
    int l=2*(i+1)-1;
    if(l<heapSz && arr[l]>arr[mxi]) mxi=l;
    int r=2*(i+1);
    if(r<heapSz && arr[r]>arr[mxi]) mxi=r;
    if(mxi!=i){
        swap(arr[i],arr[mxi]);
        siftDown(mxi,heapSz,arr);
    }
}

void heapSort(vector<int>& arr){
  // Buliding Heap
  int heapSz=arr.size();
  for(int i=arr.size()/2-1; i>=0; i--)
    siftDown(i,heapSz,arr);

  // Sort by poping the min each time
  for(int i=0; i<arr.size()-1; i++){
    swap(arr[--heapSz],arr[0]);
    siftDown(0,heapSz,arr);
  }
}

int main(){
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int &x : arr) cin>>x;
  heapSort(arr);
  for(int x : arr) cout<<x<<' ';
  cout<<'\n';
  return 0;
}
