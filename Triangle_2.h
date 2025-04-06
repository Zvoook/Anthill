#pragma once
#include <iostream>
#include <cmath>
#include <random>
using namespace std;

class Triangle {
public:
	Triangle(double s1, double s2, double s3);
	void print_Triangle();
	double P() { return (s1 + s2 + s3); }
	double S() { return sqrt(P() / 2 * ((P() / 2) - s1) * ((P() / 2) - s2) * ((P() / 2) - s3)); }
	void type();

	bool operator<(const Triangle& t);
	bool operator<=(const Triangle& t);
	bool operator>(const Triangle& t);
	bool operator>=(const Triangle& t);
	bool operator==(const Triangle& t);
	bool operator!=(const Triangle& t);
	void operator*(double x);
	void operator/(double x);
	double get_s1() const { return s1; }
	double get_s2() const { return s2; }
	double get_s3() const { return s3; }
private:
	bool real_Triangle(double a, double b, double c);
	double s1, s2, s3;
};

ostream& operator<<(ostream& out, const Triangle& t);
istream& operator>>(istream& in, Triangle& t);