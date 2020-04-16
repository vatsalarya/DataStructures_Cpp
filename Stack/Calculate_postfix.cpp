#include<iostream>
#include<stack>
#include<string>
using namespace std;

int EvaluatePostfix(string expression);
int PerformOperation(char operation, int operand1, int operand2);
bool IsOperator(char C);
bool IsNumericDigit(char C);

int main() {
	string expression; 
	cout<<"Enter Postfix Expression \n";
	getline(cin,expression);
	int result = EvaluatePostfix(expression);
	cout<<"Output = "<<result<<"\n";
}

int EvaluatePostfix(string expression){
	
	stack<int> S;
	for(int i = 0;i< expression.length();i++) {
		// Scanning each character from left. 
		// If character is a delimitter, move on. 
		if(expression[i] == ' ' || expression[i] == ',') continue; 

		// If character is operator, pop two elements from stack, perform operation and push the result back. 
		else if(IsOperator(expression[i])) {
			// Pop two operands. 
			int operand2 = S.top(); S.pop();
			int operand1 = S.top(); S.pop();

			// Perform operation
			int result = PerformOperation(expression[i], operand1, operand2);

			//Push back result of operation on stack. 
			S.push(result);
		}

		else if(IsNumericDigit(expression[i])){
			int operand = 0; 
			while(i<expression.length() && IsNumericDigit(expression[i])) {

				// For a number with more than one digits, as we are scanning from left to right. 
				operand = (operand*10) + (expression[i] - '0'); 
				i++;
			}
			// decrement i because it has now gone out of the numbers ie it is now dialemeter or operator
			i--;

			// Push operand on stack. 
			S.push(operand);
		}
	}

	// If expression is in correct format, Stack will finally have one element. This will be the output. 
	return S.top();
}

// Function to verify whether a character is numeric digit. 
bool IsNumericDigit(char C){
	if(C >= '0' && C <= '9') return true;
	return false;
}

// Function to verify whether a character is operator symbol or not. 
bool IsOperator(char C){
	if(C == '+' || C == '-' || C == '*' || C == '/')
		return true;
	return false;
}

// Function to perform an operation and return output. 
int PerformOperation(char operation, int operand1, int operand2){
	if(operation == '+') return operand1 +operand2;
	else if(operation == '-') return operand1 - operand2;
	else if(operation == '*') return operand1 * operand2;
	else if(operation == '/') return operand1 / operand2;
	else cout<<"Unexpected Error \n";
	return -1; 
}