#include <stdio.h>
#include <stdbool.h>

int array[100];
int i;
int array_value,array_size; // create array's variable.

#include<stdio.h>

void create_arr(){
    
    printf("Array Size: ");
    scanf("%d",&array_size);
    for(i=0; i<array_size; i++){
        scanf("%d",&array_value);
        array[i]=array_value;
    }
    printf("Array created successfully!!\n");
    
}

void insert_value(){
    int value,position;
    printf("Enter a value: ");
    scanf("%d",&value);
    printf("Enter a position: ");
    scanf("%d",&position);
    array[position]=value;
    printf("array inserted successfully!.\n");
}

void read_arrays(){
    for(i=0; i<array_size; i++){
       if(i==array_size-1){
            printf("%d\n\n",array[i]);
       } else{
           printf("%d ",array[i]);
       }
    }
}

void index_of_array(){
    int index_number;
    scanf("%d",&index_number);
    if(array_size<index_number){
        printf("Alert! your array size is %d\n",array_size);
    } else{
        printf("position %d Data is - %d\n\n",index_number,array[index_number]);
    }
}

void search_from_array(){
    int search_number;
    scanf("%d",&search_number);
    for(i=0; i<array_size; i++){
        if(array[i]==search_number){
            printf("array[%d]=%d\n\n",i,search_number);
        }
    }
}

void update_value(){
    int value,position;
    printf("Enter a value: ");
    scanf("%d",&value);
    printf("Enter a position: ");
    scanf("%d",&position);
    if(array_size<position){
        printf("Alert! your array size is %d\n",array_size);
        printf("You've to put it under %d\n",array_size);
    } else{
        array[position]=value;
        for(i=0; i<array_size; i++){
            if(i==array_size-1){
                printf("%d\n\n",array[i]);
            } else{
                printf("%d ",array[i]);
            }
        }
    }

}


int main(){
    int is_proceed=false;
    int is_proceed2=false;
    int direction;
    while (1)
    {   
        printf("[1] Create\n");
        printf("[2] Read\n");
        printf("[3] Update\n");
        printf("[4] Delete\n");
        printf("[5] Exit\n");
        scanf("%d",&direction);
        if(direction==5){
            break;
        }
        if(direction==1){
            printf("__[1] Create a new array__\n");
            printf("__[2] Insert A value__\n");
            int create_array;
            scanf("%d",&create_array);

            if(create_array==1){
                printf("[1]-----Create Array-----\n");
                create_arr(); // create array funciton is called here.
                is_proceed2=true; 
            } else if(is_proceed2==false){
                printf("You've to create first.\n");

            } else if(create_array==2){                 
                printf("[2]-----Insert value-----\n");
                insert_value(); // insert value funciton is called here.
            }
            is_proceed=true;


        } else if(is_proceed==false){
            printf("You've to create first.\n\nYou can Press first 1.\n\n");
        } else{
            if(direction==2){
                printf("[1]-----Read Full Data-----\n");
                printf("[2]-----Read via index-----\n");
                printf("[3]-----Search via value-----\n");


                int read_array;
                scanf("%d",&read_array);
                if(read_array==1){
                    read_arrays(); // read array function is called here.
                } else if(read_array==2){
                    index_of_array(); // index of array function is called here.
                } else if(read_array==3){
                    search_from_array();// search from array function is called here.
                }

            } else if(direction==3){
                update_value();
            } else if(direction==4){
                printf("Delete\n");
            }
        }
    }
    
    return 0;
}