#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <iomanip>
#include "sort.h"

using namespace std;

void printArray(int list[], int length);
int* merge(int listA[], int listB[], int left, int right);

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

void insertionsort (int list[], int length) {
  for(int i = 1; i < length; i++) {
    int j = i - 1;
    int insertItem = list[i];

    while(j >= 0 && list[j] > insertItem) {
      list[j + 1] = list[j];
      list[j]     = insertItem;
      j = j - 1;
    }
    printArray(list, length);
  }
}

int* mergesort(int list[], int length) {
  if(length < 2)
    return list;
  
  int i = 0;
  int j = 0;
  int half = length / 2;
  int otherHalf = length - half;

  int lstA[half];
  int lstB[otherHalf];

  while(i < half) {
    lstA[i] = list[i];
    i += 1;
  } 

  while(i < length) {
    lstB[j] = list[i];
    i += 1;
    j += 1;
  }

  printArray(lstA, half);
  printArray(lstB, otherHalf);

  return merge(mergesort(lstA, half), mergesort(lstB, otherHalf), half, otherHalf);
}

void printArray(int list[], int length) {
  for(int i = 0; i < length; i++)
    cout << setw(5) << list[i];
  cout << endl;
}


int* merge(int listA[], int listB[], int lengthA, int lengthB) {
  int i = 0;
  int j = 0;
  int currentIndex = 0;

  int* result = new int[lengthA + lengthB];

  while(i < lengthA && j < lengthB) {
    if(listA[i] < listB[j]) {
      result[currentIndex++] = listA[i];
      i += 1;
    } else {
      result[currentIndex++] = listB[j];
      j += 1;
    }
  }

  while(i < lengthA) {
    result[currentIndex] = listA[i];
    i += 1;
    currentIndex += 1;
  }

  while(j < lengthB) {
    result[currentIndex] = listB[j];
    j += 1;
    currentIndex += 1;
  }

  printArray(result, lengthA + lengthB);

  return result;
}
#endif
