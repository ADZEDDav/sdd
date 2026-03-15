#include "objects.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// TODO: Implement
Car *car_create(char *brand, char *model, char *license)
{
    Car *car = malloc(sizeof(Car));
    car->brand = strdup(brand);
    car->model = strdup(model);
    car->license = strdup(license);
    return car;
}

Customer *customer_create(char *name, char *address)
{
    Customer *customer = malloc(sizeof(Customer));
    customer->name = strdup(name);
    customer->address = strdup(address);
    customer->car = NULL;
    return customer;
}

Registry *registry_create(Customer **customers, int size)
{
    Registry *registry = malloc(sizeof(Registry));
    registry->customers = customers;
    registry->size = size;
    return registry;
}

void link_car(Car *car, Customer *customer)
{
    customer->car = car;
}

void car_destroy(Car *car)
{
    if (!car) return;
    free(car->brand);
    free(car->model);
    free(car->license);
    free(car);
}

void customer_destroy(Customer *customer)
{
    if (!customer) return;
    free(customer->name);
    free(customer->address);
    free(customer);
}

void registry_destroy(Registry *registry)
{
    if (!registry) return;
    free(registry);
}

void print_registry(Registry *registry)
{
    
}