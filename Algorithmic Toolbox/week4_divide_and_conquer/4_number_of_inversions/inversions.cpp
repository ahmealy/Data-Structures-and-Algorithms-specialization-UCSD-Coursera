#include <iostream>
#include <vector>

using std::vector;
long long get_merge_inversions(vector<int> & arr, vector<int> &temp, int left, int mid, int right) ;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right)
{
    long long number_of_inversions = 0;
    if (right <= left)
        return number_of_inversions;
    size_t ave = left + (right - left) / 2;
    number_of_inversions += get_number_of_inversions(a, b, left, ave);
    number_of_inversions += get_number_of_inversions(a, b, ave+1, right);
    number_of_inversions += get_merge_inversions(a, b, left, ave+1, right) ;

    return number_of_inversions;
}

long long get_merge_inversions(vector<int> & arr, vector<int> &temp, int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;

    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];

            /* if a[i] is greater than a[j], then there are (mid – i) inversions.
            because left and right subarrays are sorted,
            so all the remaining elements in left-subarray
            (a[i+1], a[i+2] … a[mid]) will be greater than a[j]*/
            inv_count = inv_count + (mid - i);
        }
    }

    /* Copy the remaining elements of left subarray (if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    /* Copy the remaining elements of right subarray (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];

    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cin >> a[i];
    }
    vector<int> b(a.size());
    std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}
