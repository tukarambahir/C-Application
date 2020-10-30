/*
 * StudentClass.h
 *
 *  Created on: 19-Apr-2020
 *      Author: Tukaram
 */

#ifndef STUDENTCLASS_H_
#define STUDENTCLASS_H_

namespace std {

class StudentClass {

public:
	int FormNo;
	string sname;
	int A;
	int B;
    int C;
	string Degree;
	double Dscore;
	int Allowpref;
	string AllowCourseName;
	string AllowCentreId;
	int payment;
	string status;
    //vector<preference> preferences;
	//int reported;
	//string PRN;
public:
	StudentClass();
    StudentClass(int FormNo,string sname,int A,int B,int C,string Degree,double Dscore,int Allowpref,string AllowCourseName,string AllowCentreId,double payment);
	void SetStudentClass(int FormNo,string sname,int A,int B,int C,string Degree,double Dscore,int Allowpref,string AllowCourseName,string AllowCentreId,double payment);
	int Get_formNo();
	int Get_RankA();
	int Get_RankB();
	int Get_RankC();
	string Get_Degree();
	double Get_Dscore();
	int Get_Allowpref();
	string Get_AllowCourseName();
	string Get_AllowCentreId();
	double Get_payment();
	string Get_status();
	//void Collect_prefernces();
	void Set_sname(string& sname);
	void Set_Allowpref(int& Allowpref);
	void Set_AllowCourseName(string& AllowCourseName);
	void Set_AllowCentreId(string& AllowCentreId);
	void Set_payment(int& payment);
	void Set_status(string& status);
	void Display();
	void load_student(vector<StudentClass>& student);
	void save_student(vector<StudentClass>& student);
	~StudentClass();

};





} /* namespace std */

#endif /* STUDENTCLASS_H_ */
