#include<stdint.h>
#include<stddef.h>


/*

memcpy

Copies the values of num bytes from the location pointed to by 
source directly to the memory block pointed to by destination.

The underlying type of the objects pointed to by both the source 
and destination pointers are irrelevant for this function; 
The result is a binary copy of the data.

The function does not check for any terminating null character 
in source - it always copies exactly num bytes.

To avoid overflows, the size of the arrays pointed to by both 
the destination and source parameters, shall be at least num bytes, 
and should not overlap (for overlapping memory blocks, 
memmove is a safer approach).



*/


// MIRAR MEMCPY EN EL CASO DEL OVERLAP CREO QUE HAY QUE HACER MEMMOVE O ESO DIJO ALAF


void * memcpy ( void * destination, const void * source, size_t num )
{

    uint8_t * d = destination;
    uint8_t * s = (uint8_t *) source;
    
    // if destination = source, doesn't make sense to copy

    if (destination > source) // 
    {
        for ( size_t i=0; i<num; i++)
            *d++ = *s++;         // puts one byte from source to destintation and then increments pointers
    
    } else if (destination < source)
    {
        d += num-1;
        s += num-1;
        for ( size_t i=0; i<num; i++)
            *d++ = *s++;
    };

    return destination;
}






/*

memmove

Copies the values of num bytes from the location pointed by source to the memory block pointed by destination. 
Copying takes place as if an intermediate buffer were used, allowing the destination and source to overlap.

The underlying type of the objects pointed by both the source and destination pointers are irrelevant for this 
function; The result is a binary copy of the data.

The function does not check for any terminating null character in source - it always copies exactly num bytes.

To avoid overflows, the size of the arrays pointed by both the destination and source parameters, shall be at 
least num bytes.

*/



void * memmove ( void * destination, const void * source, size_t num )
{

    uint8_t * d = destination;
    uint8_t * s = (uint8_t *) source;
    uint8_t aux[num];
    for (size_t i=0; i<num; i++)
        aux[i] = *s++;
    for (size_t i=0; i<num; i++)
        *d++ = aux[i];
    
    return destination;
}





/*

memset

Sets the first num bytes of the block of memory pointed by ptr to the specified 
value (interpreted as an unsigned char).


*/



void * memset ( void * ptr, int value, size_t num )
{

    unsigned char * p = ptr;
    unsigned char cvalue = (unsigned char) value;
    for (size_t i=0; i<num; i++)
        *p++ = cvalue;

    return ptr;
}





/*

memcmp

Compare two blocks of memory

Compares the first num bytes of the block of memory pointed by ptr1 to the first 
num bytes pointed by ptr2, returning zero if they all match or a value different 
from zero representing which is greater if they do not.

Notice that, unlike strcmp, the function does not stop comparing after finding a 
null character.

*/



int memcmp ( const void * ptr1, const void * ptr2, size_t num )
{

    uint8_t *p1 = (uint8_t *) ptr1;
    uint8_t *p2 = (uint8_t *) ptr2;
    int out = 0;

    while (num)
    {
    
        if (*p1 < *p2)
        {
            out = -1;
            num = 0;
        }
        else if (*p1 > *p2)
        {
            out = 1;
            num = 0;
        };
        num--;
        if(num)
        {
        p1++;
        p2++;
        };

    }
    return out;
}



