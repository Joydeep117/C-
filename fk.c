#include<stdio.h>
int main()
{   int n , i , j ,k;
    float sc , profit = 0 ;
    printf("Enter the number of items :");
    scanf("%d",&n);
    float arr[n][4] ;
    for ( i = 0 ; i < n ; i++ )
    {
        printf("Weight and profit of item no. %d :",i + 1 );
        scanf("%f %f",&arr[i][0] , &arr[i][1]);
    }
    printf("Enter the knapsack capacity :");
    scanf ("%f",&sc);
    for( i = 0 ; i <= n - 1 ; i++ )
    {
        for ( j = i + 1 ; j < n ; j++ )
        {
            if( arr[i][2] < arr[j][2] )
            {
                for ( k = 0 ; k < 3 ; k++ )
                {
                    float temp = arr[i][k];
                    arr[i][k] = arr[j][k];
                    arr[j][k] = temp ;
                }
            }
        }
    }
    for ( i = 0 ; i < n ; i++ )
    {
        if ( sc >= arr[i][0] )
        {
            sc -= arr[i][0];
            profit += arr[i][1];
        }
        else 
        {
            profit += sc*arr[i][2];
            break ;
        }
    }
    printf("Maximum profit = %f \n",profit);

    return 0;
}