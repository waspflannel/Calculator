#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//function prototypes
int binary();
int unary();
int variable();
void selectCommand();
float advancedMath();
void advancedBinary();
void advancedUnary();
float isVariable(char* num);
float add(float x , float y);
float sub(float x , float y);
float division(float x , float y);
float mult(float x , float y);
float min(float x , float y);
float max(float x , float y);
float squareRoot(float x);
float logb10(float x);
float lowestInt(float x);
float highestInt(float x);
/////////////////////////////////

//variables used
float a =1;//a temp used for while loops to keep looping if given wrong answer
//used to hold value for variables
float a_variable =0;
float b_variable=0;
float c_variable=0;
float d_variable=0;
float e_variable=0;
//////////////////////////
char varArr[100];//used to verify variables
char Choice[100];//used for selection of calculations
char Operation[100];//used for selection of operations
int valid =0;//used to see if inputs are valid
int len =0;//used to see if inputs are valid
int decimal =0;//used to see if inputs have a decimal
char numb1[100];//used to hold values for calulations
char numb2[100];//used to hold values for calulations
int x,y;//used to hold values

int main(void) {
  puts("Welcome to my Command-Line Calculator(CLC)");
  puts("Developer: Jaden");
  puts("Version: 3");
  puts("Date: 2022-11-30");
  selectCommand();//calls function that displays different calculations
  while(1){//used to exit calculator
    if (Choice[0] == 'e'){
      puts("thanks for using my calculator");
      break;
    }
    }
  return 0;
}
void selectCommand(){
  valid=0;
  while(valid!=1){//prints out different calculations
  puts("Select one of the following items");
  puts("B) - Binary Mathematical Operations, such as addition and subtraction.");
  puts("U) - Unary Mathematical Operations, such as square root, and log.");
  puts("A) - Advances Mathematical Operations, using variables, arrays.");
  puts("V) – Define variables and assign them values.");
  puts("E) - Exit");
  scanf(" %s", Choice);//reads choice
  Choice[0] = tolower(Choice[0]);//makes it lowercase
  if(strlen(Choice)==1){//makes sure its only length 1 input
  if(Choice[0] == 'b'){
      binary();
    valid=1;
  }
  else if(Choice[0] == 'u'){
    unary();
    valid=1;
  }
  else if(Choice[0] == 'v'){
    variable();
    valid=1;
}
  else if(Choice[0] == 'e'){
    valid=1;
  }
  else if(Choice[0] == 'a'){
    advancedMath();
    valid=1;
  }
    }
  else{//sends invalid input and repeats
    puts("invalid input");
    valid=0;
  }
  }
  }



int binary(){
  a=1;
  valid=0;
  while(a){
    while(valid !=1){
      valid=1;
      puts("enter the first number");
      scanf("%s", numb1);
      len = strlen(numb1);
      while(len > 0){//verifies that it is a valid input
        len--;
        if(!isdigit(numb1[len])){
          if(valid==1){           
            if(len==0 && numb1[len]=='-')
              valid=1;
            else if(decimal==0 && numb1[len]=='.'){
              valid=1;
              decimal=1;
              } 
            else  
              valid=0;
            }
          }
        }
      }
  decimal=0;        
  valid = 0;  
  while(valid !=1){//checks valididy of operation
  puts("Please enter the operation ( + , - , * , / ,P , X , I): ");
  scanf("%s", Operation);
  len = strlen(Operation);
  Operation[0] = tolower(Operation[0]);
  if(len==1){
    if(Operation[0]=='+' || Operation[0]=='-' || Operation[0]=='*' || Operation[0]=='/' ||Operation[0]=='p' || Operation[0]=='x' || Operation[0]=='i')
      valid=1;
      }
    }
    valid = 0;
      while(valid !=1){
      valid=1;
      puts("enter the second number");
      scanf("%s", numb2);
      len = strlen(numb2);
      while(len > 0){//checks valididy of second number
        len--;
        if(!isdigit(numb2[len])){
          if(valid==1){           
            if(len==0 && numb2[len]=='-')
              valid=1;
            else if(decimal==0 && numb2[len]=='.'){
              valid=1;
              decimal=1;
              } 
            else  
              valid=0;
            }
          }
        }
      }
      decimal=0;       
    valid = 0;
    x = atof(numb1);//turns the strings to float
    y = atof(numb2);
    if(Operation[0] == '+'){
      printf("the answer is %f\n",add(x,y));
      a=0;
      }
    else if(Operation[0] == '-'){
      printf("the answer is %f\n",sub(x,y));
      a=0;

    }
    else if(Operation[0] == '*'){
      printf("the answer is %f\n",mult(x,y));
      a=0;

    }
    else if(Operation[0] == '/'){
      if(y !=0){
        printf("the answer is %f\n",division(x,y));
        a=0;
        }
      else{
        puts("Indeterminate form!");
        a=1;
      }
    }
    else if(Operation[0] == 'p'){
      printf("the answer is %f\n",pow((float)x,(float)y));
      a=0;
  
    }
    else if(Operation[0] == 'x'){
      printf("the answer is %f\n",min(x,y));
      a=0;

    }
    else if(Operation[0] == 'i'){
      printf("the answer is %f\n",max(x,y));
      a=0;

    }
    else{
      puts("invalid input for operation");
      a=1;
    }
  }
  selectCommand();//recalls main page 
  }

