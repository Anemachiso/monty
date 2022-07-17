#include "monty.h"

/**
 * op_push - adds elements to a stack
 * @stack: pointer to the first node/element in a stack
 * @line_number: the line within the stuck
 * Return: nothing
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *op;
	int num;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: stack not found\n", line_number);
		exit(EXIT_FAILURE);
	}
	op = strtok(NULL, DELIMS);
	if (operand == NULL || _atoi(operand, &n) == -1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(*stack);
		exit(EXIT_FAILURE);
	}
	num = _strtol(op, line_number);
	new->next = *stack;
	new->prev = NULL;
	new->n = num;

	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 *op_pall - prints the data of all nodes in a stack
 *@stack: pointer to the head node pointer
 *@line_number: the line number
 *Return: void
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;
	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 *op_pint -  prints the value at the top of the stack, followed by a new line
 *@stack: pointer to the head node pointer
 *@line_number: the line number
 *Return: void
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	printf("%d\n", temp->n);
}

/**
 * instruction_pop - removes top element of stack
 * @stack: double pointer to the first node
 * @line_number: value of new node
 * Return: nothing
 */
void instruction_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	node  = *stack;
	(*stack) = (*stack)->next;
	free(node);
}

/**
 * instruction_swap - swaps 2 elements of the stack
 * @stack: double pointer to the first node
 * @line_number: value of new node
 */
void instruction_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)(line_number);
	if (!(*stack) || !((*stack)->next))
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	if (tmp->next)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack) = (*stack)->prev;
}
