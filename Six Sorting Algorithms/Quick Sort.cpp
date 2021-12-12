/// Ahmed Nasser Mohamed
/// 13/07/2020

/*
--Problem description : sort a given sequence of N elements.
--Solution :  1- recursively, choose an element as a pivot 
              2- insert the pivot in its right position
              3- repeat the same two steps for the right and the left partitions for the pivot
--Time complexity : O(N*log(N))
*/

#include<bits/stdc++.h>
using namespace std;

/*
int random(int mn, int mx){
   static bool first=true;
   if(first){
      srand(time(NULL));
      first=false;
   }
   return mn+rand()%((mx+1)-mn);
}
*/
 
pair<int,int>partition(int l, int r, vector<int>& arr){
  int m1=l-1, m2=l;
  for(int i=l+1; i<=r; i++){
    if(arr[i]<arr[m2]){
      swap(arr[++m1],arr[i]);
      swap(arr[++m2],arr[i]);
    }
    else if(arr[i]==arr[m2])
      swap(arr[++m2],arr[i]);
  }
  return {m1+1,m2};
}
 
void quickSort(int l, int r, vector<int>& arr){
  if(l>=r) return;
 
  /*
  // Randomized Pivot
  int randomI=random(l,r);
  swap(arr[randomI],arr[l]);
  */
 
  /*
  // Median Pivot
  int md=(l+r)/2;
  if((arr[r]>=arr[md] && arr[r]<=arr[l]) || (arr[r]>=arr[l] && arr[r]<=arr[md]))
    swap(arr[r],arr[l]);
  else if((arr[md]>=arr[l] && arr[md]<=arr[r]) || (arr[md]>=arr[r] && arr[md]<=arr[l]))
    swap(arr[md],arr[l]);
  */
 
  // First Pivot
  pair<int,int>m1m2=partition(l,r,arr);
  quickSort(l,m1m2.first-1,arr);
  quickSort(m1m2.second+1,r,arr);
}
 
 
int main(){
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int &x : arr) cin>>x;
  quickSort(0,n-1,arr);
  for(int x : arr) cout<<x<<' ';
  cout<<'\n';
  return 0;
}
