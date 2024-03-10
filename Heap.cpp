#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int max=root;
   
   int left=2*root+1;
   int right=2*root+2;
   if(left <n && arr[root]<arr[left]){
       max=left;
   }
   if(right <n && arr[max]<arr[right]){
       max=right;
   }
   if(max!=root){
       int temp=arr[root];
       arr[root]=arr[max];
       arr[max]=temp;
       heapify(arr,n,max);
   }
   
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   int firstkey=(n/2)-1;
   for(int i=firstkey;i>=0;i--){
       heapify(arr,n,i);
       
   }
   for(int j=n-1;j>0;j--){
       
       int temp=arr[j];
       arr[j]=arr[0];
       arr[0]=temp;
       heapify(arr,j,0);
       
   }
   
  
   // extracting elements from heap one by one
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
    string input;
    getline(cin, input);

    stringstream ss(input);
    int num;
    vector<int> heap_arr;

    while (ss >> num) {
        heap_arr.push_back(num);
    }

    int n = heap_arr.size();
  
    heapSort(heap_arr.data(), n);
   
    displayArray(heap_arr.data(), n);
}