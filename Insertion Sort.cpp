#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
    for(int i=0;i<n;i++){
        int j=i;
        while(arr[j]<arr[j-1]&&j>0){
            swap(arr[j],arr[j-1]);
            j--;
        }    
    } 
}
