// Recursive simplification of summation

// Pre: 

int triangle_number(int n)
{
    int index, sum = 0;
    for (index = 1; index <= n; ++index)
    {
        sum = sum + index;
    }

    return sum;
}

// Post:

int triangle_number_recursive(int n)
{
    if (n == 0)
        return 0;
    else
        return (n + triangle_number_recursive(n - 1));
}

