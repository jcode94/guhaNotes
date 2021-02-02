// Recursive lucas number algorithm for muscle mem(from GUHA)

int lucas_num (int n)
{
    if (n == 1)
        return 1;
    else if (n == 2)
        return 3;
    else
        return lucas_num(n - 1) + lucas_num(n - 2);
}
