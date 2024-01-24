
two_dim_arr.o : ./dynamic_two_dim_arr/real_2/two_dim_arr.c
	gcc -ggdb -c $@ $<


dynamic_array.o : ./dynamic_array/dynamic_array.c
	gcc -ggdb -c $@ $<


linked_list.o : ./linked_list/linked_list.c
	gcc -ggdb -c $@ $<

main : ./main.c linked_list.o dynamic_array.o two_dim_arr.o
	gcc -ggdb -o $@ $^

.PHONY : clean
clean :
	rm *.o