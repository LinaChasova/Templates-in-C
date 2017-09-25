/*
Write a template for the function fib() that accepts no arguments. Template
parameter takes an integer value N that is used to start calculating the
Fibonacci number. The function returns the integer value: the sum of values
returned by two templates instantiated using N-1 and N-2. See lecture
slides for reference.

1. The name of the function must be precisely fib().
2. Do template specialization for N=1 that returns 1
3. Do template specialization for N=2 that returns 1
4. Write a template for the class Fib that has the single public method fib().
    The functionality for this method is the same as for fib() in step 1.
5. Do full class template specialization for N=1 where the public method fib()
    returns 1
6. Do full class template specialization for N=2 where the public method fib()
    returns 1
7. Do not include additional libraries here

We may test your implementation by calling:
  fib<10>();
  Fib<10> a; a.fib();

Make sure that the names for the function template, the class template and
for the class method match the requirements. Failure to comply with these
requirements will result in failure during compilation and the assignment
receiving the score of 0.
*/

template <unsigned N>	//counts the fibonacci number recursively
int fib(void)
{
	return fib<N - 1>() + fib<N - 2>();
};

template<>	//specified function, in order for the main function to terminate
int fib<1>(void)
{
	return 1;
};

template<>	//specified function, in order for the main function to terminate
int fib<2>(void)
{
	return 1;
};

template <unsigned N>	//class that counts the fibonacci number recursively
class Fib
{
public:
	int fib(void)	//the only function of the class
	{
		Fib <N - 1> a;	//creates new object of this class with argument N - 1
		Fib <N - 2> b;	//creates new object of this class with argument N - 2
		return a.fib() + b.fib();	//makes the recursive counting
	}
};

template <>	//specified class, in order for the main class to terminate
class Fib <1>
{
public:
	int fib(void)
	{
		return 1;
	}
};

template <>	//specified class, in order for the main class to terminate
class Fib <2>
{
public:
	int fib(void)
	{
		return 1;
	}
};
