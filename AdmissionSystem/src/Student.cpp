//============================================================================
// Name        : Student.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>
#include "StudentClass.h"
#include "preference.h"
#include "eligibities.h"
#include "Course.h"
#include "Centre.h"
#include "Capacity.h"
#include<algorithm>
using namespace std;
StudentClass s;
preference p;
eligibities e;
eligibities fe;
Course c;
Centre cent;
Capacity cap;
static int PRN=0;
static int lastFormNo;
vector<StudentClass> student;
vector<preference> preferences;
vector<Course> courses;
vector<Capacity> capacities;
vector<Centre> centres;
vector<eligibities> eligibility;
vector<eligibities> FormNo_resp_eligibility;
vector<Centre> FormNo_resp_Centres;
vector<vector<int>> PRN_FormNO;
vector<string> section_courses;
vector<int> Prefereces_count_by_formNo;
preference preferences_as_per_student_formNo;
vector<preference> preferences_as_per_student_formNo_vector;


bool compare_by_RankA(StudentClass s,StudentClass s1)
{
	return s.Get_RankA()<s1.Get_RankA();
}

bool compare_by_RankB(StudentClass s,StudentClass s1)
{
	return s.Get_RankB()<s1.Get_RankB();
}

bool compare_by_RankC(StudentClass s,StudentClass s1)
{
	return s.Get_RankC()<s1.Get_RankC();
}



void check_eligibity(vector<StudentClass>& student,vector<eligibities>& eligibility)
{
	for(unsigned i=0;i<eligibility.size();i++)
	{

		for(unsigned j=0;j<student.size();j++)
		{

		}
	}
}


// Linking between student form Number and preferance
void Display_preferences_of_student(int formNo)
{
	for(unsigned i=0;i<preferences.size();i++)
	{
		if(preferences[i].Get_formNo() == formNo)
		{
        cout<<preferences[i].Get_formNo()<<","<<preferences[i].Get_PreferenceNo()<<","<<preferences[i].Get_Course_name()<<","<<preferences[i].Get_Centre_id()<<endl;
		}
	}
};
//for running preferences Loop need no. of preferences given by each student
void Preference_Count_of_Student()
{
	int count;
	for(unsigned i=0;i<student.size();i++)
	{
		count=0;
		for(unsigned j=0;j<preferences.size();j++)
		{
			if(student[i].Get_formNo()==preferences[j].Get_formNo())
			{
				count++;
			}
		}
		Prefereces_count_by_formNo.push_back(count);
	}

};

//adding vector to course of course-capacity link
void Course_Capacity_link(vector<Course>& courses,vector<Capacity>& capacities)
{
for(unsigned i=0;i<courses.size();i++)
{
	for(unsigned j=0;j<capacities.size();j++)
	{
		if(courses[i].Get_Course_name()==capacities[j].Get_Course_name())
		{
         //courses[i].Set_Vector_joining_course(courses[i].Get_Course_id());
         courses[i].Set_Vector_joining_course(j);
		}
	}
}
};

//adding vector to centre of centre-capacitylink
void  Centre_Capacity_link(vector<Centre>& centres,vector<Capacity> capacities)
{
	for(unsigned i=0;i<centres.size();i++)
	{
		for(unsigned j=0;j<capacities.size();j++)
		{
			if(centres[i].Get_centre_id()==capacities[j].Get_Centre_id())
			{
	         centres[i].Set_Vector_joining_centre(j);
			}
		}
	}
};

string Get_Course_name_for_ExamSec(string Sec)
{
 string A;
	for (unsigned i=0;i<courses.size() && Sec=="A";i++)
	{
        if(Sec==courses[i].Get_Exam_Sec())
        {
        	cout<<courses[i].Get_Course_name()<<endl;
        	return courses[i].Get_Course_name();
        }
	}
	for (unsigned j=0;j<courses.size() && Sec=="B" ;j++)
	{
	     if(Sec==courses[j].Get_Exam_Sec())
	     {
	    	 A=courses[j].Get_Course_name();
	       	section_courses.push_back(A);
	     }

	}
	for (unsigned i=0;i<courses.size() && Sec=="C";i++)
		{
	        if(Sec==courses[i].Get_Exam_Sec())
	        {
	        	cout<<courses[i].Get_Course_name()<<endl;
	        	return courses[i].Get_Course_name();
	        }
		}

	cout<<section_courses[0]<<","<<section_courses[1]<<","<<section_courses[2]<<endl;

	return section_courses[0];
};

