#include<iostream>
#include<cmath>
using namespace std;

#define PI 3.14159265

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		friend ComplexNumber operator+(double,const ComplexNumber &);
		friend ComplexNumber operator-(double,const ComplexNumber &);
		friend ComplexNumber operator*(double,const ComplexNumber &);
		friend ComplexNumber operator/(double,const ComplexNumber &);
		friend ostream & operator<<(ostream &os,const ComplexNumber &);
		friend bool operator==(const ComplexNumber &,const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber((real*c.real) - (imag*c.imag),(imag*c.real) + (real*c.imag));
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	return ComplexNumber(((real*c.real)+(imag*c.imag))/(pow(c.real,2)+pow(c.imag,2)),((real*c.imag)-(imag*c.real))/(pow(c.real,2)+pow(c.imag,2))*(-1));
}

ComplexNumber operator+(double s,const ComplexNumber &c){
	return ComplexNumber(s+c.real,c.imag);
}

ComplexNumber operator-(double s,const ComplexNumber &c){
	return ComplexNumber(s-c.real,-c.imag);
}

ComplexNumber operator*(double s,const ComplexNumber &c){
	return ComplexNumber(s*c.real,s*c.imag);
}

ComplexNumber operator/(double s,const ComplexNumber &c){
	return ComplexNumber(s*c.real/(pow(c.real,2)+pow(c.imag,2)),s*c.imag/(pow(c.real,2)+pow(c.imag,2))*(-1));
}

bool operator==(const ComplexNumber &c,const ComplexNumber &d){
	if(d.real == c.real and d.imag == c.imag){
		return true;
	}
	else{
		return false;
	}
}

double ComplexNumber::abs(){
	return sqrt(pow(real,2) + pow(imag,2));
}

double ComplexNumber::angle(){
	return atan2(imag,real) * 180 / M_PI;
}

ostream & operator<<(ostream &os,const ComplexNumber &c){
	if(c.real == 0 and c.imag != 0){
		return os <<c.imag<<"i";
    }
	else if(c.real != 0 and c.imag == 0){
		return os <<c.real;
	}
	else if(c.imag == 0 and c.real == 0){
		return os <<0;
	}
	else if(c.real != 0 and c.imag<0){
		return os <<c.real<<c.imag<<"i";
	}
	else{
		return os <<c.real<<"+"<<c.imag<<"i";
	}
}