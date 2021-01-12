#include<iostream>
#include "Fraction.h"
using namespace std;


void Fraction::print() const
{
	cout << num << "/" << denom << endl;
}

void Fraction::setDenom(int denom_)
{
	if (denom_ == 0)
	{
		this->denom = 1;
	}
	else if (denom_ < 0) //-1
	{
		this->num *= (-1);
		this->denom *= (-1);
	}
	this->denom = denom_;
}

void Fraction::setNum(int num)
{
	this->num = num;
}

const int Fraction::getDenom() const
{
	return denom;
}

const int Fraction::getNum() const
{
	return num;
}

const int Fraction::gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a% b);
}

void Fraction::fractionReduction()
{
	if (gcd(num, denom) != 1)
	{
		int temp = gcd(num, denom);
		setDenom(denom / temp);
		setNum(num / temp);
	}
}

Fraction Fraction::add(const Fraction& two) const
{
	Fraction result;
	result.num = (this->num * two.denom)+(two.num*this->denom);
	result.denom = this->denom * two.denom;
	result.fractionReduction();
	return result;
}

Fraction Fraction::add(int number) const
{
	Fraction result;
	result.num = this->num + (number * this->denom);
	result.denom = this->denom;
	return result;
}

Fraction Fraction::subtraction(const Fraction& two) const
{
	Fraction result;
	result.num = (this->num * two.denom) - (two.num * this->denom);
	result.denom = this->denom * two.denom;
	result.fractionReduction();
	return result;
}

Fraction Fraction::mult(const Fraction& two) const
{
	Fraction result;
	result.num = this->num * two.num;
	result.denom = this->denom * two.denom;
	result.fractionReduction();
	return result;
}

Fraction Fraction::mult(int number) const
{
	Fraction result;
	result.num = this->num * number;
	result.denom = this->denom;
	result.fractionReduction();
	return result;
}

Fraction Fraction::division(const Fraction& two) const
{
	Fraction result;
	result.num = this->num * two.denom;
	result.denom = this->denom * two.num;
	result.fractionReduction();
	return result;
}

const bool Fraction::equalOrNot(const Fraction& two) const
{
	//Fraction first = (one.num, one.denom);
	//Fraction second = (two.num, two.denom);
	//first.fractionReduction();
	//second.fractionReduction();
	//if (first.num == second.num && first.denom==second.denom)
	//	return true;
	//else
	//	return false;

	Fraction first = (this->num, this->denom);
	Fraction second = (two.num, two.denom);
	first.fractionReduction();
	second.fractionReduction();
	if (first.num == second.num && first.denom == second.denom)
		return true;
	else
		return false;






}

Fraction::~Fraction()
{
}
