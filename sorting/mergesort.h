#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <iomanip>

using namespace std;

void merge(int number[], int left, int mid, int right);
void printArray(int numbers[], int left, int right);

void mergesort(int numbers[], int left, int right) {
  if(left < right) {
    int m = left + (right - left) / 2;
    printArray(numbers, left, right);
    mergesort(numbers, 0, m);
    mergesort(numbers, m+1, right);

    merge(numbers, left, m, right);
  }
}

void merge(int numbers[], int left, int mid, int right) {
  
}

void printArray(int numbers[], int left, int right) {
  for(int j = left; j <= right; j++) {
    cout << numbers[j] << "\t";
  }
  cout << endl;
}

#endif