/*
 * Course.h
 *
 *  Created on: 20-Apr-2020
 *      Author: Tukaram
 */

#ifndef COURSE_H_
#define COURSE_H_

namespace std {

class Course {
private:
	int Course_id;
	string Course_name;
	double Course_fees;
	string Exam_sec;
	vector<int> joining_course;// vector for connecting Course ID and centre Id;
public:
	Course();
	Course(int Course_id,string Course_name,double Course_fees,string Exam_sec);
	void load_course(vector<Course>& courses);
	int Get_Course_id();
	string Get_Course_name();
	string Get_Exam_Sec();
	void Set_Vector_joining_course(int num);
	void Display_with_Vector();
	void Display();

	~Course();
};

} /* namespace std */

#endif /* COURSE_H_ */
