/***********************************************************************
* Program:
*  Lab08 VULNERABILITIES & EXPLOITS
* Author:
*  CSE 453 Group 3
* Summary:
* 
************************************************************************/
#include <iostream>
#include <array>
#include <string>
#include <cassert>

using namespace std;
void pointerVulnerability(long * array, int size);
void pointerWorking();
void pointerExploit();

void arrayVulnerability(int input1, int input2);
void arrayWorking();
void arrayExploit();

void integerVulnerability(unsigned short deposit);
void integerWorking();
void integerExploit();

void arcVulnerability(char * input);
void arcWorking();
void arcExploit();

void stackVulnerability(char input[]);
void stackWorking();
void stackExploit();

void heapVulnerability(int input[]);
void heapWorking();
void heapExploit();

//add comment

int main()
{   
   // menu
      cout << "Select the test you want to run:\n";
   cout << "\t1. Array Index\n";
   cout << "\t2. Pointer Subterfuge\n";
   cout << "\t3. ARC Injection\n";
   cout << "\t4. Vtable Spraying\n";
   cout << "\t5. Stack Smashing\n";
   cout << "\t6. Heap Spraying\n";
   cout << "\t7. Integer Overflow\n";
   cout << "\t8. ANSI-Unicode Conversion\n";

   char choice;
   cout << "> ";
   cin >> choice;
   switch (choice)
   {
   case 'a':

      break;
   case '1':
      arrayWorking();
      arrayExploit();
      cout << "Array Index *In Development*\n";
      break;
   case '2':
      pointerWorking();
      pointerExploit();
      cout << "Pointer Subterfuge *In Development*\n";
      break;
   case '3':
      arcWorking();
      arcExploit();
      cout << "ARC Injection\n";
      break;
   case '4':

      cout << "VTable Spraying *Not Implimented*\n";
      break;
   case '5':
      stackWorking();
      stackExploit();
      cout << "Stack Smashing *Not Implimented*";
      break;
   case '6':
      heapWorking();
      heapExploit();
      cout << "Heap Spraying *Not Implimented*";
      break;
   case '7':
      integerWorking();
      integerExploit();
      cout << "Integer Overflow Complete?";
      break;
   case '8':

      cout << "ANSI-Unicode Conversion *Not Implimented*";
      break;
   default:
      cout << "Unrecognized command, exiting...\n";
   }
   return 0;
}

// ARRAY INDEX
/************************************************************************
 * ARRAY VULNERABILTY
 * 1. There must be an array and an array index variable
 * 2. The array index variable must be reachable through external input.
 * 3. There must not be bounds checking on the array index variable.
************************************************************************/
//change to retuen a data type
void arrayVulnerability(int input1, int input2)
{
   
   int grade[] = {90, 70, 60};
  
   
   grade[input1] = input2;
   
   int count = 0;

   try {
      
      for (int grade : grade)
      {
         cout << "Element " << count << " : " << grade << endl;
         count++;
      }
   }
   catch (...) {
   
      cout << "Error " << endl;
   
   };
}

/***********************************************************************
 * ARRAY WORKING
 * Call arrayVulnerability() in a way that does
 * not yield unexpected behavior
 **********************************************************************/
void arrayWorking()
{
   cout << "Array Index without Exploit" << endl;
   arrayVulnerability(0, 70);
  
}

/***********************************************************************
 * ARRAY EXPLOIT
 * 1. The attacker provides an array index value outside the expected range
 * 2. The attacker must be able to provide input or redirect
 *    existing input into the array at the index he provided
 * 3. The injected value must alter program state in a way
 *    that is desirable to the attacker
 **********************************************************************/
void arrayExploit()
{
   cout << "Array Index with Exploit" << endl;
   arrayVulnerability(3, 100);
}

// POINTER SUBTERFUGE
/**********************************************************************
 * Pointer VULNERABILTY
 * 1. There must be a pointer used in the code.
 *************************************************************************/
