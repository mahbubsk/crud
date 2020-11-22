#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int array[1000];
int array_size;
int i;

// create array function.
void create()
{
    printf("Enter the size of array: ");
    scanf("%d", &array_size);
    array[array_size];

    int wish_size, spy = 0;
    printf("Enter how many values you want to insert now (limit: 1-%d): ", array_size);
    scanf("%d", &wish_size); //

    if (wish_size > array_size)
    {
        printf("array is overflow.\n");
    }
    else
    {

        for (i = 0; i < wish_size; i++)
        {
            int value, position;
            printf("Enter a position: ");
            scanf("%d", &position);
            if (position > array_size)
            {
                spy = 1;
                break;
            }
            printf("Enter a value: ");
            scanf("%d", &value);
            array[position - 1] = value;
        }
        if (spy == 0)
        {
            printf("___________________________\n");
            printf("array created successfully.\n");
            printf("---------------------------\n\n\n");
        }
        else
        {
            printf("!!invalid input\n");
        }
    }
}

// insert a value.
void insert()
{
    printf("Available position for insert.\n");

    int value, position, flag = false, spy_for_invalid = false;
    printf("\n");
    for (i = 0; i < array_size; i++)
    {
        if (array[i] == 0)
        {
            if (i == array_size - 1)
            {
                printf("%d\n\n", i + 1);
            }
            else
            {
                printf("%d ", i + 1);
            }
        }
    }

    printf("\n");

    printf("enter a position: ");
    scanf("%d", &position);

    for (i = 0; i < array_size; i++)
    {
        if (array_size < position || array[position - 1] != 0)
        {
            spy_for_invalid = true;
            break;
        }
        else if (array[i + 1] == 0 && array[position - 1] == 0)
        {

            printf("enter a value: ");
            scanf("%d", &value);
            array[position - 1] = value;
            flag = true;
            spy_for_invalid = true;
        }
    }
    if (flag == false || spy_for_invalid == false)
    {
        printf("!invalid input.\n\n");
    }
    else
    {
        printf("value inserted successfully.\n\n");
    }
}

// read function is written here.
void read()
{
    for (i = 0; i < array_size; i++)
    {
        if (array[i] == 0)
        {
            printf("array[%d] = empty\n", i + 1);
        }
        else
        {
            printf("array[%d] = %d\n", i + 1, array[i]);
        }
    }
}

void index_of_array()
{
    int position, flag = 0;

    printf("Enter a position: ");
    scanf("%d", &position);

    if (array_size < position)
    {
        printf("array overflow!!\n\n");
    }
    else
    {
        for (i = 0; i < array_size; i++)
        {
            if (i + 1 == position)
            {
                if (array[i] == 0)
                {
                    printf("array[%d] = empty\n\n\n", position);
                }
                else
                {
                    printf("array[%d] = %d\n\n\n", position, array[i]);
                }
            }
        }
    }
}

void search_from_array()
{
    int number, flag = 0;
    printf("Enter a number for searching: ");
    scanf("%d", &number);

    for (i = 0; i < array_size; i++)
    {
        if (array[i] == number)
        {
            printf("value found\nthe number %d is at %d\n\n", array[i], i + 1);

            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("value not found.\n");
    }
}

// update function ..............
void update()
{
    printf("available position for update.\n");

    int value, position, flag = false, spy_for_invalid = false;

    printf("\n");
    for (i = 0; i < array_size; i++)
    {
        if (array[i] > 0)
        {
            if (i == array_size - 1)
            {
                printf("%d\n", i + 1);
            }
            else
            {
                printf("%d ", i + 1);
            }
        }
    }

    printf("\n");

    printf("enter a position: ");
    scanf("%d", &position);

    for (i = 0; i < array_size; i++)
    {
        if (array_size < position || array[position - 1] <= 0)
        {
            spy_for_invalid = true;
            break;
        }
        else if (array[position - 1] != 0)
        {

            printf("enter a value: ");
            scanf("%d", &value);
            array[position - 1] = value;
            flag = true;
            spy_for_invalid = true;
            break;
        }
    }
    if (flag == false || spy_for_invalid == false)
    {
        printf("!!invalid input.\n\n");
    }
    else
    {
        printf("value updated successfully.\n\n\n");
    }
}

// delete full array function...
void delete_array()
{
    array_size = 0;
    printf("array deleted.\n\n");
}

// delete index of array function..
void delete_index()
{
    int delete_position;

    printf("Enter a position: ");
    scanf("%d", &delete_position);
    if (delete_position <= 0 || delete_position > array_size)
    {
        printf("!invalid input.\n");
    }
    else
    {
        for (i = delete_position - 1; i < array_size; i++)
        {
            array[i] = array[i + 1];
        }
        array_size--;
    }

    printf("position deleted successfully.\n");
}

int main()
{
    int is_proceed = false;
    int is_proceed2 = false;
    int direction;
    printf("\n\n\t\t0 means empty\n\n\n");
    do
    {
        printf(" [1] Create\n");
        printf(" [2] Read\n");
        printf(" [3] Update\n");
        printf(" [4] Delete\n");
        printf(" [5] Exit\n");

        scanf("%d", &direction);

        if (direction == 5)
        {
            break;
        }
        if (direction == 1)
        {
            printf(" [1] Create a new array\n");
            printf(" [2] Insert A value\n");

            int create_array;
            scanf("%d", &create_array);

            if (create_array == 1)
            {
                if (array_size <= 0)
                {
                    create(); // create array funciton is called here
                    is_proceed2 = true;
                }
                else
                {
                    printf("You still have an array..\ndo you want to create a new array?\n");
                    printf("your data will destroy.\n");
                    printf(" [1] create a new array.\n");
                    printf(" [2] main menu\n");

                    int again_array;
                    scanf("%d", &again_array);
                    if (again_array == 1)
                    {
                        for (i = 0; i < array_size; i++)
                        {
                            array_size = 0;
                        }
                        create();
                    }
                    else if (again_array == 2)
                    {
                        continue;
                    }
                    else
                    {
                        printf("You've create first\n");
                    }
                }
            }
            else if (array_size <= 0)
            {
                printf("You've to create first.\n");
            }
            else if (create_array == 2)
            {
                insert(); // insert value funciton is called here.
            }
            else
            {
                printf("!invalid input\n");
            }
            is_proceed = true;
        }
        else if (array_size == 0)
        {
            printf("You've to create first.\n\nYou can Press first 1.\n\n");
        }
        else if (array_size > 0)
        {
            if (direction == 2)
            {
                printf(" [1] Read Full Data\n");
                printf(" [2] Read via index\n");
                printf(" [3] Search via value\n");

                int read_array;
                scanf("%d", &read_array);

                if (read_array == 1)
                {
                    read(); // read function is called here.
                }
                else if (read_array == 2)
                {
                    index_of_array(); // index of array function is called here.
                }
                else if (read_array == 3)
                {
                    search_from_array(); //search from array function is called here.
                }
                else
                {
                    printf("!invalid input.\n");
                }
            }
            else if (direction == 3)
            {
                update();
            }
            else if (direction == 4)
            {
                printf("[1] delete full array.\n");
                printf("[2] delete position.\n");

                int delete_array_dir;
                scanf("%d", &delete_array_dir);
                if (delete_array_dir == 1)
                {
                    delete_array(); // delete full array function.
                }
                else if (delete_array_dir == 2)
                {
                    delete_index(); // delete index function.
                }
                else
                {
                    printf("!invalid input\n");
                }
            }
        }
    } while (1);

    return 0;
}
