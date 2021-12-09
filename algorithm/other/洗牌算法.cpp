#include <iostream>
#include <ctime>

void Shuffle(int arr[], const int N)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < N; ++i)
    {
        int index = rand() % N;

        std::swap(arr[i], arr[index]);
    }
}

int main()
{
    const int N = 100;
    int arr[N] = {};

    for (int i = 0; i < N; ++i)
    {
        arr[i] = i;
    }

    Shuffle(arr, N);

    return 0;
}
