/*
 * Centre.h
 *
 *  Created on: 20-Apr-2020
 *      Author: Tukaram
 */

#ifndef CENTRE_H_
#define CENTRE_H_

namespace std {

class Centre {
private:
	string Centre_id;
	string Centre_name;
	string Centre_addrs;
	string Centre_coordinator;
	string Centre_password;
	vector<int> joining_centres;
public:
  Centre();
  Centre(string Centre_id,string Centre_name,string Centre_addrs,string Centre_coordinator,string Centre_password);
  void load_centre(vector<Centre>& centres);
  void Set_Vector_joining_centre(int num);
  string Get_centre_id();
  string Get_Centre_coordinator();
  void Display_with_Vector();
  void Display();

};

} /* namespace std */

#endif /* CENTRE_H_ */
