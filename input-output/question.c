#include <stdio.h>

int main()
{
    int age;
    printf("Write your age: ");

    scanf("%d", &age);
    fflush(stdin);

    // not require \n at start because when you do INTRO create a new line
    // printf("\n%d * 4 = %d\n", age, age*4);
    printf("%d * 4 = %d\n", age, age*4);

    char firstCharecterOfYourName;

    printf("Your first charecter of your name?: ");

    scanf("%c", &firstCharecterOfYourName);

    printf("Hello, %c...\n", firstCharecterOfYourName);


    /*
    // using scanf() for multiple inputs
    char gender;
    int age;

    printf("Enter your age and then gender(M, F or O): ");
    scanf("%d %c", &age, &gender);
    printf("You entered: %d and %c", age, gender);
    */

    int i = printf("studytonight"); // printf return the len of writed charecters
    printf("Value of i is: %d\n", i);

    return 0;
}