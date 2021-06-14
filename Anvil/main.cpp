#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void Parse(std::string buffer)
{
	std::vector<int>memory(16384, 0);
	int tmem = 0;
	int head = 0;
	unsigned long long pos = 0;
	for (unsigned long long i = 0; i < (unsigned long long)buffer.size(); i++)
	{
		char k = buffer[i];
		switch (k)
		{
		case 'l':
			head--;
			break;
		case 'r':
			head++;
			break;
		case 'o':
			std::cout << (char)memory[head];
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
		case 'f':
			if (tmem == memory[head])
			{
				i = pos - 1ULL;
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
		case '+':
			memory[head] += 10;
			break;
		case '-':
			memory[head] -= 10;
			break;
		case 'y':
			memory[head] = 0;
			break;
		case ';':
			if (tmem > 0)
				i = pos - 1ULL;
			break;
		case ':':
			tmem--;
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
	else if (argc == 0)
	{
		std::cout << "Did not specify a path to an Anvil file." << std::endl;
		return 0;
	}
	std::string path = std::string(argv[1]);
	std::ifstream op(path);
	std::string buffer;
	op >> buffer;
	Parse(buffer);
	return 0;
}