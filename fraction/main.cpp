#include<iostream>
#include "Fraction.h"
using namespace std;

int main() {
	Fraction one;
	one.setNum(2);
	one.setDenom(3);
	one.print();

	Fraction two;
	two.setNum(5);
	two.setDenom(7);
	two.print();

	(one.mult(two)).print();
	Fraction three = one.mult(two);  // 10/21
	cout << "multiplicating fraction one and two: " << one.getNum() << "/" << one.getDenom() << " and "
		<< two.getNum() << " / " << two.getDenom() << " it will be : " << three.getNum()<<"/"<<three.getDenom() << endl;

	Fraction four(46, 23);
	four.print();
	
	cout << "Redution fraction four:"<< four.getNum()<<"/"<<four.getDenom()<< " it has greatest common divider :"
		<<four.gcd(four.getNum(), four.getDenom()) << " after redution it will be : " << endl;
	four.fractionReduction();
	four.print(); //2/1
	
	Fraction five = one.add(four);
	cout << "Adding fraction one and fraction four:" << one.getNum() << "/" << one.getDenom() << " + "
		<< four.getNum() << "/" << four.getDenom() << " = " << five.getNum() << "/" << five.getDenom() << endl;
	
	Fraction six = two.add(5);
	cout << "Adding fraction two and integer \"5\" :" << two.getNum() << "/" << two.getDenom() << " + "
		<< " \"5\"" << " = " << six.getNum() << "/" << six.getDenom() << endl;

	Fraction seven = four.subtraction(one);
	cout << "Subtraction fraction one and fraction four:" << four.getNum() << "/" << four.getDenom() << " - "
		<< one.getNum() << "/" << one.getDenom() << " = " << seven.getNum() << "/" << seven.getDenom() << endl;

	Fraction eight = two.mult(3);
	cout << "Multiplicating fraction two with integer \"3\" :" << two.getNum() << "/" << two.getDenom() << " * "
		<< " \"3\"" << " = " << eight.getNum() << "/" << eight.getDenom() << endl;

	Fraction nine = one.division(four);
	cout << "Division fraction one and fraction four:" << one.getNum() << "/" << one.getDenom() << " : "
		<< four.getNum() << "/" << four.getDenom() << " = " << nine.getNum() << "/" << nine.getDenom() << endl;

	cout << "Checking if fraction one and fraction four are equal? " << one.getNum() << "/" << one.getDenom() << " and "
		<< four.getNum() << "/" << four.getDenom() << " are (1 if equal, 0 if not): "<< one.equalOrNot(four) << endl;


}


// ctor with 2 params, ctor with 1 param cascade
// main() - test of ctors



// * - видео про ссилки і поінтери