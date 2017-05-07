#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

// Infix Prefix Postfix

// SIWAKORN RUENRIT, 04/07/2016
// 2559-2 305233 Pre-Exam 3
// ======================================
// Infix to Postfix and Calculate Postfix
// ======================================
//
// Convert Infix to Postfix
//
//    operator_stack
//    postfix_stack (operand)
//
//    while in infix_string index
//        if found operand
//            push current_operand to postfix_stack
//        if found operator
//            if operator_stack == null
//                push current_operator to operator_stack
//            else
//                if current_operator == ')'
//                    pop top_operator_in_stack and push to postfix_stack, until found '(' and erase '(', ')'
//                else if current_operator more important than top_operator_in_stack
//                    push current_operator to operator_stack
//                else
//                    while priority_of current_operator less than or equal top top_operator_in_stack
//                        pop top_operator_in_stack and push to postfix_stack
//                    push current_operator to operator_stack
//    if operator_stack != null
//        push all element from last_index in operator_stack to postfix_stack
//

// if you want to convert infix to prefix
// 1. reverse infix form = reverse_infix
// 2. convert reverse_infix to postfix
// 3. reverse postfix form

void display_vector(vector<string> arr);
bool is_operator(char op);
int priority_of_operator(string op1, string op2);
vector<string> infix_to_postfix(string text);
double postfix_calculate(vector<string> postfix);
double prefix_calculate(vector<string> prefix);
double power(int a, int b);
string reverse_infix(string text, int len);
string stack_to_string(vector<string> &Stack);

int main()
{
    string text = {"((2^5)*3)+(9*2)-(7/8)-9"};
    string reverse_text;
    reverse_text = reverse_infix(text, text.length());

    // Postfix // -----------------------------------------
    vector<string> postfix = infix_to_postfix(text);
    cout << "Postfix: ";
    display_vector(postfix);
    cout << "Result: " << postfix_calculate(postfix);
    cout << endl << endl;


    // Prefix // -----------------------------------------
    vector<string> prefix = infix_to_postfix(reverse_text);
    reverse(prefix.begin(), prefix.end());
    cout << "Prefix: ";
    display_vector(prefix);
    cout << "Result: " << prefix_calculate(prefix);
    cout << endl << endl;

}

string reverse_infix(string text, int len)
{
    string reverse_text;
    for (int i = len - 1; i >= 0; --i)
    {
        if (text[i] == '(') {
            reverse_text += ')';
        }
        else if (text[i] == ')') {
            reverse_text += '(';
        }
        else {
            reverse_text += text[i];
        }
    }
    return reverse_text;
}

double postfix_calculate(vector<string> postfix)
{
    vector<double> calculate;
    int calculate_size;
    for (int i = 0; i < postfix.size(); ++i) {
        calculate_size = calculate.size();

        if (postfix[i] == "+") {
            calculate[calculate_size - 2] = calculate[calculate_size - 1] + calculate[calculate_size - 2];
            calculate.pop_back();
        }
        else if (postfix[i] == "-") {
            calculate[calculate_size - 2] = calculate[calculate_size - 2] - calculate[calculate_size - 1];
            calculate.pop_back();
        }
        else if (postfix[i] == "*") {
            calculate[calculate_size - 2] = calculate[calculate_size - 1] * calculate[calculate_size - 2];
            calculate.pop_back();
        }
        else if (postfix[i] == "/") {
            calculate[calculate_size - 2] = calculate[calculate_size - 2] / calculate[calculate_size - 1];
            calculate.pop_back();
        }
        else if (postfix[i] == "%") {
            calculate[calculate_size - 2] = fmod(calculate[calculate_size - 2], calculate[calculate_size - 1]);
            calculate.pop_back();
        }
        else if (postfix[i] == "^") {
            calculate[calculate_size - 2] = power(calculate[calculate_size - 2], calculate[calculate_size - 1]);
            calculate.pop_back();
        }
        else {
            double value;
            istringstream(postfix[i]) >> value;
            calculate.push_back(value);
        }
    }

    return calculate[0];
}

