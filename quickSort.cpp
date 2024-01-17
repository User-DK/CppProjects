#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector <int> &arr,int low ,int high){
    int pivot=low;
    int i=low;
    int j=high;
    while(i<=j){
        while(arr[i]<=arr[pivot]){
            i++;
        }
        while(arr[j]>arr[pivot]){
            j--;
        }
        if(i<=j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j],arr[pivot]);
    quickSort(arr,j+1,high);
}

int main(){

}