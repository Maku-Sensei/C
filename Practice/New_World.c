#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//prototype
double cube(double number, int index);
double cubew(double number, int index);

//structs
struct Student{
  char name [50];
  char major[50];
  int age;
  double gpa;
};

int main(){
    char characterName[] = "John";
    int age = 10; 
    double gpa = 0.6;
    char grade = 'F';
    char phrase[] = "Hello, world";
    int x = 2;
    int y = 3;
    int z = 36;

    printf("Hello, world!");
    printf("%s", phrase);
    printf("There was a man called %s\n", characterName); //%s "placeholder" for String"
    printf("%d\n", age);
    printf("he was %d years old\n", age); //%d "placeholder" for Integer"
    printf("%d is %s\n", age, phrase);
    printf("%f\n", gpa); //%f "placeholder" for Double"
    printf("%c\n", grade); //%c "placeholder" for character

    printf("Hello\"world!\n");
    printf("\n");

    //math functions
    printf("x raised to the power of y: %f\n", pow(x, y)); //x raised to the power of y, returns double, float
    printf("square root: %f\n", sqrt(z)); //square root, returns float, double
    printf("next highest number: %f\n", ceil(gpa)); //next highest number
    printf("next lowest number: %f\n", floor(gpa)); //next lowest number 

    /*
    This is a comment
    */

   //constant varibale, can't be modified
   const int num = 5; 
   printf("%d\n", num);
    /* num = 8;
   printf("%d", num);
   */
  

  //Getting User Input
  int ageinput;
  double gpainput;
  char gradeinput;
  char name[50];
  printf("enter your age:");
  scanf("%d", &ageinput); //&age is called a pointer, so we can store input from the user
  printf("Your are %d years old\n",ageinput );
  printf("Enter your gpa: ");
  scanf("%lf", &gpainput);
  printf("Your gpa is %f\n", gpainput);
  printf("Enter your grade: ");
  scanf(" %c", &gradeinput);
  printf("Your grade is %c\n", gradeinput);
  printf("Enter your name: ");
  fgets(name, 50, stdin); //no need for &name, fgets stores string of characters and stores multiple words(whitespaces)
  printf("Your name is %s\n", name);

  //basic calculator
  double num1;
  double num2;
  printf("Enter first number: ");
  scanf("%lf", &num1);
  printf("Enter second number: ");
  scanf("%lf", &num2);
  printf("Answer: %f", num1 + num2);

  //mad lips game
  char color[20];
  char pluralNoun[20];
  char celebrityF[20];
  char celebrityL[20];

  printf("Enter a color: ");
  scanf("%s", color);
  printf("Enter a plural-noun: ");
  scanf("%s", pluralNoun);
  printf("Enter a celebrity: ");
  scanf("%s%s", celebrityF, celebrityL);
  
  printf("Roses are %s/n", color);
  printf("%s are bue/n", pluralNoun);
  printf("I love %s %s", celebrityF, celebrityL);

  //Arrays
  int luckynumbers[] = {4, 8, 15, 16, 43};
  luckynumbers[1] = 200;
  printf("%d", luckynumbers[1]);
  int luckynumber[10];
  luckynumber[1] = 80;
  printf("%d", luckynumber[0]); //output is -2 meaning "not found"

  //functions
  sayHi();
  sayHiUser("Maku", 20);

  //better calculator
  double c1;
  double c2;
  char op;
  printf("Enter a number: ");
  scanf("%d", c1);
  printf("Enter a operator");
  scanf(" %c", op);
  printf("Enter a second number: /n");
  scanf("%d", c2);
  printf("result is %d", calculator(c1, c2, op));
  
  //switch statements
  grade = 'A';
  switch (grade) {
    case 'A': 
      printf("You did great!"); 
      break;
     case 'F': 
      printf("You did very poorly! You failed!"); 
      break;
    default: //like else
      printf("You got an invalid Grade");
  }

  //structs
  struct Student student1; 
  student1.age = 22;
  student1.gpa = 4.6;
  strcpy(student1.name, "Maku");
  strcpy(student1.major, "CS");

  struct Student student2;
  student2.age = 22;
  student2.gpa = 7.5;
  strcpy(student2.name, "Cagatay");
  strcpy(student2.major, "BWL");

  //2 Dimensional Arrays (short 2D Arrays)
  //three array elements and each of them has two array elmeents inside of them
  int nums[3][2] = {
                 {1,2},
                  {3,4},
                  {5,6}
                   };
  printf("%d\n", nums[0][0]); //output will be 1
  printf("%d\n", nums[1][1]); //output will be 4
  nums[0][0] = 2; 

  int i, j;
  for (i = 0; i < 3; i++){     //3 is the length of the first array
    for (j = 0; j < 2; j++){   //2 is the length of the second array
        printf("%d,", nums[i][j]); 
    }
    printf("\n");
  }

  //Memorial Addresses
  //Memory which C uses to access for ex. variables

  //printing out memory addresses
  printf("%p", &age);

  //Pointers: Variable for memory addresses
  printf("age's memory address: %p/n", &age);
  //declaring pointer variable
  int * pAge = &age;
  double * pGpa = &gpa;
  char * pGrade = &grade;

  //dereferencing Pointers
  printf("%d", *pAge); //when we dereference a pointer it is gonna be whatever was stored at that memory address
  printf("%d", *&age); //same thing

  //Writing Files
  //file modes: r for read, w for write, a for append
  FILE * fpointer = fopen("employees.txt","w");
  fprintf(fpointer,"Maku", "Programmer/n", "Cagatay", "Business Analyst");
  fclose(fpointer); 

  //Reading Files
  char line [254];
  FILE * fpointer= fopen("employees.txt","r");
  fgets(line, 254, fpointer); //stores the first line
  fgets(line, 254, fpointer); //stores the second line
  printf("%s", line); 
  fclose(fpointer);


}
//functions
void sayHi(){
  printf("function says Hi");
}

