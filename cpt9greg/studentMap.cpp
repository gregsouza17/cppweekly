#include <iostream>
#include <string>
#include <vector>

struct StudentGrade{
  std::string name;
  char grade;  
};

class GradeMap{
private:
  std::vector<StudentGrade> m_map;

public:
  GradeMap() {}

  char& operator[](const std::string &name);
  
};


int main(){

  GradeMap grades;
  grades["Joe"] = 'A';
  grades["Frank"] = 'B';
  std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
  std::cout << "Frank has a grade of " << grades["Frank"] << '\n';
 
  return 0;

}

char& GradeMap::operator[](const std::string &name){
  //If we found a name in the map, we return a reference to the grade
  //If we don't, we create a new key with the name input and reference the new avaiable
  //grande in the map
  
  for(auto &ref:m_map){
    if(name==ref.name){
      return ref.grade;
    }
  }

  StudentGrade temp{ name,' '};
  m_map.push_back(temp);
  
  return m_map.back().grade;
  
}
  