double prefix_calculate(vector<string> prefix)
{
    vector<double> calculate;
    int calculate_size;
    for (int i = prefix.size() - 1; i >= 0; --i) {
        calculate_size = calculate.size();

        if (prefix[i] == "+") {
            calculate[calculate_size - 2] = calculate[calculate_size - 1] + calculate[calculate_size - 2];
            calculate.pop_back();
        }
        else if (prefix[i] == "-") {
            calculate[calculate_size - 2] = calculate[calculate_size - 1] - calculate[calculate_size - 2];
            calculate.pop_back();
        }
        else if (prefix[i] == "*") {
            calculate[calculate_size - 2] = calculate[calculate_size - 1] * calculate[calculate_size - 2];
            calculate.pop_back();
        }
        else if (prefix[i] == "/") {
            calculate[calculate_size - 2] = calculate[calculate_size - 1] / calculate[calculate_size - 2];
            calculate.pop_back();
        }
        else if (prefix[i] == "%") {
            calculate[calculate_size - 2] = fmod(calculate[calculate_size - 1], calculate[calculate_size - 2]);
            calculate.pop_back();
        }
        else if (prefix[i] == "^") {
            calculate[calculate_size - 2] = power(calculate[calculate_size - 1], calculate[calculate_size - 2]);
            calculate.pop_back();
        }
        else {
            double value;
            istringstream(prefix[i]) >> value;
            calculate.push_back(value);
        }
    }

    return calculate[0];
}

vector<string> infix_to_postfix(string text)
{
    string infix;
    string temp;
    vector<string> operator_stack;
    vector<string> postfix_stack;

    for (int i = 0; i < text.length(); ++i) if (text[i] != ' ') infix += text[i];

    cout << "Infix: " << infix << endl;

    for (int i = 0; i < infix.length(); ++i) {
//        if found operand
//            push current_operand to postfix_stack
        if (!is_operator(infix[i])) {
            temp += infix[i];
            if (is_operator(infix[i + 1]) || i == infix.length() - 1) {
                postfix_stack.push_back(temp);
                temp.clear();
            }
        }
        else {
//        if found operator
//            if operator stack == null
//                push current_operator to operator_stack
            if (operator_stack.size() == 0) {
                temp += infix[i];
                operator_stack.push_back(temp);
                temp.clear();
            }
            else {
                temp += infix[i];
//                if current_operator == ')'
//                    pop top_operator_in_stack and push to postfix_stack, until found '(' and erase '(', ')'
                if (temp == ")") {
                    int k = operator_stack.size() - 1;
                    while (operator_stack[k] != "(") {
                        postfix_stack.push_back(operator_stack[operator_stack.size() - 1]);
                        operator_stack.pop_back();
                        --k;
                    }
                    operator_stack.pop_back();
                }
//                if current_operator more important than top_operator_in_stack
//                    push current_operator to operator_stack
                else if (priority_of_operator(temp, operator_stack[operator_stack.size() - 1]) == 1) {
                    operator_stack.push_back(temp);
                }

//                else
//                    while priority_of current_operator less than or equal top top_operator_in_stack
//                        pop top_operator_in_stack and push to postfix_stack
//                    push current_operator to operator_stack
                else {
                    while (operator_stack.size() > 0 && (priority_of_operator(temp, operator_stack[operator_stack.size() - 1]) == -1 ||
                            priority_of_operator(temp, operator_stack[operator_stack.size() - 1]) == 0)) {

                        postfix_stack.push_back(operator_stack[operator_stack.size() - 1]);
                        operator_stack.pop_back();
                    }
                    operator_stack.push_back(temp);
                }
                temp.clear();
            }
        }
    }
//    if operator_stack != null
//        push all element in operator_stack to postfix_stack
    if (operator_stack.size() > 0) {
        for (int i = operator_stack.size() - 1; i >= 0; --i) {
            postfix_stack.push_back(operator_stack[i]);
        }
    }


    return postfix_stack;
}

int priority_of_operator(string op1, string op2)
{
//    equal return 0
//    more than return 1
//    less than return -1
    string first_order[] = {"*", "/", "%"};
    string second_order[] = {"+", "-"};

    if (op2 == "(") return 1;
    if (op1 == "^") return 1;
    if (op2 == "^") return -1;

    for (int i = 0; i < 3; ++i) {
        if (op1 == first_order[i]) {
            for (int j = 0; j < 3; ++j) {
                if (op2 == first_order[j]) {
                    return 0;
                }
            }
            return 1;
        }
    }

    for (int i = 0; i < 2; ++i) {
        if (op1 == second_order[i]) {
            for (int j = 0; j < 2; ++j) {
                if (op2 == second_order[j]) {
                    return 0;
                }
            }
            return -1;
        }
    }
}

bool is_operator(char op)
{
    return op == '+' || op == '-' || op == '*' || op == '/' || op == '%' || op == '(' || op == ')' || op == '^';
}

void display_vector(vector<string> arr)
{
    for (int i = 0; i < arr.size(); ++i) cout << arr[i] << " ";
    cout << endl;
}

double power(int a, int b)
{
    double result = 1;
    for (int i = 0; i < b; ++i) {
        result *= a;
    }
    return result;
}

