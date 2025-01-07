#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    int per_num;
    char* first_name;
    char* last_name;
    char* gender;
    char* program;
    int age;
    char* email;
} student;

typedef struct program{
    char prog_name[50];
    char prog_code[10];
    char prog_resp[50];
    char resp_email[100];    
} program;

int counter = 0;
program array_prog[50]; // Create a static array of 50 program structs

typedef struct node{
    student *student;
    struct node *next;
    struct node *prev;
   
} node;

node *head = NULL; //head of the list, points to nothing at init

void add_student(int per_num, char *first_name, char *last_name, char *gender, char *program, int age, char *email){ 
    node* new_node = (node*) malloc (sizeof(node));

    student* new_student  = (student*) malloc (sizeof(student));

    //                              NEED TO ADD "FREE"

    if (new_student == NULL){
        printf("Error allocating memory");
        exit(0);
    }

    new_node->student = new_student;
   
    new_node->next = NULL; //So that the last pointer in the list is always NULL

    new_node->prev = NULL;

    if (head == NULL) {
        head = new_node;
    }

    else {
        node *temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = new_node;

        new_node->prev = temp;
    }

    new_student->per_num = per_num;

    new_student->first_name = strdup(first_name);

    new_student->last_name = strdup(last_name);

    new_student->gender = strdup(gender);

    new_student->program = strdup(program);

    new_student->age = age;

    new_student->email = strdup(email);

    printf("\n\n");

    /* node *temp = head; 

    while(temp != NULL) {
        printf("%d-->", temp->student->per_num);
        temp = temp->next; // Move down the list to the last node
    }

    printf("\n"); */
 
    /* while(temp != NULL && temp->next != NULL) {
        temp = temp->next; // Move down the list to the last node
    }

    while (temp != NULL){
        printf("%d<--", temp->student.first_name);
        temp = temp->prev; // Start moving up towards the head
    }

    printf("\n"); */

   // return head; //returns the head pointer of the list
}


void modify_student(int per_num){
    node* temp = head;
/*
    if (temp->student == NULL);{
        printf("No students in database");
        return;
    }
*/
    while(temp != NULL){
        if (temp->student->per_num == per_num){
            printf("Enter new first name: ");
            scanf("%s", temp->student->first_name);
            printf("Enter new last name: ");
            scanf("%s", temp->student->last_name);
            printf("Enter new gender: ");
            scanf("%s", temp->student->gender);
            printf("Enter new program: ");
            scanf("%s", temp->student->program);
            printf("Enter new age: ");
            scanf("%d", &temp->student->age);
            printf("Enter new email: ");
            scanf("%s", temp->student->email);
            getchar();
            return;
        }
        temp = temp->next;
    }
    printf("Student not found!");
}






void delete_student(){
/*
    int per_num
    printf("Enter Personnumber: ")
        scanf(%d, &per_num);
    node_s *current=head;
    node_s *previous =NULL;

    while (current !=NULL) {
        if (current -> currentd-> pernum==per_num) {
            if(previous ==NULL)
            previous->next = current->next;
            }

        else{
            previous->next = current->next;
            if (current -> next !=NULL) {
                current ->next ->previous = previous;
        }
    }

    printf("person %d deleted \n" , per_num);

    return;

    }
        previous = current:
        current = current->next:
    }
        printf ("not found %d \n", per_num):
    }
*/    

}

void search_student(){
/*
int choice2 = 0;
printf(" 1. Personal number:\n 2. Name\n 3. Study Program\n 4. Statistics");
scanf("%d" , choice2);

switch(choice2); {
    case 1:
    break;

    case 2:
    break;

    case 3:
    break;

    case 4:
    break;

}
*/

}

void save_file(){
/*
The program asks for a file name and saves all information in the database into the file. If the file exits,
it will be overwritten and if it does not exist it has to be created
*/

    char *filename;

    printf("Please enter the file you would like to save to. If no such file exists a new one will be created.\nAny pre-existing information in the file will be overwritten");
    scanf("");

    FILE *filptr = fopen(filename, "w");

    node *temp = head;

    while (temp != NULL) {

        fprintf(filptr, "%d,", temp->student->per_num);      //per_num
        fprintf(filptr, "%s,", temp->student->first_name);   //first_name
        fprintf(filptr, "%s,", temp->student->last_name);    //last_name
        fprintf(filptr, "%s,", temp->student->gender);       //gender
        fprintf(filptr, "%s,", temp->student->program);      //program
        fprintf(filptr, "%d,", temp->student->age);          //age
        fprintf(filptr, "%s,", temp->student->email);        //email
        
        fprintf(filptr, "\n");
        
        temp = temp->next;
    }

    printf("\n\nWrote to file\n\n");

    fclose(filptr);
    
    return;
}

void load_file(){
/*
The program asks for a file name. If the file exists its contents will be loaded into the database. Note that the current information
in the database will be overwritten by the information from the file. Therefore the program asks for a confirmation from the user.
*/

    head = NULL; //Makes head  NULL since any previous information in the database will be overwritten/discarded

   /*  scanf("%d", &new_student->per_num);

    scanf("%s %s", &new_student->first_name, &new_student->last_name); 

    scanf("%s", &new_student->gender);

    scanf("%s", &new_student->program);

    scanf("%d", &new_student->age);

    scanf("%s", &new_student->email);  */

    printf("\n\n");

    /* node *temp = head; 

    while(temp != NULL) {
        printf("%d-->", temp->student->per_num);
        temp = temp->next; // Move down the list to the last node
    }

    printf("\n"); */
 
    /* while(temp != NULL && temp->next != NULL) {
        temp = temp->next; // Move down the list to the last node
    }

    while (temp != NULL){
        printf("%d<--", temp->student.first_name);
        temp = temp->prev; // Start moving up towards the head
    }

    printf("\n"); */

}

