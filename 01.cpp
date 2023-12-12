#include <iostream> 
#include <string>
#include <vector>
#include <fstream>


const std::string DIGITS[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
int main()
{
    int sum = 0;
    std::string in;
    std::ifstream inFile;
    inFile.open("inputs/01.txt");
    while (std::getline(inFile, in))
    {
        std::vector<char> digits;
        std::string temp = "";
        for (int i = 0; i < in.size();i++)
        {
            if (isdigit(in[i]))
            {
                digits.push_back((in[i]));
                temp = "";
            }
            else
            {
                temp += in[i];
                for (int j = 0; j < 9; j++)
                {
                    if (temp.find(DIGITS[j]) != std::string::npos)
                    {
                        digits.push_back(j + '1');
                        temp = temp.back(); // Allows to check for overlapping words 
                                            // Ex: eightwone
                    }
                }
            }
        }
        sum += (((digits.front() - '0') * 10) + (digits.back() - '0'));
    }
    inFile.close();
    std::cout << "Sum is: " << sum << std::endl;

    return 0;
}