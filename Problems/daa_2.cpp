#include<stdio.h>
void merge(int arr[],int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int L[n1],M[n2];
    for(int i=0;i<n1;i++)
    {
        L[i]=arr[p+i];
    }
    for(int j=0;j<n2;j++)
    {
        M[j]=arr[q+1+j];
    }
    int i,j=0;
    int k=1;
    while(i<n1 && j<n2)
    {
        if(L[i] <= M[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=M[j];
            j++;

        }
        k++;
    }
    while(i < n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        arr[k]=M[j];
        j++;
        k++;
    }
}
    void mergesort(int arr[],int l, int r)
    {
        if(l<r)
        {
            int m=(l+(r-1))/2;
            mergesort(arr, l, m);
            mergesort(arr, m+1, r);
            merge(arr , l, m, r);
        }

    }
    int printArray(int arr[],int size)
    {
        for(int i=0;i<size;i++)
        {
            printf("%d",arr[i]);
        }
        printf("\n");
        return 0;
    }
    int main()
    {
        int arr[]={1,3,2,4,0};
        int size=sizeof(arr) / sizeof(arr[0]);
        mergesort(arr, 0, size-1);
        printf("the sorted array \n");
        int merged=printArray(arr,size);
        printf("%d",merged);
        
    }


