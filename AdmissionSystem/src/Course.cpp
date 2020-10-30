/*
 * Course.cpp
 *
 *  Created on: 20-Apr-2020
 *      Author: Tukaram
 */
#include<string>
#include <iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<map>
#include "Course.h"

namespace std {
Course::Course()
{
		this->Course_id=0;
		this->Course_name="";
		this->Course_fees=0;
		this->Exam_sec=" ";
}

Course::Course(int Course_id,string Course_name,double Course_fees,string Exam_sec)
	{
			this->Course_id=Course_id;
			this->Course_name=Course_name;
			this->Course_fees=Course_fees;
			this->Exam_sec=Exam_sec;
	}

void Course::load_course(vector<Course>& courses)
{
	ifstream fn("courses.csv",ios::in);
	    			string line;
	    			int i;
	    			if(!fn)
	    			{
	    				cerr<<"Courses file not found "<<endl;
	    				return;
	    			}
	    			else
	    				cout<<"Courses file opened"<<endl;
	    			    i=0;
	    				while(getline(fn, line)) {
	    					string tokens[4];
	    					stringstream str(line);
	    					for(int j=0; j<4; j++)
	    					   getline(str, tokens[j], ',');

	    					Course c(stoi(tokens[0]),tokens[1],stod(tokens[2]),tokens[3]);
	    					courses.push_back(c);
	    					i++;

	    				}
	    				fn.close();

}

int Course::Get_Course_id()
{
	return this->Course_id;
}

string Course::Get_Course_name()
{
  return this->Course_name;
}
string Course::Get_Exam_Sec()
{
	return this->Exam_sec;
}

void Course::Display()
{
	cout<<this->Course_id<<","<<this->Course_name<<","<<this->Course_fees<<","<<this->Exam_sec<<endl;

}
void Course::Display_with_Vector()
{
	cout<<this->Course_id<<","<<this->Course_name<<","<<this->Course_fees<<","<<this->Exam_sec;
  //display Vector
	for(unsigned i=0;i<this->joining_course.size();i++)
	{
		cout<<","<<this->joining_course[i];
	}
	cout<<endl;
}




void Course::Set_Vector_joining_course(int num)
{
	this->joining_course.push_back(num);
}


Course::~Course()
{

}

} /* namespace std */
