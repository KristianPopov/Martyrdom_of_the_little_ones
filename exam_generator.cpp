#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <fstream>

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
          a = rand()%0xFFFFFFFF+0x10000000;
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

void html_generator(int diff,string task[12],char* file_path){
     char* buff = (char*)malloc(sizeof(int));
     
     string tasks[12];
     
     for(int i=0;i<12;i++){
         tasks[i]=task[i];            
     }
     
     string doc="<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n\
<html xmlns=\"http://www.w3.org/1999/xhtml\">\n\
<head>\n\
<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n\
<title>Ð¢ÐµÑÑ‚ Ð¿Ð¾Ð±Ð¸Ñ‚Ð¾Ð²Ð¸ Ð¾Ð¿ÐµÑ€Ð°Ñ†Ð¸Ð¸ </title>\n\
</head>\n\
<script>\n\
function Check_HEX(value,bytes){\n\
	validChar='0123456789ABCDEFabcdef';\n\
	var i;\n\
	if(value.length<=bytes){\n\
		for(j=0;j<value.length;j++){\n\
			i=0;\n\
			while(i<validChar.length){\n\
				if(validChar.charAt(i)==value.charAt(j)) break;\n\
				i++;\n\
			}\n\
			if(i==validChar.length){\n\
				return false\n\
			}\n\
		}\n\
		return true;\n\
	}\n\
	else return false;\n\
}\n\
\n\
function Check_Result(answer,real_answer,bytes){\n\
	if(Check_HEX(answer,bytes)){\n\
		answer = \"0x\" + answer;\n\
		if(parseInt(answer)>2147483647) answer = -4294967296 + parseInt(answer);\n\
		if(parseInt(answer)==parseInt(real_answer)) return true;\n\
		else return false;\n\
	}\n\
	else return false;\n\
}\n\
\n\
function Task_Solve(num_task){\n\
    switch(num_task){\n";


   for(int i=0;i<12;i++){
        string str = tasks[i].substr (0,tasks[i].find("?")-3);
        tasks[i].replace(0,tasks[i].find("?")+2,"");
        while(tasks[i].find("int")<tasks[i].length()){
             tasks[i].replace(tasks[i].find("int"),4,"");                                         
        }
        while(tasks[i].find("long")<tasks[i].length()){
             tasks[i].replace(tasks[i].find("long"),4,"");                                         
        }
        tasks[i]+=" return ";
        tasks[i]+=str;
        tasks[i]+=";\n";
        
        doc+="        case ";
        doc+=itoa((i+1),buff,10);
        doc+=":{\n";
        doc+=tasks[i];
        doc+="               }\n";   
   }
    	
   doc+="	}\n\
}\n\
\n\
function Check_Test(){\n\
	var bytes=0;\n\
	var result =0;\n\
	for(k=1;k<13;k++){\n\
		var answer = document.forms[\"form_1\"][\"task_\"+k].value;\n\
		real_answer=Task_Solve(k);\n\
		if(real_answer>65535) bytes=8;\n\
		else bytes=4;\n\
		if(k>10) bytes=8;\n\
		if(Check_Result(answer,real_answer,bytes)) result++;\n\
	}\n\
	alert(result+\"/12\");\n\
	return 0;\n\
}\n\
\n\
</script>\n\
\n\
<body>\n\
<div align=\"center\">\n\
  <p><strong>Ð¢ÐµÑ…Ð½Ð¾Ð»Ð¾Ð³Ð¸Ñ‡Ð½Ð¾ ÑƒÑ‡Ð¸Ð»Ð¸Ñ‰Ðµ Ð•Ð»ÐµÐºÑ‚Ñ€Ð¾Ð½Ð½Ð¸ ÑÐ¸ÑÑ‚ÐµÐ¼Ð¸ <br />\n\
  </strong>Ð¢ÐµÑ…Ð½Ð¾Ð»Ð¾Ð³Ð¸Ñ Ð½Ð° Ð¿Ñ€Ð¾Ð³Ñ€Ð°Ð¼Ð¸Ñ€Ð°Ð½ÐµÑ‚Ð¾</p>\n\
  <p> Ð¢ÐµÑÑ‚ Ð¿Ð¾Ð±Ð¸Ñ‚Ð¾Ð²Ð¸ Ð¾Ð¿ÐµÑ€Ð°Ñ†Ð¸Ð¸</p>\n\
  <form name=\"form_1\">\n\
  <table width=\"60%\" border=\"1\" bordercolor=\"#000000\" bordercolordark=\"#000000\" bordercolorlight=\"#000000\" cellpadding=\"10\" cellspacing=\"0\">\n";
   
   for(int i=0;i<12;i++){
           if(i%2==0){
              doc+="<tr>";     
           }
           doc+="<td><p>";
           while(task[i].find('\n')<task[i].length()) task[i].replace(task[i].find('\n'),1,"<br />");
           task[i].insert(task[i].find("<br />"),"  [HEX] 0x <input name=\"task_\" type=\"text\" />");
           task[i].insert(task[i].find("\" type"),itoa(i+1,buff,10));
           doc+=task[i];
           doc+="</p></td>";
           if(i%2){
              doc+="</tr>";     
           }           
   }
   doc+="</tr>";
   doc+="  </table>\n\
  <button type=\"submit\" form=\"form_1\" value=\"Submit\" onclick=\"Check_Test()\">ÐŸÑ€ÐµÐ´Ð°Ð¹</button>\n\
  </form>\n\
</div>\n\
</body>\n\
</html>";
  	
   ofstream myfile;
   myfile.open (file_path);
    myfile << doc;
   myfile.close();
}

