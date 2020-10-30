/*
 * eligibities.cpp
 *
 *  Created on: 19-Apr-2020
 *      Author: Tukaram
 */
#include<string>
#include <iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include "eligibities.h"


namespace std{

eligibities::eligibities()
{
	this->Course_name="A";
	this->Degree="B";
	this->minPercentage=0.0;
}
eligibities::eligibities(string Course_name,string Degree,double minPercentage)
{
	this->Course_name=Course_name;
	this->Degree=Degree;
	this->minPercentage=minPercentage;
}
void eligibities::load_eligibility(vector<eligibities>& eligibility)
{
	ifstream fn("eligibilities.csv",ios::in);
	string line;
	int i;
	if(!fn)
		cerr<<"Eligibility file not opened"<<endl;
	else
		//cout<<"Eligibility file opened "<<endl;

	i=0;
	while(getline(fn,line))
	{
		string tokens[3];
		stringstream str(line);
		for(int j=0; j<3; j++)
	       getline(str, tokens[j], ',');
       eligibities e(tokens[0],tokens[1],stod(tokens[2]));
       eligibility.push_back(e);
		i++;
	}
	fn.close();
}
void eligibities::Set_Course_name(string courseName)
{
	this->Course_name=courseName;
}
void eligibities::Set_Degree(string degree)
{
	this->Degree=degree;
}
void eligibities::Set_minPercentage(double Minpercentage)
{
	this->minPercentage=Minpercentage;
}
string eligibities::Get_Course_name()
{
	return this->Course_name;
}

string eligibities::Get_Degree()
{
	return this->Degree;
}

double eligibities::Get_minPercentage()
{
	return this->minPercentage;
}

void eligibities::Display()
{
	cout<<this->Course_name<<","<<this->Degree<<","<<this->minPercentage<<endl;
}


eligibities::~eligibities()
{

}

} /* namespace std */