bool check_Capacity(string centre_id,string course_name)
{
	int capacity_Check=0,capacity;
	for(unsigned i=0;i<capacities.size();i++)
	{

		// finding in capacity for centre whose capacity to be increased

			if((capacities[i].Get_Centre_id()==centre_id) && (capacities[i].Get_Course_name()==course_name))
			{
				capacity_Check=i;
				//check capacity for FULL condition
				//cout<<"Filled capacity ="<<capacities[capacity_Check].Get_Filled_capacity()<<endl;
				if(capacities[capacity_Check].Get_Filled_capacity()<capacities[capacity_Check].Get_Max_capacity())
				{
					//cout<<"Entered in capacity condition "<<endl;
					capacity=capacities[i].Get_Filled_capacity();
					capacity++;
					capacities[i].Set_Filled_capacity(capacity);
					return 1;
				}
		}
			else
			{
				//cout<<"Capacity index not found "<<endl;
			}
	}
return 0;
};

void Deleting_Round01_prefer_Alogrithm()
{
    string A=" ";
    int B=0;
    int P=-1,C=0;

	//Setting -1 to Payemnt thos who has not paid fees after allowcating centre and setting all student data to default
	for(unsigned i=0;i<student.size();i++)
	{
		if(student[i].Get_Allowpref()!=0)
		{
			student[i].Set_AllowCourseName(A);
			student[i].Set_Allowpref(B);
			student[i].Set_AllowCentreId(A);
			if(student[i].Get_payment()!=11800)
				student[i].Set_payment(P);
			else
				student[i].Set_payment(C);
		}

	}

}

void Delete_Capacity_filled()
{
	int a=0;
	for(unsigned i=0;i<student.size();i++)
		{
			if(capacities[i].Get_Filled_capacity()!=0)
			{
				capacities[i].Set_Filled_capacity(a);
			}
		}
}


void Set_Student_values(int i,int j,int k,string Course_name01)
{
	string Centre_id;
	student[j].Set_Allowpref(k);
	student[j].Set_AllowCourseName(Course_name01);
	Centre_id=preferences[i].Get_Centre_id();
	student[j].Set_AllowCentreId(Centre_id);
	cout<<"Form No "<<student[j].Get_formNo()<<" centre "<<student[j].Get_AllowCentreId()<<" course "<<student[j].Get_AllowCourseName()<<" allocated for His rank A = " <<student[j].Get_RankA()<<" rank B = " <<student[j].Get_RankB()<<" rank C = " <<student[j].Get_RankC()<<endl;

}



void ALlocation_Alogrithm(int i,int j,int k,string Course_name01,string Sec)
{
	string Centre_id;
	//finding student form number corrospondes to preferences to update data in student file
	if(student[j].Get_formNo()== preferences[i].Get_formNo() && (preferences[i].Get_PreferenceNo()==k) && (preferences[i].Get_Course_name()==Course_name01) && (student[j].Get_payment()>=0) && (student[j].Get_Allowpref()==0)  )
	{
		//cout<<"student form No received "<<endl;
		 Centre_id=preferences[i].Get_Centre_id();
		//cout<<Centre_id<<endl;
		if(check_Capacity(Centre_id,Course_name01))//capacity check for corrosponding centre
		{
			Set_Student_values(i,j,k,Course_name01);
		}
	}

}


//find students whose 1st preferance is this course, capacity of center is not full and preference is not yet allocated to the student
//and student fees >= 0

void Search_In_preference_by_Course_name_of_all_student(string Course_name01,string Sec)
{
	for(unsigned k=0;k<student.size();k++)
	{
		//cout<<"Search_In_preference_by_Course_name_of_all_student called"<<endl;
		string Centre_id;
		for(unsigned j=0;j<student.size();j++)
				{
					for(unsigned i=0;i<preferences.size();i++)
							{
								ALlocation_Alogrithm(i,j,k,Course_name01,Sec);
							}
				}
	}
};


