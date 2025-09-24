/*
 * CSC-301
 * project1.hpp
 * Fall 2025
 *
 * Partner 1: Tim Yu
 * Partner 2: Medhashree Adhikari
 * Date: Friday, September 26, 2025
 */

#ifndef PROJECT1_HPP_
#define PROJECT1_HPP_

#include <iostream>
#include <vector>

void swap(std::vector<double> &arr, int a, int b);
void selectionSort(std::vector<double> &arrayToSort);
void insertionSort(std::vector<double> &arrayToSort);
void bubbleSort(std::vector<double> &arrayToSort);
void mergeSort(std::vector<double> &arrayToSort);
void quickSortHelper(std::vector<double> &arrayToSort, int i, int j);
void quickSort(std::vector<double> &arrayToSort);

#endif  // PROJECT1_HPP_
