/*
 * Capacity.cpp
 *
 *  Created on: 20-Apr-2020
 *      Author: Tukaram
 */
#include<string>
#include <iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include "Capacity.h"

namespace std {
    Capacity::Capacity()
    {
    	this->Center_id="";
    	this->Course_name="";
    	this->Max_capacity=0;
    	this->Filled_capacity=0;
    }
    Capacity::Capacity(string Center_id,string Course_name,int Max_capacity,int Filled_capacity)
    {
    	this->Center_id=Center_id;
    	this->Course_name=Course_name;
    	this->Max_capacity=Max_capacity;
    	this->Filled_capacity=Filled_capacity;
    }

    void Capacity::load_capacity(vector<Capacity>& capacities)
		{
			ifstream fn("capacities.csv",ios::in);
		    string line;
			int i;
			if(!fn)
			{
				cerr<<"Capacities file not found "<<endl;
				return;
			}
			else
				cout<<"Capacities file opened";
			     i=0;
				while(getline(fn, line)) {
					string tokens[4];
					stringstream str(line);
					for(int j=0; j<4; j++)
						getline(str, tokens[j], ',');

					Capacity c(tokens[0],tokens[1],stoi(tokens[2]),stoi(tokens[3]));
					capacities.push_back(c);
					i++;

				}
				fn.close();

	}
	void Capacity::Display()
	{
		cout<<this->Center_id<<","<<this->Course_name<<","<<this->Max_capacity<<","<<this->Filled_capacity<<endl;

	}

	string Capacity::Get_Course_name()
	{
		return this->Course_name;
	}

	string Capacity::Get_Centre_id()
	{
		return this->Center_id;
	}
	int Capacity::Get_Max_capacity()
	{
		return this->Max_capacity;
	}

	int Capacity::Get_Filled_capacity()
	{
		return this->Filled_capacity;
	}

	void Capacity::Set_Filled_capacity(int Filled_capacity )
	{
		this->Filled_capacity=Filled_capacity;
	}

	Capacity::~Capacity()
		{

		}


} /* namespace std */
