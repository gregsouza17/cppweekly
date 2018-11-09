#include <iostream>
#include <cstdint>

class RGBA{
  //Models a Red, Green, Blue, Alpha Channel
private:
  std::uint8_t m_red, m_green, m_blue, m_alpha;

public:
  RGBA(const std::uint8_t &red=0, const std::uint8_t &green=0,
       const std::uint8_t &blue=0, const std::uint8_t &alpha=255):
    m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)  {}

  void print(){
    printf("r = %d g=%d b=%d a=%d \n", m_red, m_green, m_blue, m_alpha);
  }
};

int main(void){
  RGBA teal(0, 127, 127);
  teal.print();
 

  return 0;
}
