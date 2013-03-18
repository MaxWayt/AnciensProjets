/*
** castmania.c for ex04 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d02m-2016-ginter_m/ex04
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Thu Jan 10 12:44:36 2013 maxime ginters
** Last update Thu Jan 10 13:17:03 2013 maxime ginters
*/

#include <stdio.h>
#include "castmania.h"

void exec_operation(t_instruction_type instruction_type, void* data)
{
    if (instruction_type == ADD_OPERATION)
    {
        exec_add((t_add*)((t_instruction*)data)->operation);
        if (((t_instruction*)data)->output_type  == VERBOSE)
            printf("%d\n", ((t_add*)((t_instruction*)data)->operation)->add_op.res);
    }
    else if (instruction_type == DIV_OPERATION)
    {
        exec_div((t_div*)(((t_instruction*)data)->operation));
        if (((t_instruction*)data)->output_type  == VERBOSE)
        {
            if (((t_div*)((t_instruction*)data)->operation)->div_type == DECIMALE)
                printf("%f\n", ((t_decimale_op*)((t_div*)((t_instruction*)data)->operation)->div_op)->res);
            else if (((t_div*)((t_instruction*)data)->operation)->div_type == INTEGER)
                printf("%d\n", ((t_integer_op*)((t_div*)((t_instruction*)data)->operation)->div_op)->res);
        }
    }
}

void exec_instruction(t_instruction_type instruction_type, void* data)
{
    if (instruction_type == PRINT_INT)
        printf("%d\n", *((int*)data));
    else if (instruction_type == PRINT_FLOAT)
        printf("%f\n", *((float*)data));
    else exec_operation(instruction_type, data);
}
