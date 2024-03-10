#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2, 13, 29, 3, 23, 21, 4};
    int max = 0;
    for (int i = 0; i < 7; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << "The max element of the array is : " << max << endl;
    return 0;
}