//2128056
//Unathi Lenkoe
//Batch 02
//section B
//Compiler: c++17GNU c++ language standard (ISO c++ plus GNU extensions)[std=gnu++17]
//preprocessors directories
#include <iostream>
using namespace std;
#include<cstdlib>


int main();
//class
class loans{ // creating a node class for loans
   public:
      //setting attributes public for access
      string firstName; //declaring first name attribute
      string surname;  //declaring surname attribute
      string emailAddress; //declaring email address attribute
      int amountApplied;//declaring amount attribute
      string status; //declaring status attribute
      loans* next;   //creating a pointer to link nodes

     //setting constructors and methods public for access
      loans(){    //creating a loan constructor to set defaults
         firstName = "Default";  //setting first name variable's default
         surname = "Default";  //setting surname variable's default
         emailAddress = "nameSurname@gmail.com"; //setting email address variable's default
         amountApplied = 0;  //setting amount applied variable's default to 0
         status = "Pending"; //setting status variable's default as "pending"
         next = NULL;    //setting the pointer to null
         }

};
//main menu function
void main_menu();//declare globally
//pointers
loans *FRONT = NULL, *REAR = NULL; //application list pointers
loans *TOP = NULL; //stack pointer
//a function to add new application
void addApplication(){
	cout<<"____________Add Applications__________________"<<endl;
    string fName, surname, emailAddress; //declaring string variables to store string values
    int amount; //declaring int variable to store int value
    loans *new_loan = new loans(); // creating a node for loan applications

    //step 1, prompt user to insert attributes
        cout<<"Please Enter First Name: \t";
	    cin>>fName;                        //prompt user to enter first name
	    cout<<endl;
	    cout<<"Please Enter Surname: \t";
	    cin>>surname;                     //prompt user to enter surname
	    cout<<endl;
	    cout<<"Please Enter Email Address: \t";
	    cin>>emailAddress;               //prompt user to enter email address
	    cout<<endl;
	    cout<<"Please Enter the Amount Applied For (M): \t";
	    cin>>amount;                     //prompt user to enter an amount
	    cout<<endl;

    //step2, set attributes to data inserted
        new_loan->firstName = fName;
		new_loan->surname = surname;
	    new_loan->emailAddress = emailAddress;
	    new_loan->amountApplied = amount;
       //step3, check if the list is empty
     if (FRONT == NULL) // if the list is empty
      {
        FRONT = new_loan; //set Front to new node
	    REAR = new_loan;  //set Rear to new node
        FRONT->next = NULL; //set front's next field to null
		REAR->next = NULL; //set rear's next field to null
	  }
	   else //step 4, if the list is not empty
     {
        REAR->next = new_loan; //set rear's next field to new application node
        REAR = new_loan;  // set rear  to new application node
        REAR->next = NULL; //set rear's next field to null
	 }
    cout<<"Do You Wish To Add Another Application?(enter '1' to continue, or any number to go to the main menu): ";
	       int reply; //declare variable to store replies
           cin>>reply; //prompt user to reply
	       if(reply == 1) //if the user wants to continue
	       {
	       	 addApplication();
		   }
		   else //if the user does not want to continue
		   {
		   	 main_menu(); //return to main menu
		   }

}
//Creating a function to update status
void updateStatus(){ //Creating a function to update status
     cout<<"____________Update Status__________________"<<endl;
    //declaring variables
    string email,status;
    bool found = false;
    //declare a temporary pointer and initialize it to front pointer
    loans *temporary_pointer = FRONT;
    //step1, prompt user to enter applications
     cout<< "Please Enter The Email Address of the applicant: \t";
     cin>> email;  //prompt user to enter email to search application as the key
    //step2, check if list is empty
    if(temporary_pointer == NULL) //if the temporary pointer is null
        {
            cout<<"There are no applications to update status"<<endl; //display this message
            main_menu();
        }
	//step3 traverse the list and look for the node with email similar to inserted email
    while(temporary_pointer != NULL) //loop till null
        {
            if(temporary_pointer->emailAddress == email) //if the email address at the temporary pointer matches with the email inserted
            {
                found= true;
                break;  //goto step4
            }
            temporary_pointer = temporary_pointer->next; //point the temporary pointer to the next node
        }
    //step4, if the node is found
    if(found)
    {
        cout<<"Please Enter the status of the amount M"<<temporary_pointer->amountApplied<<":";// display a messages and amount applied
        cin>>status;                    //prompt user to insert status
        temporary_pointer->status = status;  //set status where the temporary pointer is to the status entered
        cout<<"Application Status Successfully updated"<<endl; //display message
    }
    else  // if the application is not found
    {
         cout<<"Application not found/available"<<endl; //display message
    }
    //step 5, check if the user wants to continue updating status
    cout<<"Do You Wish To Update Status of Another Application?(enter '1' to continue, or any number to go to the main menu): ";
    int reply; //declare variable to store replies
    //prompt user to reply
    cin>>reply;
    if(reply == 1) //if the user wants to continue
    {
        updateStatus();
    }
    else //if the user does not want to continue
    {
        main_menu(); //return to main menu
    }

}

