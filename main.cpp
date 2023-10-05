#include <iostream>
#include <vector>
#include <iomanip>



using namespace std;

// AERSP 424 Homework 1: Question 1
// Goal: Write a program to predict roll rate of aircraft
// for up to five seconds and print the result at every time step


int main()
{
	// Design aircraft by picking favorite non-zero real numbers for Lp abd Ldelta

	double Lp = .75; //roll damping coefficient
	double Ldelta = -.25; //aileron effectiveness
	double p_dot; //derivative of roll rate
	int delta; // aileron deflection angle
	double dt = .01; //step size
	double duration = 5; //total time to find roll rate for
	double size = duration / dt + 1; // size of array to get time increments
	double p[502]; //roll rate array
	p[0] = 1; //initial roll rate

	for (int i = 0; i < size; i++)
	{
		double time = dt * i; //total time
		// deflection angle depends on time (=1 if between 0 and 2 seconds, =0 if greater than 2)
		if (time <= 2)
		{
			delta = 1;
		}
		else
		{
			delta = 0;
		};


		p_dot = Lp * p[i] + Ldelta * delta; //calculate derivative of roll rate
		p[i + 1] = p[i] + p_dot * dt; //calculate next roll rate 

		cout << fixed;
		cout << setprecision(2); // prints two decimal points of time and roll rate 
		cout << "When t = " << time << " seconds, the roll rate = " << p[i] << " radians per second" << endl; // prints every result
	}
	return 0;
}