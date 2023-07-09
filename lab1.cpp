#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int c = 0;
int partition(int arr[], int p, int r){
	int key = arr[r];
	int i = p - 1;
	
	for(int j = p; j <= r; j++){
		if(arr[j] < key){
			c++;
			i++;
			swap(arr[i], arr[j]);		
		}
	}

	swap(arr[i+1], arr[r]);
	return i + 1;
}


int random_partition(int arr[], int p, int r){
	int i = p + rand() % (r - p + 1);
	swap(arr[i], arr[r]);
	return(partition(arr,p,r));
}



void random_quicksort(int arr[], int p, int r){
	if (p < r){
		int q = random_partition(arr, p, r);
		random_quicksort(arr, p , q - 1);
		random_quicksort(arr, q + 1, r);
	}
}

int main(){
	srand(time(0));
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	random_quicksort(arr, 0, n-1);
	for(int i = 0; i < n; i++){
		cout <<  arr[i] << " ";
	}
		cout << "comparisions" << c  << endl;
	
return 0;	
}