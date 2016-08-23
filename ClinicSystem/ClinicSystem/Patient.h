#pragma once
#include<string>
#include<ctime>
class patient
{
public:
	string name;
	int pat_id;
	long int phone;
	string address;
	time_t dateOfBirth;
	

	int a;      // The user's selection
	patient();
	patient(string name, int pat_id, long int phone, string adress, time_t dateOfBirth);
	void patientdata();
	void showdata();



};
