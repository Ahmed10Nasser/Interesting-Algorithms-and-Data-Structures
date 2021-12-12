/// Ahmed Nasser Mohamed
/// 12/12/2021

/*
--Problem description : sort a given sequence of N elements.
--Solution :  1- Iterate over the digits from first digit to last digit
              2- For each digit, sort the numbers using count sort
--Time complexity : O(N*D) where N is the number of element, and D is the maximum digit
*/

#include<bits/stdc++.h>
using namespace std;

void countSort(vector<int>&arr, int place){
  vector<int> freq[10];
  for(auto val : arr){
    int digit=(val/place) %10;
    freq[digit].push_back(val);
  }
  int i=0;
  for(auto dv : freq)
    for(auto val : dv)
      arr[i++]=val;
}

void radixSort(vector<int>& arr){
  int mx=*max_element(arr.begin(), arr.end());
  for(int place=1; mx/place>0; place*=10)
    countSort(arr,place);
}

int main(){
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int &x : arr) cin>>x;
  radixSort(arr);
  for(int x : arr) cout<<x<<' ';
  cout<<'\n';
  return 0;
}
