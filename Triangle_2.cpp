#include "Triangle_2.h"
Triangle::Triangle(double a, double b, double c)
{
	srand(time(0));
	do {
		a = rand();
		b = rand();
		c = rand();
	} while (!real_Triangle(a, b, c));
	s1 = a; s2 = b; s3 = c;
}
void Triangle::print_Triangle()
{
	cout << "Triangle: " << s1 << ',' << s2 << ',' << s3 << endl;
}
bool Triangle::real_Triangle(double a, double b, double c)
{
	return (a > 0 && b > 0 && c > 0 && (a + b) > c && (a + c) > b && (b + c) > a);
}
void Triangle::type()
{
	if (pow(s1, 2) + pow(s2, 2) == pow(s3, 2) || pow(s1, 2) + pow(s3, 2) == pow(s2, 2) || pow(s3, 2) + pow(s2, 2) == pow(s1, 2)) cout << "Прямоугольный треугольник" << endl;
	else if (pow(s1, 2) + pow(s2, 2) < pow(s3, 2) || pow(s1, 2) + pow(s3, 2) < pow(s2, 2) || pow(s3, 2) + pow(s2, 2) < pow(s1, 2)) cout << "Тупоугольный треугольник" << endl;
	else cout << "Остроугольный треугольник" << endl;
}

bool Triangle::operator<(const Triangle& t)
{
	return s1<t.s1 || s2<t.s2 || s3<t.s3;
}
bool Triangle::operator<=(const Triangle& t)
{
	return s1 < t.s1 || s2 < t.s2 || s3 < t.s3 || (s1==t.s1 && s2==t.s2 && s3==t.s3);
}
bool Triangle::operator>(const Triangle& t)
{
	return s1 > t.s1 || s2 > t.s2 || s3 > t.s3;
}
bool Triangle::operator>=(const Triangle& t)
{
	return s1 > t.s1 || s2 > t.s2 || s3 > t.s3 || (s1 == t.s1 && s2 == t.s2 && s3 == t.s3);
}
bool Triangle::operator==(const Triangle& t)
{
	return s1 == t.s1 && s2 == t.s2 && s3 == t.s3;
}
bool Triangle::operator!=(const Triangle& t)
{
	return s1 != t.s1 || s2 != t.s2 || s3 != t.s3;
}
void Triangle::operator*(double x)
{
	s1 += x;
	s2 *= x;
	s3 *= x;
}
void Triangle::operator/(double x)
{
	s1 /= x;
	s2 /= x;
	s3 /= x;
}
ostream& operator<<(ostream& out, const Triangle& t) {
	out << "Triangle: " << t.get_s1() << ',' << t.get_s2() << ',' << t.get_s3() << endl;
	return out;
}
istream& operator>>(istream& in, Triangle& t) {
	int s1, s2, s3;
	in >> s1 >> s2 >> s3;
	t = Triangle(s1, s2, s3);
	return in;
}