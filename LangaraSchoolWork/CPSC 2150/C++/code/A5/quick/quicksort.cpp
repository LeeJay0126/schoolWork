// sort the values A[low] up to and including A[high] using quicksort
// postcondition:
//    A[low] <= A[low+1] <= ... <= A[high-1] <= A[high]
void quickSort(int A[], int low, int high);

// partition is used for quicksort
// find a pivot and guarantee that all the elements 
// before the pivot are <= the pivot 
// and all the elements  after the pivot are >= the pivot
// explanation given in class 
// choose the first element as pivot like in the textbook by Liang, Listing 19.8
// postcondition:
//    the value returned is the index of the pivot
//    the pivot is stored at A[value returned]
int partition(int A[], int low, int high);

int partition(int A[], int low, int high) { 
   int pivot = A[low];
   while (low < high) {
      // gap is now at A[low]
      while (low < high && A[high] >= pivot) {
         high--;
      }
      A[low] = A[high];
      // gap is now at A[high]
      while (low < high && A[low] <= pivot) { 
         low++;
      }
      A[high] = A[low];
   }
   A[low] = pivot; 
   // return index of the pivot
   return low;
}
void quickSort(int A[], int low, int high) {
   if (low >= high) { 
      return;
   }
   if (low + 1 == high) {
      if (A[low] > A[high]) {
         int tmp = A[low];
         A[low] = A[high];
         A[high] = tmp;
      }
      return;
   }
   int pivotIndex = partition(A, low, high);
   quickSort(A, low, pivotIndex - 1);
   quickSort(A, pivotIndex + 1, high);
}

void quickSort(int A[], int n) {
   quickSort(A, 0, n-1);
}

// copyright 2023 Gladys Monagan
