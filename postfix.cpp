#include <iostream>
#include <string>
#include <fstream>
#include "stackdbl.h"

using namespace std;

double calculate (string& expr, bool& success){
  double num1 = 0.0;
  double num2 = 0.0;
  char oper = a;
  while (!expr.empty()){
      
    if (oper == '+'){
      num1 += num2;
    }
    else if (oper == '-'){
      num1 = num1 - num2;
    }
    else if (oper == '*')
      num1 = num1 * num2;
    }
    else if (oper == '/'){
      num1 = num1 / num2;
    }

}

int main(int argc, char *argv[]){
  string line;
  bool valid;
  ifstream ifile;
  ifile.open(argv[2]);
  getline (ifile,line);