//delete application
void storeDeletedApplications(loans *delete_loan);

void deleteApplication(){
    string email; //declaring variables
    cout<<"____________Delete an Application__________________"<<endl;
    //step 0, declare a temporary pointer and initialize it to front pointer
    loans *current = FRONT;
    loans *previous = NULL;

	//step 1, prompt user to insert search key
	cout<< "Please Enter The Email Address of the applicant to be deleted: \t";
    cin>> email;  //prompt user to enter email to search application as the key

    //step 2, check if loan application list is empty
    if (current == NULL)
    {
        cout<<"There are no applications to update"<<endl; //display message
        main_menu(); //return to main menu
    }
    //step 3, traverse list, look for a node with similar email
    while(current != NULL && current->emailAddress != email) //loop till null or email found
    {
        previous = current; //before moving to the next node, move previous to current
        current = current->next; // move to the next node
    }
    //step 4, if not found
	if(current == NULL)
    {
        cout<<"Application not found"<<endl; //display message
        goto STEP8;
    }
    //step 5, if found:
    if(previous == NULL) // check if it exists at the beginning of the list
    {
        FRONT = current->next;  //point the front to the next node
    }
    else  //if it does not exist at the beginning og the list
    {
        previous->next = current->next; //next pointer of previous point to the node after current
    }
    //step 6, add node to be deleted to the stack
    storeDeletedApplications(current);
    // step 7, release memory and delete node
    delete current; // release memory and delete node
    cout<<"Application successfully deleted"<<endl;
    //step 8, check if the user wants to continue deleting
	STEP8: cout<<"Do You Wish To Delete Another Application?(enter '1' to continue, or any number to go to the main menu): ";
    int reply; //declare variable to store replies
    //prompt user to reply
    cin>>reply;
    if(reply == 1) //if the user wants to continue
    {
        deleteApplication();
    }
    else //if the user does not want to continue
    {
        main_menu(); //return to main menu
    }
}
//store deleted applications in a stack
void storeDeletedApplications(loans *delete_loan){
           //1. create a new node and retrieve data from the top node of the stack
			loans *pushStack = new loans(); //creating new node for recovered data
        	//retrieving information from the node to be deleted
            pushStack->firstName = delete_loan->firstName;
            pushStack->surname = delete_loan->surname;
            pushStack->emailAddress = delete_loan->emailAddress;
            pushStack->amountApplied = delete_loan->amountApplied;
            pushStack->status = delete_loan->status;
		   // 2. if the list is empty
    	if (TOP == NULL)
		    {
		        TOP = pushStack; //set top to new deleted loan instance
		    }
		else //3. if the list is not empty
		{
			pushStack->next = TOP; //next pointer of new to point to the top
			TOP = pushStack; //new node set on the top
		}
}
//display all deleted applications
void displayDeletedApplications()
{
	cout<<"____________Deleted Applications__________________"<<endl;
	//step 0, declare a temporary pointer and initialize it to top of the stack
	STEP0: loans *temporary_pointer = TOP;
     //step 1, if the stack is empty
    if (temporary_pointer == NULL)
    {
        cout<<"There are no deleted applications to view"<<endl; //display message
        main_menu();
    }
   	//step 2, traverse list and display attributes
   	while(temporary_pointer != NULL)  //loop till pointer reaches the bottom of the stack
    {
        //display attributes
        cout<<"First Name:\t"<<temporary_pointer->firstName<<endl;
        cout<<"Surname:\t"<<temporary_pointer->surname<<endl;
        cout<<"Email Address:\t"<<temporary_pointer->emailAddress<<endl;
        cout<<"Amount Applied:\t"<<temporary_pointer->amountApplied<<endl;
        cout<<"Status:\t"<<temporary_pointer->status<<endl;
        cout<<"_______________________________________________________________"<<endl;

        temporary_pointer = temporary_pointer->next; //point to the next node
    }
    cout<<"You have reached the bottom of the stack"<<endl; //when done, display message
     //step 3, check if the user wants to continue
	cout<<"Do You Wish To View Applications Again?(enter '1' to continue, or any number to go to the main menu): ";
    int reply; //declare variable to store replies
    //prompt user to reply
    cin>>reply;
    if(reply == 1) //if the user wants to continue
    {
        goto STEP0;
    }
    else //if the user does not want to continue
    {
        main_menu(); //return to main menu
    }
}
//display all applications
void displayApplications(){
    cout<<"____________All Applications__________________"<<endl;
	//step 0, declare a temporary pointer and initialize it to front pointer
	STEP0: loans *temporary_pointer = FRONT;
     //if the list is null
    if (temporary_pointer == NULL)
    {
        cout<<"There are no applications to display"<<endl; //display message
        main();
    }
    //step 2, traverse the list and display attributes
    while(temporary_pointer != NULL)  //loop till pointer reaches the end
    {   //display attributes
        cout<<"First Name:\t"<<temporary_pointer->firstName<<endl;
        cout<<"Surname:\t"<<temporary_pointer->surname<<endl;
        cout<<"Email Address:\t"<<temporary_pointer->emailAddress<<endl;
        cout<<"Amount Applied:\t"<<temporary_pointer->amountApplied<<endl;
        cout<<"Status:\t"<<temporary_pointer->status<<endl;
        cout<<"_______________________________________________________________"<<endl;
        temporary_pointer = temporary_pointer->next; //point to the next node
    }
    cout<<"You have reached the end of the list"<<endl; //when done, display message
    //step 3, check if the user wants to continue updating status
	cout<<"Do You Wish To Display Applications Again?(enter '1' to continue, or any number to go to the main menu): ";
    int reply; //declare variable to store replies
    //prompt user to reply
    cin>>reply;
    if(reply == 1) //if the user wants to continue
        goto STEP0;
    else //if the user does not want to continue
        main_menu(); //return to main menu

}
//recover applications
void recoverDeletedApplication(){
	       loans *temporary = TOP;
          //step 1, if the stack is empty
          if (TOP == NULL)
		  {
	        cout<<"There are no applications to recover"<<endl; //display message
	        main_menu(); //return to main menu
   	      }
   	      else // if the stack is not empty
          {
               //step 2, loop till top is null
                while (TOP != NULL) {
                	temporary = TOP;
                    //step 3, memory allocation for a new node
                    loans *pop = new loans();
                    //step 4, set new node's attribute to top node's attribute
                    pop->firstName = temporary->firstName;
                    pop->surname = temporary->surname;
                    pop->emailAddress = temporary->emailAddress;
                    pop->amountApplied = temporary->amountApplied;
                    pop->status = "pending";  //set to default status
                    //step 5, check if the application's list is empty
                    if (FRONT == NULL) { //if the list is empty
                        FRONT = pop; //set front to pop node
                        REAR = pop;  //set rear to pop node
                        FRONT->next = NULL; // set front's next pointer to null
                    } else {
                        REAR->next = pop; // set rear's next pointer to the address of the popped node
                        REAR = pop;       // set rear to pop node

                    }
                     REAR->next = NULL; // set rear's next pointer to null

                    TOP = TOP->next;//step 6. move top to the previous node
                    delete temporary;//step 7, delete pop
                }
   	      }
        cout<<"You have recovered all the application"<<endl; //when done, display message
        main_menu();
}
//lookup an application
void lookupApplication(){
    string email;
    cout<<"____________Lookup Applications__________________"<<endl;
    //step 0, declare a temporary pointer and initialize it to front pointer
    STEP0: loans *temporary_pointer = FRONT;
           bool found = false;
    //step 1, //prompt user to enter email to search application as the key
    cout<< "Please Enter The Email Address of the applicant to lookup: \t";
    cin>> email;
    //step 2, check if list is empty
    if(temporary_pointer == NULL) //if the temporary pointer is empty
    {
        cout<<"There are currently no applications to lookup "<<endl; //display the message
        main_menu(); //return to main menu
    }
    //step 3, traverse list and find node with similar email inserted
    while(temporary_pointer != NULL) //loop while temporary pointer is not null
    {
        if(temporary_pointer->emailAddress == email) //if the email address at the temporary pointer matches with the email inserted
        {
            found = true;   //to indicate that the application was found
            cout<<"The Address of the current node:\t "<< temporary_pointer<<endl;// display a message and address
            cout<<"The Address of the next node:\t"<< temporary_pointer->next<<endl; //display message and value of next
            break;
        }
            temporary_pointer = temporary_pointer->next; //point the temporary pointer to the next node
    }
    //step 4, if the application is not found in the list
    if (!found) // if the application is not found
    {
        cout<<"Application not found/available"<<endl; //display message
    }
	//step 5, check if the user wants to continue
	cout<<"Do You Wish To lookup another Application?(enter '1' to continue, or any number to go to the main menu): ";
    int reply; //declare variable to store replies
    //prompt user to reply
    cin>>reply;
    if(reply == 1) //if the user wants to continue
    {
        goto STEP0;
    }
    else //if the user does not want to continue
    {
        main_menu(); //return to main menu
    }
}
// display accepted loans function
void displayAcceptedLoans(){
	cout<<"____________Accepted Applications__________________"<<endl;
    //step 0, declare a temporary pointer and initialize it to front pointer
    STEP0: loans *temporary_pointer = FRONT;
           bool found = false;
    //step 1, check if list null
	if (temporary_pointer == NULL)
    {
        cout<<"There are no applications to display"<<endl;// if the list is null, display message
        main_menu();
    }
	//step 2, Traverse list and display attributes where status is accepted
    while(temporary_pointer != NULL) //loop till it reaches the end of the list
    {   //if the accepted / approved status matches status at the node
        if (temporary_pointer->status == "approved" || temporary_pointer->status == "accepted" )
        {
            found = true;
            //display attributes
            cout<<"Status:\t"<<temporary_pointer->status<<endl;
            cout<<"First Name:\t"<<temporary_pointer->firstName<<endl;
            cout<<"Surname:\t"<<temporary_pointer->surname<<endl;
            cout<<"Email Address:\t"<<temporary_pointer->emailAddress<<endl;
            cout<<"Amount Applied:\t"<<temporary_pointer->amountApplied<<endl;
            cout<<"_______________________________________________________________"<<endl;
        }
        temporary_pointer = temporary_pointer->next; //go to the next node
    }
     //step 3, if the application is not found in the list
    if (!found) // if the application is not found{
        cout<<"Application not found/available"<<endl; //display message
    //step 4, check if the user wants to continue
	cout<<"Do You Wish To Display Accepted Applications Again?(enter '1' to continue, or any number to go to the main menu): ";
    int reply; //declare variable to store replies
    //prompt user to reply
    cin>>reply;
    if(reply == 1) //if the user wants to continue
        goto STEP0;
    else //if the user does not want to continue
        main(); //return to main menu
}
void main_menu()
{//system menu
 int choice; //declare variable to store option choosen
 //menu layout and options
 cout <<"___________________________________________________"<<endl;
 cout <<"__________________SYSTEM MENU______________________"<<endl;
 cout << "1. New Loan Applications"<<endl;
 cout << "2. Update Loan Status"<<endl;
 cout << "3. Delete Loan Application"<<endl;
 cout << "4. Display All Applications"<<endl;
 cout << "5. Lookup An Application"<<endl;
 cout << "6. Display Accepted Applications"<<endl;
 cout << "7. Display Deleted Applications"<<endl;
 cout << "8. Recover Applications"<<endl;
 cout << "9. Exit program"<<endl<<endl;
 cout <<"____________________________________________________"<<endl;
 cout <<"Enter Option:\t";
 //prompt user to enter option
 cin>>choice;
 switch(choice)
 {
 	case 1:
 		addApplication(); //if 1 is inserted ,call addApplication function
 	case 2:
 		updateStatus();  //if 2 is inserted ,call updateStatus function
 	case 3:
 		deleteApplication();   //if 3 is inserted, call deleteApplication function
 	case 4:
	    displayApplications();   //if 4 is inserted, call displayApplication function
	case 5:
	    lookupApplication();   // if 5 is inserted, call lookupApplication function
	case 6:
	    displayAcceptedLoans(); //if 6 is inserted, call displayAcceptedLoans function
	case 7:
		displayDeletedApplications(); //if 7 is inserted, call displayDeletedApplications function
	case 8:
		recoverDeletedApplication(); //if 8 is inserted , call recoverDeletedApplication function
	case 9:
		exit(0);    //if 9 is inserted , exit program
	default:
		cout<<"Invalid Input"<<endl;     //if any number greater than 9 and less than 1 is inserted , display message
 }
}
int main(){
 main_menu();
return 0;
}
