#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(5);
    cout << "Enter the element in vector : " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }

    cout << "Enter the occurance element : ";
    int x, pos = -1;
    cin >> x;

    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (x == v[i])
        {
            pos = i;
            break;
        }
    }

    cout << pos << endl;
    return 0;
}