void Sec_A_Allocation()
{
	//sort(student.begin(),student.end(),compare_by_RankA);
		//unsigned i=4;
		//1.sorting
		sort(student.begin(),student.end(),compare_by_RankA);
		//student[i].Display();
		//preferences_as_per_student_formNo_vector[i].Display();
		//unsigned j=i+1;
		//Display_preferences_of_student(j);
		//2. Serching of having 1st preference as A sec course
		string Course_name,Sec;
		Sec={"A"};
		Course_name=Get_Course_name_for_ExamSec(Sec);//PG-DGI
		//cout<<Course_name<<endl;
		//3. find students whose 1st preferance is this course, capacity of center is not full and preference is not yet allocated to the student
		//and student fees >= 0
	    Search_In_preference_by_Course_name_of_all_student(Course_name,Sec);
}
void Sec_B_Allocation()
{
	string Course_name,Sec;
	sort(student.begin(),student.end(),compare_by_RankB);
	    	//student[i].Display();
	    	//preferences_as_per_student_formNo_vector[i].Display();
	    	//unsigned j=i+1;
	    	//Display_preferences_of_student(j);
	    	//2. Serching of having 1st preference as A sec course
	    	//string Course_name,Sec;
	    	Sec={"B"};
	    	Course_name=Get_Course_name_for_ExamSec(Sec);//PG-DAC,PG-DMC,PG-DBDA
	    	//cout<<Course_name<<endl;
	    	//3. find students whose 1st preferance is this course, capacity of center is not full and preference is not yet allocated to the student
	    	//and student fees >= 0
	        Search_In_preference_by_Course_name_of_all_student(Course_name,Sec);
	        Search_In_preference_by_Course_name_of_all_student(section_courses[1],Sec);
	        Search_In_preference_by_Course_name_of_all_student(section_courses[2],Sec);

}

void Sec_C_Allocation()
{
	string Course_name,Sec;
    sort(student.begin(),student.end(),compare_by_RankC);
    Sec={"C"};
    Course_name=Get_Course_name_for_ExamSec(Sec);
    Search_In_preference_by_Course_name_of_all_student(Course_name,Sec);
}


//Round 1 Allocation Algorithm
void Round_one_allocation()
{
	vector<string> Sec_Courses;
//Round 1 - A Allocation
//cout<<"Round 1 A called"<<endl;
	Sec_A_Allocation();
//Round 1 - B Allocation
//cout<<"Round 1 B called"<<endl;
	Sec_B_Allocation();
//Round 1 - C Allocation
//cout<<"Round 1 C called"<<endl;
	Sec_C_Allocation();

};
void Round_two_allocation()
{
	vector<string> Sec_Courses;
//Round 1 - A Allocation
//cout<<"Round 1 A called"<<endl;
	Sec_A_Allocation();
//Round 1 - B Allocation
//cout<<"Round 1 B called"<<endl;
	Sec_B_Allocation();
//Round 1 - C Allocation
//cout<<"Round 1 C called"<<endl;
	Sec_C_Allocation();
};
//student login
int find_FornNoAndIndex(double Ad_username,unsigned& index)
{
	for(unsigned i=0; i<student.size(); i++)
	{
		if(Ad_username==student[i].Get_formNo())
		{
			index=i;
			cout<<"checked"<<endl;
			cout<<student[i].Get_formNo()<<", "<<student[i].sname<<endl;
			return student[i].Get_formNo();

		}
	}
	return 1;
}
//Centre Coordinator login

string find_CentreIDAndCoordinatorName(string Co_username,string& CentreID)
{
	for(unsigned i=0;i<centres.size(); i++)
	{
		if(Co_username==centres[i].Get_centre_id())
		{
		    CentreID=centres[i].Get_centre_id();
			//cout<<"checked"<<endl;
			//cout<<centres[i].Get_centre_id()<<", "<<centres[i].Get_Centre_coordinator()<<endl;
			return centres[i].Get_centre_id();

		}
		//cout<<centres[i].Get_centre_id()<<", "<<centres[i].Get_Centre_coordinator()<<endl;
	}
	return "A";
}
//student
void Register_new_student()
{

	int FormNo;
	FormNo=lastFormNo+1;
	string sname;
	int A=0;
	int B=0;
	int C=0;
	string Degree;
	double Dscore;
	int Allowpref=0;
	string AllowCourseName="";
	string AllowCentreId="";
	int payment=0;
	string status="";
	cout<<"Enter the student Name "<<endl;
	cin>>sname;
	cout<<"Enter Degree "<<endl;
	cin>>Degree;
	cout<<"Enter the Degree Score "<<endl;
	cin>>Dscore;
	//StudentClass s(FormNo,sname,A,B,C,Degree,Dscore,Allowpref,AllowCentreId,payment);
	//student.push_back(s);

	}

