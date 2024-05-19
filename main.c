#include <stdio.h>
#include "column.h"
#include <string.h>

int main() {

    //creating a menu
    printf("Welcome to the dataframe program\n");
    //create a dataframe
    dataframe df = NULL;
    int columnsnb = 0;
    //create a list to keep track of the length of each column
    int firsttime = 1;
    printf("1 - Create x columns\n");
    printf("2 - Add values to a column\n");
    printf("3 - Display the whole dataframe or only a part of it\n");
    printf("4 - Display the number of rows in the dataframe\n");
    printf("5 - Display the number of columns in the dataframe\n");
    printf("6 - Hard-fill a column\n");
    printf("7 - Delete a column\n");
    printf("8 - Empty the dataframe\n");
    printf("9 - Display the number of of occurences of a value\n");
    printf("10 - Display the number of values greater than x\n");
    printf("11 - Display the number of values less than x\n");
    printf("12 - Made a mistake ? Rename a column\n");
    printf("13 - Modify a value\n");
    printf("14 - Exit\n");
    int answer = 0;
    while (answer < 1 || answer > 13){
        answer  = 0;
        printf("WHat do you want to do ?\n");
        scanf("%d", &answer);
        if (answer < 1 || answer > 13){
            printf("Please enter a number between 1 and 13\n");
        }
    }
    while (answer != 14) {
        if (firsttime == 1) {
            firsttime = 0;
        } else {
            printf("1 - Create x columns\n");
            printf("2 - Add values to a column\n");
            printf("3 - Display the whole dataframe or only a part of it\n");
            printf("4 - Display the number of rows in the dataframe\n");
            printf("5 - Display the number of columns in the dataframe\n");
            printf("6 - Hard-fill a column\n");
            printf("7 - Delete a column\n");
            printf("8 - Empty the dataframe\n");
            printf("9 - Display the number of occurences of a value\n");
            printf("10 - Display the number of values greater than x\n");
            printf("11 - Display the number of values less than x\n");
            printf("12 - Made a mistake ? Rename a column\n");
            printf("13 - Modify a value\n");
            printf("14 - Exit\n");
            scanf("%d", &answer);
        }
        if (answer == 1) {
            printf("How much columns do you want to create?\n");
            int n;
            scanf("%d", &n);
            //creating n columns with for loop
            char name[100];
            //create a list to store the columns adresses
            for (int i = 0; i < n; i++) {
                columnsnb++;
                //name is to be chosen by the user
                printf("Enter the name of the column %d\n", i + 1);
                scanf("%s", name);
                //put the col in the dataframeO
                add_tail_df(&df, name);
            }
        } else if (answer == 2) {
            char name_col[100];
            printf("In which column do you want to add values ?");
            scanf("%s", name_col);
            //find column
            COLUMN *tmp = df;
            //iterate until column name match user input
            while (tmp != NULL && strcmp(tmp->name, name_col) != 0) {
                tmp = tmp->succ;
            }
            //create safe input by checking if column exists and if no do a loop
            while (tmp == NULL) {
                printf("This column does not exist\n");
                printf("Enter the name of the column you want to add values to\n");
                scanf("%s", name_col);
                tmp = df;
                while (tmp != NULL && strcmp(tmp->name, name_col) != 0) {
                    tmp = tmp->succ;
                }
            }
            //add values to the column
            add_value_col(tmp);
        } else if (answer == 3) {
            printf("How much columns at max do you want me to display ?\n");
            int cols;
            scanf("%d", &cols);
            printf("How much rows at max do you want me to display ?\n");
            int rows;
            scanf("%d", &rows);
            print_df(df, rows, cols);
        } else if (answer == 4) {
            display_number_rows_df(df);
        } else if (answer == 5) {
            display_nb_columns(df);
        } else if (answer == 6) {
            char name_col[100];
            printf("In Which column do you want to hard-fill ?");
            scanf("%s", name_col);
            //find column
            COLUMN *tmp = df;
            //iterate until column name match user input
            while (tmp != NULL && strcmp(tmp->name, name_col) != 0) {
                tmp = tmp->succ;
            }
            //create safe input by checking if column exists and if no do a loop
            while (tmp == NULL) {
                printf("This column does not exist\n");
                printf("Enter the name of the column you want to hard-fill\n");
                scanf("%s", name_col);
                tmp = df;
                while (tmp != NULL && strcmp(tmp->name, name_col) != 0) {
                    tmp = tmp->succ;
                }
            }
            //add values to the column
            hardfill_col(tmp);
        } else if (answer == 7) {
            char name_col[100];
            printf("Which column do you want to delete ?");
            scanf("%s", name_col);
            delete_col(&df, name_col);
        } else if (answer == 8) {
            df = NULL;
        } else if (answer == 9) {
            printf("Enter the value you want to compare to\n");
            int val;
            scanf("%d", &val);
            COLUMN *tmp = df;
            while (tmp != NULL) {
                equal_to(tmp, val);
                tmp = tmp->succ;
            }
        } else if (answer == 10) {
            printf("Enter the value you want to compare to\n");
            int val;
            scanf("%d", &val);
            COLUMN *tmp = df;
            while (tmp != NULL) {
                greater_than(tmp, val);
                tmp = tmp->succ;
            }
        } else if (answer == 11) {
            printf("Enter the value you want to compare to\n");
            int val;
            scanf("%d", &val);
            COLUMN *tmp = df;
            while (tmp != NULL) {
                less_than(tmp, val);
                tmp = tmp->succ;
            }
        } else if (answer == 12) {
            COLUMN *tmp = NULL;
            while (tmp == NULL) {
                char name_col[100];
                printf("Which column do you want to rename ?");
                scanf("%s", name_col);
                tmp = df;
                while (tmp != NULL && strcmp(tmp->name, name_col) != 0) {
                    tmp = tmp->succ;
                }
                if (tmp == NULL) {
                    printf("This column does not exist\n");
                } else {
                    rename_col(tmp);
                }
            }
        }else if (answer == 13){
            int row, value;
            COLUMN *tmp = df;
            int col, it = 0;
            printf("Enter the column index of the cell you want to modify : \n");
            scanf("%d", &col);
            while ((col - 1) != it) {
                tmp = tmp->succ;
                it++;
            }
            printf("Enter the row index of the cell you want to modify\n");
            scanf("%d", &row);
            printf("Enter the new value\n");
            scanf("%d", &value);
            modify_value(tmp, row-1, value);
        }
    }
    return 0;
}