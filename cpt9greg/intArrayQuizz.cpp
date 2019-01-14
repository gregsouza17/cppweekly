#include <iostream>
#include <cassert>

class IntArray{
private:
  int m_length;
  int *m_values=nullptr;

public:

  //Regular Constructor
  IntArray(int length){

    assert(length>0 && "IntArray length should be positive!!!11");
    
    m_length=length;

    m_values = new int[m_length]{0};
    
  }

  //Copy Constructor
  IntArray(const IntArray &array): m_length(array.m_length)
  {
    //Delete old values
    delete[] m_values;

    //Reallocate values
    m_values = new int[m_length] {0};

    for(int i=0; i<m_length; i++)
      m_values[i] = array.m_values[i];
  }

  //Destructor
  ~IntArray(){
    delete[] m_values;
  }

  int& operator[](const int index);

  friend  std::ostream& operator<<(std::ostream &out, const IntArray &array);
  
  
};


IntArray fillArray()
{
  IntArray a(5);
  a[0] = 5;
  a[1] = 8;
  a[2] = 2;
  a[3] = 3;
  a[4] = 6;
 
  return a;
}
 
int main()
{
  IntArray a = fillArray();
  std::cout << a << '\n';
 
  IntArray b(1);
  a = a;
  b = a;
	
  std::cout << b << '\n';
	
  return 0;
}


int& IntArray::operator[](const int index){
  
  assert(index>=0 && index<m_length && "Index out of range");
  
  return m_values[index];
  
}


std::ostream& operator<<(std::ostream &out, const IntArray &array){
  
  std::cout << "Array(";
  
  for(int i=0; i < array.m_length ; i++)
      std::cout<< array.m_values[i] << ",";
  
  std::cout <<")";
  
  return out;
  
}
