# Push_Swap

Push_Swap is a sorting algorithm project that aims to sort a stack of numbers in ascending order using a specific set of operations. The project consists of two programs: push_swap and checker.
Rules

## The project follows the following rules:
Two stacks are used, named a and b.
- At the beginning:
	- Stack a contains a random amount of negative and/or positive numbers, which are unique and cannot be duplicated.
	- Stack b is empty.
- The goal is to sort the numbers in stack a in ascending order.
- The following operations are available:
	- sa: Swap the first two elements at the top of stack a. No effect if there is only one or no elements.
	- sb: Swap the first two elements at the top of stack b. No effect if there is only one or no elements.
	- ss: sa and sb at the same time.
	- pa: Take the first element at the top of stack b and put it at the top of stack a. No effect if stack b is empty.
	- pb: Take the first element at the top of stack a and put it at the top of stack b. No effect if stack a is empty.
	- ra: Shift up all elements of stack a by 1. The first element becomes the last one.
![ra](https://github.com/Mushigarou/push_swap/assets/115739322/01f01932-b8dd-498e-83e9-638466f6921e)
	- rb: Shift up all elements of stack b by 1. The first element becomes the last one.
	- rr: ra and rb at the same time.
	- rra: Shift down all elements of stack a by 1. The last element becomes the first one.
	- rrb: Shift down all elements of stack b by 1. The last element becomes the first one.
	- rrr: rra and rrb at the same time.

## push_swap Program

- The push_swap program is responsible for sorting the stack a using the given operations. It takes the stack a as an argument, formatted as a list of integers. The first argument should be at the top of the stack.

- The program will display the smallest list of instructions possible to sort the stack a, with the smallest number at the top. Instructions are separated by a newline character (\n).

- The goal is to sort the stack with the lowest possible number of operations. If the program displays a longer list or if the numbers are not sorted properly, the grade will be 0.

- If no parameters are specified, the program will not display anything and return to the prompt. In case of an error, it will display "Error" followed by a newline character (\n) on the standard error.

### Example usage:
```
$> make
$> ./push_swap 2 1 3 6 5
sa
pb
pb
rra
sa
pa
pa
```

## Checker Program

The checker program is used to validate the sorting performed by push_swap. It takes the stack a as an argument, formatted as a list of integers. The first argument should be at the top of the stack.

- After receiving the stack and the instructions on the standard input, the program executes the instructions on the stack.
- If, after executing the instructions, stack a is sorted in ascending order and stack b is empty, the program will display "OK" followed by a newline character (\n) on the standard output.
- In all other cases, it will display "KO" followed by a newline character (\n) on the standard output.

In case of an error, it will display "Error" followed by a newline character (\n) on the standard error.

### Example usage:
```
$> make bonus
$> ./push_swap 2 1 3 6 5 | ./checker 2 1 3 6 5
OK
```
- The checker program accepts `-v` as a flag, the program will print the content of both stacks after each instruction is executed. It also accepts `-V` flag, which will print the stack and the instruction executed.

## Contribution

Contributions to this project are welcome! If you find any issues or have improvements to suggest, please feel free to submit a pull request.
## License

This project is licensed under the MIT License.
