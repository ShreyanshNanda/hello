// Question 32: Given an array arr and a number k where k is smaller than size of array. Write a program for printing k largest elemnets in that given array

Source: https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/

//Approach 1: Naive approach using sorting 
int kthSmallest(int A[], int n, int K)
{
   sort(A,n)
   return A[K-1]
}
T.C: O(nlogn)
S.C: If you use merge sort, then O(n), else if you use heap sort, its O(1)

//Approach 2: Using Min Heap
int kthSmallest(int A[], int n, int K)
{
   build_minHeap(A, n)
   for( i = 0 to K-1 )
        extractMin(A)
   return A[0]
}
T.C: Building the min heap of n elements + Extracting min element K-1 times = O(n) + (K-1) * log(n) = O( n + Klogn)
S.C: O(1)

//Approach 3: Using Max Heap
int kthSmallest(int A[], int n, int K)
{
   build_maxHeap(A, K)
   for ( i = K to n-1 )
   {
      if ( A[i] < A[0] )
      {
         A[0] = A[i]   // Now A[i] the new root
         heapify(A, 0)
      }
   }
   return A[0]
}
T.C: Building max-heap of k elements + Inserting n-K elements to the heap = O(K) + O((n-K)logK) = O(K + (n-K)logK)
S.C: O(1)

//Approach 4: Approach similar to quick sort
T.C: O(n)
S.C: O(logn)

