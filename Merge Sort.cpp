void merge(vector<int> &arr,int low,int mid,int high){
    vector<int> temp;
    int i=low;
    int j=mid+1;
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=high){
        temp.push_back(arr[j]);
        j++;
    }
    
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }

}
void divide(vector <int> &arr,int low,int high){
    if(low>=high){
        return;
    }
    int mid=low+(high-low)/2;
    divide(arr,low,mid);
    divide(arr,mid+1,high);
    merge(arr,low,mid,high);   
}
void mergeSort(vector < int > & arr, int n) {
    int low=0;
    int high=arr.size()-1;
    divide(arr,low,high);
}