int signIn(int choice,int& formNo,string& CentreID)
{
	int valid,l;
	unsigned index;
	string m;
	int St_username=0;
	int St_password=0;
	double Ad_username=0;
	string Ad_password="";
	string Co_username="";
	string Co_password="";
	switch(choice)
	{
	case 1:
			do   //studentform Number to link
			{
			 cout<<"Enter the Username = "<<endl;
			 cin>>St_username;
			 cout<<"Enter the password = "<<endl;
			 cin>>St_password;
			 l=find_FornNoAndIndex(St_username,index);
			}while(St_password!=l);
			formNo=index;
			valid =1;
			break;

	case 2:
			do//Admin Number to link
			{
				cout<<"Enter the Username = "<<endl;
				cin>>Ad_username;
				cout<<"Enter the password = "<<endl;
				cin>>Ad_password;
			}while(Ad_username!=1234 && Ad_password!="admin");
			valid =2;
			break;
	case 3:
		     do//Cetre coordinator to link
		     {
		    	 cout<<"Enter the Username = "<<endl;
				 cin>>Co_username;
				 cout<<"Enter the password = "<<endl;
				 cin>>Co_password;
				 m=find_CentreIDAndCoordinatorName(Co_username,CentreID);
				 cout<<m;
		     }while(Co_password!=m);
		     CentreID=m;
		     valid =3;
		     break;
	}
	return valid;
}

//student
void Display_Eligibility_for_respStudent(int formNo)
{
	string courseName;
	string DregreeName;
	double Minpercentage;
	int k=formNo;
	//int l=-1;
	for(unsigned i=0; i<eligibility.size(); i++)
	{
		//l=-1;
		if(student[k].Get_Degree()==eligibility[i].Get_Degree() && (student[k].Get_Dscore()>=eligibility[i].Get_minPercentage()))
		{
			eligibility[i].Display();

			//l=k;
		}
		/*if(l==k)
		{
			courseName=eligibility[i].Get_Course_name();
			DregreeName=eligibility[i].Get_Degree();
			Minpercentage=eligibility[i].Get_minPercentage();
			FormNo_resp_eligibility[i].Set_Course_name(courseName);
			FormNo_resp_eligibility[i].Set_Degree(DregreeName);
			FormNo_resp_eligibility[i].Set_minPercentage(Minpercentage);
		}
		else
		{
			courseName="";
			DregreeName="";
			Minpercentage=0;
			FormNo_resp_eligibility[i].Set_Course_name(courseName);
			FormNo_resp_eligibility[i].Set_Degree(DregreeName);
			FormNo_resp_eligibility[i].Set_minPercentage(Minpercentage);
		}*/
	}
}
//student
void Display_Centres_for_respStudent(int formNo)
{
	int k=formNo;
	for(unsigned i=0; i<eligibility.size(); i++)
		{

			if(student[k].Get_Degree()==eligibility[i].Get_Degree() && (student[k].Get_Dscore()>=eligibility[i].Get_minPercentage()))
			{

			    cout<<"Course Name= "<<eligibility[i].Get_Course_name()<<endl;
				for(unsigned j=0; j<capacities.size(); j++)
				{
					if(capacities[j].Get_Course_name()==eligibility[i].Get_Course_name())
					{
						capacities[j].Get_Centre_id();
						for(unsigned k=0; k<centres.size(); k++)
						{
							if(capacities[j].Get_Centre_id()==centres[k].Get_centre_id())
								centres[k].Display();

						}	}		}	}	}	}
