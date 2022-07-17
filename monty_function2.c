#include "monty.h"

/**
 * op_add - adds top 2 nodes of the stack
 * @stack: double pointer to top of stack
 * @line_number: value of node
 * Return: nothing
 **/
void op_add(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	op_pop(stack, line_number);
	(*stack)->n += tmp;
}

/**
 * op_nop - doesn't do anything
 * @stack: double pointer to top of stack
 * @line_number: value of node
 * Return: nothing
 **/
void op_nop(stack_t **stack, unsigned int line_number)
{
}

/**
 * op_sub - substracts top node from second top node
 * @stack: double pointer to top of stack
 * @line_number: value of node
 * Return: nothing
 **/
void op_sub(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	op_pop(stack, line_number);
	(*stack)->n -= tmp;
}

/**
 * op_div - divides second top node from top node
 * @stack: double pointer to top of stack
 * @line_number: value of node
 * Return: nothing
 **/
void op_div(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	if (tmp == 0)
	{
		printf("L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	op_pop(stack, line_number);
	(*stack)->n /= tmp;
}

/**
 * op_mul - multiplies second top node from top node
 * @stack: double pointer to top of stack
 * @line_number: value of node
 * Return: nothing
 **/
void op_mul(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	op_pop(stack, line_number);
	(*stack)->n *= tmp;
}
