/*
Asks the user to enter the size of the array

Takes array elements as input

Applies the Selection Sort algorithm to sort the array in ascending order

Does not print the sorted array at the end (you can add that if needed)
*/

#include<iostream>
using namespace std;
int main(){
        cout<<"Enter size of array";
    int size;
    cin>>size;

    int array [size];
    for(int ind=0;ind<size;ind++)
    {
        cout<<"Enter array element at index "<<ind;
        cin>>array[ind];
    }

    // selection sort logic
    for(int i = 0 ;i <size-1;i++){
        int min = i;
        for(int j = i+1;j<size;j++){
            if(array[min]>array[j]){
                min = j;
            }
        }
        if(i!=min){
            int temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
    }
    return 0;
}
