
#include <stdio.h>
#include <assert.h>

#include "array.h"
#include "int.h"
#include "new.h"

int main()
{
    Object* array = new(Array, 10, Int, 2);
    Object* it = begin(array);
    Object* it_end = end(array);

    printf("array size: %zu\n", len(array));
    setitem(array, 5, 12);
    setitem(array, 6, 13);
    while (lt(it, it_end))
    {
        printf("%s\n", str(getval(it)));
        incr(it);
    }
    delete(it);
    delete(it_end);
    printf("resize de 15\n");
    resize(array, 6, 42);
    pushback(array, 199);
    it = begin(array);
    it_end = end(array);
    while (lt(it, it_end))
    {
        printf("%s\n", str(getval(it)));
        incr(it);
    }
	delete(it);
	delete(it_end);

    delete(array);
    return 0;
}