int unary(){
  a=1;
  while(a){
    while(valid !=1){
      valid=1;
      puts("enter the first number");
      scanf("%s", numb1);
      len = strlen(numb1);
      while(len > 0){//verifies a valid input
        len--;
        if(!isdigit(numb1[len])){
          if(valid==1){           
            if(len==0 && numb1[len]=='-')
              valid=1;
            else if(decimal==0 && numb1[len]=='.'){
              valid=1;
              decimal=1;
              } 
            else  
              valid=0;
            }
          }
        }
      }
  decimal=0;         
  valid = 0;  
  while(valid !=1){//verifies a valid operation
   puts("Please enter the operation ( S(sqrt) , L(log10) , E(exponentiate), C(cieling) , F(floor) )");
  scanf("%s", Operation);
  len = strlen(Operation);
  Operation[0] = tolower(Operation[0]);
  if(len==1){
    if(Operation[0]=='s' || Operation[0]=='l' || Operation[0]=='e' || Operation[0]=='c' ||Operation[0]=='f')
      valid=1;
      }
    }
    x= atof(numb1);//turns to float
    if(isalpha(Operation[0])){
      if(Operation[0] == 's'){
    if(x >=0){
        printf("the answer is %f\n",squareRoot(x));
        a=0;
          }
        else{
          puts("invalid number");
          a=1;
        }
      }
    if(Operation[0]== 'l'){
      if(x >0){
        printf("the answer is %f\n",logb10(x));
         a=0;

        }
      else{
        puts("INVALID NUMBER");
        a=1;
      }
      }
    if(Operation[0]=='e'){
        printf("the answer is %f\n",pow(x,x));
      a=0;
      }
    if(Operation[0] == 'c'){
        printf("the answer is %f\n",highestInt(x));

         a=0;
      }
    if(Operation[0] == 'f'){
        printf("the answer is %f\n",highestInt(x));
  
         a=0;
      }
      }
    else{
      puts("invalid operation");
      a=1;
    }
    }
  }
int variableValue(){
  valid=0;
  while(valid!=1){   
    valid = 1;
    printf("Please enter a value to assign to the variable: ");//makes sure input to variable is valid
    scanf("%s", numb1);
    len = strlen(numb1);
    while (len > 0){                             
          len--;
          if(!isdigit(numb1[len])){
            if(valid==1){
              if(len==0 && numb1[len]=='-')
                valid=1;
              else if(decimal==0 && numb1[len]=='.'){
                valid=1;
                decimal=1;
              }
              else
                valid=0;
              return 0;//return 0 if not
            }
          }
        }
  }
valid=0;
return 1;//return 1 if it is
}
int variable(){
  a=1;
  while(a){
  valid=0;
  while(valid != 1){ //makes sure variable is a valid one
  puts("enter a variable a-e");
  scanf(" %s", varArr);
  varArr[0] = tolower(varArr[0]); 
  len = strlen(varArr);
  if(len==1){
    if(varArr[0]=='a' || varArr[0]=='b' || varArr[0]=='c' || varArr[0]=='d' || varArr[0]=='e')
      valid=1;
  }
    }
  if(varArr[0] == 'a'){//if a is selected and variableValue function passes, set value to variable
    //repeat for a - e
    while(a){
    if(variableValue()){
      x = atoi(numb1);
      a_variable = x;
      a=0;
      }
    else{
      puts("invalid number");
      a=1;
    }
      }
    }
  else if(varArr[0] == 'b'){
    while(a){
    if(variableValue()){
      x = atoi(numb1);
    printf("the variable has value %s\n",numb1);
      b_variable = x;
      a=0;
      }
    else{
      puts("invalid number");
      a=1;
    }
      }

  }
  else if(varArr[0] == 'c'){
    while(a){
    if(variableValue()){
      x = atoi(numb1);
    printf("the variable has value %s\n",numb1);
      c_variable = x;
      a=0;
      }
    else{
      puts("invalid number");
      a=1;
    }
      }

  }
  else if(varArr[0] == 'd'){
    while(a){
    if(variableValue()){
      x = atoi(numb1);
    printf("the variable has value %s\n",numb1);
      d_variable = x;
      a=0;
      }
    else{
      puts("invalid number");
      a=1;
    }
      }
  }
  else if(varArr[0] == 'e'){
    while(a){
    if(variableValue()){
      x = atoi(numb1);
    printf("the variable has value %s\n",numb1);
      e_variable = x;
      a=0;
      }
    else{
      puts("invalid number");
      a=1;
    }
      }
  }
  else{
    puts("invalid input");
    a=1;
  }
    }
  selectCommand();
  }
