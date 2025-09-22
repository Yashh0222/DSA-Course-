#include <iostream>
using namespace std;
void spiralMatrix(int arr[3][3], int n, int m)
{
    int srow = 0, scol = 0;
    int erow = n - 1, ecol = m - 1;

    while (srow <= erow && scol <= ecol)
    {
        // top
        for (int j = scol; j <= ecol; j++)
        {
            cout << arr[srow][j] << " ";
        }

        // right
        for (int i = srow + 1; i <= erow; i++)
        {
            cout << arr[i][ecol] << " ";
        }

        // bottom
        for (int j = ecol - 1; j >= scol; j--)
        {
            if(srow == erow ){//prevents from printing twise
                break;
            }
            cout << arr[erow][j] << " ";
        }

        // top
        for (int i = erow - 1; i >= srow + 1; i--)
        {
            if(scol == ecol ){//prevents from printing twise
                break;
            }
            cout << arr[i][scol] << " ";
        }

        srow++; scol++;
        erow--;ecol--;
    }
    cout<<endl;
}
int main()
{
    int arr[3][3] = {{1, 2, 3}, 
                      {4, 5, 6}, 
                       {7, 8, 9}};

    spiralMatrix(arr,3,3);
    return 0;
}