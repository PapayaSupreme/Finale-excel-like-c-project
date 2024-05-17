//
// Created by pablo on 03/05/2024.
//

#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//create a column with a long string name
COLUMN* create_col(char name[]){
    //create a column of a value of
    //type integer given in parameter and a successor to NULL
    COLUMN* new_col = (COLUMN*)malloc(sizeof(COLUMN));
    if(new_col == NULL){
        printf("Error: memory allocation failed\n");
        exit(1);
    }
    //give a string name to the column
    strcpy(new_col->name, name);
    new_col->succ = NULL;
    new_col->length = 0;
    return new_col;
}

void add_value_col(COLUMN* col) {
    //add a value to the column
    //create a new element
    printf("How much values do you want to add ?");
    int nbval;
    scanf("%d", &nbval);
    int val, i;
    for (i = col->length; i<nbval+col->length; i++){
        printf("Enter the value %d : \n", i+1);
        scanf("%d", &val);
        col->values[i] = val;       //issue if we reenter values it will always go from index 0
    }
    col->length += nbval;
}

void display_col(COLUMN* col, int nbval){
    //display the column
    printf("Column name: %s\n", col->name);
    for (int i = 0; i<nbval; i++){
        printf("%d ", col->values[i]);
    }
    printf("\n");
}
bool empty_dataframe(dataframe df){
    //return true if the list is empty
    return df == NULL;
}

void add_head_df(dataframe* df, char name[]){
    //add a column at the head of the df
    COLUMN* new_df = create_col(name);
    new_df->succ = *df;
    *df = new_df;
}

void add_tail_df(dataframe* l, char name[]){
    //add a column at the tail of the df
    COLUMN* new_col = create_col(name);
    if(empty_dataframe(*l)){
        *l = new_col;
    }else{
        COLUMN* tmp = *l;
        while(tmp->succ != NULL){
            tmp = tmp->succ;
        }
        tmp->succ = new_col;
    }
}

void print_df(dataframe l, int rows, int cols){
    //display a part of the dataframe depending on rowmax and colmax
    COLUMN* tmp = l;
    int i = 0;
    while(tmp != NULL && i < cols){
        printf("Column name: %s\n", tmp->name);
        for (int j = 0; j<rows; j++){
            if (tmp->values[j] < 10000 && tmp->values[j] != 0) {
                printf("%d ", tmp->values[j]);
            }
        }
        printf("\n");
        tmp = tmp->succ;
        i++;
    }


}

void display_number_rows_df(dataframe l){
    //display the number of rows in the dataframe
    COLUMN* tmp = l;
    while(tmp != NULL) {
        printf("Column name: %s\n", tmp->name);
        int i = 0;
        while(tmp->values[i] < 10000 && tmp->values[i] != 0){
            i++;
        }
        printf("Number of rows: %d\n", i);
        tmp = tmp->succ;
    }
}

void display_nb_columns(dataframe l){
    //display the number of columns in the dataframe
    COLUMN* tmp = l;
    int i = 0;
    while(tmp != NULL && tmp != 0){
        i++;
        tmp = tmp->succ;
    }
    printf("Number of columns: %d\n", i);
}

void hardfill_col(COLUMN* col){
    //fill the column with random values
    printf("How much values do you want to hardfill ?");
    int nbval;
    scanf("%d", &nbval);
    printf("Up to how much do you want \nthe randomized values to go ?\n");
    int random;
    scanf("%d", &random);
    srand(time(NULL));
    for (int i = col->length; i<nbval+col->length; i++){
        col->values[i] = rand()%random;
    }
    col->length += nbval;
}

void delete_col(dataframe* l, char name[]){
    //delete a column from the dataframe
    COLUMN* tmp = *l;
    COLUMN* prev = NULL;
    while(tmp != NULL && strcmp(tmp->name, name) != 0){
        prev = tmp;
        tmp = tmp->succ;
    }
    if(tmp == NULL){
        printf("Column not found\n");
        return;
    }
    if(prev == NULL){
        *l = tmp->succ;
    }else{
        prev->succ = tmp->succ;
    }
    free(tmp);
}

void equal_to(dataframe l, int val){
    //display the columns that have a value equal to val
    COLUMN* tmp = l;
    int cpt = 0;
    while(tmp != NULL){
        for (int i = 0; i<tmp->length; i++){
            if(tmp->values[i] == val){
                cpt++;
            }
        }
        tmp = tmp->succ;
    }
    if (cpt == 0){
        printf("No column with value %d\n", val);
    }else {
        printf("Number of cells that are equal to value %d: %d\n", val, cpt);
    }
}

void greater_than(dataframe l, int val){
    //display the columns that have a value greater than val
    COLUMN* tmp = l;
    int cpt = 0;
    while(tmp != NULL){
        for (int i = 0; i<tmp->length; i++){
            if(tmp->values[i] > val){
                cpt++;
            }
        }
        tmp = tmp->succ;
    }
    if (cpt == 0){
        printf("No column with value greater than %d\n", val);
    }else {
        printf("Number of cells with value greater than %d: %d\n", val, cpt);
    }
}

void less_than(dataframe l, int val){
    //display the columns that have a value less than val
    COLUMN* tmp = l;
    int cpt = 0;
    while(tmp != NULL){
        for (int i = 0; i<tmp->length; i++){
            if(tmp->values[i] < val){
                cpt++;
            }
        }
        tmp = tmp->succ;
    }
    if (cpt == 0){
        printf("No column with value less than %d\n", val);
    }else {
        printf("Number of cells with value less than %d: %d\n", val, cpt);
    }
}

void rename_col(COLUMN* col){
    //rename the column
    char name[100];
    printf("Enter the new name of the column\n");
    scanf("%s", name);
    strcpy(col->name, name);
}

void modify_value(COLUMN* col, int row, int val){
    col->values[row - 1] = val;
}
