/*
Dear Procrastinator,
You still have to wait for X days (Y minutes or Z seconds) before you can procrastinate!
*/

#include <stdio.h>
int main(void) {
    printf("Dear Procrastinator,\nYou still have to wait for %d days (%d minutes or %d seconds) before you can procrastinate!", 25-23, 60*24*(25-23), 60*(60*24*(25-23)));

    return 0;
}