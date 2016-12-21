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

struct date
{
    int day;
    int month;
    int year;
};


struct person
{
    enum gender my_gender;
    int active;
    char first_name[30];
    char last_name[30];
    struct date birthdate;
    struct date enrollment;
};

struct person students[100];

struct date inputeDate(){
    struct date new_date;
    
    fseek(stdin,0,SEEK_END);
    
    scanf("%d.%d.%d",&new_date.day,&new_date.month,&new_date.year);
    
    fseek(stdin,0,SEEK_END);
    
    return new_date;
}

struct person inputStudent(){
    
    char vorname[30];
    char nachname[30];
    char gender;
    struct person new_person;

    fseek(stdin,0,SEEK_END);
    
    printf("\n\tfirst name: ");
    scanf("%[^\n]",vorname);
    
    fseek(stdin,0,SEEK_END);
    
    printf("\tlast name: ");
    scanf("%[^\n]",nachname);
    
    fseek(stdin,0,SEEK_END);
    
    printf("\tgender: ");
    gender = getchar();
    
    if (gender == 'm') {
        new_person.my_gender = male;
    }else if(gender == 'f'){
        new_person.my_gender = female;
    }else{
        new_person.my_gender = male;
    }

    
    strcpy(new_person.first_name, vorname);
    strcpy(new_person.last_name, nachname);
    printf("\tbirth: ");
    new_person.birthdate = inputeDate();
    printf("\tenrollment: ");
    new_person.enrollment = inputeDate();
    
    
    
    new_person.active = 1;
    
    
    printf("\n\e[1m Student wurde gespeichert.\e[0m\n");
    fseek(stdin,0,SEEK_END);
    
    return new_person;
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

void printStudent(struct person *s,int i){
        printf("\t%d\n\t\t%s\n\t\t%s\n\t\t%d.%d.%d\n\t\t%d.%d.%d\n", i,s->first_name,s->last_name,s->birthdate.day,s->birthdate.month,s->birthdate.year,s->enrollment.day,s->enrollment.month,s->enrollment.year);
}

void addStudent(){
    if (countStudents() < max ) {
        students[countStudents()] =inputStudent();
    }else{
        printf("Arry of Students is full.");
    }
}

void printAllStudents(){
    for (int i=0; i<max; i++) {
        if (students[i].active == 1) {
            printStudent(&students[i],i);
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
        printf("\n1) add a Student\n2) print all Students\n3) exit the Programm\n\n");
        
        char action;
        printf("=> ");action = getchar();
        fseek(stdin,0,SEEK_END);

        if (action == '1') {
            addStudent();
        }else if (action == '2') {
            printAllStudents();
        }else if (action == '3') {
            start = 0;
        }else{
            printf("\n\e[1m Eingabe ungültig.\e[0m\n");
        }
        
    }
    
    printf("\n****************************************************************\n\n");
    
    
}
