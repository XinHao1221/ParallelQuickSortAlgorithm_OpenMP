///*  Author: Koh Xin Hao
//*   Platform: OpenMP
//*   Method 3: Proposed parallel quicksort algorithm
//*   Thread: 1
//*/
//
//#include<stdio.h>
//#include <omp.h>
//#include <math.h>
//#include <list>
// 
//// int splitter1, splitter2, splitter3
//int splitter1, splitter2, splitter3;
// 
//// Define array size
//#define SIZE 500
//
//int indexPartition1 = 0, indexPartition2 = 0, indexPartition3 = 0, indexPartition4 = 0;
//
//// A utility function to swap two elements
//void swap(int* a, int* b)
//{
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//
//}
//
///* Partition the array into two section
//    The last element of the array will be chosen as pivot value
//    */
//int partition(int arr[], int low, int high)
//{
//    int pivot = arr[high];    // pivot
//    int i = (low - 1);  // Index of smaller element
//
//    for (int j = low; j <= high - 1; j++)
//    {
//        // If current element is smaller than or
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
//
//void quickSort(int arr[], int low, int high)
//{
//    if (low < high)
//    {
//        // Get the partition value
//        int pi = partition(arr, low, high);
//
//        // Perform quicksort for two partition
//        quickSort(arr, low, pi - 1);
//        quickSort(arr, pi + 1, high);
//    }
//}
//
//// Print arrray
//void printArray(int arr[], int size)
//{
//    int i;
//    for (i = 0; i < size; i++)
//        printf("%d ", arr[i]);
//    printf("\n");
//}
//
//void defineSplitter(int arr[], int size, int splitter[]) {
//
//    int temp;
//
//    printf("Splitters: \n");
//
//    // Define splitter
//    // Use to chunk the array into four part
//#pragma omp parallel sections num_threads(1) private (temp)
//    {
//#pragma omp section
//        {
//            // Define splitter 1
//            temp = floor(size / 4);
//            splitter[0] = arr[temp];
//
//            // Define splitter 2
//            temp = floor(size / 2);
//            splitter[1] = arr[temp];
//
//            // Define splitter 3
//            temp = size * floor(3 / 4);
//            splitter[2] = arr[temp];
//        }
//    }
//
//    // Sort the three splitter
//    quickSort(splitter, 0, 2);
//
//    // Display partition value to the ueer
//    printf("Splitter 1: %d\n", splitter[0]);
//    printf("Splitter 2: %d\n", splitter[1]);
//    printf("Splitter 3: %d\n\n", splitter[2]);
//
//}
//
//// Combine three array partitions
//void combineArrayPartition(int arr[], int splitter[], int partition1[], int partition2[], int partition3[], int partition4[]) {
//
//    int i = 0;
//    int j = 0;
//
//    // Assign value in array partition 1 into main array
//    while (partition1[j] > 0) {
//        arr[i] = partition1[j];
//        i++;
//        j++;
//    }
//
//    j = 0;
//
//    // Assign value in array partition 2 into main array
//    while (partition2[j] > 0) {
//        int temp = partition2[j];
//        arr[i] = partition2[j];
//        i++;
//        j++;
//    }
//
//    j = 0;
//
//    // Assign value in array partition 3 into main array
//    while (partition3[j] > 0) {
//        arr[i] = partition3[j];
//        i++;
//        j++;
//    }
//
//    j = 0;
//
//    // Assign value in array partition 4 into main array
//    while (partition4[j] > 0) {
//        arr[i] = partition4[j];
//        i++;
//        j++;
//    }
//}
//
//// Split array to four different partition
//// Array is assigned to each partition base on three splitter
//void arrangeArray(int arr[], int size, int partition1[], int partition2[], int partition3[], int partition4[], int splitter[]) {
//
//    // Execute for loop in paralllel
//#pragma omp parallel for shared(indexPartition1, indexPartition2, indexPartition3, indexPartition4, partition1,partition2, partition3, partition4)
//    for (int i = 0; i < size; i++) {
//
//        if (arr[i] <= splitter[0]) {    // element < Spliiter1
//#pragma omp critical
//            {
//                partition1[indexPartition1] = arr[i];
//                indexPartition1++;
//            }
//        }
//        else if (arr[i] <= splitter[1]) {   // Splitter1 < element <= splitter2
//#pragma omp critical
//            {
//                partition2[indexPartition2] = arr[i];
//                indexPartition2++;
//            }
//        }
//        else if (arr[i] <= splitter[2]) {   // Splitter2 < element <= splitter3
//
//#pragma omp critical
//            {
//                partition3[indexPartition3] = arr[i];
//                indexPartition3++;
//            }
//        }
//        else {  // Splitter3 < element
//#pragma omp critical
//            {
//                partition4[indexPartition4] = arr[i];
//                indexPartition4++;
//            }
//
//        }
//    }
//
//    // Combine four partition into one main array before sorting
//    combineArrayPartition(arr, splitter, partition1, partition2, partition3, partition4);
//
//    // Print array partition
//    printf("\nArray Parition: \n");
//
//    printf("\nPartition 1: \n");
//    printArray(partition1, indexPartition1);
//    printf("\nPartition 2: \n");
//    printArray(partition2, indexPartition2);
//    printf("\nPartition 3: \n");
//    printArray(partition3, indexPartition3);
//    printf("\nPartition 4: \n");
//    printArray(partition4, indexPartition4);
//    printf("\n");
//}
//
//// Driver program to test above functions
//int main()
//{
//
//    // Use for parallel quicksort
//    int parallelArr[SIZE];
//    // Use for serial quicksort
//    int serialArr[SIZE];
//
//    printf("Method 3: Proposed parallel quicksort algorithm \n\n");
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
//    printf("Array before sorted: \n");
//    printArray(parallelArr, SIZE);
//
//    printf("\nArray Generated!\n\n");
//
//    printf("\n\n");
//
//    printf("-------------------------Executing Quick Sort-------------------------\n\n");
//
//    // Get array size
//    int n = sizeof(parallelArr) / sizeof(parallelArr[0]);
//
//    // Declare splittter and partition
//    int splitter[3];
//    int partition1[SIZE] = {}, partition2[SIZE] = {}, partition3[SIZE] = {}, partition4[SIZE] = {};
//
//    // Get execution start time
//    double start_time = omp_get_wtime();
//
//    // Set maximum number of thread
//    omp_set_num_threads(1);
//
//    // Get three splitter
//    defineSplitter(parallelArr, n, splitter);
//
//    /* Split array into four partition 
//    * combine four partition into one main array
//    */
//    arrangeArray(parallelArr, n, partition1, partition2, partition4, partition3, splitter);
//
//    // Execute quicksort for 4 array partition in 1 thread
//#pragma omp parallel sections num_threads(1)
//    {
//#pragma omp section
//        {
//            quickSort(parallelArr, 0, indexPartition1 - 1);
//
//            quickSort(parallelArr, indexPartition1, (indexPartition1 + indexPartition2 - 1));
//
//            quickSort(parallelArr, (indexPartition1 + indexPartition2), (indexPartition1 + indexPartition2 + indexPartition3 - 1));
//
//            quickSort(parallelArr, (indexPartition1 + indexPartition2 + indexPartition3), n - 1);
//        }
//    }
//
//    // Get execution end time
//    double end_time = omp_get_wtime();
//
//    printf("Exucution Completed!\n\n");
//
//    printf("-------------------------Result-------------------------\n\n");
//
//    // Print sorted array
//    printf("Sorted array: \n");
//    printArray(parallelArr, n);
//
//    // Print total execution time
//    printf("\nWork took %f seconds\n", end_time - start_time);
//
//    // Check if result is valid
//    printf("\n\n-------------------------Validate Result-------------------------\n\n");
//
//
//    quickSort(serialArr, 0, n - 1);
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