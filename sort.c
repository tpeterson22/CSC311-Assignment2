#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void merge(int[], int, int ,int);

//This function will create an array of random integers
// of a specified length. The integers in this list will be in the range
// of [-length->length]
void fill_random(int array[], int length){

	for(int i=0; i<length; i++){
		array[i] = (rand() % length) + 1;
	}
	
}


void mergeSort(int nums[], int low, int high){
	if(low<high){
		int mid = (low+high)/2;
		mergeSort(nums, low, mid);
		mergeSort(nums, mid+1, high);
		merge(nums, low, mid, high);
	}
}


void merge(int nums[], int low, int mid, int high){
	//1. create two arrays
	int left_len = (mid-low)+1;
	int right_len = high-mid;
	int left[left_len];
	int right[right_len];
	
	//2. copy elements from original array into new arrays
	for(int index=0; index<left_len; index++){
		left[index] = nums[low+index];
	}
	
	
	int right_start = mid+1;
	for(int index=0; index<right_len; index++){
		right[index] = nums[right_start+index];
	}
	
	//3. start the merge process
	int left_index= 0;
	int right_index= 0;
	int num_index= low;
	
	while(left_index<left_len && right_index<right_len){
		if( left[left_index] < right[right_index] ){
			nums[num_index] = left[left_index];
			left_index++;
		}
		else{
			nums[num_index] = right[right_index];
			right_index++;
		}
		num_index++;
	}//end of while
	
	while(left_index < left_len){
		nums[num_index] = left[left_index];
		num_index++;
		left_index++;
	}
	
	while(right_index<right_len){
		nums[num_index] = right[right_index];
		num_index++;
		right_index++;
	}
	
}


int main(int argc, char *argv[]){

	if(argc == 2){
		//establish random seed
		srand (time(NULL));
		
		//converts the string argument to an integer
		int arrayLen = strtol(argv[1], NULL, 10);
		
		//creates an array and fills it with random numbers
		int array1[arrayLen];
		fill_random(array1, arrayLen);
		
		//Initializes a clock, starts it, sorts the array, then
		//stops the clock, and type casts it to double.
		clock_t t;
		t = clock();
		mergeSort(array1, 0, arrayLen);
		t = clock() - t;
		double time_taken = ((double)t)/CLOCKS_PER_SEC;	
		
		printf("%d : %f\n", arrayLen, time_taken);
	
	
	} else if(argc != 2){
		//if two arguments are not given, do not run the program.
		// [file name and array length]
		printf("Enter the proper amount of arguments.");
	}
			
	return 0;
}
















