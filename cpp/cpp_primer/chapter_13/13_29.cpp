//因为swap（HasPtr&, HasPtr&)函数中，swap (lhs.ps, rhs.ps);调用了std::swap(string, string)
//swap (lhs.i, rhs.i);调用了std::swap(int, int)。调用了不同的swap函数，因此不会导致递归循环