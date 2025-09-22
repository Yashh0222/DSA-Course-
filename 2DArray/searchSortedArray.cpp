#include <iostream>
using namespace std;
// Brute forse() time complexity 0(n*m)
// int search(int arr[][3],int n ,int m, int target){
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            if (arr[i][j] == target)
//            {
//                cout<<"("<<i<<","<<j<<")"<<endl;
//            }
//
//        }
//
//    }
//    return -1;
//}

// using binary search time copmplexity 0(logm *n)
/*
int search(int arr[][3], int n, int m, int target)
{
   int row = 0;
   int col = m-1;
    while (row < n && col >= 0)
    {
        if(arr[row][col] == target){
            cout<<"("<<row<<","<<col<<")"<<endl;
        }
        if(arr[row][col] > target){
            col--;
        }else{
            row++;
        }
    }
    return -1;
}*/

/*
//stare search matrix time complexity 0(logn *m)
int search(int arr[][3],int n, int m, int target){
    int row = 0;
    int col = m-1;

    while( row < n && col >= 0){
        if(arr[row][col] == target){
            cout<<"("<<row<<","<<col<<")"<<endl;
        }
        
        //start (0,m-1) and shift to (left) if target is less than present array
        if(arr[row][col] > target){
            col--;
        }else{
            // shift  (down) because elements will insecrese row so search in second row 
            row++; 
        }
    }
    return -1;
}*/

//Modified binary search on 2D array (by converting 2D array to 1D arrry) time comple 0(logN)
int search(int arr[][3], int n, int m, int target)
{
   int st = 0, end = n*m -1;//here we  start with 0 and end starts from last element (n*m -1)

   while (st < end)
   {
      int mid = st + (end - st)/2;
      int row = mid/m; // this gives us row num
      int col = mid%m; // this gives us col num

      if(arr[row][col] == target){
        cout<<"found at ("<<row<<","<<col<<")"<<endl;
      }
      
      if(arr[row][col] > target){
        end = mid - 1;
      }else{
        st = mid + 1;
      }
   }
   
}
int main()
{
    int arr[3][3] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}};

    search(arr, 3, 3, 5);
    return 0;
}