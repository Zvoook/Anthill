#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <time.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define START 1900
#define len 8

class Date {
public:
	Date();
	Date(int d, int m, int y);
	Date(const char* s);
	bool isLeap(int y);
	void print_Date();
	void replace(int, int, int);
	int get_day() const { return day; }
	int get_month() const { return month; }
	int get_year() const { return year; }
	void balancing();

	void operator+(int x);
	void operator-(int x);
	unsigned operator-(const Date& date);
	void operator++();
	void operator--();
	bool operator>(const Date& date);
	bool operator<(const Date& date);
	bool operator==(const Date& date);
	bool operator!=(const Date& date);
private:
	int day, month, year;
};

ostream& operator<<(std::ostream& out, const Date& date);
istream& operator>>(std::istream& in, Date& date);