/// Ahmed Nasser Mohamed
/// 09/07/2020

/*
--Problem description : sort a given sequence of N elements.
--Solution :  1- Iterate over the N elements
              2- for each itration, find the right postion to put (insert) the current element
--Time complexity : O(N^2)
*/

#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>&arr){
  for(int i=1; i<arr.size(); i++){
    int cur=arr[i];
    int j=i-1;
    while(j>=0 && arr[j]>cur){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=cur;
  }
}

int main(){
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int& x : arr) cin>>x;
  insertionSort(arr);
  for(int x : arr) cout<<x<<' ';
  cout<<'\n';
  return 0;
}
