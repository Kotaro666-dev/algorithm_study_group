#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const double EPS = 1e-10;

void check_if_floating_point_exception(int num1, int num2)
{
    if (num1 == 0 || num2 == 0)
    {
        cout << "ERROR: SIGFPE" << endl;
        exit(128 + SIGFPE);
    }
}

int get_stack_top(stack<int> &my_stack)
{
    if (my_stack.empty())
    {
        cout << "ERROR: formula is wrong." << endl;
        exit(EXIT_FAILURE);
    }
    int num = my_stack.top();
    my_stack.pop();
    return (num);
}

void execute_calculation(char op, stack<int> &my_stack)
{
    int num1, num2, result;
    num1 = get_stack_top(my_stack);
    num2 = get_stack_top(my_stack);
    switch (op)
    {
        case '+':
            result = num2 + num1;
            break;
        case '-':
            result = num2 - num1;
            break;
        case '*':
            result = num2 * num1;
            break;
        case '/':
            check_if_floating_point_exception(num1, num2);
            result = num2 / num1;
            break;
        default:
            break;
    }
    my_stack.push(result);
}

int convert_char_to_int(char char_num)
{
    return (char_num - '0');
}

int main(void)
{
    string str;
    cin >> str;

    stack<int> my_stack;

    for (auto itr = str.begin(); itr != str.end(); itr++)
    {
        if (isdigit(*itr))
        {
            my_stack.push(convert_char_to_int(*itr));
        }
        else
        {
            execute_calculation(*itr, my_stack);
        }
    }
    cout << "result is " << my_stack.top() << endl;
    return (0);
}