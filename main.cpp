#include <iostream>
#include <vector>

using std::cin;
using std::cout;

long long MaxPairwiseProduct(const std::vector<int>& input)
{
    long long result = 0;
    int n = input.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            auto tmp = ((long long)input[i]) * input[j];
            if (tmp > result)
            {
                result = tmp;
            }
        }
    }
    return result;
}


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

    //long long result = MaxPairwiseProduct(input);
    long long result = MaxPairwiseProductFast(input);
    //long long result = MaxPairwiseProductFast(std::vector<int>(100000, 0 ));
    cout << "result: " << result << "\n";
    return 0;
}