void pointerVulnerability(long * array, int size)
//void pointerVulnerability(const char *input1)
{
   /*long buffer[1];
   long buffer[2]; 
   const char * message = "Safe";
   for (int i = 0; i < size; i++)
   {
      buffer[i] = array[i];
   }
   cout << "Message is: \"" << message << "\".\n";
}

/***********************************************************************
 * Pointer WORKING
 * Call pointerVulnerability() in a way that does
 * not yield unexpected behavior
 **********************************************************************/
void pointerWorking()
{
   long array[1] = { 1 };
   pointerVulnerability(array, 1);
}

/***********************************************************************
 * Pointer EXPLOIT
 * 1. The attacker must exploit a vulnerability allowing unintended access to
 **********************************************************************/
void pointerExploit()
{
   //4197490
   //pointerVulnerability("Safe\0");
   // an attacker�s array
   long array[3] = {1, 1, (long)"Dangerous"};
   // exploit it
   pointerVulnerability(array, 3);
}

//ARC INJECTION
/**********************************************************************
 *  ARC VULNERABILTY
 *  1. There must be a function pointer used in the code.
 *************************************************************************/
void arcVulnerability(char * input)
{
   long buffer[1];
   //void (*pointerFunction)() = input;
   cin >> buffer[1];
  // cout << pointerFunction() << endl;
}

/***********************************************************************
 *  ARC WORKING
 *  Call arcVulnerability() in a way that does
 *  not yield unexpected behavior
 **********************************************************************/
void arcWorking()
{
   cout << "Arc Injection with Exploit" << endl;
   //arcVulnerability(safe);
}

/***********************************************************************
 * ARC EXPLOIT
 * 1. The attacker must exploit a vulnerability allowing unintended access to
 **********************************************************************/
void arcExploit()
{
   cout << "Arc Injection with Exploit" << endl;
   //arcVulnerability(dangerous);
}

//VTABLE SPRAYING
/**********************************************************************
 *  VTABLE VULNERABILTY
 *  1. The vulnerable class must be polymorphic.
 **********************************************************************/
void vtableVulnerability(/* feel free to add parameters */)
{
}

/***********************************************************************
 *  VTABLE WORKING
 *  Call vtableVulnerabilityy() in a way that does
 *  not yield unexpected behavior
 **********************************************************************/
void vatableWorking()
{
   vtableVulnerability(/* parameters with non-malicious data */);
}

/***********************************************************************
 * VTABLE EXPLOIT
 * 1. Through some vulnerability, the V-Table pointer or a function pointer
 *********************************************************************/
void vtableExploit()
{
   vtableVulnerability(/* parameters with malicious data */);
}

//STACK SMASHING
/**********************************************************************
 * STACK VULNERABILTY
 * 1. There must be a buffer (such as an array) on the stack.
 *********************************************************************/
void stackVulnerability(char input[])
{
   char text[8]; 
   strcpy_s(text, sizeof(input), input);
}

/***********************************************************************
 *  STACK WORKING
 *  Call stackVulnerability() in a way that does
 *  not yield unexpected behavior
 **********************************************************************/
void stackWorking()
{
   cout << "Stack Smashing Working" << endl;
   char array[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
   stackVulnerability(array);
}

/***********************************************************************
 * STACK EXPLOIT
 * 1. The attacker must provide more data into the outwardly facing buffer
 **********************************************************************/
void stackExploit()
{
   cout << "Stack Smahing Exploit" << endl;
   char array[] = { 1, 2, 3, 4, 5, 6, 7, 8};
   stackVulnerability(array);
}

//HEAP SPRAYING
/**********************************************************************
 * HEAP VULNERABILTY
 * 1. There must be two adjacent heap buffers.
 *************************************************************************/
void heapVulnerability(int input[])
{
   int * buffer1 = new int[4];  
   buffer1 = input;
   delete [] buffer1;
}

/***********************************************************************
 *  HEAP WORKING
 *  Call heapVulnerability() in a way that does
 *  not yield unexpected behavior
 **********************************************************************/
void heapWorking()
{
   cout << "Heap Working" << endl;
   int input[4] = { 1, 2, 3, 4 };   
   heapVulnerability(input);
}

/***********************************************************************
 * HEAP EXPLOIT
 * 1. The attacker must provide more data into the outwardly facing heap
 **********************************************************************/
void heapExploit()
{
   cout << "Heap Exploit" << endl;
   int input1[8] = { 1, 2, 3, 4, 5, 6 ,7 ,8 };  
   heapVulnerability(input1);
}

//INTEGER OVERFLOW
/**********************************************************************
 * INTEGER VULNERABILTY
 * 1. There must be a security check represented by an expression.
 *********************************************************************/
void integerVulnerability(unsigned short deposit)
{
   short balance = 100;
   cout << "Current Balance: " << balance << endl;
   cout << "Enter the deposit ammount: " << endl;
   cout << deposit << endl;
   if (deposit > 0)
   {
      balance += deposit;
   }
   cout << "New balance: " << balance << endl;   
}

/***********************************************************************
 *  INTEGER WORKING
 *  Call integerVulnerability() in a way that does
 *  not yield unexpected behavior
 **********************************************************************/
void integerWorking()
{
   integerVulnerability(246);
}

/***********************************************************************
 * INTEGER EXPLOIT
 * 1. Provide input, either a buffer size or a single value, that is directly or
 **********************************************************************/
void integerExploit()
{
   integerVulnerability(-1);
}

//ANSI-UNICODE CONVERSION
/**********************************************************************
 * UNICODE VULNERABILTY
 * 1. There must be a buffer where the basetype is greater than one.
 *********************************************************************/
void unicodeVulnerability(/* feel free to add parameters */)
{
}

/***********************************************************************
 *  UNICODE WORKING
 *  Call unicodeVulnerability() in a way that does
 *  not yield unexpected behavior
 **********************************************************************/
void unicodeWorking()
{
   unicodeVulnerability(/* parameters with non-malicious data */);
}

/***********************************************************************
 * UNICODE EXPLOIT
 * 1. The attacker must provide more than half as much data into the
 **********************************************************************/
void unicodeExploit()
{
   unicodeVulnerability(/* parameters with malicious data */);
}