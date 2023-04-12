//merge sort
#include<stdio.h>
void merge(int a[],int i1,int j1,int i2,int j2)
{
    int temp[50];       //temporary array used
    int i,j,k;
    i=i1;               //beginning of the first list
    j=i2;               //beginning of the second list
    k=0;
    while(i<=j1 && j<=j2)       //while element in both lists
    {
        if(a[i]<a[j])
        {
            temp[k++]=a[i++];
        }
        else
            temp[k++]=a[j++];
    }
    while(i<=j1)                //copy remaining element of the first list
    {
        temp[k++]=a[i++];
    }
    while(j<=j2)                //copy remaining element of the second list
    {
        temp[k++]=a[j++];
    }
    //transfer element from temp[] back to a[]
    for(i=i1,j=0;i<=j2;i++,j++)
    {
        a[i]=temp[j];
    }
}
//perform merge operation
void mergesort(int a[],int i,int j)
{
    int mid;
    if(i<j)
    {
        mid=(i+j)/2;
        mergesort(a,i,mid);
        mergesort(a,mid+1,j);
        merge(a,i,mid,mid+1,j);
    }
}
int main()
{
    int a[30],n,i;
    printf("enter no of element:");
    scanf("%d",&n);
    printf("enter array element:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(a,0,n-1);
    printf("\nSorted array is :\n");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
    return 0;
}
