#pragma once
#include <random>
#include <iostream>

const int SORT_SIZE = 50;

template <class T>
class Jqsort
{
public:
   Jqsort() {}
   ~Jqsort() {}
   void fillData(T lower, T upper);
   void randomPivot();
   void specifyPivot(const int pivot);
   void displayData();

private:
   T data[SORT_SIZE];
   void qSorter(const int pivot);
   int partition(const int pivot, const int low, const int high);
   void swap(const int low, const int high);
};


template <class T>
void Jqsort<T>::fillData(T lower, T upper)
{
   // Fill the data with random values
   std::uniform_real_distribution<T> uniRand(lower, upper);
   std::default_random_engine dre;
   for (int i = 0; i < SORT_SIZE; ++i)
   {
      data[i] = uniRand(dre);
   }
}


void Jqsort<int>::fillData(int lower, int upper)
{
   // Fill the data with ints
   for (int i = 0; i < SORT_SIZE; ++i)
   {
      data[i] = lower + (rand() % (upper - lower));
   }
}

template <class T>
void Jqsort<T>::displayData()
{
   // Print the data in current order
   std::cout << "Data: ";
   for (int i = 0; i < SORT_SIZE; ++i)
   {
      std::cout << data[i] << " ";
   }
   std::cout << std::endl;
}

template <class T>
void Jqsort<T>::randomPivot()
{
   // Pick a random number and use as pivot
   int pivot = rand() % SORT_SIZE;
   qSorter(pivot);
}

template <class T>
void Jqsort<T>::specifyPivot(const int pivot)
{
   // User specified the pivot, apply qsort
   qSorter(pivot);
}

template <class T>
void Jqsort<T>::qSorter(const int pivot)
{
   // Create a stack to use for iterative processing
   int stack[SORT_SIZE - 1];
   int top = -1;
   int iterations = 0;

   // Push the initial values to the stack
   stack[++top] = 0;
   stack[++top] = SORT_SIZE - 1;

   // Keep popping from the stack while it is not empty
   int low, high, newPivot;
   bool firstPass = true;
   while (top >= 0)
   {
      iterations++;
      // Pop the low and high off the stack
      high = stack[top--];
      low = stack[top--];

      // Pick a pivot based on first pass or not
      if (firstPass)
      {
         newPivot = pivot;
         firstPass = false;
      }
      else
      {
         newPivot = low + (rand() % (high - low));
      }

      // Parition the data using latest pivot, low, and high values
      newPivot = partition(newPivot, low, high);

      // If there are elements to the left, push to left side of stack
      if ((newPivot - 1) > low)
      {
         stack[++top] = low;
         stack[++top] = newPivot - 1;
      }

      // If there are elements to the right, push to the right side of stack
      if ((newPivot + 1) < high)
      {
         stack[++top] = newPivot + 1;
         stack[++top] = high;
      }
   }
   std::cout << "Iterations: " << iterations << std::endl << std::endl;
}

template <class T>
int Jqsort<T>::partition(const int pivot, const int low, const int high)
{
   // Store the pivot being used
   T tempData = data[pivot];
   int tempLow = (low - 1);

   // Loop over values to store the pivot in the correct location while placing
   // smaller elements to the left and larger to the right
   for (int i = low; i <= high; i++)
   {
      if (data[i] <= tempData)
      {
         tempLow++;
         swap(tempLow, i);
         displayData();
      }
   }
   // Move the pivot element to the middle between low and high elements
   if (pivot < tempLow)
   {
      // Swap with last low element to put pivot in correct spot
      swap(tempLow, pivot);
   }
   else if (pivot > tempLow)
   {
      // Swap the next element, so it becomes the smallest of the greater values
      swap((tempLow + 1), pivot);
      tempLow++;
   }
   displayData();
   // Return the location of the pivot
   return tempLow;
}

template <class T>
void Jqsort<T>::swap(const int left, const int right)
{
   // Swap the elements
   T temp = data[left];
   data[left] = data[right];
   data[right] = temp;
}