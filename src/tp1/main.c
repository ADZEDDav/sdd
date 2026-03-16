#include <stdio.h>
#include "../../lib/objects/objects.h"

int main()
{
    // TODO: Implement
    Customer *c = customer_create("David", "Rue du Lac 12");
    Car *v = car_create("Toyota", "Corolla", "GE1234697");

    link_car(v, c); 

    printf("Client: %s\nAdresse: %s\n", c->name, c->address);

    return 0;
}
