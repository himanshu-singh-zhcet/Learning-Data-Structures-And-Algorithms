#include <iostream>
#include <vector>
using namespace std;
int finding_peak(vector<int> &v)
{
    int n = v.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid == 0)
        {
            if (v[mid] > v[mid + 1])
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else if (mid == n - 1)
        {
            if (v[mid] >= v[mid - 1])
            {
                return mid;
            }
            else
            {
                return mid - 1;
            }
        }
        else
        {
            if (v[mid] >= v[mid + 1] and v[mid] >= v[mid - 1])
            {
                return mid;
            }
            else if (v[mid] >=v[mid - 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main(){
    vector<int> v={1,2,1,2,6,10,3};
    cout<<finding_peak(v);
    return 0;
}