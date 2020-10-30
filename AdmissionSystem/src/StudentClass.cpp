/*
 * StudentClass.cpp
 *
 *  Created on: 19-Apr-2020
 *      Author: Tukaram
 */
#include<string>
#include <iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include "StudentClass.h"
namespace std {

StudentClass::StudentClass()
	{
		this->FormNo=0;
		this->sname="N";
		this->A=0;
		this->B=0;
		this->C=0;
		this->Degree="BE";
		this->Dscore=0.0;
		this->Allowpref=0;
		this->AllowCourseName="";
		this->AllowCentreId="";
		this->payment=0.0;

	}
StudentClass::StudentClass(int FormNo,string sname,int A,int B,int C,string Degree,double Dscore,int Allowpref,string AllowCourseName,string AllowCentreId,double payment)
	{
		this->FormNo=FormNo;
		this->sname=sname;
		this->A=A;
		this->B=B;
		this->C=C;
		this->Degree=Degree;
		this->Dscore=Dscore;
		this->Allowpref=Allowpref;
		this->AllowCourseName=AllowCourseName;
		this->AllowCentreId=AllowCentreId;
		this->payment=payment;
		this->status=status;
	}
void StudentClass::SetStudentClass(int FormNo,string sname,int A,int B,int C,string Degree,double Dscore,int Allowpref,string AllowCourseName,string AllowCentreId,double payment)
		{
			this->FormNo=FormNo;
			this->sname=sname;
			this->A=A;
			this->B=B;
			this->C=C;
			this->Degree=Degree;
			this->Dscore=Dscore;
			this->Allowpref=Allowpref;
			this->AllowCourseName=AllowCourseName;
			this->AllowCentreId=AllowCentreId;
			this->payment=payment;
		}
int StudentClass::Get_formNo()
{
	return this->FormNo;
}

int StudentClass::Get_RankA()
	{
		return this->A;
	}
int StudentClass::Get_RankB()
		{
			return this->B;
		}
int StudentClass::Get_RankC()
		{
			return this->C;
		}

/*
void StudentClass::Collect_prefernces(vector<preference>& preferences)
{
	for(unsigned i=0;i<prefrences.size();i++)
	{

	}
}
*/


 void StudentClass::Display()
  {
 cout<<"\n"<<this->FormNo<<","<<this->sname<<",\t\t\t\t"<<this->A<<","<<this->B<<","<<this->C<<",\t\t"<<this->Degree<<","<<this->Dscore<<",\t"<<this->Allowpref<<",\t"<<this->AllowCourseName<<","<<this->AllowCentreId<<","<<this->payment<<",\t"<<this->status<<endl;
  }

  void StudentClass::load_student(vector<StudentClass>& student)
    {
    		ifstream fn("students.csv",ios::in );
    			string line;
    			int i;
    			if(!fn)
    			{
    				cerr<<"file not found "<<endl;
    				return;
    			}
    			else
    				//cout<<"student file opened";

    			    i=0;
    				while(getline(fn, line)) {
    					string tokens[11];
    					stringstream str(line);
    					for(int j=0; j<11; j++)
    					   getline(str, tokens[j], ',');

    					StudentClass s(stoi(tokens[0]),tokens[1],stoi(tokens[2]),stoi(tokens[3]),stoi(tokens[4]),tokens[5],stod(tokens[6]),stoi(tokens[7]),tokens[8],tokens[9],stod(tokens[10]));
    					student.push_back(s);
    					i++;

    				}
    				fn.close();

    }

 void StudentClass::save_student(vector<StudentClass>& student)
 {
	 ofstream fout("New_students.csv",ios::out);
	 string line;
	 if(!fout)
		 cerr<<"New Student file not opened"<<endl;
	 else
		 cout<<"New Student file created "<<endl;;
	 for(unsigned i=0;i<student.size();i++)
	 {
		 fout<<student[i].FormNo<<","<<student[i].sname<<","<<student[i].A<<","<<student[i].B<<","<<student[i].C<<","<<student[i].Degree<<","<<student[i].Dscore<<","<<student[i].Allowpref<<","<<student[i].AllowCourseName<<","<<student[i].AllowCentreId<<","<<student[i].payment<<","<<student[i].status<<endl;
	 }
 }
 string StudentClass::Get_Degree()
 {
	 return this->Degree;
 }
 double StudentClass::Get_Dscore()
 {
	 return this->Dscore;
 }

 int StudentClass::Get_Allowpref()
  {
	  return this->Allowpref;
  }
 double StudentClass::Get_payment()
 {
	 return this->payment;
 }
 string StudentClass::Get_AllowCourseName()
 {
	 return this->AllowCourseName;
 }
 string StudentClass::Get_AllowCentreId()
 {
	 return this->AllowCentreId;
 }
 string StudentClass::Get_status()
 {
	return this->status;
 }
 void StudentClass::Set_sname(string& sname)
 {
	 this->sname=sname;
 }

 void StudentClass::Set_Allowpref(int& Allowpref)
   {
 	 this->Allowpref=Allowpref;
   }
 void StudentClass::Set_AllowCourseName(string& AllowCourseName)
 {
	this->AllowCourseName=AllowCourseName;
 }
 void StudentClass::Set_AllowCentreId(string& AllowCentreId)
  {
 	this->AllowCentreId=AllowCentreId;
  }
 void StudentClass::Set_payment(int& payment)
    {
  	 this->payment=payment;
    }
 void StudentClass::Set_status(string& status)
 {
	 this->status=status;
 }

 StudentClass::~StudentClass()
  {
  }


} /* namespace std */
