/*
 * preference.h
 *
 *  Created on: 19-Apr-2020
 *      Author: Tukaram
 */

#ifndef PREFERENCE_H_
#define PREFERENCE_H_

namespace std {

class preference {
private:
	//vector<StudentClass> student;
	int formNo;
	int PreferenceNo; //(1, 2, 3, …, 10)
	string Course_name;
	string Center_id;
public:
	preference();
	preference(int formNo,int PreferenceNo,string Course_name,string Center_id);
	void load_preference(vector<preference>& preferences);
	int Get_formNo();
	int Get_PreferenceNo();
	string Get_Course_name();
	string Get_Centre_id();
	void Set_formNo(int formNo);
	void Set_PreferenceNo(int PreferenceNo);
	void Set_Course_name(string Course_name);
	void Set_Centre_id(string Centre_id);
	void save_preferences(vector<preference>& preferences);

	void Display();
	~preference();
};

} /* namespace std */

#endif /* PREFERENCE_H_ */
