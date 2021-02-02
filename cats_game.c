int main()
{
    int max, min;

    scanf("%d", &max);
    min = 0;

    recurse_range(max, min);

    return 0;
}

void recurse_range(int max, int min)
{
    if(max - min == 0)
    {
        printf("%d\n", max);
        fflush(stdout);
        return;
    }
    else
    {
        if (

}

