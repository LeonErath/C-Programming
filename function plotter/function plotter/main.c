/* Function_plotter.c
  This program uses pointers to functions, which are passed as arguments in function calls.
  
  TO DO 1: Have a look at the program and see how function pointers are used.
  TO DO 2: Extend the draw_function such that the range for x and y can be passed:
  Define a struct range, which provides values for min, max and step.
  TO DO 3: Extend the draw_function, such that two functions
  can be passed to the draw function and are shown in the same diagram.
  Use a NULL pointer to indicate that there is no second function to display.
  TO DO 4: Add more functions and a menu to flexibly choose
  which functions to show (use two function pointers).
  */

#include <math.h>
#include <stdio.h>

struct settings{
    double minX;
    double maxX;
    double minY;
    double maxY;
    double stepX;
    double stepY;
};

// Display function
void draw_function(double (*f)(double),struct settings sett)
{
    double x, y;
    
    
    for(y=sett.maxY; y>=sett.minY; y-=sett.stepY) {
        for(x=sett.minX; x<sett.maxX; x+=sett.stepX) {
            printf("%c", ((*f)(x)>=y && (*f)(x)<y+sett.stepY)? '*': ' ');
        }
        printf("\n");
    }
}

// Mathematical function to be displayed
double my_function(double x)
{
    return 1.5*sin(x);
}

int main()
{
    double (*fn_ptr)(double);     // Defines a variable pointing to a function
    // double some_function_name(double);
    fn_ptr=&my_function;          // & can be omitted
    
    struct settings sett;
    sett.maxX = 10;
    sett.minX = -10;
    sett.minY = -2;
    sett.maxY = 2;
    sett.stepY = 0.1;
    sett.stepX = 0.25;
    draw_function(fn_ptr,sett);        // or directly: draw_function(my_function);
}
