#include <iostream>
#include "sort.h"

using namespace std;

int main() {
   int choice;
   int unsorted[] = {90, 0, 3, 2, -1, -80, 200, -300};
   int size = sizeof(unsorted) / sizeof(int);
   int* sorted;

   do {
    cout << "Enter a sorting choice from menu" << endl;
    cout << " 1: Bubble sort" << endl;
    cout << " 2: Selection sort" << endl;
    cout << " 3: Merge sort" << endl;
    cout << " 4: Enter (-1) to quit" << endl;
    cin >> choice;

    switch(choice) {
      case 1:
        bubblesort(unsorted, size);
      break;
      case 2:
        selectionsort(unsorted, size);
      break;
      case 3:
        sorted = mergesort(unsorted, size);
        printArray(sorted, size);
      break;
      default:
      break;
    }
   }while(choice != -1);

}