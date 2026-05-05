#include <bits/stdc++.h>
using namespace std;
int quicksort(vector<int> &arr, int start, int end){
    int pivot = arr[end];
    int i = start-1;
    for(int j = start; j <= end; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[end]);
    return i+1;
}
void partition(vector<int>& arr, int start, int end){
    if(start < end){
        int pivot = quicksort(arr, start, end);
        partition(arr, start, pivot-1);
        partition(arr, pivot+1, end);

    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int a;
    cin >> a;
    vector<int> arr(a);
    for(int i = 0; i < a; i++){
        cin >> arr[i];
    } 
    partition(arr, 0, a-1);
    for(auto x : arr) {
        cout << x << " ";
    }
    cout << endl;

}
