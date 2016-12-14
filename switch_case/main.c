// Switch case: Order your burger...
// TO DO 1: Replace the if-statements with switch case and add a default case for invalid input
// TO DO 2: Add support for extra-large and fish burgers
// TO DO 3: Extend the program such that is executed in a loop, which can be aborted by entering 'q' as size
// TO DO 4: If there is a much longer list of options: How can long if-else-chains / switch-case-statements be avoided?
// With some while or for loops
// TO DO 5: Optional: Any further ideas for additional sizes and options?

#include <stdio.h>

main() {
    char size,specials;
    int height;
    float price;
    int loop=1;
    
    while (loop) {
        price=0.0;
        
        printf("********************************* 🌉 Leon's Burger Palast 🏙 ************************************\n\n");

        printf("Welcome!\n\n");
        printf("How many Patties do you want?\n\ns = 1 Pattie\nm = 2 Patties\nl = 3 Patties\nx = 4 Patties\n\n");
        scanf(" %c",&size);
        
        
        switch (size) {
            case 's':
                height=1;
                price=2.5f;
                break;
            case 'm':
                height=2;
                price=3.5f;
                break;
            case 'l':
                height=3;
                price=4.5f;
                break;
            case 'x':
                height=4;
                price=5.5f;
                break;
                
                
            default:
                printf("Invalid answer..\n\n");
                continue;
                break;
        }
        
        printf("Which Burger do you want ? 🍔🍟\n\nr = Hamburger\nv = Veggieburger\nc = Cheeseburger (+1 Euro)\nf = NEW Fishburger (+1.50 €)\nn = NEW Crispy Chicken (+2.50 €)\n\n");
        scanf("\n %c",&specials);
        
        
        
        printf("\n\n.-\"\"\"\"-.\n");
        while(height--) {
            switch (specials) {
                case 'c':
                    price+=1;
                    printf(" ------ \n");
                    scanf("\n %c",&specials);
                    height++;
                    break;
                case 'v':
                    printf("(xxxxxx)\n");
                    break;
                case 'f':
                    price+=1.5;
                    printf("(≈≈≈≈≈≈)\n");
                    break;
                case 'n':
                    price+=2.5;
                    printf("🐥🐥🐥🐥\n");
                    
                    break;
                
                default:
                    printf("(mmmmmm)\n");
                    break;
            }
            

        }
        printf("\\______/\n");
        printf("\n\n%.2f Euro 💶 - Enjoy!\n\n", price);
    }
    
}
