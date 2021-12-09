#include <iostream>

void Move(char x, char y)
{
    printf("%c --> %c\n", x, y);
}

void Hanoi(int N, char A, char B, char C)
{
    if (N == 1)
    {
        Move(A, C);
    }
    else
    {
        Hanoi(N - 1, A, C, B);
        Move(A, C);
        Hanoi(N - 1, B, A, C);
    }
}

int main()
{
    /**
     * => A --> C
     * => A --> B
     * => C --> B
     * => A --> C
     * => B --> A
     * => B --> C
     * => A --> C
     */
    Hanoi(3, 'A', 'B', 'C');

    return 0;
}
