#include <stdio.h>
#include<stdlib.h>
#define N 100
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i)
{
    int left, right, largest;
    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heap_sort(int arr[], int n)
{
    int i;
    for (i = (n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
int main()
{
    int arr[N];
    int n, i,k,s;
    printf("Enter number of cookies: ");
    scanf("%d",&n);
    printf("Enter the sweetness you want: ");
    scanf("%d",&k);
    printf("Enter the sweetness of cookies one by one:\n");
    for (i = 0; i < n; i++)
        scanf("%d ", &arr[i]);
    printf("Sweetness of cookies:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    heap_sort(arr, n);
    printf("\nAfter performing Heap Sort:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    i=0;
  repeat:
  {
    if(arr[i]<k)
    {
      s=arr[0]+arr[1];
      arr[0]=s;
      for(i=1;i<n-1;i++)
         {arr[i]=arr[i+1];}
      printf("\nArray:\n");
      for(i=0;i<n-1;i++)
        { printf("%d ",arr[i]);}
      i++;
     }
    else
      exit(1);
   }
    for(i=0;i<n-1;i++){
      if(arr[i]<k)
       goto repeat;

     }
    return 0;
}
