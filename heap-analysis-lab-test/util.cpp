#include "util.hpp"
#include<iostream>
#include<cstdio>

int dummy(int a, int b){
    std::cout << "I do nothing but add 2 integers "<<  a + b
	      <<". Please get rid of me." << std::endl;
    return 0;
}

int add_ints(int a, int b){
  return (a + b);
}
