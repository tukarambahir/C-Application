/*
 * Centre.cpp
 *
 *  Created on: 20-Apr-2020
 *      Author: Tukaram
 */
#include<string>
#include <iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include "Centre.h"

namespace std {

Centre::Centre()
{
	this->Centre_id="";
	this->Centre_name="";
	this->Centre_addrs="";
	this->Centre_coordinator="";
	this->Centre_password="";
}
Centre::Centre(string Centre_id,string Centre_name,string Centre_addrs,string Centre_coordinator,string Centre_password)
{
	this->Centre_id=Centre_id;
	this->Centre_name=Centre_name;
	this->Centre_addrs=Centre_addrs;
	this->Centre_coordinator=Centre_coordinator;
	this->Centre_password=Centre_password;
}
void Centre::load_centre(vector<Centre>& centres)
{
	ifstream fn("centers.csv",ios::in);
    string line;
	int i;
	if(!fn)
	{
		cerr<<"Centres file not found "<<endl;
		return;
	}
	else
		cout<<"Centres file opened";
	     i=0;
		while(getline(fn, line)) {
			string tokens[5];
			stringstream str(line);
			for(int j=0; j<5; j++)
				getline(str, tokens[j], ',');

			Centre c(tokens[0],tokens[1],tokens[2],tokens[3],tokens[4]);
			centres.push_back(c);
			i++;

		}
		fn.close();

}

void Centre::Set_Vector_joining_centre(int num)
{
	this->joining_centres.push_back(num);
}

string Centre::Get_centre_id()
{
	return this->Centre_id;
}
string Centre::Get_Centre_coordinator()
{
	return this->Centre_coordinator;
}

void Centre::Display()
{
	cout<<this->Centre_id<<","<<this->Centre_name<<","<<this->Centre_addrs<<","<<this->Centre_coordinator<<","<<this->Centre_password<<endl;

}

void Centre::Display_with_Vector()
{
	cout<<this->Centre_id<<","<<this->Centre_name<<","<<this->Centre_addrs<<","<<this->Centre_coordinator<<","<<this->Centre_password;
  //display Vector
	for(unsigned i=0;i<this->joining_centres.size();i++)
	{
		cout<<","<<this->joining_centres[i];
	}
	cout<<endl;
}


} /* namespace std */
