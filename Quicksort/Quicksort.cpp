// Quicksort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Jqsort.h"

int main()
{
   // Automatic execution
   Jqsort<double> jd;
   jd.fillData(1.0, 30.0);
   jd.displayData();
   jd.randomPivot();

   // User selects an index as the initial pivot
   Jqsort<int> ji;
   ji.fillData(3, 1333);
   ji.displayData();
   int pivot = 0;
   std::cout << "Enter a pivot index: ";
   std::cin >> pivot;
   ji.specifyPivot(pivot);

   // User selects another index as the initial pivot
   ji.fillData(3, 1333);
   ji.displayData();
   std::cout << "Enter a pivot index: ";
   std::cin >> pivot;
   ji.specifyPivot(pivot);

   system("PAUSE");
   return 0;
}

