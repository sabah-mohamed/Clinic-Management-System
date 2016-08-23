#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
#include "Patient.h"
using namespace std;

//*******************************************************
//    FUNCTIONS TO GET AND SHOW DATA
//*******************************************************

patient::patient() {
	
}

patient::patient(string n, int id, long int phn, string adrss, time_t date) {
	name = n;
	pat_id = id;
	phone = phn;
	address = adrss;
	dateOfBirth = date;
}
void patient::patientdata()
{
	cout << " *******************************************************************************\n";
	cout << " \n\n\t\t\tCreate New Patient ";
	cout << " *******************************************************************************\n";
	cout << "\nEnter Patient ID : ";
	cin >> pat_id;
	cout << "\nEnter Patient Name : ";
	cin >> name;
	cout << "Enter your address : ";
	cin >> address;
	cout << "Enter your date of birth : ";
	cin >> dateOfBirth;
	cout << "\nEnter Patient Phone  : ";
	cin >> phone;
}
void patient::showdata()
{
	cout << "\nPatient ID\t: " << pat_id;
	cout << "\nPatient Name\t: " << name;
	cout << "\nPatient Phone\t: " << phone;
	cout << "\n\n";
}
