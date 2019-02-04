#include<iostream>
#include<string>
using namespace std;

class rectangle
{
private:
	int width;
	int length;
public:
	int getwidth()const;
	int getlength()const;
	void setlength(int l);
	void setwidth(int w);
	int getarea()const;
	void rotaterectangle();
	void draw();





};