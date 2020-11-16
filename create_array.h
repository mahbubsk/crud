#include<stdio.h>

void create_arr(){
    extern int array[100];
    int i,array_value,array_size;
    scanf("%d",&array_size);
    for(i=0; i<array_size; i++){
        scanf("%d",&array_value);
        array[i]=array_value;
    }
    printf("Array created successfully!!\n");
    
}
