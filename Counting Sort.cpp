// Original (works for negative elements also)
#include <bits/stdc++.h> 
vector<int> sort(int n, vector<int> &arr)
{
    if (n <= 0) {
        return arr;
    }

    int minElement = *min_element(arr.begin(), arr.end());
    int maxElement = *max_element(arr.begin(), arr.end());
    int range = maxElement - minElement + 1;

    vector<int> count(range, 0);
    vector<int> sortedArr(n, 0);

    for (int i = 0; i < n; ++i) {
        count[arr[i] - minElement]++;
    }

    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        sortedArr[count[arr[i] - minElement] - 1] = arr[i];
        count[arr[i] - minElement]--;
    }

    return sortedArr;
}
 
// map method - 10/11 internal test case satisfied

#include <bits/stdc++.h> 
vector<int> sort(int n, vector<int> &arr)
{
    vector<int> sorted;
    int max=*max_element(arr.begin(),arr.end());
    int min=*min_element(arr.begin(),arr.end());
    map<int,int> count;
    for(auto i:arr){
        count[i]++;
    }
    for(int i=min ;i<max+1;i++){
        while(count[i]>0){
            sorted.push_back(i);
            count[i]--;
        }
    }

    return sorted;
}

