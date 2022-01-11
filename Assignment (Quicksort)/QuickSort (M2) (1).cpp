///*  Author: Koh Xin Hao
//*   Platform: OpenMP
//*   Method 2: Lauch Thread in Recursive Function
//*   Thread: 1
//*/
//
//#include<stdio.h>
//#include <omp.h>
//#include <list>
//
//// define array size
//#define SIZE 500
//
//// swap value within two elements in a array
//void swap(int* a, int* b)
//{
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
///* partition the array into two section
//    the last element of the array will be chosen as pivot value
//    */
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
//// Paralllel quicksort with 1 thread
//void quickSort(int arr[], int low, int high)
//{
//    if (low < high)
//    {
//        // get the partition value
//        int pi = partition(arr, low, high);
//
//        // execute quicksort in one thread
//#pragma omp parallel sections num_threads(1)
//        {
//#pragma omp section  
//            {
//                quickSort(arr, low, pi - 1); 
//
//                quickSort(arr, pi + 1, high);
//            }
//        } 
//    }
//}
//
//// Serial quicksort
//void serialQuickSort(int arr[], int low, int high) {
//
//    if (low < high)
//    {
//        // get the partition value
//        int pi = partition(arr, low, high);
//
//        // execute quicksort in one thread
//        serialQuickSort(arr, low, pi - 1);
//        serialQuickSort(arr, pi + 1, high);
//    }
//}
//
//// print array
//void printArray(int arr[], int size)
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
//
//    // Use for parallel quicksort
//    int parallelArr[SIZE];
//    // Use for serial quicksort
//    int serialArr[SIZE];
//
//    printf("Method 2: Launch thread in recursive function \n\n");
//
//    printf("Quicksort with 1 threads\n\n");
//
//    printf("-------------------------Generate array-------------------------");
//    printf("\nArray Size: %d\n\n", SIZE);
//
//    // Assign value into array
//    for (int i = 0; i < SIZE; i++) {
//
//        parallelArr[i] = (rand() % 1000) + 1;
//        serialArr[i] = parallelArr[i];
//    }
//
//    // Print array before sorted
//    printf("Array Before Sorted:\n");
//    printArray(parallelArr, SIZE);
//
//    printf("\nArray Generated!\n\n");
//
//    printf("-------------------------Executing Quick Sort-------------------------\n\n");
//
//    // get array size
//    int n = sizeof(parallelArr) / sizeof(parallelArr[0]);
//
//    // get execution start time
//    double start_time = omp_get_wtime();
//
//    // set maximum number of thread
//    omp_set_num_threads(1);
//
//    // Execute quicksort parallely in 1 thread
//    quickSort(parallelArr, 0, n - 1);
//
//    // get execution end time
//    double end_time = omp_get_wtime();
//
//    printf("Exucution completed!\n\n");
//
//    printf("-------------------------Result-------------------------\n\n");
//    // print stored array
//    printf("sorted array: \n");
//    printArray(parallelArr, n);
//
//    // print total execution time
//    printf("\nwork took %f seconds\n\n", end_time - start_time);
//
//    // Check if result is valid
//    printf("\n\n-------------------------Validate Result-------------------------\n\n");
//
//    serialQuickSort(serialArr, 0, n - 1);
//
//    /* Compare result of parallel and serial sorting*/
//    int valid = 1;
//    for (int i = 0; i < SIZE; i++) {
//
//        if (serialArr[i] != parallelArr[i]) {
//
//            printf("Unmatch element in element %d  value: %d\n", i, serialArr[i]);
//            valid = 0;
//
//        }
//    }
//
//    if (valid == 1) {   // Execute when result is valid
//        printf("Good! Result are valid.");
//    }
//    else {              // Execute when result is invalid
//        printf("Result invalid!!!");
//    }
//
//    printf("\n\n\n\n\n");
//
//    return 0;
//}