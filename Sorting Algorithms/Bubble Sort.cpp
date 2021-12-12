/// Ahmed Nasser Mohamed
/// 09/07/2020

/*
--Problem description : sort a given sequence of N elements.
--Solution :  1- Iterate over two nested loops
              2- swap two elements if they are not in order
--Time complexity : O(N^2)
*/

#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&arr){
  for(int i=0; i<arr.size(); i++)
    for(int j=0; j<arr.size()-1; j++)
      if(arr[j]>arr[j+1])
        swap(arr[j],arr[j+1]);
}

int main(){
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int& x : arr) cin>>x;
  bubbleSort(arr);
  for(int x : arr) cout<<x<<' ';
  cout<<'\n';
  return 0;
}
