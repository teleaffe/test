// Basic.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include <math.h>
#include <memory>
#include <string>
#include <vector>
#include <forward_list>

using namespace std;

	class Person {

		string Name;
		int16_t Alter;

	public:

		string Get_Name() {
			return this->Name;
		}

		void Set_Name(string n) {
			this->Name = n;
		}

		int16_t Get_Alter() {
			return this->Alter;
		}

		void Set_Alter(int16_t a) {
			this->Alter = a;
		}

		Person(string N, int16_t A) {
			this->Name = N;
			this->Alter = A;
		}

		virtual void Drucke_Attribute() {
			cout << "Name: "<< this ->Get_Name() << endl;
			cout << "Alter: " << this->Get_Alter() << endl;
		}

		virtual string gen_key() = 0;

	};


	class Student : public Person {

		int16_t Matrikelnummer;

	public:
		int16_t  Get_Matrikelnummer() {
			return this->Matrikelnummer;
		}

		void Set_Matrikelnummer(int16_t m) {
			this->Matrikelnummer = m;
		}

		Student(string N, int16_t A, int16_t M)
			: Person(N, A)
		{
			this->Matrikelnummer = M;
		}
		virtual void Drucke_Attribute() override {
			cout << "Name: " << this->Get_Name() << endl;
			cout << "Alter: " << this->Get_Alter() << endl;
			cout << "Matrikelnummer: " << this->Get_Matrikelnummer() << endl;
		}

		virtual string gen_key() override {
			return "Student_" + this->Get_Name();
		}

	};

	class Dozent : public Person {

		string Fach;

	public:

		string Get_Fach() {
			return this->Fach;
		}

		void Set_Fach(string f) {
			this->Fach = f;
		}

		Dozent(string N, int16_t A, string F)
			: Person(N, A)
		{
			this->Fach = F;
		}
		virtual void Drucke_Attribute() override {
			cout << "Name: " << this->Get_Name() << endl;
			cout << "Alter: " << this->Get_Alter() << endl;
			cout << "Fach: " << this->Get_Fach() << endl;
		}

	string gen_key()override {
			return "Dozent_" + this->Get_Name() + "_" + this->Get_Fach();

		}

	};


	class DHBW_Student : public Student {
		string Firma;

	public:
		string Get_Firma() {
			return this->Firma;
		}

		void Set_Firma(string f) {
			this->Firma = f;
		}

		DHBW_Student(string N, int16_t A, int16_t M, string F)
			: Student(N, A, M)
		{
			this->Firma = F;
		}


		virtual void Drucke_Attribute() override {
			cout << "Name: " << this->Get_Name() << endl;
			cout << "Alter: " << this->Get_Alter() << endl;
			cout << "Matrikelnummer: " << this->Get_Matrikelnummer() << endl;
			cout << "Firma: " << this ->Get_Firma() << endl;
		}

		virtual string gen_key() override {
			return "Student_" + this->Get_Name() + "_DH-Stdent";
		}

	};

	class Uni_Student : public Student {
		string Uni;

	public:
		string Get_Uni() {
			return this->Uni;
		}

		void Set_Uni(string u) {
			this->Uni = u;
		}

		Uni_Student(string N, int16_t A, int16_t M, string u)
			: Student(N, A, M)
		{
			this->Uni = u;
		}


		virtual void Drucke_Attribute() override {
			cout << "Name: " << this->Get_Name() << endl;
			cout << "Alter: " << this->Get_Alter() << endl;
			cout << "Matrikelnummer: " << this->Get_Matrikelnummer() << endl;
			cout << "UNI: " << this->Get_Uni() << endl;
		}

		virtual string gen_key() override {
			return "Student_" + this->Get_Name()+"_UNI-Student";
		}
	};



int main()
{
	Uni_Student a("Marcel", 19, 123, "DHBW");
	a.Drucke_Attribute();
//	cout << endl;
	Uni_Student* Uni_ptr = &a;
	//Uni_ptr->Drucke_Attribute();
	cout << endl;

	Person* Pers_ptr = &a;
	//Pers_ptr->Drucke_Attribute();

	Student b("Alex", 24, 456);
	//cout << endl;
	//cout << a.gen_key() << endl;


	Uni_Student x("x", 1, 100, "DHBW");
	DHBW_Student y("y", 2, 200, "DHBW");
	Dozent z("z", 3, "Info");

	vector<Person*> Liste;
	Person* Pers_ptr_a = &a;
	Person* Pers_ptr_b = &b;
	Person* Pers_ptr_x = &x;
	Person* Pers_ptr_y = &y;
	Person* Pers_ptr_z = &z;

	Liste.push_back(Pers_ptr_a);
	Liste.push_back(Pers_ptr_b);
	Liste.push_back(Pers_ptr_x);
	Liste.push_back(Pers_ptr_y);
	Liste.push_back(Pers_ptr_z);

	for (auto i = Liste.begin(); i != Liste.end();i++) {
		(*i)->Drucke_Attribute();
		cout << "key: " << (*i)->gen_key() << endl;
		cout << endl;
	}



	system("pause");
	return 0;
}