//below student  preference allowcation --centre id
string select_EligibilecentreID_name(int formNo,string courseName)
{
	int k=formNo;
	int index,input;
		cout<<"Course Name= "<<courseName<<endl;
				for(unsigned j=0; j<capacities.size(); j++)
				{
					if(capacities[j].Get_Course_name() ==courseName )
					{
			            index=j;
						cout<<index<<"\t Centre ID ="<<capacities[j].Get_Centre_id()<<endl;
					}
				}
	    cout<<"Enter the index number of the centreID to select = "<<endl;
	    cin>>input;

		return capacities[input].Get_Centre_id();

}

//done
//below student  preference allowcation --course Name
string select_EligibileCourse_name(int formNo)
{
	int k=formNo;
	int index;
	int input;
		for(unsigned i=0; i<eligibility.size(); i++)
			{

				if(student[k].Get_Degree()==eligibility[i].Get_Degree() && (student[k].Get_Dscore()>=eligibility[i].Get_minPercentage()))
				{
					index=i;
					cout<<index<<"\t#Course Name= "<<eligibility[i].Get_Course_name()<<endl;

				}
			}
		cout<<"Enter the index number of the centre to select = "<<endl;
		cin>>input;

	return eligibility[input].Get_Course_name();
}
//student
void Give_preferences(int formNo)
{
	int count;
	string courseName;
	string centreID;
	cout<<"current preferences ="<<endl;
	for(unsigned i=0; i<preferences.size(); i++)
	{
		if(preferences[i].Get_formNo()==formNo)
		{
			preferences[i].Display();
			count=preferences[i].Get_PreferenceNo();
		}
	}
	courseName=select_EligibileCourse_name(formNo);
	centreID=select_EligibilecentreID_name(formNo,courseName);
	if(count<10)
	{
		count++;
		preference p(formNo,count,courseName,centreID);
		preferences.push_back(p);
	}
	else
		cout<<"preferences count exceeded"<<endl;
}
//student
void See_allocated_CentreCourse(int formNo)
{
	for(unsigned i=0; i<student.size(); i++)
	{
		if(student[i].Get_formNo()==formNo)
			student[i].Display();
	}

}

//student
void Update_payemnt_Details(int formNo)
{
	int k=formNo;
	int payment=11800;
		for(unsigned i=0; i<student.size(); i++)
		{
			if(student[i].Get_formNo()==k)
				student[i].Set_payment(payment);
		}
}

//admin
void Display_Eligibility()
{
	for(unsigned i=0; i<eligibility.size(); i++)
		eligibility[i].Display();
}

//admin
void Display_Capacity()
{
	for(unsigned i=0; i<capacities.size(); i++)
		capacities[i].Display();
}
//admin
void Display_Student()
{
	for(unsigned i=0; i<student.size(); i++)
	{
			student[i].Display();
			lastFormNo=student[i].Get_formNo();
	}

}
//admin
void List_allowcated_student()
{
	//Round_one_allocation();
	//Deleting_Round01_prefer_Alogrithm();
	//Delete_Capacity_filled();
	//Round_two_allocation();
	for(unsigned i=0; i<student.size(); i++)
		if((student[i].Get_Allowpref()!=0))
			student[i].Display();
}
//admin
void Generate_PRN()
{
	vector<int> row(1);//size taken for 50 rows 2 coulm
	unsigned i, j;
	for(i=0; i<250; i++)
		PRN_FormNO.push_back(row);
	for(unsigned i=0; i<student.size(); i++)
	{
		if(student[i].Get_status()!="")
		{
			PRN_FormNO[i].push_back(PRN);
			PRN++;
		}
	}
}
//admin
void List_reported_students()
{
	for(unsigned i=0; i<student.size(); i++)
	{
		if(student[i].Get_status()!="")
			student[i].Display();
	}
}
//admin
void List_paid_student()
{

	for(unsigned i=0; i<student.size(); i++)
		if((student[i].Get_payment()!=0))
			student[i].Display();
}
//admin
void List_Admitted_students_resp_centre()
{
	for(unsigned j=0; j<centres.size(); j++)
	{
		cout<<"Centre ID = "<<centres[j].Get_centre_id()<<endl;
		for(unsigned i=0; i<student.size(); i++)
		{
			if((student[i].Get_status()!="" && centres[j].Get_centre_id()==student[i].Get_AllowCentreId() ))
				student[i].Display();
		}
	}
}

