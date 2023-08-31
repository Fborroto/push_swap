# push_swap

This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

The instructions allowed are described as follows, as written in our task:

sa : swap a - Swap the first 2 elements at the top of stack A. (Do nothing if there is only one or no elements).

sb : swap b - Swap the first 2 elements at the top of stack B. (Do nothing if there is only one or no elements).

ss : sa and sb at the same time.

pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if B is empty.

pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if A is empty.

ra : rotate a - shift up all elements of stack A by 1. The first element becomes the last one.

rb : rotate b - shift up all elements of stack B by 1. The first element becomes the last one.

rr : ra and rb at the same time.

rra : reverse rotate a - shift down all elements of stack A by 1. The last element becomes the first one.

rrb : reverse rotate b - shift down all elements of stack B by 1. The last element becomes the first one.

rrr : rra and rrb at the same time.