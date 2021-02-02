// This singular conversion function should sufficiently cover the recursive
// method for base conversion of all values
// Note that to convert the function to one that covers all bases, we can
// replace the 2 divisor with the base of choice. The operations remain the
// same.

void dectobin(int n)
{
    if (n < 2)
        printf("%d", n);

    else
    {
        dectobin(n / 2);
        printf("%d", n % 2);
    }
}

