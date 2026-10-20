#include<stdbool.h>
#include<array.c>
#include <time.h>
#include <stdlib.h>

bool is_sorted_increasing(int A[], int n){
    if (n <=1) {
        return true;
    }
    for(int i=0,i<n-1,i++){
        if( A[i+1]<A[i]){
            return false ;
        }
    return true;

    }


}
int linear_search(int A[],int n,int x){
    for (int i=0,i<n,i++){
        if (A[i]==x){
            return i;
        }
    return -1;

    }

}
int min(int a,int b){
    if (a<= b){
        return a;
    }
    return b;

}
int jump_search(int A[],int x){
    int m=(int)square(n);
    prev=0;
    while(A[min(m,n)-1]<x){
        prev=m;
        m=m+(int)square(n);
        if (prev=>n){
            return -1;
        }
    for(int i-=prev, i<=n,i++){
        if (A[i]==x){
            return x;
        }
    }
    }
return -1
}
int binary_search(int A[],int x){



    int low=0;
    int high=n-1;
    while (low<=high){

        mid=(int)(low+high)/2;
        if(A[mid]==x){
            return mid;
        }
        else if (A[mid]<x){
            low=mid+1;
        }
        else (A[mid]>x){
            high=mid-1;
        }
    }
    return -1;
}
void compare_performance_sorted_arrays() {
    int sizes[] = {1000, 5000, 10000, 50000};
    int num_sizes = 4;

    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];
        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        printf("Taille du tableau : %d\n", n);
        clock_t start, end;
        double cpu_time_used;
        start = clock();
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Temps d'exécution : %f secondes\n", cpu_time_used);

        free(arr);
    }
}
void swap_int(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int is_sorted_ascending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void copy_array(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap_int(&arr[min_idx], &arr[i]);
    }
}

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap_int(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap_int(&arr[i], &arr[j]);
        }
    }
    swap_int(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
void compare_performance() {
    int sizes[] = {1000, 5000, 10000, 50000};
    int num_sizes = 4;

    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];
        int *original = (int *)malloc(n * sizeof(int));
        int *copy = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            original[i] = rand() % 1000000;
        }

        printf("Taille : %d\n", n);
        clock_t start, end;

        copy_array(original, copy, n);
        start = clock();
        selection_sort(copy, n);
        end = clock();
        printf("Selection sort: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

        copy_array(original, copy, n);
        start = clock();
        insertion_sort(copy, n);
        end = clock();
        printf("Insertion sort: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

        copy_array(original, copy, n);
        start = clock();
        bubble_sort(copy, n);
        end = clock();
        printf("Bubble sort:    %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

        copy_array(original, copy, n);
        start = clock();
        merge_sort(copy, 0, n - 1);
        end = clock();
        printf("Merge sort:     %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

        copy_array(original, copy, n);
        start = clock();
        quick_sort(copy, 0, n - 1);
        end = clock();
        printf("Quick sort:     %f s\n\n", (double)(end - start) / CLOCKS_PER_SEC);

        free(original);
        free(copy);
    }
}

int main() {
    srand(time(NULL));
    compare_performance();
    return 0;
}
