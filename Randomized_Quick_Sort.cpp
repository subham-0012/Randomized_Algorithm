#include <cstdlib> 
#include <iostream>
#include<ctime>
using namespace std; 
int partition(int arr[], int low, int high) 
{ 
    int pivot = arr[low]; 
    int i = low - 1, j = high + 1; 
    while (true)
    {
        do
        { 
            i++; 
        } while (arr[i] < pivot); 
        do
        { 
            j--; 
        } while (arr[j] > pivot); 
        if (i >= j) 
            return j; 
        swap(arr[i], arr[j]); 
    } 
} 
int partition_r(int arr[], int low, int high) 
{ 
    srand(time(NULL)); 
    int random = low + rand() % (high - low); 
    // Swap A[random] with A[high] 
    swap(arr[random], arr[low]); 
    return partition(arr, low, high); 
}
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high)
    {
        int pi = partition_r(arr, low, high); 
        quickSort(arr, low, pi); 
        quickSort(arr, pi + 1, high); 
    } 
}
void printArray(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf(" "); 
}
int main() 
{ 
    int arr[] = { 10, 7, 8, 9, 1, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    quickSort(arr, 0, n - 1); 
    printf("Sorted array: "); 
    printArray(arr, n); 
    return 0; 
}