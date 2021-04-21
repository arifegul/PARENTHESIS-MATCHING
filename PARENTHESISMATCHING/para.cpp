#include<stdio.h>
#include<string.h>
#include<ctype.h> // Used for isalnum () function

#define MAXSIZE 50 // Maximum array size for stack

//I created stack data structure
struct Stack {
    int top;
    int stk[MAXSIZE];
} st;

void initialValue() {	//The default initial value of top is -1.
 st.top = -1;
}

void push(char); //The current character is a starting bracket (‘(‘ or ‘{‘ or ‘[‘)  //Add element
int pop(); //The current character is a closing bracket (‘)’ or ‘}’ or ‘]’) then pop from stack //Element exit


void push(char value) {
	
	if(st.top == MAXSIZE-1)
	printf("Stack is Full!");  // If the stack is full, I can't add elements. 
	//So I first checked if the directory is full.
	
	else {
	st.top++;
    st.stk[st.top] = value;  
	//If the array is not full, a new element can be added. 
	//For this, I assigned the number to the index by increasing the ball value from -1 at the beginning.
	}
}

int pop() {
	
    if(st.top == -1)  // First I checked if the stack is empty.
        return -1;
    else
    	return st.stk[st.top--]; //If the array is not empty, the element can be omitted. 
		//This can only be done by decreasing the top value by 1.
}

int precedence(char value)	//Function written for priority order
{
    if(value == '(' || value == '[' || value == '{' )
        return 0;
    if(value == '+' || value == '-')
        return 1;
    if(value == '*' || value == '/')
        return 2;
    return 0;
}

int main() {

    char expression[100];
    char *exp, value; // 'e' is the character value to be processed.
    
    printf("\nEnter the Expression: ");
    scanf("%s",expression);
    
    exp = expression;
    

    while(*exp != '\0') {
    	
    	if(isalnum(*exp)) //Checks whether the 'e' parameter value passed in the Expression is a letter or a number in the alphabet.
        	printf("%c ",*exp); 
			
        	
    	else if(*exp == '(') // Expression is pushed if it starts with parentheses
		
        	push(*exp);
        else if(*exp == ')') // If Expression is the closing parenthesis, pops the values up to the opening brackets
        {
            while((value = pop()) != '(')
                printf("%c ", value);

        }


        else if(*exp == '{')	// Expression is pushed if it starts with parentheses
            push(*exp);
        else if(*exp == '}')	// If Expression is the closing parenthesis, pops the values up to the opening brackets
        {
            while((value = pop()) != '{')
                printf("%c ", value);
        }
        
        
        else if(*exp == '[')	// Expression is pushed if it starts with parentheses
            push(*exp);
        else if(*exp == ']')
        {
            while((value = pop()) != '[')	// If Expression is the closing parenthesis, pops the values up to the opening brackets
                printf("%c ", value);
        }
        
	
		else
        {
          	while(precedence(st.stk[st.top]) >= precedence(*exp)) 
            printf("%c ",pop()); //Expression values are subtracted from the array until it reaches top.Pop function is applied.
            push(*exp); //Then the entire expression is pushed.
            

        }
        exp++;
    }
    
    while(st.top != -1)
    {
        printf("%c ",pop());	//Expression subtracts values until the top value reaches -1, i.e. until the array ends.
    }
	
	
	return 0;

}


