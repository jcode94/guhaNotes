/* treat string as base-256 integers */
/* with digits in the range 1 to 255 */
#define BASE (256)

unsigned long hash(const char *s, unsigned long m)
{
    unsigned long h;
    unsigned const char *us;

    /* cast s to unsigned const char * */
    /* this ensures that elements of s will be treated as having values >= 0 */
    us = (unsigned const char *) s;

    h = 0;
    while( *us != '\0')
    {
        h = (h * BASE + *us) % m;
        us++;
    }

    return h;
}
