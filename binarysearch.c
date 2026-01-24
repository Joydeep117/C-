#include<stdio.h>
int binarusearch(int arr[] , int n , int target)
{   
    int low = 0 , high = n - 1 ;
    while ( low <= high )
    {
        int mid = low - ( high - low ) / 2 ;
        if ( arr[mid] == target )
        {
            return mid ;
        }
        else if ( arr[mid] < target )
        {
            low = mid + 1 ;
        }
        else 
        {
            high = high - 1 ;
        }
    }
    return -1 ;
}
int main()
{
    int n , target ;
    printf ("Enter the number of array elements :");
    scanf ("%d",&n);
    int arr[n];
    printf ("The elements are :");
    for ( int i = 0 ; i < n ; i ++ )
    {
        scanf ("%d",&arr[i]);
    }
    printf("Enter the element you want to search :");
    scanf ("%d",&target);
    int result = binarusearch( arr , n , target );
    if (result != -1 )
    {
        printf(" %d Element found at index number : %d",target , result);
    }
    else 
    {
        printf(" %d Element found not found ",target);
    }
    return 0 ;
}