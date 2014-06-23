#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>

using namespace std;

void num_generator(int diff,unsigned int &a,unsigned int &b){
       a = b = 0;
       char temp = 0;
       if(diff<3){
          temp = rand()%6+10;
          if(diff == 2) a = rand()%15+1;
          else if(diff == 1) a = temp;
          a = a <<8;
          if(diff == 2) a+= rand()%15+1;
          else if(diff == 1) a+= temp;          
          a = a <<4;
          b = rand()%16;
       }
       else{
          a = rand();
          b = rand();  
       }
}

void long_num_generator(int diff,unsigned long int &a){
       srand(time(NULL));
       a = 0;
       char temp = 0;
       if(diff<3){
          temp = rand()%6+10;
          if(diff == 2) a = rand()%15+1;
          else if(diff == 1) a = temp;
          a = a <<8;
          if(diff == 2) a+= rand()%15+1;
          else if(diff == 1) a+= temp;          
          a = a <<4;
          if(diff == 2) a = a;
          else if(diff == 1) a = temp;
          a = a <<17;
          if(diff == 2) a+= temp;
          else if(diff == 1) a+= temp;          
          a = a <<9;
       }
       else{
          a = rand()%4294967295+268435456;
       }
}

char operator_generator(){
     char op = rand()%3;
     switch(op){
         case 0: return '&';
         case 1: return '|';
         case 2: return '^';
     }
}

int shift_generator(int diff){
    int shift = 0;
    shift = (rand()%4+1)*2;
    if(diff>2) shift-=1;
    return shift;
}

int main(int argc,char* argv[]){
       srand(time(NULL));
    int diff;
    
    if(argc>1) diff=atoi(argv[1]);
    else diff=rand()%3+1;
    
    unsigned int a,b;
    num_generator(diff,a,b);
    
    cout<<"the difficulty is:"<<diff<<endl<<endl;

    cout<<"exercise 1:\n"
    "a = ?\n int orig = 0x" << hex << a <<
    ";\n int insert = 0x" << hex << b <<
    ";\n int a = orig "<< operator_generator() <<" (insert << "<< shift_generator(diff) << ")\n"<<endl;
    
    cout<<"exercise 2:\n"  
    "AND = ?"<<endl	
    <<"int orig = 0x" <<hex<<a<<";"<<endl
    <<"int insert = 0x" <<hex<<b<<";"<<endl
    <<"int a = orig " << operator_generator() <<" (insert" << operator_generator()<< shift_generator(diff) <<")\n"<<endl
    <<"int b = orig " << operator_generator() <<" (insert" << operator_generator()<< shift_generator(diff) <<")\n"<<endl
    <<"int AND = a & b"<<endl;

       system("pause");
  return 0;
}
