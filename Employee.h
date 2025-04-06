#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Date.h"
using namespace std;
class Employee {
private:
	string name, surname;
	Date employ_time, unemploy_time;
	int tabel_number;
	static int count;
	bool bonused;
public:
	Employee(string s1, string s2, Date emp, Date unemp): name(s1), surname(s2), employ_time(emp), unemploy_time(unemp), bonused(false) { tabel_number = count++; }
	void set_name(string n) { name = n; }
	void set_surname(string n) { surname = n; }
	void set_employ_time(Date n) { employ_time=n; }
	void set_unemploy_time(Date n) { unemploy_time=n; }
	void give_bonus() { bonused = true; }

	int print_number() { cout << tabel_number << endl; }
	void print_name() { cout << name << endl; }
	void print_surname() { cout << surname << endl;}
	void print_employ_time() {cout << employ_time << endl;}
	void print_unemploy_time() { cout << unemploy_time << endl; }

	int get_number() const { return tabel_number; }
	string get_name() const { return name; }
	string get_surname() const { return surname; }
	Date get_employ_time() const { return employ_time; }
	Date get_unemploy_time() const { return unemploy_time; }
	bool have_bonus() const { return bonused; }
};