/*================================================================
*                source for learn_notes
*   
*   filename   : double_list.c
*   author     : chenjiang
*   date       : 2018-09-22
*   description: 实现双链表
*
================================================================*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "double_list.h"

struct double_list_node__ {
    void *p_data;
    double_list_node_t *p_last;
    double_list_node_t *p_next;
};

static void list_add_tail(double_list_t *p_list, void *p_data, 
        double_list_len_t data_size)
{
    if (p_list && p_data && data_size)
    {
        double_list_node_t *p_node = \
            (double_list_node_t*)malloc(sizeof(double_list_node_t));
        if (NULL == p_node)
        {
            printf("list_add_tail() - *p_node 申请内存失败！ \n");
            return;
        }
        p_node->p_data = calloc(sizeof(uint8_t), data_size);
        memcpy(p_node->p_data, p_data, data_size);
        if (NULL == p_node->p_data)
        {
            printf("list_add_tail() - *p_node->p_data 申请内存失败！ \n");
            return;
        }
        if (NULL == p_list->p_head)
        {
            p_node->p_last = p_node;
            p_node->p_next = p_node;
            p_list->p_head = p_node;
        }
        else
        {
            p_node->p_last = p_list->p_head->p_last;
            p_node->p_next = p_list->p_head;
            p_list->p_head->p_last->p_next = p_node;
            p_list->p_head->p_last = p_node;
        }
        p_list->len += 1;
    }
    else
    {
        printf("list_add_tail() - 空指针或是 data_size 等于零！ \n");
    }
}

static void list_del(double_list_t *p_list, void *p_data)
{
    if (p_list && p_data)
    {
        double_list_node_t *p_del_node = p_list->p_head;
        double_list_len_t i = 0;
        
        for (; i < p_list->len; i++)
        {
            /* TODO 如果有两个一样的数据，就只能 del 前面的一个 */
            if (0 == p_list->pf_data_compare(p_data, p_del_node->p_data))
            {
                break;
            }
            p_del_node = p_del_node->p_last;
        }
        /* 找到了这个 node */
        if (i < p_list->len)
        {
            p_del_node->p_last->p_next = p_del_node->p_next;
            p_del_node->p_next->p_last = p_del_node->p_last;
            /* 如果删除的是第一个 node ，需要给 list 的 head 指针赋值 */
            if (0 == i)
            {
                p_list->p_head = p_del_node->p_next;
            }
            free(p_del_node->p_data);
            free(p_del_node);
            p_list->len -= 1;
        }
    }
    else
    {
        printf("list_del() - 空指针或是 data_size 等于零！ \n");
    }
}

static void list_foreach(double_list_t *p_list, double_list_foreach_cb_t pf, 
        void *res_val)
{
    if (p_list && pf)
    {
        double_list_node_t *p_node = p_list->p_head;
        
        for (double_list_len_t i = 0; i < p_list->len; 
                i++, p_node = p_node->p_next)
        {
            pf(res_val, p_node->p_data);
        }
    }
    else
    {
        printf("list_foreach() - NULL == p_list or NULL == pf \n");
    }
}

static void *list_max(double_list_t *p_list)
{
    void *p_data = NULL;

    if (p_list)
    {
        double_list_node_t *p = p_list->p_head;
        
        for (double_list_len_t i = 0; i < p_list->len - 1; i++, p = p->p_next)
        {
            int8_t compare_res = p_list->pf_data_compare(p->p_data, 
                    p->p_next->p_data);
            if (compare_res >= 0)
            {
                p_data = p->p_data;
            }
            else if (compare_res < 0)
            {
                p_data = p->p_next->p_data;
            }
        }
    }
    else
    {
        printf("list_max() - NULL == p_list \n");
    }

    return p_data;
}

static int64_t list_sum(double_list_t *p_list, double_list_sum_t pf)
{
    int64_t sum = 0;

    if (p_list)
    {
        double_list_node_t *p = p_list->p_head;
        
        for (double_list_len_t i = 0; i < p_list->len; i++, p = p->p_next)
        {
            sum += pf(p->p_data);
        }
    }
    else
    {
        printf("list_sum() - NULL == p_list \n");
    }

    return sum;
}

static void list_show(double_list_t *p_list)
{
    if (p_list)
    {
        double_list_node_t *p = p_list->p_head;
        
        for (double_list_len_t i = 0; i < p_list->len; i++, p = p->p_next)
        {
            p_list->pf_show(p->p_data);
        }
        putchar('\n');
    }
    else
    {
        printf("list_show() - NULL == p_list \n");
    }
}

static void list_free(double_list_t **p_list)
{
    if (p_list)
    {
        double_list_node_t *p = (*p_list)->p_head;
        for (double_list_len_t i = 0; i < (*p_list)->len; i++)
        {
            double_list_node_t *p_free_node = p;
            
            p = p->p_next;
            free(p_free_node->p_data);
            free(p_free_node);
        }
        free(*p_list);
        *p_list = NULL;
    }
    else
    {
        printf("list_free() - NULL == p_list \n");
    }
}

double_list_t *double_list_init(double_list_data_compare_t pf_data_compare,
        double_list_show_t pf_show)
{
    double_list_t *p_list = (double_list_t*)malloc(sizeof(double_list_t));
    if (p_list != NULL)
    {
        p_list->p_head = NULL;
        p_list->len = 0;
        p_list->pf_data_compare = pf_data_compare;
        p_list->pf_show = pf_show;
        p_list->add_tail = list_add_tail;
        p_list->del = list_del;
        p_list->foreach = list_foreach;
        p_list->max = list_max;
        p_list->sum = list_sum;
        p_list->show = list_show;
        p_list->free = list_free;
    }

    return p_list;
}