//centre Coordinstor
void List_Courses_Centre(string CentreID)
{
	for(unsigned i=0; i<capacities.size(); i++)
	{
		if(CentreID==capacities[i].Get_Centre_id())
			capacities[i].Display();
	}

}
//centre Coordinator
void List_students_Allocated_to_centre(string CentreID)
{
	Round_one_allocation();
	Deleting_Round01_prefer_Alogrithm();
	Delete_Capacity_filled();
	Round_two_allocation();
	for(unsigned i=0; i<student.size(); i++)
		if((student[i].Get_Allowpref()!=0 && (student[i].Get_AllowCentreId()==CentreID)))
			student[i].Display();

}
//centre Coordinator
void Update_reported_status(string CentreID)
{
	int formNo;
	string R="Reported";
	cout<<"Enter the formNo which reported at centre"<<endl;
	cin>>formNo;
	for(unsigned i=0; i<student.size(); i++)
		if((student[i].Get_Allowpref()!=0 && (student[i].Get_AllowCentreId()==CentreID) && (student[i].Get_formNo()==formNo)))
		{
			student[i].Set_status(R);
		}
}
//centre coordinator
void List_admitted_students_with_PRN(string CentreID)
{
	for(unsigned i=0; i<student.size(); i++)
			if((student[i].Get_Allowpref()!=0) && (student[i].Get_AllowCentreId()==CentreID) && (student[i].Get_status()!=""))
			{
				student[i].Display();
				cout<<"\nPRN NO = "<<PRN_FormNO[student[i].Get_formNo()][1]<<endl;
			}
}

