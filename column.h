//
// Created by pablo on 03/05/2024.
//

#ifndef PROJETVPITIE_COLUMN_H
#define PROJETVPITIE_COLUMN_H

#include <stdbool.h>

struct column
{
    char name[100];
    struct column *succ;
    //as much values as the user wants
    int values[100];
    int length;
};
/*-Definition of type COLUMN*/
typedef struct column COLUMN;
/*-Definition of type dataframe-*/

typedef COLUMN* dataframe;
COLUMN* create_col(char name[]);
bool empty_dataframe(dataframe df);
void add_head_df(dataframe *df, char name[]);
void add_tail_df(dataframe *l, char name[]) ;
void print_df(dataframe l, int rows, int cols);
void add_value_col(COLUMN* col);
void display_col(COLUMN* col, int nbval);
void display_number_rows_df(dataframe l);
void display_nb_columns(dataframe l);
void hardfill_col(COLUMN* col);
void delete_col(dataframe* l, char name[]);
void equal_to(COLUMN* col, int val);
void greater_than(COLUMN* col, int val);
void less_than(COLUMN* col, int val);
void rename_col(COLUMN* col);
void modify_value(COLUMN* col, int row, int val);
#endif //PROJETVPITIE_COLUMN_H