void sayHiUser(char name[], int age){
  printf("%s says Hi, you are %d", name, age);
}

double cube(double number, int index){
  double result;
  int i= index;

  //if statement
  if(i > 0){
   result = number * cube(number, i--);
  }else{
    return result;
  }
}

double cubew(double number, int index){
  double result;
  int i= index;

  //while loop
  while (i>0){
   result = number * number;
   i--;
  }
  return result;
}

int dwtest(int num1){
  int i = 6;
  //do while loop
  do{
    printf("%d", num1);
    i++;
  }while (i <=5);
  return num1;
}

void countontopof(int num){
  //for loop
  for(int i=0; i<num; i++){
    num += 1;
    printf("%d", num);
}
}
void arrayLoop(int num){
  int luckynumbers [] = {0,1,2,3,4,5,6,};
  int size = sizeof(luckynumbers) / sizeof(luckynumbers[0]); //using sizeof to get length of array
  int size2 = *(&luckynumbers + 1) - luckynumbers;           //using pointer arithmetic to get length of array

  //for loop with size of the array as the limit
  for (int i=0 ; i < size; i++){
    printf("%d", luckynumbers[i]);
}
}
double calculator(double num1, double num2, char op){
  double result;
  if (op == '+'){
    result = num1 + num2;
    result = num1 - num2;
}else if (op == '*'){
  result = num1 * num2;
}else if (op == '/'){
  result = num1 / num2;
}else{
  printf("error: Invalid Operator");
  return 0.0;
}
return result;
}
//guessing Game
void GuessingGame(int guess){
int secretNumber = 5;
int g = guess;
int guessCount =0;
int guessLimit = 3;
int outofGuesses = 0; //works like a boolean, C has no boolean type

while (g != secretNumber && outofGuesses != 1) {
  if (guessCount < guessLimit){
  printf("Enter a number: ");
  scanf("%d",&guess);
  guessCount++;
  }else{
    outofGuesses = 1;
  }

}if (outofGuesses == 0){
  printf("You win!");
}else{
  printf("You lose!");
}

}

