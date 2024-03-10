#include <iostream>
using namespace std;

int main()
{
    int a1[] = {1, 3, 6, 7, 13};
    int a2[] = {2, 4, 5, 10, 12, 14, 16};

    int a3[12];

    int i = 0, ub1 = 5;
    int j = 0, ub2 = 7;
    int k = 0;

    while (i <= ub1 && j <= ub2)
    {
        if (a1[i]<a2[j]){
            a3[k] = a1[i];
            i++;
            k++;
        }
        else{
            a3[k] = a2[j];
            j++;
            k++;
        }

    }

    while(i < ub1){
        a3[k] = a1[i];
        i++;
        k++;
    }

    while(j< ub2){
        a3[k] = a2[j];
        j++;
        k++;
    }

    for(int i : a3){
        cout<<i<<" ";
    }
    return 0;
}