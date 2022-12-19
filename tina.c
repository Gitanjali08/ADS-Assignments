#include <stdio.h>
#define N 100

int k,arr[N],i,j,temp,n,sum;

void sort(int [],int n);
void dis(int [],int n);
void mitha();

int main() {
    printf("Input k : ");
    scanf("%d",&k);
    printf("Enter the number of cookies : ");
    scanf("%d",&n);
    printf("Enter the sweetness of cookies : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    repeat:
    sort(arr,n);
    dis(arr,n);
    mitha();
    for(i=1;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    dis(arr,(n-1));
    for(i=0;i<(n-1);i++)
    {
        if(arr[i]<=k)
        {
         n=n-1;
         goto repeat;
        }
        else
        {
        n=n-1;
        printf("Final sweetness of all cookies : ");
        dis(arr,n);
        }
    }
    return 0;
}

void sort(int arr[],int n)
{
 for(i=0;i<n;i++)
 {
  for(j=i+1;j<n;j++)
  {
  if(arr[i]>arr[j])
  {
   temp=arr[i];
   arr[i]=arr[j];
   arr[j]=temp;
  }
  }
 }
}

void dis(int arr[],int n)
{
 for(i=0;i<n;i++)
    {
        printf(" %d",arr[i]);
    }
 printf("\n");
}

void mitha()
{
  sum=arr[0]+arr[1];
  arr[0]=sum;
}


