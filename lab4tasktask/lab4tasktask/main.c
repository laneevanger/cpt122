#include "./lab4.h"

int main(void)
{
	Stack s = stack_create();

	stack_push(&s, 1.0);

	stack_push(&s, 2.0);

	stack_push(&s, 3.0);

	assert(s.size == 3);
	//assert(s.top->data == );

	Stack s = stack_create();
	stack_push(&s, 1.0);

	double result = stack_pop(&s);

	assert(result == 1);


	//stack peak returns top
	{
		//arrange
		Stack s = stack_create();
		stack_push(&s, 1.0);

		//act
		double result = stack_peak(&s);

		//assert
		assert(result == 1.0);
	}

	printf("tests passed");

}