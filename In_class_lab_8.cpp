#include <iostream>
using namespace std;
  
// function to Heapify the tree
void Heapify(int arr[], int n, int root)
{

 
    // Initialize largest 
    int larg = root;
 
    // left 
    int l = 2 * root + 1;
 
    // right 
    int r = 2 * root + 2;
 
    // When child is larger than root
    if (l < n && arr[l] > arr[larg])
        larg = l;
 
    // When right child is larger than largest
    if (r < n && arr[r] > arr[larg])
        larg = r;
 
    // when largest is not root
    if (larg != root) {
        swap(arr[root], arr[larg]);
 
        // Recursively Heapify the affected
        // sub-tree
        Heapify(arr, n, larg);
    }
}
  
  
// implementing heap sort
void HeapSort(int arr[], int n)
{

 
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);
 
    // One by one extract an element
    // from heap
    for (int i = n - 1; i > 0; i--) {
 
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max Heapify on the reduced heap
        Heapify(arr, i, 0);
    }
}
   
  
/* print contents of array */
void DisplayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main code
int main()
{   
    
    int length;
    cout<<"Enter the length of the array ";
    cin >> length;
    
    
   int heap_arr[length];
   for(int i = 0 ; i < length ; i++){
       cin >> heap_arr[i];
       
   }
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   DisplayArray(heap_arr,n);
  
   HeapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   DisplayArray(heap_arr,n);
}

