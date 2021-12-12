/// Ahmed Nasser Mohamed
/// 13/07/2020

/*
--Problem description : sort a given sequence of N elements.
--Solution :  1- Iterate over the N elements
              2- for each iteration, find (select) the min/max element so far
--Time complexity : O(N^2)
*/

#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>&arr){
  for(int i=0; i<arr.size(); i++)
    for(int j=i+1; j<arr.size(); j++)
      if(arr[i]>arr[j])
        swap(arr[i],arr[j]);
}

int main(){
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int& x : arr) cin>>x;
  selectionSort(arr);
  for(int x : arr) cout<<x<<' ';
  cout<<'\n';
  return 0;
}
