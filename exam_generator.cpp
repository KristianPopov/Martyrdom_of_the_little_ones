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

void num_generator(int diff,unsigned int &a){
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
       }
       else{
          a = rand();
       }
}


int main(){

  return 0;
}