void add_program(){
    char prog_n[50];
    char prog_c[10];
    char resp_n[50];   
    char resp_e[100];

    if(counter > 50){
        printf("Reached maximum program limit");
        return;
    }

    printf("Name of program: \n");
    scanf("%s" , prog_n);
    printf("Program code: \n");
    scanf("%s" , prog_c);
    printf("Name of program responsible: \n");
    scanf("%s" , resp_n);
    printf("Responsible email: \n");
    scanf("%s" , resp_e);
/*
    prog_n = array_prog[counter].prog_name
    prog_c = array_prog[counter].prog_code
    resp_n = array_prog[counter].prog_resp
    resp_e = array_prog[counter].resp_email
*/
    strcpy(array_prog[counter].prog_name , prog_n);
    strcpy(array_prog[counter].prog_code , prog_c);
    strcpy(array_prog[counter].prog_resp , resp_n);
    strcpy(array_prog[counter].resp_email , resp_e);
    counter++;
}

void modify_program(){
/*
The program ask the program by asking its code and let the user to modify informations about the program
*/

}

void exit_function(){
    node* temp = head;
    node* next_temp;
    char choice1;
    printf("Do you want to save database? y/n: ");
    scanf("%s", &choice1);
    if (choice1 == 'y'){
        // Some code for file saving
        // Some code for file saving
        while(temp != NULL){ // Traverse through all nodes and free the one by one
            next_temp = temp->next; // Since temp will be freed we must pre define the next node so that we can keep track of the nodes
            free(temp->student);
            temp = next_temp;
        }
        printf("Freed allocated memory, terminating program");
        exit(0);
    }

    else if(choice1 == 'n'){
        while(temp != NULL){
        next_temp = temp->next;
        free(temp->student);
        temp = next_temp;
        }
        printf("Freed allocated memory, terminating program");
        exit(0);
    }

    else {
    printf("Please type either y or n");
    exit_function();
    }

}

void print_function(){
    node* temp = head;
    printf("-------------------------------------------------\n");
    while (temp != NULL){
        printf("Personal Number: %d\n", temp->student->per_num);
        printf("First Name: %s\n", temp->student->first_name);
        printf("Last Name: %s\n", temp->student->last_name);
        printf("Gender: %s\n", temp->student->gender);
        printf("Program: %s\n", temp->student->program);
        printf("Age: %d\n", temp->student->age);
        printf("Email: %s\n", temp->student->email);
        printf("-------------------------------------------\n");
        temp = temp->next;
    }
}

void print_programs(){
    for(int i = 0; i<counter; i++){
        printf("-----------------------------------------\n");
        printf("Program Name: %d\n", array_prog[i].prog_name);
        printf("Program code: %s\n", array_prog[i].prog_code);
        printf("Program responsible: %s\n", array_prog[i].prog_resp);
        printf("Responsible email: %s\n", array_prog[i].resp_email);
        printf("-----------------------------------------\n");
    }
}

int main(){

int per_num;
char first_name[50];
char last_name[50];
char gender[3];
char program[50];
int age;
char email[100];
    
node * head = NULL;
while(1){
int choice = 0;

printf("Enter a number:\n 1. Add\n 2. Modify\n 3. Delete\n 4. Search\n 5. Save\n 6. Load\n 7. Add program\n 8. Modify program\n 9. Exit\n 10. Print Students\n 11. Print Programs\n");
scanf("%d", &choice);

switch (choice){

    case 1:

        plus_student:

        printf("Enter Personnummer: ");
        scanf("%d", &per_num);

        printf("Enter first and last name: ");
        scanf("%s %s", &first_name, &last_name); 

        printf("Enter gender (M/F): ");
        scanf("%s", &gender);

        printf("Enter Program: ");
        scanf("%s", &program);

        printf("Enter age: ");
        scanf("%d", &age);

        printf("Enter Email: ");
        scanf("%s", &email);

        add_student(per_num, first_name, last_name, gender, program, age, email);

        char yn;

        printf("Would you like to enter another student? \nEnter y for yes. Enter any other key for no.");

        scanf(" %c", &yn);

        printf("\r\n\n");

        if (yn == 'y') {
            goto plus_student;
        }

        node *temp = head; 

        while(temp != NULL) {
            printf("%d-->", temp->student->per_num);
            temp = temp->next; // Move down the list to the last node
        }

        printf("\n"); 

    break; //A while loop could have been used here but a goto statement felt more readable and thus more fitting in this case

    case 2:

        printf("Enter Personnummer: \n");
        scanf("%d", &per_num);

        modify_student(per_num);

    break;

    case 3:
        delete_student();

    break;

    case 4:
        search_student();

    break;

    case 5:
        save_file();

    break;

    case 6:
        load_file();

    break;

    case 7:
        add_program();

    break;

    case 8:
        modify_program();

    break;

    case 9:
        exit_function();
    
    break;

    case 10:
        print_function();
    break;

    case 11:
        print_programs();
    break;

    default:
    main();
    break;
 }
}
//char *study_prg = &student.gender;




}
