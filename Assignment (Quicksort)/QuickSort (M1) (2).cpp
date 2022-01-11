///*  Author: Koh Xin Hao
//*   Platform: OpenMP
//*   Method 1: Launch Thread in main program
//*   Thread: 2
//*/
//
//#include<stdio.h>
//#include <omp.h>
//#include <math.h>
//#include <list>
//
//#define SIZE 500
//
//// a utility function to swap two elements
//void swap(int* a, int* b)
//{
//    int t = *a;
//    *a = *b;
//    *b = t;
//}
//
///* this function takes last element as pivot, places
//   the pivot element at its correct position in sorted
//    array, and places all smaller (smaller than pivot)
//   to left of pivot and all greater elements to right
//   of pivot */
//int partition(int arr[], int low, int high)
//{
//    int pivot = arr[high];    // pivot
//    int i = (low - 1);  // index of smaller element
//
//    for (int j = low; j <= high - 1; j++)
//    {
//        // if current element is smaller than or
//        // equal to pivot
//        if (arr[j] <= pivot)
//        {
//            i++;    // increment index of smaller element
//            swap(&arr[i], &arr[j]);
//        }
//    }
//    swap(&arr[i + 1], &arr[high]);
//    return (i + 1);
//}
//
///* the main function that implements quicksort
// arr[] --> array to be sorted,
//  low  --> starting index,
//  high  --> ending index */
//void quicksort(int arr[], int low, int high)
//{
//    if (low < high)
//    {
//        /* pi is partitioning index, arr[p] is now
//           at right place */
//        int pi = partition(arr, low, high);
//
//        // separately sort elements before
//        // partition and after partition
//        quicksort(arr, low, pi - 1);
//        quicksort(arr, pi + 1, high);
//    }
//}
//
///* function to print an array */
//void printarray(int arr[], int size)
//{
//    int i;
//    for (i = 0; i < size; i++)
//        printf("%d ", arr[i]);
//    printf("\n");
//}
//
//// driver program to test above functions
//int main()
//{
//    // use for parallel quicksort
//    int parallelarr[SIZE];
//    // use for serial quicksort
//    int serialarr[SIZE];
//
//    printf("Method 1: Launch thread in main program \n\n");
//
//    printf("Quicksort with 2 threads\n\n");
//
//    printf("-------------------------Generate Array-------------------------");
//    printf("\narray size: %d\n\n", SIZE);
//
//    // assign value into array
//    for (int i = 0; i < SIZE; i++) {
//
//        parallelarr[i] = (rand() % 1000) + 1;
//        serialarr[i] = parallelarr[i];
//    }
//
//    // print array before sorted
//    printf("array before sorted:\n");
//    printarray(parallelarr, SIZE);
//
//    printf("\narray generated!\n\n");
//
//    printf("-------------------------Executing Quick Sort-------------------------\n\n");
//
//    // get array size
//    int n = sizeof(parallelarr) / sizeof(parallelarr[0]);
//
//    // get execution start time
//    double start_time = omp_get_wtime();
//
//    // set maximum number of thread
//	omp_set_num_threads(2);
// 
//    /* partitin array into two part
//        pi --> value that split array into two partition */
//    int pi = partition(parallelarr, 0, n - 1);
//
//    // sort two partition parallely 
//#pragma omp parallel sections
//    {
//#pragma omp section
//        {
//            quicksort(parallelarr, 0, pi - 1);
//        }
//
//#pragma omp section
//        {
//            quicksort(parallelarr, pi + 1, n - 1);
//        }
//    }
//
//    // get execution end time
//    double end_time = omp_get_wtime();
//
//    printf("exucution completed!\n\n");
//
//    printf("-------------------------Result-------------------------\n\n");
//    // print sorted array
//    printf("sorted array: \n");
//    printarray(parallelarr, n);
//
//    printf("\nwork took %f seconds\n", end_time - start_time);
//
//    // check if result is valid
//    printf("\n\n-------------------------Validate Result-------------------------\n\n");
//
//    quicksort(serialarr, 0, n - 1);
//
//    /* compare result of parallel and serial sorting*/
//    int valid = 1;
//    for (int i = 0; i < SIZE; i++) {
//
//        if (serialarr[i] != parallelarr[i]) {
//
//            printf("Unmatch element in element %d  value: %d\n", i, serialarr[i]);
//            valid = 0;
//
//        }
//    }
//
//    if (valid == 1) {   // execute when result is valid
//        printf("Good! result are valid.");
//    }
//    else {              // execute when result is invalid
//        printf("result invalid!!!");
//    }
//
//    printf("\n\n\n\n\n");
//
//    return 0;
//}