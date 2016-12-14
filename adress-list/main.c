/* address_list.c */
// This program should be completed such that it maintains a list of students
// TO DO 1: Write a function inputStudent(int i), which allows the user to enter first name and last name and stores it at position i in the array.
// TO DO 2: Use a variable to count the number of students stored in the array.
// TO DO 3: Write a function printStudent(i), which prints student i stored in the array
// TO DO 4: Write functions addStudent(), for adding a student at the end of the array, and printAllStudents() for printing all students stored.
// TO DO 5: Write a function menu(), which allows the user to select one of the actions
//            - add Student
//            - print all students
//            - Quit program
// TO DO 6: Extend the student data and the corresponding functions with the gender male/female (using "enum").
// TO DO 7: Create a structure for handling dates (day, month, year) and use it for birth date, date of enrollment etc.
// TO DO 8: Extend the program such it also handles address information (street, number, zip-code and city).
// TO DO 9: optional: Add a function and menu item for deleting a selected student.
// TO DO 10: optional: Add a function to sort the data according to given criteria

#include <stdio.h>
#include <string.h>

int max = 100;
enum gender{
    male,female
};

struct person
{
    enum gender my_gender;
    int active;
    char first_name[30];
    char last_name[30];
};

struct person students[100];

void inputStudent(int i){
    
    char vorname[30];
    char nachname[30];
    char gender;
    struct person new_person;

    fseek(stdin,0,SEEK_END);
    
    printf("\nPlease enter your first name ");
    scanf("%[^\n]",vorname);
    
    fseek(stdin,0,SEEK_END);
    
    printf("\nPlease enter your last name ");
    scanf("%[^\n]",nachname);
    
    fseek(stdin,0,SEEK_END);
    
    
    printf("\nPlease enter your gender m/f");
    gender = getchar();
    
    if (gender == 'm') {
        new_person.my_gender = male;
    }else if(gender == 'f'){
        new_person.my_gender = female;
    }
    
    
    strcpy(new_person.first_name, vorname);
    strcpy(new_person.last_name, nachname);
    new_person.active =1;
    students[i] = new_person;
    
    printf("\nStudent wurde gespeichert");
}

int countStudents(){
    int cnt =0;
    for (int i=0; i<max; i++) {
        if (students[i].active == 1) {
            cnt++;
        }
       
    }
    return cnt;
}

void printStudent(int i){
    struct person printPerson = students[i];
    printf("\nDer Student %d heißt %s %s",i,printPerson.first_name,printPerson.last_name);
    
}

void addStudent(){
    int lastStudentIndex = 0;
    for (int i=0; i<max; i++) {
        for (int i=0; i<max; i++) {
            if (students[i].active == 1) {
                if (lastStudentIndex<i) {
                    lastStudentIndex = i;
                }
            }
            
        }
    }
    if (lastStudentIndex < max && lastStudentIndex >0) {
        inputStudent(lastStudentIndex+1);
    
    }else if(lastStudentIndex == 0){
        inputStudent(0);
    }else{
        printf("Arry of Students is full.");
    }
}

void printAllStudents(){
    for (int i=0; i<max; i++) {
        if (students[i].active == 1) {
            printStudent(i);
        }
        
    }
   
    
}

int main()
{
    for (int i=0; i<max; i++) {
        students[i].active = 0;
    }
    int start = 1;
    
    printf("****************************************************************\n\n");
    printf("Menü\n");
    
    
    while (start) {
        printf("\nWhat do you want to do?\n");
        printf("\na to add a Student\np to print all Students\ne to exit the Programm\n\n");
        
        char action;
        action = getchar();
        

        if (action == 'a') {
            addStudent();
        }
        if (action == 'p') {
            printAllStudents();
        }
        if (action == 'e') {
            start = 0;
        }
        
    }
    
    printf("\n****************************************************************\n\n");
    
    
}