float isVariable(char* num){//used to validate variables
  num[0] = tolower(num[0]);   
  if(strlen(num) ==1){
    if(num[0]=='a' || num[0]=='b' || num[0]=='c' || num[0]=='d' || num[0]=='e')
      return 1;
  }
  return 0;
  }

float advancedMath(){
  valid=0;
  while(valid!=1){//makes sure the input is valid for this selection
  puts("Select one of the following items");
  puts("B) - Binary Mathematical Operations, such as addition and subtraction.");
  puts("U) - Unary Mathematical Operations, such as square root, and log.");
  scanf("%s", Choice);
  Choice[0] = tolower(Choice[0]);
  if(strlen(Choice)==1){
  if(Choice[0] == 'b'){//if it is call advancedbinary
      advancedBinary();
    valid=1;
  }
  else if(Choice[0] == 'u'){//if it is call advancedunary
    advancedUnary();
    valid=1;
  }
    }
    }
  }
void advancedBinary(){
  a=1;
  char string1[99];//used for validation
  char string2[99];//used for validation
  int advNum1=0;//used for holding value
  int advNum2=0;//used for holding value
  while(a){
    valid=0;
  while(valid != 1){//makes sure input is a valid number or variable
    valid=1;
    puts("Please enter the first number or a variable name ('a' to 'e'): ");
    scanf("%s", string1);
    len = strlen(string1);
    if(isVariable(string1))//if its a proper variable its valid  
      valid=1;
    else{                                    
      while (len > 0){
        len--;
        if(!isdigit(string1[len])){
          if(valid==1){
            if(len==0 && string1[len]=='-'){
              valid=1;
              }
            else if(decimal==0 && string1[len]=='.'){
              valid=1;
              decimal=1;
            }
            else
              valid=0;
          }
        }
      }         
    }
  }
  decimal=0;
  valid = 0;
      if(string1[0]=='a'){//these statments set the value holder variables to values of the variable     
        advNum1=a_variable;
        }
    else if(string1[0]=='b')
        advNum1=b_variable;
    else if(string1[0]=='c')
        advNum1=c_variable;
    else if(string1[0]=='d')
        advNum1=d_variable;
    else if(string1[0]=='e')
        advNum1=e_variable;
    a=0;
    }
  while(valid !=1){//makes sure operation is valid
  puts("Please enter the operation ( + , - , * , / ,P , X , I): ");
  scanf("%s", Operation);
  len = strlen(Operation);
  Operation[0] = tolower(Operation[0]);
  if(len==1){
    if(Operation[0]=='+' || Operation[0]=='-' || Operation[0]=='*' || Operation[0]=='/' ||Operation[0]=='p' || Operation[0]=='x' || Operation[0]=='i')
      valid=1;
      }
    }
  valid = 0;
  a=1;
  while(a){
    valid=0;
  while(valid != 1){//same process is repeated for second number, same as first number
    valid=1;
    puts("Please enter the second number or a variable name ('a' to 'e'): ");
    scanf("%s", string2);
    len = strlen(string2);
    if(isVariable(string2)){  
      valid=1;
      }
    else{                                     
      while (len > 0){
        len--;
        if(!isdigit(string2[len])){
          if(valid==1){
            if(len==0 && string2[len]=='-'){
              valid=1;

              }
            else if(decimal==0 && string2[len]=='.'){
              valid=1;
              decimal=1;
            }
            else
              valid=0;
          }
        }
      }         
    }
  }

  x=atoi(string1);//makes the string1 value to an integer
  y = atoi(string2);//makes the string2 value to an integer
  decimal=0;
  valid = 0;

      if(string2[0]=='a'){//if it is a variable set the variable value to the value holder        
        advNum2=a_variable;
        }
      else if(string2[0]=='b')
        advNum2=b_variable;
      else if(string2[0]=='c')
        advNum2=c_variable;
      else if(string2[0]=='d')
        advNum2=d_variable;
      else if(string2[0]=='e')
        advNum2=e_variable;
      
    a=0;
    if(!isVariable(string1)){//if string1 is not a variable set value holder to the value
        advNum1=x;
    }
    if(!isVariable(string2)){//if string2 is not a variable set value holder to the value
        advNum2=y;
    }

    }
    a=0;
  if(Operation[0] == '+'){//checks operation and runs corresponding function
      printf("the answer is %f\n",add(advNum1,advNum2));
      a=0;
      }
    else if(Operation[0] == '-'){
      printf("the answer is %f\n",sub(advNum1,advNum2));
      a=0;
    }
    else if(Operation[0] == '*'){
      printf("the answer is %f\n",mult(advNum1,advNum2));
      a=0;

    }
    else if(Operation[0] == '/'){
      if(y !=0){
        printf("the answer is %f\n",division(advNum1,advNum2));
        a=0;
        }
      else{
        puts("Indeterminate form!");
        a=1;
      }
    }
    else if(Operation[0] == 'p'){
      printf("the answer is %f\n",pow((float)advNum1,(float)advNum2));
      a=0;
  
    }
    else if(Operation[0] == 'x'){
      printf("the answer is %f\n",min(advNum1,advNum2));
      a=0;

    }
    else if(Operation[0] == 'i'){
      printf("the answer is %f\n",max(advNum1,advNum2));
      a=0;

    }
    else{
      puts("invalid input for operation");
      a=1;
    }
  selectCommand();
  }
