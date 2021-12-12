/// Ahmed Nasser Mohamed
/// 12/12/2021

/*
--Problem description : sort a given sequence of N elements.
--Solution :  1- Get the frequency (number of occurrences) for each value
              2- For each value from min to max, insert that value as much as their frequency
--Time complexity  : O(N) where N is the number of elements
--Space complexity : O(D) where D is the domain of the elements (max value)
*/

#include<bits/stdc++.h>
using namespace std;

void countSort(vector<int>& arr){
  int shift=0;
  int mn=*min_element(arr.begin(), arr.end());
  if(mn<0) shift=-mn;
  for(int &x : arr) x+=shift;

  int mx=*max_element(arr.begin(), arr.end());
  vector<int>freq(mx+1,0);
  for(int x : arr) freq[x]++;

  int i=0;
  for(int val=0; val<=mx; val++)
    while(freq[val]--)
      arr[i++]=val-shift;
}

int main(){
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int &x : arr) cin>>x;
  countSort(arr);
  for(int x : arr) cout<<x<<' ';
  cout<<'\n';
  return 0;
}

