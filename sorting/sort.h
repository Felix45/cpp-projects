#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <iomanip>
#include "sort.h"

using namespace std;

void bubblesort(int* numbers, int n) {
  int arr_length = n;
  cout << "Sorting with Bubble Sort:" << endl;
  cout << "===============================================" << endl;
  for(int i = 0; i < arr_length; i++) {
    for (int j = 0; j < arr_length - 1; j++) {
        if(numbers[j] > numbers[j+1]) {
          int temp = numbers[j];
          numbers[j] = numbers[j+1];
          numbers[j+1] = temp;
        }
    }
    cout << "Pass " << i+1 << ":" << "\t";
    for(int k = 0; k < arr_length; k++) {
      cout << setw(5) << numbers[k] << "\t";
    }
    cout << endl;
  }
  cout << "===============================================" << endl;
}

void selectionsort(int* numbers, int n) {
  const int ARR_LENGTH = n;
  
  cout << "Sorting with Selection Sort:" << endl;
  cout << "===============================================" << endl;

  for (int i = 0; i < ARR_LENGTH; i++) {
    int minIndex = i;

    for (int j = i + 1; j < ARR_LENGTH; j++) {
      if(numbers[j] < numbers[minIndex]) {
        minIndex = j;
      }
    }

    int temp = numbers[minIndex];
    numbers[minIndex] = numbers[i];
    numbers[i] = temp;

    cout << "Pass " << i+1 << ":" << "\t";
    for(int k = 0; k < ARR_LENGTH; k++) {
      cout << setw(5) << numbers[k] << "\t";
    }
    cout << endl;
  }
  cout << "===============================================" << endl;
}

#endif
