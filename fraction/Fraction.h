#pragma once
class Fraction // ordinary fraction
{
public:
	Fraction() : num(0), denom(1)	
		//список ініціалізації - можна викликати конструктори, можна ініціалізувати поля
	{
	}
	Fraction(int num) : Fraction()
	{
		setNum(num);
	}
	Fraction(int num, int denom) : Fraction(num)
	{
		setDenom(denom);
	}

	void print() const;
	void setDenom(int denom);
	void setNum(int num);// { this->setNum = num; } //inline methods
	const int getDenom() const;
	const int getNum() const;
	const int gcd(int num, int denom);
	void fractionReduction();
	Fraction add(const Fraction & two) const;
	Fraction add(int number) const;
	Fraction subtraction(const Fraction& two) const;
	Fraction mult(const Fraction & two) const; // this(перший дріб) two = другий
	Fraction mult(int number) const;
	Fraction division(const Fraction& two) const;
	const bool equalOrNot(const Fraction& two) const; // this(перший дріб) two = другий


	~Fraction();
private:
	int num=0, denom=1;
	
};

