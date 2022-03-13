#include "Logs.h"

int main ()
{
    Logs.error ("Some text");
    Logs.warn ("Some text");
    Logs.debug ("Some text");
    Logs.trace ("Some text");

    return 0;
}
