/**
	Date: 10/12/2023
	By: Justin Su
	Purpose: Polynomial.h for Problem #1 of Lab #13
**/
#pragma once
#define MAX_COUNT 100
class Polynomial
{
	public:
		Polynomial();         // Default constructor
		Polynomial(int* coef, int degree);
		Polynomial(const Polynomial& poly); // Copy constructor
		~Polynomial();

		// setters and getters
		void setDegree(int degree);
		void setCoef(int* coef, int degree);
		int getDegree();
		int* getCoef();
		Polynomial& operator=(const Polynomial& rightSide);  // operator =
		friend Polynomial operator+(const Polynomial&, const Polynomial&);
		friend Polynomial operator-(const Polynomial&, const Polynomial&);
	private:
		int* coef;   // dynamic array of coefficients
		int degree;  // degree of a polynomial
};

