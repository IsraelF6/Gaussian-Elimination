# Gaussian-Elimination


Write a subroutine that takes as input n, A, and b, and then outputs x where x solves Ax = b. 
n is an integer. A is a n × n two dimensional array of type double, b is a n × 1 one dimensional 
array of type double, and x is a n × 1 one dimensional array of type double. Test your subroutine on 
the systems from problem 1. Also test your subroutine on the n × n matrix system defined as follows:

A[i,j] =  4 if i = j,
	−1 if j = i + 1,
	−1 if j = i − 1,
	0 otherwise

b[i] =  1 if i is odd,
	0 otherwise

----------------------------------------------------------------------------------

Also write a subroutine that takes as inputs n,A, x, and b, and then
outputs r where r is the residual r = b − Ax. n is an integer. A is a n × n
two dimensional array of type double, b is a n × 1 one dimensional array
of type double, x is a n × 1 one dimensional array of type double, and r
is a n × 1 one dimensional array of type double.
