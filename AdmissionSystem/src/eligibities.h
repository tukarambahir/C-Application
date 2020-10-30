/*
 * eligibities.h
 *
 *  Created on: 19-Apr-2020
 *      Author: Tukaram
 */

#ifndef ELIGIBITIES_H_
#define ELIGIBITIES_H_

namespace std {

class eligibities {
private:
	string Course_name;
	string Degree;
	double minPercentage;
public:
	 eligibities();
	 eligibities(const string Course_name,const string Degree,const double minPercentage);
	 void load_eligibility(vector<eligibities>& eligibility);
	 void Display();
	 void Set_Course_name(string courseName);
	 void Set_Degree(string degree);
	 void Set_minPercentage(double Minpercentage);
	 string Get_Course_name();
	 string Get_Degree();
	 double Get_minPercentage();
	 ~eligibities();
};

} /* namespace std */

#endif /* ELIGIBITIES_H_ */
