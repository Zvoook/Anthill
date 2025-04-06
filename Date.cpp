//#include "Date.h"
//Date::Date(){
//	auto t = time(NULL);
//	auto date = localtime(&t);
//	day = date->tm_mday;
//	month = date->tm_mon + 1;
//	year = date->tm_year + START;
//}
//Date::Date(int d, int m, int y) {
//	year = y;
//	if (m < 13 && m > 0) {
//		month = m;
//		switch (m) {
//		case 1:case 3:case 5:case 7:case 8:case 10:case 12:
//			if (d > 0 && d < 32) day = d;
//			else { Date(); break; }
//		case 2:
//			if (d > 0 && d < 30 && isLeap(d)) day = d;
//			else if (d > 0 && d < 29 && !isLeap(d)) day = d;
//			else { Date(); break; }
//		case 4:case 6:case 9:case 11:
//			if (d > 0 && d < 31) day = d;
//			else { Date(); break; }
//		}
//	}
//	else Date();
//}
//Date::Date(const char* s) {
//	int d = (s[0] - '0') * 10 + (s[1] - '0');
//	int m = (s[3] - '0') * 10 + (s[4] - '0');
//	int y = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0');
//	year = y;
//	if (m > 0 && m < 13) month = m;
//	switch (m) {
//	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
//		if (d > 0 && d < 32) day = d;
//		else { Date(); break; }
//	case 2:
//		if (d > 0 && d < 30 && isLeap(y)) day = d;
//		else if (d > 0 && d < 29 && isLeap(y)) day = d;
//		else { Date(); break; }
//	case 4:case 6:case 9:case 11:
//		if (d > 0 && d < 31) day = d;
//		else { Date(); break; }
//	}
//}
//bool Date::isLeap(int y)
//{
//	return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
//}
//void Date::print_Date()
//{
//	cout << day << '.' << month << '.' << year << endl;
//}
//void Date::replace(int d, int m, int y)
//{
//	if (y > 0) year = y;
//	if (m > 0 && m < 13) month = m;
//	switch (month) {
//	case 1:case 3:case 5:case 7:case 8:case 10:case 12:if (day > 0 && day <= 31) { day = d; break; }
//	case 2:if (day > 1 && day<=29) { day = d; break; }
//	case 4:case 6:case 9:case 11:if (day > 1 && day<=30) { day = d; break; }
//	}
//}
//
//void Date::balancing()
//{
//	bool flag = 0;
//	while (!flag) {
//		flag = 1;
//		if (month < 1 || month > 12) flag = 0;
//		switch (month) {
//		case 1:case 3:case 5:case 7:case 8:case 10:case 12:if (day < 1 || day > 31) flag=0;
//		case 2:
//			if (day < 1 || (day > 29 && isLeap(year))) flag = 0;
//			else if (day < 1 || (day > 28 && !isLeap(year))) flag = 0;
//		case 4:case 6:case 9:case 11:if (day < 1 || day > 30) flag = 0;
//		}
//	}
//	if (month > 12) {
//		year += (int)(month / 12);
//		month %= 12;
//	}
//	switch (month) {
//	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
//		if (day > 31) {
//			month += (int)(day / 31);
//			day %= 31;
//		}
//	case 4:case 6:case 9:case 11:
//		if (day > 30) {
//			month += (int)(day / 30);
//			day %= 30;
//		}
//	case 2:
//		if (day > 29 && isLeap(year)) {
//			month += (int)(day / 29);
//			day %= 29;
//		}
//		else if (day > 28 && !isLeap(year)) {
//			month += (int)(day / 28);
//			day %= 28;
//		}
//	}
//}
//void Date::operator+(int x)
//{
//	day += x;
//	balancing();
//}
//void Date::operator-(int x)
//{
//	day -= x;
//	balancing();
//}
//unsigned Date::operator-(const Date& date)
//{
//	unsigned res = abs(day - date.day);
//	if (isLeap(year)) res += abs(year - date.year) * 366;
//	else res += abs(year - date.year) * 365;
//	int n = month, k = 0;
//	while (n > 0) {
//		switch (n) {
//		case 1:case 3:case 5:case 7:case 8:case 10:case 12:	k += 31;
//		case 4:case 6:case 9:case 11: k += 30;
//		case 2:
//			if (isLeap(year)) k += 29;
//			else if (!isLeap(year)) k += 28;
//		}
//		n--;
//	}
//	int p = 0, n = date.month;
//	while (n > 0) {
//		switch (n) {
//		case 1:case 3:case 5:case 7:case 8:case 10:case 12:	p += 31;
//		case 4:case 6:case 9:case 11: p += 30;
//		case 2:
//			if (isLeap(date.year)) p += 29;
//			else if (!isLeap(date.year)) p += 28;
//		}
//		n--;
//	}
//	res += abs(k - p);
//	return res;
//}
//void Date::operator++()
//{
//	day++;
//	balancing();
//}
//void Date::operator--()
//{
//	day--;
//	balancing();
//}
//bool Date::operator>(const Date& date)
//{
//	return year > date.year || (year == date.year && month > date.month) || (day > date.day && year == date.year && month == date.month);
//}
//bool Date::operator<(const Date& date)
//{
//	return year < date.year || (year == date.year && month < date.month) || (day < date.day && year == date.year && month == date.month) ;
//}
//bool Date::operator==(const Date& date)
//{
//	return day == date.day && month == date.month && year == date.year;
//}
//bool Date::operator!=(const Date& date)
//{
//	return day != date.day || month != date.month || year != date.year;
//}
//ostream& operator<<(ostream& out, const Date& date) {
//	out << date.get_day() << "." << date.get_month() << "." << date.get_year();
//	return out;
//}
//istream& operator>>(istream& in, Date& date) {
//	int d, m, y;
//	char s1, s2;
//	in >> d >> s1 >> m >> s2 >> y;
//	if (s1 == '.' && s2 == '.') {
//		date = Date(d, m, y);
//	}
//	return in;
//}