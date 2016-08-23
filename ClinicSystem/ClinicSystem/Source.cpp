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
//    CLASS NAME : patient
//*******************************************************

/***************************************************************************
Main Function
*************************************************************************/
void main()
{
	cout << "*****************************************************************" << endl;
	cout << "                    WElcome to clinical System project " << endl;
	cout << "******************************************************************" << endl;

	char s;
	patient obj;

z:
	fstream f;
	f.open("patient.txt", ios::in | ios::out );
	cout << "\n\t 1 . Enter Patient Data";
	cout << "\n\t 2 . View  Patient Data";
	cout << "\n\t 3 . Modify Patient Data";
	cout << "\n\t 4 . Search Patient Data";
	cout << "\n\t 5 . Exit ";
	int a;    // The user's selection
	cout << "\n\n\n\tEnter your Choice:";
	f.seekg(0);
	cin >> a;
	char x;
	switch (a)
	{
		//*******************************************************
		//                     ADD A PATIENT RECORD
		//*******************************************************
	case 1:

		f.open("patient", ios::in | ios::out | ios::ate | ios::app | ios::binary);
		char ans;
		obj.patientdata();
		f.write((char *)&obj, sizeof(obj));
		cout << "Do You Want To Continue? y/n  :";
		cin >> ans;
		if (ans == 'Y' || ans == 'y')
			goto z;    //unconditional jump statement
		else
			break;
		//*******************************************************
		//    CASE       : 2
		//    DETAILS    : TO SHOW ALL patient RECORDS
		//*******************************************************
	case 2:
	{
		cout << "\n\n";
		fstream f;
		f.open("patient", ios::in | ios::out | ios::ate | ios::app | ios::binary);
		// cout<<"\n\n";
		char ans;
		f.seekg(0);
		int ctr = 0;
		while (f.read((char *)&obj, sizeof(obj)))
		{
			ctr = ctr + 1;
			if (ctr == 8)
			{
				getchar();

				ctr = 0;
			}
			obj.showdata();
			if (f.eof() == 1)
			{
				break;
			}
		}
		f.close();
		cout << "Do You Want To Continue? y/n :";
		cin >> ans;
		if (ans == 'y' || ans == 'Y')
			goto z;
		else
		{

			exit(1);
		}
	}
	break;
	//===========================================================
	//                           Case 3
	//============================================================
	case 3:
	{

		 char ans;
		fstream f;
		patient obj;
		string name;
		long int phone;
		int pat_id;
		f.open("patient", ios::in | ios::binary);
		cout << "\n";
		cout << "\n ******************************************************************************\n";
		cout << "\n                  Edit Patient  Data       \n";
		cout << "\n ******************************************************************************\n";
		cout << "\n Enter Patient Name  :";
		cin >> name;
		do
		{
			f.read((char *)&obj, sizeof(obj));
			if (f.eof() == 1)  
			{ 
				break; 
			}
			if (obj.name == name)
			{
				cout << "\n\tPatient Name :" << obj.name;
				cout << "\n\tPatient ID : " << obj.pat_id;
				cout << "\n\tPatient Phone :" << obj.phone;
				getchar();
				cout << endl;
				cout << endl;
				cout << "\n \t      Enter New Data";
				cout << "\n\n\tEnter  Patient name : ";
				cin >> name;
				cout << "\n\tEnter Patient ID : ";
				cin >> pat_id;
				cout << "\n\tEnter Patient Phone :";
				cin >> phone;
				cout << "\n\n";
				obj.name = name;
				obj.a = a;
				int l = f.tellg();
				f.close();
				f.open("patient", ios::out | ios::binary | ios::ate);
				f.seekg(l - sizeof(obj));
				f.write((char *)&obj, sizeof(obj));
			}
		} while (f);
		f.close();
		cout << "Do You Want To Continue?y/n :";
		ans = getchar();
		if (ans == 'Y' || ans == 'y')
		{
			goto z;
		}
		else
			break;
	}
	//******************************************************
	//            Case 4    Searching The Patient From Database
	//******************************************************
	case 4:
	{

		// char ans;
		fstream f;
		patient obj;
		char name[20];
		long int phone;
		int pat_id;
		f.open("patient", ios::in | ios::binary);
		cout << "\n";
		cout << "\n ******************************************************************************\n";
		cout << "\n                  Search Patient  Data       \n";
		cout << "\n ******************************************************************************\n";
		cout << "\n Enter Patient Name  :";
		cin >> name;
		do
		{
			f.read((char *)&obj, sizeof(obj));
			if (f.eof() == 1) { break; }
			if (obj.name == name)
			{
				cout << "\n\tPatient Name :" << obj.name;
				cout << "\n\tPatient ID : " << obj.pat_id;
				
				cout << "\n\tPatient Phone :" << obj.phone;
				getchar();
				cout << endl;
				obj.name = name;
				obj.a = a;
				int l = f.tellg();
				f.close();
				f.open("patient", ios::out | ios::binary | ios::ate);
				f.seekg(l - sizeof(obj));
				//f.write((char *)&obj,sizeof(obj));
			}
			else
			{
				cout << "\n\n\Patient Does Not Exist\n\n\n";
			}
		} while (f);
		f.close();
		cout << "\n\nDo You Want To Continue?y/n :";
		ans = getchar();
		if (ans == 'Y' || ans == 'y')
		{
			goto z;
		}
		else
			break;
	}
	/*    Exit  */
	case 5:
	{
		exit(1);
	}
	default:
	{
		cout << "\n\tWrong input \n";
	}
	cout << "\n\tDo You Want To Continue?y/n :";
	ans = getchar();

	if (ans == 'Y' || ans == 'y')
	{
		goto z;
	}
	else
		break;
	}

}