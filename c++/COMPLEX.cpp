#include <iostream>

using namespace std;

template <typename T>
class Complex;

template <typename T>
ostream& operator<<(ostream& os,Complex<T>& C){
  os<<C.real<<"+ i"<<C.img;
}

template <typename T>
class Complex{
public:
  Complex<T>(T real,T img);
  Complex<T>& operator+(Complex<T>& C);
  Complex<T>& operator=(Complex<T>& C);
  friend ostream& operator<< <T>(ostream& os,Complex& C);
  
  T real;
  T img;
};

template <typename T>
Complex<T>::Complex(T real, T img){
  this->real=real;
  this->img=img;
}

template <typename T>
Complex<T>& Complex<T>::operator+(Complex<T>& C){
  this->real+=C.real;
  this->img+=C.img;
}

template <typename T>
Complex<T>& Complex<T>::operator=(Complex<T>& C){
  this->real=C.real;
  this->img=C.img;
}


int main() {
  Complex<int> c(1,1);
  cout<<c<<endl;
  Complex<int> b(2,3);
  Complex<int> a(0,0);
  a=c+b;
  cout<<a<<'\t'<<b<<'\t'<<c<<endl;
}

