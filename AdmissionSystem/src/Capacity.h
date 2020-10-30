/*
 * Capacity.h
 *
 *  Created on: 20-Apr-2020
 *      Author: Tukaram
 */

#ifndef CAPACITY_H_
#define CAPACITY_H_

namespace std {

class Capacity {
private:
	string Center_id;
	string Course_name;
	int Max_capacity;
	int Filled_capacity;
public:
	Capacity();
	Capacity(string Center_id,string Course_name,int Max_capacity,int Filled_capacity);
	void load_capacity(vector<Capacity>& capacities);
	void Display();
	string Get_Course_name();
	string Get_Centre_id();
	int Get_Max_capacity();
	int Get_Filled_capacity();
	void Set_Filled_capacity(int Filled_capacity);
	~Capacity();
};

} /* namespace std */

#endif /* CAPACITY_H_ */
