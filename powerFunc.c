// In case I'm not allowed to use the math.h lib, I will need this for hashing

int Power(int base, int exponent)
{
    if (exponent == 0)
        return 1;
    else
        return (base * Power(base, exponent - 1));
}
