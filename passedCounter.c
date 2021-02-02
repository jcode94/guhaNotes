// Note that in the following implementation, the passed parameters are 
// not of equal meaning. While first is used to initiate a sum, second 
// is maintained as a decrementing counter value for our recursive summation.

int mult_recursion (int first, int second)
{
    if((second == 0 || first == 0))
    {
        return 0;
    }
    else
    {
        return (first + mult_recursion(first, second - 1));
    }
}
