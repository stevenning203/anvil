#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdlib>

int FParse(std::string& function, std::vector<std::string>& functions)
{
	std::vector<int>memory(128, 0);
	int tmem = 0, head = 0, pos = 0, return_register = 0;
	std::stack<int> heads, fp;
	for (int i = 0; i < (int)function.size(); i++)
	{
		char k = function[i];
		switch (k)
		{
		case '?':
			memory[head] = return_register;
			break;
		case 'j':
			i = pos - 1;
			break;
		case '!':
			std::cout << "HEAD LOCATION: " << head << " ||| DATA AT HEAD: " << memory[head] << " ||| RETURN REGISTER: " << return_register << std::endl;
			break;
		case 'f':
			if (memory[head] <= 1)
			{
				std::cout << "Invalid function number. Must be greater than or equal to 2." << std::endl;
				return 0;
			}
			return_register = FParse(functions[memory[head]], functions);
			break;
		case 'F':
			return memory[head];
			break;
		case '@':
			head = 0;
			break;
		case '#':
			std::cout.flush();
			system("cls");
			break;
		case '*':
			std::fill(memory.begin(), memory.end(), 0);
			break;
		case 'l':
			head--;
			break;
		case 'r':
			head++;
			break;
		case 'o':
			std::cout << (char)memory[head];
			break;
		case '%':
			std::cout << memory[head];
			break;
		case 'i':
			memory[head]++;
			break;
		case 'd':
			memory[head]--;
			break;
		case 's':
			std::cin >> memory[head];
			break;
		case 'b':
			std::cout << std::endl;
			break;
		case 'a':
			memory[head] += tmem;
			break;
		case 'q':
			tmem = memory[head];
			break;
		case '=':
			if (tmem != memory[head])
			{
				i++;
			}
			break;
		case 'p':
			pos = memory[head];
			break;
		case '>':
			head += 10;
			break;
		case '<':
			head -= 10;
			break;
		case '\\':
			head += 50;
			break;
		case '/':
			head -= 50;
			break;
		case '+':
			memory[head] += 10;
			break;
		case '-':
			memory[head] -= 10;
			break;
		case 'y':
			memory[head] = 0;
			break;
		case '[':
			heads.push(i);
			break;
		case ']':
			if (memory[head] > 0)
			{
				i = heads.top() - 1;
				heads.pop();
			}
			break;
		}

		if (head < 0 || head >= memory.size())
		{
			std::cout << "Pointer head out of bonds: " << head << std::endl;
			return 0;
		}
	}
	return 0;
}

void Parse(std::string& buffer, std::vector<std::string>& functions, bool debug = false)
{
	std::vector<int>memory(32768, 0);
	int tmem = 0, head = 0, pos = 0, return_register = 0;
	std::stack<int> heads, fp;
	for (int i = 0; i < (int)buffer.size(); i++)
	{
		char k = buffer[i];
		switch (k)
		{
		case '?':
			memory[head] = return_register;
			break;
		case 'f':
			if (memory[head] <= 1)
			{
				std::cout << "Invalid function number. Must be greater than or equal to 2." << std::endl;
				return;
			}
			return_register = FParse(functions[memory[head]], functions);
			break;
		case 'j':
			i = pos - 1;
			break;
		case '!':
			std::cout << "HEAD LOCATION: " << head << " ||| DATA AT HEAD: " << memory[head] << " ||| RETURN REGISTER: " << return_register << std::endl;
			break;
		case '@':
			head = 0;
			break;
		case '#':
			std::cout.flush();
			system("cls");
			break;
		case '*':
			std::fill(memory.begin(), memory.end(), 0);
			break;
		case 'l':
			head--;
			break;
		case 'r':
			head++;
			break;
		case 'o':
			std::cout << (char)memory[head];
			break;
		case '%':
			std::cout << memory[head];
			break;
		case 'i':
			memory[head]++;
			break;
		case 'd':
			memory[head]--;
			break;
		case 's':
			std::cin >> memory[head];
			break;
		case 'b':
			std::cout << std::endl;
			break;
		case 'a':
			memory[head] += tmem;
			break;
		case 'q':
			tmem = memory[head];
			break;
		case '=':
			if (tmem != memory[head])
			{
				i++;
			}
			break;
		case 'p':
			pos = memory[head];
			break;
		case '>':
			head += 10;
			break;
		case '<':
			head -= 10;
			break;
		case '\\':
			head += 50;
			break;
		case '/':
			head -= 50;
			break;
		case '+':
			memory[head] += 10;
			break;
		case '-':
			memory[head] -= 10;
			break;
		case 'y':
			memory[head] = 0;
			break;
		case '[':
			heads.push(i);
			break;
		case ']':
			if (memory[head] > 0)
			{
				i = heads.top() - 1;
				heads.pop();
			}
			break;
		}
		
		if (head < 0 || head >= memory.size())
		{
			std::cout << "Pointer head out of bonds: " << head << std::endl;
			return;
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc > 2)
	{
		std::cout << "Too many arguments: " << argc << std::endl;
		return 0;
	}
	else if (argc == 1)
	{
		std::cout << "Did not specify a path to an Anvil file." << std::endl;
		return 0;
	}
	std::string path = std::string(argv[1]);
	std::ifstream op(path);
	std::string buffer, line;
	std::vector<std::string> functions;
	functions.push_back("");
	functions.push_back("");
	op >> buffer;
	while (op.good())
	{
		op >> line;
		functions.push_back(line);
	}
	Parse(buffer, functions);
	return 0;
}