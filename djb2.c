# include <math.h>
// Note: to implement in C, you will have to #include <math.h> library for pow
unsigned long djb2Hash(char *name)
{
    unsigned long hash = 5381;
    int c;

    while(c = *name++)
    {
	hash = (hash * pow(2, 5) + hash) + c; // hash * 33 + c
    }

    return hash;
} 