void advancedUnary(){
  a=1;
  char string1[99];
  int advNum1=0;
  while(a){
   valid=0;
  while(valid != 1){//checks if  a valid number or variable is inputted
    valid=1;
    puts("Please enter the first number or a variable name ('a' to 'e'): ");
    scanf("%s", string1);
    len = strlen(string1);
    if(isVariable(string1)) 
      valid=1;
    else{                                     
      while (len > 0){
        len--;
        if(!isdigit(string1[len])){
          if(valid==1){
            if(len==0 && string1[len]=='-'){
              valid=1;
              }
            else if(decimal==0 && string1[len]=='.'){
              valid=1;
              decimal=1;
            }
            else
              valid=0;
          }
        }
      }         
    }
  }
  decimal=0;
  valid = 0;
      if(string1[0]=='a'){     //if it is a variable then set value holder to variable
        advNum1=a_variable;
        }
    else if(string1[0]=='b')
        advNum1=b_variable;
    else if(string1[0]=='c')
        advNum1=c_variable;
    else if(string1[0]=='d')
        advNum1=d_variable;
    else if(string1[0]=='e')
        advNum1=e_variable;

    if(!isVariable(string1)){//if it is not a variable then set value holder to the number
        advNum1=x;
    }
    a=0;
    }
 while(valid !=1){//validates the operation
  puts("Please enter the operation ( S(sqrt) , L(log10) , E(exponentiate), C(cieling) , F(floor) )");
  scanf("%s", Operation);
  len = strlen(Operation);
  Operation[0] = tolower(Operation[0]);
  if(len==1){
    if(Operation[0]=='s' || Operation[0]=='l' || Operation[0]=='e' || Operation[0]=='c'   ||Operation[0]=='f')
      valid=1;
      }
   }
  valid = 0;
  a=1;
  if(Operation[0] == 's'){//checks operation and runs corresponding function
    if(x >=0){
        printf("the answer is %f\n",squareRoot(x));
        a=0;
          }
        else{
          puts("invalid number");
          a=1;
        }
      }
    else if(Operation[0] == 'l'){
      if(advNum1 >0){
        printf("the answer is %f\n",logb10(advNum1));
         a=0;
        }
      else{
        puts("INVALID NUMBER");
        a=1;
      }
      }
   else if(Operation[0] ==  'e'){
        printf("the answer is %f\n",pow(x,x));
      a=0;
      }
    else if(Operation[0] ==  'c'){
        printf("the answer is %f\n",lowestInt(advNum1));

         a=0;
      }
    else if(Operation[0] == 'F'){
        printf("the answer is %f\n",highestInt(advNum1));
  
         a=0;
      }
    else{
      puts("invalid operation");
      a=1;
    }
  selectCommand();
    }

float add(float x , float y){
  return x + y;
}
float sub(float x , float y){
  return x - y;
}
float mult(float x , float y){
  return x*y;
  }
float division(float x,float y){
  return x/y;
}
float min(float x , float y){
  if(x >= y)
    return y;
  else
    return x;
  }
float max(float x , float y){
  if(x > y)
    return x;
  else
    return y;
  }

float squareRoot(float x){
  return sqrt(x);
}

float logb10(float x){
  return log10(x);
}


float lowestInt(float x){
  return floor(x);
}

float highestInt(float x){
  return ceil(x);
}



  