int main() {
	setvbuf(stdout,NULL,_IONBF,0);
	unsigned i;
	s.load_student(student);
	p.load_preference(preferences);
	Preference_Count_of_Student();
	//load preferences into student class;
	//s.Collect_prefernces(preferences);
	e.load_eligibility(eligibility);
	//Linking Between Course and centre
	c.load_course(courses);
	cent.load_centre(centres);
	cap.load_capacity(capacities);
	//-------------------------------------------------------------------------




	int choice=1,entry=0;
	int formNo;
	string CentreID;
		while(choice!=0)
		{
			cout<<"Enter Choice to Procced : "<<endl;
			cout<<"0.Exit"<<endl;
			cout<<"1.Student"<<endl;
			cout<<"2.Admin"<<endl;
			cout<<"3.CenterCoordinator"<<endl;
			cin>>choice;
			if(choice ==1)
			{
					while(choice!=0)
					{
						cout<<"Enter Choice "<<endl;
						cout<<"0.Exit"<<endl;
						cout<<"1.Register New Student"<<endl;
						cout<<"2.Sign In "<<endl;
						cin>>choice;
						if(choice == 1)
						{

							Register_new_student();
							//Enter data of new Student Entry;
							//a. Register new student (Append student data at the end of Students.csv)
							//Add Break at the end to stop going ahead
						}
						else if( choice == 2)
						{
							choice =1;
							entry=signIn(choice,formNo,CentreID);
							while(choice!=0)
							{

								cout<<"Enter Choice to Execute Student Menu : "<<endl;
								cout<<"0.Exit"<<endl;
								cout<<"1.List courses (as per eligibility) "<<endl;
								cout<<"2.List centers "<<endl;
								cout<<"3.Give preferences "<<endl;
								cout<<"4.See allocated center/course"<<endl;
								cout<<"5.Update payment details"<<endl;
								cin>>choice;
								switch(choice)
								{
									//b. Sign in
								case 1:
									//c. List courses (as per eligibility)
									Display_Eligibility_for_respStudent(formNo);
									break;
								case 2:
									//d. List centers
									Display_Centres_for_respStudent(formNo);
									break;
								case 3:
									//e. Give preferences (Allowed to give preference only if the student is eligible for that
									Give_preferences(formNo);
									p.save_preferences(preferences);
									break;
								case 4:
									//f. See allocated center/course
									See_allocated_CentreCourse(formNo);
									break;
								case 5:
									//g. Update payment details
									Update_payemnt_Details(formNo);
									break;
								}
							}
						}
					}
					choice=1;
			}
			else if(choice== 2)
			{
				entry=signIn(choice,formNo,CentreID);
				while(choice!=0)
				{

					 cout<<"Enter Choice to Execute Admin Menu : "<<endl;
					 cout<<"0.Exit"<<endl;
					 cout<<"01.List courses & eligibilities"<<endl;
					 cout<<"02.List centers & capacities "<<endl;
					 cout<<"03.List students "<<endl;
					 cout<<"04.Update student ranks "<<endl;
					 cout<<"05.Allocate centers (Round 1) "<<endl;
					 cout<<"06.Allocate centers (Round 2) "<<endl;
					 cout<<"07.List allocated students"<<endl;
					 cout<<"08.List paid students "<<endl;
					 cout<<"09.List reported (at center) students"<<endl;
					 cout<<"10.Generate PRN"<<endl;
					 cout<<"11.List admitted students (with PRN) for given center"<<endl;
					 cin>>choice;
					 switch(choice)
					 {
						 //a. Sign in (username & password: admin)
						 case 1:
							 //b. List courses & eligibilities
								Display_Eligibility();
								break;
						 case 2:
							//c. List centers & capacities
							 Display_Capacity();
							 break;
						 case 3:
							//d. List students
							 Display_Student();
							 break;
						 case 4:
							 //e. Update student ranks---------------
						 case 5:
							//f. Allocate centers (Round 1)
							 Round_one_allocation();
							 break;
						 case 6:
							//g. Allocate centers (Round 2)
							 Deleting_Round01_prefer_Alogrithm();
							 Delete_Capacity_filled();
							 Round_two_allocation();
							 break;
						 case 7:
							 //h. List allocated students
							 List_allowcated_student();
							 break;
						 case 8:
							//i. List paid students
							 List_paid_student();
							 break;
						 case 9:
							//j. List reported (at center) students
							 List_reported_students();
							 break;
						 case 10:
							//k. Generate PRN
							 Generate_PRN();
							 break;
						 case 11:
							//l1. List admitted students (with PRN) for given center
							List_Admitted_students_resp_centre();
							 break;
					 }
				}
				choice=2;
			}
			else if(choice ==3)
			{
				entry=signIn(choice,formNo,CentreID);
				while(choice!=0)
				{

					 cout<<"Enter Choice to Centre Coordinator  Menu : "<<endl;
					 cout<<"0.Exit"<<endl;
					 cout<<"1.List courses (of that center) "<<endl;
					 cout<<"2.List students (allocated to that center) "<<endl;
					 cout<<"3.Update reported status "<<endl;
					 cout<<"4.List admitted students (with PRN) "<<endl;
					 cin>>choice;
					 switch(choice)
					 {
						//a. Sign In
						 case 1:
							//b. List courses (of that center)
							 List_Courses_Centre(CentreID);
							 break;
						 case 2:
							//c. List students (allocated to that center)
							 List_students_Allocated_to_centre(CentreID);
							 break;
						 case 3:
							//d. Update reported status
							 Update_reported_status(CentreID);
							 break;

						 case 4:
							//e. List admitted students (with PRN)
							 List_admitted_students_with_PRN(CentreID);
							 break;
					 }
				}
				choice=3;
			}
		}









	//--------------------------------------------------------------------------------
	//Read_file();

	Course_Capacity_link( courses,capacities);
	Centre_Capacity_link( centres,capacities);


    /*cout<<"Loading student CSV "<<endl;
		for(i=0; i<student.size(); i++)
			student[i].Display();
*/




	/*cout<<"Loading student CSV "<<endl;
	 		for(i=0; i<student.size(); i++)
	 			student[i].Display();*/

	/*cout<<"Loading courses CSV "<<endl;
		for(i=0; i<courses.size(); i++)
				courses[i].Display_with_Vector()*/;
	/*cout<<"Loading capacities CSV "<<endl;
			*/
	/*cout<<"Loading centre CSV "<<endl;
			for(i=0; i<centres.size(); i++)
	     			centres[i].Display_with_Vector();
	*///check_eligibity(student,eligibility);
	//Allowcation_preferences(student,preferences);
			s.save_student(student);
	return 0;
}
