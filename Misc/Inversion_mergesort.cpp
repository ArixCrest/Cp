int merge(int arr[],int temp[], int l, int m , int r){
    int i = l;
    int j = m;
    int ind = l;
    int count = 0;
    while(i<m && j<=r){
        if(arr[i]<=arr[j]){
            temp[ind] = arr[i];
            ind++,i++;
        }else{
            temp[ind] = arr[j];
            count+=(m-i);
            ind++,j++;
        }
    }
    while(i<m){
        temp[ind] = arr[i];
        ind++,i++;
    }
    while(j<=r){
        temp[ind] = arr[j];
        ind++,j++;
    }
    for(int k = l;k<=r;k++){
        arr[k] = temp[k];
    }
    return count;
    
} 
// need to pass by reference so thats its modifiable the arr vector.
int inversions_arr(int arr[],int temp[],int l, int r){
    int inversions = 0;
    if(l<r){
        int mid = (l+r)/2;
        inversions += inversions_arr(arr,temp,l,mid);
        inversions += inversions_arr(arr,temp,mid+1,r);
        inversions += merge(arr,temp,l,mid+1,r);
    }
    return inversions;
}