/*================================================================
*                source for learn_notes
*   
*   filename   : main.c
*   author     : chenjiang
*   date       : 2018-09-22
*   description: 程序入口
*
================================================================*/

#include <stdio.h>
#include <string.h>

#include "task1_double_list/double_list.h"

static int8_t double_list_data_compare(void *p_data1, void *p_data2)
{
    int num1 = *((int*)p_data1);
    int num2 = *((int*)p_data2);
    int8_t res = 0;
    if (num1 > num2)
    {
        res = 1;
    }
    else if (num1 < num2)
    {
        res = -1;
    }

    return res;
}

static void double_list_elem_show(void *p_data)
{
    printf("%d ", *((int*)p_data));
}

static int64_t double_list_sum(void *p_data)
{
    return *((int*)p_data);
}

static void double_list_foreach_show(void *res_val, void *p_data)
{
    if (p_data)
    {
        printf("%d ", *((int*)p_data));
    }
}

static void double_list_foreach_max(void *res_val, void *p_data)
{
    if (p_data)
    {
        if (NULL == res_val)
        {
            res_val = p_data;
        }
        else if (*((int*)res_val) < *((int*)p_data))
        {
            res_val = p_data;
        }
    }
}

static void double_list_foreach_sum(void *res_val, void *p_data)
{
    if (res_val && p_data)
    {
        *((int64_t*)res_val) += *((int*)p_data);
    }
}

static void double_list_foreach_str_show(void *res_val, void *p_data)
{
    if (p_data)
    {
        puts((char*)p_data);
    }
}

static void task1_double_list_test(void)
{
    double_list_t *p_list = double_list_init(double_list_data_compare, 
            double_list_elem_show);

    if (p_list)
    {
        for (int i = 0; i < 10; i++)
        {
            p_list->add_tail(p_list, &i, sizeof(int));
        }
        
        puts("add_tail() - show() :");
        p_list->show(p_list);
        
        for (int i = 9; i >= 3; i--)
        {
            p_list->del(p_list, &i);
            puts("del() - show() :");
            p_list->show(p_list);
            puts("del() - foreach() as show() :");
            p_list->foreach(p_list, double_list_foreach_show, NULL);
            putchar('\n');
            int *p_num = (int*)(p_list->max(p_list));
            if (p_num)
            {
                printf("current list max = %d \n", *p_num);
            }
            puts("del() - foreach() as max() :");
            p_list->foreach(p_list, double_list_foreach_max, p_num);
            if (p_num)
            {
                printf("current list max = %d \n", *p_num);
            }
            printf("current list sum = %ld \n", 
                    p_list->sum(p_list, double_list_sum));
            puts("del() - foreach() as sum() :");
            int64_t sum = 0;
            p_list->foreach(p_list, double_list_foreach_sum, &sum);
            printf("current list sum = %ld \n", sum);
        }
    }
    p_list->free(&p_list);

    /* 链表的数据是字符串 */
    double_list_t *p_list_str = double_list_init(NULL, NULL);
    char *p_str = "chen jiang";
    p_list_str->add_tail(p_list_str, p_str, strlen(p_str) + 1);
    p_str = "I love you!";
    p_list_str->add_tail(p_list_str, p_str, strlen(p_str) + 1);
    p_str = "code for c and python";
    p_list_str->add_tail(p_list_str, p_str, strlen(p_str) + 1);
    p_str = "陈江喜欢写代码，主要喜欢 c 语言和 python ！";
    p_list_str->add_tail(p_list_str, p_str, strlen(p_str) + 1);
    p_list_str->foreach(p_list_str, double_list_foreach_str_show, NULL);
    p_list_str->free(&p_list_str);
}

int main(int argc, char *argv[])
{
    
    task1_double_list_test();

    return 0;
}


