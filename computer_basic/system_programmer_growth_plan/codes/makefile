


#================================================================
#                source for learn_notes
#   
#   filename   : makefile
#   author     : chenjiang
#   date       : 2018-09-22
#   description: TODO
#
#================================================================

all : double_list_test
	@echo "-->all done!<--"

double_list_test : main.c task1_double_list/double_list.c \
	task1_double_list/double_list.h
	@mkdir -p objs
	@gcc -Wall -g $^ -o objs/$@

# 增加检测内存使用释放，valgrind 使用来自“笨办法学 C ”
run_task1 : double_list_test
	@valgrind -v ./objs/$<

debug_task1 : double_list_test 
	@ gdb ./objs/$<

clean:
	rm -rf objs
