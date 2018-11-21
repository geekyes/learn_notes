/*================================================================
*                source for learn_notes
*   
*   filename   : double_list.h
*   author     : chenjiang
*   date       : 2018-09-22
*   description: 双链表的接口
*
================================================================*/

#ifndef DOUBLE_LIST_H__
#define DOUBLE_LIST_H__

#include <stdint.h>

struct double_list_node__;
typedef struct double_list_node__ double_list_node_t;
typedef uint16_t double_list_len_t;
typedef void (*double_list_show_t)(void *p_data);
typedef int8_t (*double_list_data_compare_t)(void *p_data1, void *p_data2);
typedef int64_t (*double_list_sum_t)(void *p_data);
typedef void (*double_list_foreach_cb_t)(void *res_val, void *p_data);

// TODO 书中说不要暴露调用者用不到的变量等，不然失去了封装的意义，这里需要从新设
// 计对 double list 的抽象。
// 封装需要达到两个要求：隔离变化和降低复杂度，怎么理解了？
// 隔离变化：我理解为独立性，其他模块改变，不需要改这个里的代码；
// 降低复杂度：我这里就做的不好，接口提供的过于复杂，这个我认为是需要和
// “隔离变化”有个取舍，书中也有讨论，如果需要复杂度低，就得牺牲“隔离变化”来达到
// 高度去耦合，其实现必定复杂，这个只能视情况而定。
// TODO 但是我下面违背了封装的原则，就是暴露了调用者不用关心的部分，这个是自己没
// 有想好数据和操作数据的方法到底要怎么去组合，是分开看，还是看成一个对象。
// 记录一个好的链表的抽象，最基础的应该是 init, add, del, foreach, free
// TODO 每个函数都应该返回操作的结果
typedef struct double_list__ double_list_t;
struct double_list__ {
    double_list_node_t *p_head;
    double_list_len_t len;
    double_list_data_compare_t pf_data_compare;
    double_list_show_t pf_show;
    void (*add_tail)(double_list_t *p_list, void *p_data, 
            double_list_len_t data_size);
    void (*del)(double_list_t *p_list, void *p_data);
    void (*foreach)(double_list_t *p_list, double_list_foreach_cb_t pf, 
            void *res_val);
    void *(*max)(double_list_t *p_list);
    int64_t (*sum)(double_list_t *p_list, double_list_sum_t pf);
    void (*show)(double_list_t *p_list);
    void (*free)(double_list_t **p_list);
};

// 返回一个双链表的引用
double_list_t *double_list_init(double_list_data_compare_t pf_data_compare,
        double_list_show_t pf_show);

#endif /* DOUBLE_LIST_H__ */


