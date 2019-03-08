//=========================================================
//HW#: HW1P1 stack
//Your name: David Garcia
//Complier:  g++
//File type: client program for stack
//===========================================================

using namespace std;
#include <cstdlib>
#include <iostream>
#include <string>
#include "stack.h"

//Purpose of the program: Uses a stack to make an integer postfix expression calculator
//                        that can add, subtract, and muliply.
//Algorithm: Asks the user for an expression which it stores into a string variable,
//           named expression. Using the string class it breaks down the string into
//           an array of chracters ending with the NULL charcter ('\0'). The while   
//           loop keeps going until it reaches the NULL charcter, adding operands to
//           the stack and poping them when there is a operator. Finally it pops
//           the result and displays it.
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "Type a postfix expression: ";
  cin >> expression; //Get input from user
  
  int i = 0;  // character position within expression
  char item;  // one character out of the expression
  
  int box1, box2;  // receive things from pop
  
  //While it doesn't reach the end of expression
  while (expression[i] != '\0')
    {
       try
	{
	  item = expression[i];  // current character from expression
	  
	  //2.  if it is an operand (number), 
	  //    push it (you might get Overflow exception)
	  //    subtract 48 to turn char into correct int
	  if(isdigit(item)) postfixstack.push(item - 48);
	  
	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	apply the operator to the two operands, and
	  //    push the result.
	  else if ( (item == '+') || (item == '-') || (item == '*'))
	    {
	      postfixstack.pop(box1); //Pop 1st operand, store in box1 
	      postfixstack.pop(box2); //Pop 2nd operand, store in box2
	      //cases for different operators follow:
	      switch(item) //Switch case uses current iteam being checked
		{
		  //check what operator is in item and push the
		  //result of the first operand operator operand
		case '+': postfixstack.push(box2 + box1); break;
		case '-': postfixstack.push(box2 - box1); break;
		case '*': postfixstack.push(box2 * box1); break;
		}
	    }
	  //If it's neither a number or valid operator throw invalid item
	  else throw "Invalid item entered";
	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{
	  cout << "Error: Expression is too long\n"; exit(1);
	}
      catch (stack::Underflow) // for too few operands
	{
	  cout << "Error: Not enough numbers\n"; exit(1);
	}
      catch (char const* errorcode) // for invalid item
	{
	  cout << "Error: " << errorcode << endl; exit(1);
	}
       i++; // go back to the loop after incrementing i
    }// end of while
  
  // After the loop successfully completes: 
  // The result will be at the top of the stack. Pop it and show it.
  postfixstack.pop(box1); 
  cout << "Result: " << box1 << endl;
  // If anything is left on the stack, an incomplete expression was found.
  // Inform the user.
  try
    {
      //If there is something in the stack throw error code
      if(!postfixstack.isEmpty()) throw "Incomplete expression was found";
    }
  catch(stack::Underflow) // There was nothing in the stack :) end program
    {
      return 0;
    }
  catch(char const* errorcode)
    {
      cout << "Error: " << errorcode << endl; return 0;
    }
  
}// end of the program 
