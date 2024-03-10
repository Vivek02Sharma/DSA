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
    int x, count = 0;
    cin >> x;

    for (int i = 0; i < v.size(); i++)
    {
        if (x == v[i])
        {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}