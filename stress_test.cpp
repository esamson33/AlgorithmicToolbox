#include <cstdlib>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

long long MaxPairwiseProduct(const std::vector<int>& numbers)
{
    long long result = 0;
    int n = numbers.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            long long tmp = ((long long)numbers[i]) * numbers[j];
            if (tmp > result)
            {
                result = tmp;
            }
        }
    }
    return result;
}


long long MaxPairwiseProductFast(const std::vector<int>& numbers)
{
    int max_index1 = -1;
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (max_index1 == -1 || numbers[i] > numbers[max_index1])
        {
            max_index1 = i;
        }
    }

    int max_index2 = -1;
    for (int j = 0; j < numbers.size(); ++j)
    {
        if ((j != max_index1) && ((max_index2 == -1) || numbers[j] > numbers[max_index2]))
        {
            max_index2 = j;
        }
    }

    return ((long long) (numbers[max_index1])) * numbers[max_index2];
}

int main() {
    /*
    while (true)
    {
        int n = rand() % 100 + 2;
        cout << n << "\n";
        vector<int> a;
        for (int i = 0; i < n; ++i)
        {
            a.push_back(rand() % 100000);
        }
        for (int i = 0; i < n; ++i)
        {
            cout << a[i] << ' ';
        }
        cout << "\n";
        long long res1 = MaxPairwiseProduct(a);
        long long res2 = MaxPairwiseProductFast(a);
        if (res1 != res2)
        {
            cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
            break;
        }
        else
        {
            cout << "OK\n";
        }
    }*/

    int len;
    cin >> len;
    if (len < 2)
        return 1;

    std::vector<int> numbers(len);
    for (int n=0; n < len; ++n)
    {
        cin >> numbers[n];
    }

    //long long result = MaxPairwiseProduct(numbers);
    long long result = MaxPairwiseProductFast(numbers);
    //long long result = MaxPairwiseProductFast(std::vector<int>(100000, 0 ));
    cout << result << "\n";
    return 0;
}