int main(int argc,char* argv[]){
    srand(time(NULL));
    int diff;
    char* buff = (char*)malloc(sizeof(long));
    char* file_path;
    
    if(argc>1){ 
       diff=atoi(argv[1]);
       if(argc>2) file_path=argv[2];
       else file_path="test.html";
    }
    else{
         diff=rand()%3+1;
         file_path="test.html";
    }
    
    unsigned int a,b;
    unsigned long c,c1;
    num_generator(diff,a,b);
    long_num_generator(diff,c);
    long_num_generator(diff,c1);
    
    string tasks[12];
    
    cout<<"The difficulty is:"<<diff<<endl<<endl;
    
    cout<<"Generating the test";
    for(char i=0;i<2;i++){
        tasks[i]="a = ?\n int orig = 0x";
        tasks[i]+=itoa(a,buff,16);
        tasks[i]+=";\n int insert = 0x";
        tasks[i]+=itoa(b,buff,16);
        tasks[i]+=";\n int a = orig ";
        tasks[i]+=operator_generator();
        tasks[i]+=" (insert << ";
        tasks[i]+=itoa(shift_generator(diff),buff,10);
        tasks[i]+=");\n";
    }
    cout<<'.';
    
    for(char i=2;i<4;i++){
        tasks[i]="AND = ?\n int orig = 0x";
        tasks[i]+=itoa(a,buff,16);
        tasks[i]+=";\n int insert = 0x";
        tasks[i]+=itoa(b,buff,16);
        tasks[i]+=";\n int a = orig ";
        tasks[i]+=operator_generator();
        tasks[i]+=" (insert <<";
        tasks[i]+=itoa(shift_generator(diff),buff,10);
        tasks[i]+=");\n int b = orig ";
        tasks[i]+=operator_generator();
        tasks[i]+=" (insert <<";
        tasks[i]+=itoa(shift_generator(diff),buff,10);
        tasks[i]+=");\n int AND = a & b;\n";
    }
    cout<<'.';

    for(char i=4;i<6;i++){
        tasks[i]="a = ?\n long testValue =0x";
        tasks[i]+=itoa(c,buff,16);
        tasks[i]+=";\n int a =0;\n if (testValue ";
        tasks[i]+=operator_generator();
        tasks[i]+=" (1<<";
        tasks[i]+=itoa(shift_generator(diff),buff,10);
        tasks[i]+="))\n {\n    a = 1; \n }\n else\n { \n   a = 2; \n }\n";
    }
    cout<<'.';

    for(char i=6;i<8;i++){
        tasks[i]=" XOR = ?\n int orig  = 0x";
        tasks[i]+=itoa(a,buff,16);
        tasks[i]+=";\n int a = 0x";
        tasks[i]+=itoa(b,buff,16);
        tasks[i]+=";\n int b = orig ";
        tasks[i]+=operator_generator();
        tasks[i]+=" (a << ";
        tasks[i]+=itoa(shift_generator(diff),buff,10);
        tasks[i]+=");\n int XOR  = a ^ b;\n"; 
    }
    cout<<'.';
   
    for(char i=8;i<10;i++){
        tasks[i]=" left = ?\n int i = 0x";
        tasks[i]+=itoa(a,buff,16);
        tasks[i]+=";\n int left = i ";
        tasks[i]+=operator_generator();
        tasks[i]+=" (1 << ";
        tasks[i]+=itoa(shift_generator(diff),buff,10);
        tasks[i]+=");\n";
    }
    cout<<'.';
    
    for(char i=10;i<12;i++){
        tasks[i]=" result = ?\n long value1 = 0x";
        tasks[i]+=itoa(c,buff,16);
        tasks[i]+=";\n long value2 = 0x";
        tasks[i]+=itoa(c1,buff,16);
        tasks[i]+=";\n int result = (value1 << ";
        tasks[i]+=itoa(shift_generator(diff),buff,10);
        tasks[i]+=") ";
        tasks[i]+=operator_generator();
        tasks[i]+=" (value2 >> ";
        tasks[i]+=itoa(shift_generator(diff),buff,10);
        tasks[i]+=");\n";
    }
    cout<<'.'<<endl;
    cout<<"Done."<<endl;
    cout<<"Generating html file to " <<file_path<<" ..."<<endl;
    html_generator(diff,tasks,file_path);
    cout<<"Done.The test was generated succesfull!"<<endl;
    system("pause");
       
  return 0;
}
