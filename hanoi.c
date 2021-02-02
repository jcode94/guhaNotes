// Hanoi towers recursive solution

void towers (int n, int start, int end)
{
    int mid;
    if (n > 0)
    {
        mid = 6 - start - end;
        towers(n - 1, start, mid);
        printf("Move disk %d from tower ", n);
        printf("%d to tower %d.", start, end);
        towers(n - 1, mid, end);
    }
}

