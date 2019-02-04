// 180965_question2_lab3.cpp : Defines the entry point for the console application.
//

#include "rectangle.h"
#include <iostream>
using namespace std;


int main()
{
	rectangle data;
	int length_of_rectangle = 0;
	int width_of_rectangle = 0;
	// setting the length of the rectangle by taking input from the user
	data.setlength(length_of_rectangle);
	//settinf the wifth of the rectangle by taking input from the user
	data.setwidth(width_of_rectangle);
	cout << endl;
	cout << "printing the rectangle " << endl;
	data.draw();
	cout << endl;
	cout << "The length of the rectangle is " << data.getlength() << endl;
	cout << "The width of the rectangle is " << data.getwidth ()<< endl;
	cout<<"The area of the reactangle is "<<data.getarea()<<endl<<endl;
	// this call to function swaps the width and the length of the rectangle
	data.rotaterectangle();
	cout << "The length of the rectangle is after swaping=  " << data.getlength() << endl;
	cout << "The width of the rectangle is after swaping= " << data.getwidth() << endl;
	cout << endl;
	cout << "The rectangle after swaping length by with and vice versa is as follows::" << endl;
	data.draw();
    return 0;
}

