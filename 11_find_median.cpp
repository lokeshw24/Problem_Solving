/* QuickSort Application : Find Median of the array(only odd number of elements) */

#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

int partition( int *arr, int start_index, int end_index ){
	vector<int> smaller;
	vector<int> greater;

	//The first element is the pivot element
	int i, pivot=arr[start_index];

	for(i=start_index+1 ; i<=end_index ; i++){
		if(arr[i]<pivot)
			smaller.push_back(arr[i]);
		else
			greater.push_back(arr[i]);

	}


	//Iterate over both the vectors and change our original array to insert 
	//the pivot at its position.
	int k=start_index;
	for(i=0 ; i<smaller.size() ; i++){
		arr[k++]=smaller[i];
	}

	int pivot_index=k;
	arr[k++]=pivot;

	for(i=0 ; i<greater.size() ; i++)
		arr[k++]=greater[i];

	return pivot_index;
}
//---------------------------------------------------------------------------------------
void quickSort( int *arr, int start_index, int end_index, int arr_size ){
	if( start_index==end_index || start_index>end_index )
		return ;

	int pivot_index=partition(arr, start_index, end_index);

	if( pivot_index == arr_size/2 ){
		cout << arr[pivot_index] << "\n";
		exit(0);
	}
	else if( pivot_index > arr_size/2 ){
		quickSort(arr, start_index, pivot_index-1, arr_size);
	}
	else{
		quickSort(arr, pivot_index+1, end_index, arr_size);
	}

}
//---------------------------------------------------------------------------------------
int main(){
	int size;
	cin >> size;

	int arr[size];
	int i;
	for(i=0 ; i<size ; i++ ){
		cin >> arr[i];
	}

	quickSort(arr, 0, size-1, size);

	//For some cases, the median may not be selected as pivot at all.
	//Hence we need to print it here.
	cout << arr[size/2] << "\n";
	return 0;
}
