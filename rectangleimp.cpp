# include "rectangle.h"
# include <iostream>
# include <string>
using namespace std;

// this function takes the input of width and set it to the class member width
void rectangle::setwidth(int w)
{
	do
	{
		cout << "Enter the width of rectangle" << endl;
		cin >> w;
	} while (w < 0);
	width = w;

}

// this fuction set the the length of the rectangle
 void rectangle::setlength(int l)
{
	 do
	 {
		 cout << "Enter the lenngth of rectangle" << endl;
		 cin >> l;
	 } while (l < 0);
		 length = l;

}

 //this function returs the length of the rectangle
 int rectangle::getlength()const
 {
	 return length;
 }

 //this function returns the width
 int rectangle::getwidth()const
 {
	 return width;
 }
 
 //this function returns the area of the rectangle
 int rectangle::getarea()const
 {
	 return (length*width);
 }

 //this function prints the rectangle
 void rectangle::draw()
 {
	 for (int i = 0; i < length; i++)
	 {
		 for (int j = 0; j < width; j++)
		 {
			 cout << "*";

		 }
		 cout << endl;
	 }

 }

 //this function swaps length to with and vice versa
 void rectangle::rotaterectangle()
 {
	 int temp = 0;
	 temp = width;
	 width = length;
	 length = temp;

 }