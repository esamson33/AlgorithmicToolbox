#include <iostream>
#include <vector>

using std::cin;
using std::cout;

long long MaxPairwiseProductFast(const std::vector<int>& input)
{
    int max_index1 = -1;
    for (int i = 0; i < input.size(); ++i)
    {
        if (max_index1 == -1 || input[i] > input[max_index1])
        {
            max_index1 = i;
        }
    }

    int max_index2 = -1;
    for (int j = 0; j < input.size(); ++j)
    {
        if ((max_index2 == -1 || input[j] > input[max_index2]) && (input[j] != input[max_index1]))
        {
            max_index2 = j;
        }
    }

    return ((long long) (input[max_index1])) * input[max_index2];
}

int main() {
    int len;
    cin >> len;
    if (len < 2)
        return 1;

    std::vector<int> input(len);
    for (int n=0; n < len; ++n)
    {
        cin >> input[n];
    }

    long long result = MaxPairwiseProductFast(input);
    cout << "result: " << result << "\n";
    return 0;
}
