/*
 * CSC-301
 * project1.cpp
 * Fall 2025
 *
 * Partner 1: Tim Yu
 * Partner 2: Medhashree Adhikari
 * Date: Friday, September 26, 2025
 */

#include "project1.hpp"

using namespace std;

/**
 * swap
 * Input: vector<double> (reference), int index a and b
 * Output: none
 * Side effect: Two elements in the array with the given indices are swapped.
 */
void swap(vector<double> &arr, int a, int b) {
    double temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp; 
}

/**
 * selectionSort
 * Input: vector<double> (reference)
 * Output: none
 * Side effect: The referenced array is sorted smallest to largest by
 * separating the array into a sorted and unsorted
 */
void selectionSort(vector<double> &arrayToSort) {
    // iterate through entire array
    for (int i = 0; i < arrayToSort.size(); i++) {
        int min_idx = i; 
        // iterate through unsorted array and find minimum value to add to
        // the end of the sorted part
        for (int j = i + 1; j < arrayToSort.size(); j++) {
            if (arrayToSort[j] < arrayToSort[min_idx]) {
                min_idx = j;
            }
        } // inner for loop - find minimum
        swap(arrayToSort, i, min_idx); // swap minimum to end of sorted part
    } // outer loop
}

/** 
 * insertionSort
 * Input: vector<double> (reference)
 * Output: none
 * Side effect: The referenced array is sorted smallest to largest by
 * inserting unsorted elements sequentially into a sorted part of the array.
 */
void insertionSort(vector<double> &arrayToSort) {
    // Insert each element from start to finish into sorted part
    for (int i = 0; i < arrayToSort.size(); i++) {
        // Bubble one element into correct position in sorted part
        for (int j = i; (j > 0) && (arrayToSort[j] < arrayToSort[j - 1]); j--) {
            swap(arrayToSort, j - 1, j);
        }
    }
}

/** 
 * bubbleSort
 * Input: vector<double> (reference)
 * Output: none
 * Side effect: The referenced array is sorted smallest to largest by 
 * sequentially comparing adjacent elements and swapping the largest element 
 * to the end of the array.
 */
void bubbleSort(vector<double> &arrayToSort) {
    // Move the larger elements to the end
    for (int i = arrayToSort.size(); i > 0; i--) {
        // Bubble larger elements to the end of unsorted (beginning of sorted)
        for (int j = 0; j < i - 1; j++) {
            if (arrayToSort[j] > arrayToSort[j+1]) {
                swap(arrayToSort, j, j + 1);
            }
        } // inner loop
    } // outer loop
}

/** 
 * mergeSort
 * Input: 
 * Output: 
 * The input array...
 */
void mergeSort(vector<double> &arrayToSort) {
    return;
}

/** 
 * quickSortHelper
 * Input: 
 * Output: 
 * The input array...
 * 
 * Note that i is inclusive (i.e., is the first element of subarray).
 * Note that j is not inclusive (i.e., off the end of the subarray).
 * 
 */
void quickSortHelper(vector<double> &arrayToSort, int i, int j) {
    return;
}

/** 
 * quickSort
 * Input: 
 * Output: 
 * The input array...
 */
void quickSort(vector<double> &arrayToSort) {
    quickSortHelper(arrayToSort, 0, arrayToSort.size());
    return;
}
