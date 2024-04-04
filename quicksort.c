#include <stdio.h>

void printArray(int* array, int n);
int partition(int array[], int start, int end);
int partitionDesc(int array[], int start, int end);
void swap(int *a, int *b);
void quickSort(int array[], int start, int end);
void quickSortDesc(int array[], int start, int end);
void sort(int array[], int n, int orderby);


int main(){
    int array[] = {10, 20, 3, 2, 1, 1, 3, 1, 30, 4, 5, 6, 6, 7};
    int array_n = sizeof(array) / sizeof(array[0]);

    //quickSort(array, 0, array_n - 1);
    
    sort(array, array_n, 1);
    printArray(array, array_n);

    sort(array, array_n, -1);
    printArray(array, array_n);

    return 0;
}


void printArray(int* array, int n){
    printf("[");
    for (int i=0; i<n; i++){
        printf("%d, ", array[i]);
    }
    printf("]");
}


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//sort ascending

int partition(int array[], int start, int end){
    int current_index = (start - 1);
    int pivot = array[end];

    for (int j = start; j < end; j++){
        if (array[j] <= pivot){
            current_index++;
            swap(&array[current_index], &array[j]);
        }
    }
    
    swap(&array[current_index + 1], &array[end]);
    
    return (current_index + 1);
}


void quickSort(int array[], int start, int end){
    if (end > start){
        int partition_index = partition(array, start, end);
        
        quickSort(array, start, partition_index - 1);
        quickSort(array, partition_index + 1, end);
    }
    
}

//sort descending

int partitionDesc(int array[], int start, int end){
    int current_index = (start - 1);
    int pivot = array[end];

    for (int j = start; j < end; j++){
        if (array[j] >= pivot){
            current_index++;
            swap(&array[current_index], &array[j]);
        }
    }
    
    swap(&array[current_index + 1], &array[end]);
    
    return (current_index + 1);
}


void quickSortDesc(int array[], int start, int end){
    if (end > start){
        int partition_index = partitionDesc(array, start, end);
        
        quickSortDesc(array, partition_index + 1, end);
        quickSortDesc(array, start, partition_index - 1);
    }
    
}

void sort(int array[], int n, int orderby){
    int start = 0;
    int end = n - 1;

    if (orderby == 1){
        quickSort(array, start, end);
    }
    else if (orderby == -1){
        quickSortDesc(array, start, end);
    }
}

