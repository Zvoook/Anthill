#pragma once
#include "Employee.h"
class Manager:Employee {
public:
	struct Subordinater {
		Employee* employee;
		string work;
		Date deadline;
		Date finish_time;
	};
	Manager(const string& s1, const string& s2, const Date& emp, const Date& unemp) :Employee(s1,s2,emp,unemp) {};
	void add_sub(Employee* emp);
	void assignTask(Employee* emp, const string& task, const Date& ft, const Date& dd);
	void completeTask(Employee* emp, bool onTime);
	bool allTasksCompleted() const;
	void give_bonus();
private:
	vector <Subordinater> subs;
	bool is_bonused;
};