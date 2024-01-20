#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct employee_t
{
    int id;
    char firstname[64];
    char lastname[64];
    float income;
    bool ismanager;
};

void initialize_employee(struct employee_t *employee)
{
    employee->id = 0;
    employee->income = 1000;
    employee->ismanager = false;
    strcpy(employee->firstname, "Ralph");
    strcpy(employee->lastname, "Haelle");
}

int main()
{
    int x = 3;

    int *pX = &x;

    printf("x = %d\n", *pX);
    printf("pX = %p\n", pX);

    struct employee_t Ralph;

    initialize_employee(&Ralph);

    printf("Ralph's income is %f\n", Ralph.income);
}