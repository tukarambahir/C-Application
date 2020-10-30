/*
 * preference.cpp
 *
 *  Created on: 19-Apr-2020
 *      Author: Tukaram
 */

#include<string>
#include <iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include "preference.h"

namespace std {
preference::preference()
{
this->formNo=0;
this->PreferenceNo=0;
this->Course_name="";
this->Center_id="";
}
preference::preference(int formNo,int PreferenceNo,string Course_name,string Center_id)
	{
		this->formNo=formNo;
		this->PreferenceNo=PreferenceNo;
		this->Course_name=Course_name;
		this->Center_id=Center_id;
	}
void preference::load_preference(vector<preference>& preferences)
{
	ifstream fn("preferences.csv");
	string line;
	int i;
	if(!fn)
		cerr<<"preferences file not opened"<<endl;
	else
		//cout<<"preferences file opened "<<endl;

	i=0;
	while(getline(fn,line))
	{
		string tokens[4];
		stringstream str(line);
		for(int j=0; j<4; j++)
	       getline(str, tokens[j], ',');
       preference p(stoi(tokens[0]),stoi(tokens[1]),tokens[2],tokens[3]);
       preferences.push_back(p);
		i++;
	}
	fn.close();
}


void preference::save_preferences(vector<preference>& preferences)
 {
	 ofstream fout("New_preferences.csv",ios::out);
	 string line;
	 if(!fout)
		 cerr<<"New preferences file not opened"<<endl;
	 else
		 cout<<"New preferences file created "<<endl;;
	 for(unsigned i=0;i<preferences.size();i++)
	 {
		 fout<<preferences[i].formNo<<","<<preferences[i].PreferenceNo<<","<<preferences[i].Course_name<<","<<preferences[i].Center_id<<endl;
	 }
 }



int preference::Get_formNo()
{
	return this->formNo;
}
int preference::Get_PreferenceNo()
{
 return this->PreferenceNo;
}
string preference::Get_Course_name()
{
	return this->Course_name;
}
string preference::Get_Centre_id()
{
	return this->Center_id;
}


void preference::Set_formNo(int formNo)
{
 this->formNo=formNo;
}
void preference::Set_PreferenceNo(int PreferenceNo)
{
 this->PreferenceNo=PreferenceNo;
}
void preference::Set_Course_name(string Course_name)
{
	this->Course_name=Course_name;
}
 void preference::Set_Centre_id(string Centre_id)
{
	this->Center_id=Center_id;
}



void preference::Display()
{
	cout<<"\n"<<this->formNo<<","<<this->PreferenceNo<<","<<this->Course_name<<","<<this->Center_id<<endl;
}

preference::~preference()
{
}

} /* namespace std */
