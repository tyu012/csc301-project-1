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
 * Input: vector<double> (reference)
 * Output: none
 * Side effect: This function will recursively split and sort the array, then
 * merge it. It will result in the input array being sorted.
  */
void mergeSort(vector<double> &arrayToSort) {
    if (arrayToSort.size() <= 1) {
        return;
    }

    int mid_idx = arrayToSort.size()/2;

    vector<double> left(arrayToSort.begin(), arrayToSort.begin() + mid_idx);
    vector<double> right(arrayToSort.begin() + mid_idx, arrayToSort.end());

    // call mergeSort recursively
    mergeSort(left);
    mergeSort(right);

    // merge back
    int l = 0;
    int r = 0;
    int i = 0;

    // Both arrays have unmerged elements
    while (l < left.size() && r < right.size()) {
        if (left[l] < right[r]) {
            arrayToSort[i] = left[l];
            i++;
            l++;
        } else {
            arrayToSort[i] = right[r];
            i++;
            r++;
        }
    }

    // One array has unmerged elements
    while (l < left.size() || r < right.size()) {
        if (l < left.size() && r >= right.size()) {
            arrayToSort[i] = left[l];
            i++;
            l++;
        }
        if (r < right.size() && l >= left.size()) {
            arrayToSort[i] = right[l];
            i++;
            r++;
        }
    }


}

/** 
 * quickSortHelper
 * Input: A vector of doubles to sort, and the index range that is sorted
 * Output: none
 * The input array between indices i and j are sorted.
 * 
 * Note that i is inclusive (i.e., is the first element of subarray).
 * Note that j is not inclusive (i.e., off the end of the subarray).
 * 
 */
void quickSortHelper(vector<double> &arrayToSort, int i, int j) {
    // If the array has 1 element then it is sorted
    if (j - i <= 1) {
        return;
    } else {
        // Choose a pivot element value
        double p = arrayToSort[i + (j - i) / 2];

        // Partition the array based on the pivot
        int a = i;
        int b = j - 1;

        while (a < b) {
            // Move pointers inwards
            while (arrayToSort[a] < p) {
                a++;
            }
            while (arrayToSort[b] > p) {
                b--;
            }

            // Swap when both pointers stuck
            if (a <= b) {
                swap(arrayToSort, a, b);
                a++;
                b--;
            }
        }

        // Recursively perform quicksort on the partitioned sub-arrays
        quickSortHelper(arrayToSort, i, b + 1);
        quickSortHelper(arrayToSort, a, j);
    }
}

/** 
 * quickSort
 * Input: A vector of doubles to sort
 * Output: None
 * This function makes a call to quickSortHelper from 0 to the size of the array
 * which is the end. Thus it calls quickSortHelper on the entire array.
 */
void quickSort(vector<double> &arrayToSort) {
    quickSortHelper(arrayToSort, 0, arrayToSort.size());
    return;
}
