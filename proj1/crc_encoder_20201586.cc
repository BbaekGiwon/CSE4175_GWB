#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <cstdlib>
#include <deque>

using namespace std;

deque<char> output;

// generate codeword dataword size is 4
void gen_is_4_division(unsigned int dividend, string divisor)
{
    bitset<4> dividend_bit(dividend);
    bitset<203> divisor_bit(divisor);
    int divisor_size = divisor.size();

    bitset<203> temp(dividend);
    temp <<= divisor_size - 1;

    // do modulo2 cal
    for (int i = 2 + divisor_size; i >= divisor_size - 1; --i)
    {
        if (temp.test(i))
        {
            temp ^= divisor_bit << (i - divisor_size + 1);
        }
    }

    // push to output
    string str_dividend = dividend_bit.to_string();
    for (int i = 0; i < 4; i++)
    {
        output.push_back(str_dividend[i]);
    }
    string str_remain = temp.to_string();
    for (int i = temp.size() - divisor_size + 1; i < temp.size(); i++)
    {
        output.push_back(str_remain[i]);
    }
}

// generate codeword dataword size is 8
void gen_is_8_division(unsigned int dividend, string divisor)
{
    bitset<8> dividend_bit(dividend);
    bitset<207> divisor_bit(divisor);
    int divisor_size = divisor.size();

    bitset<207> temp(dividend);
    temp <<= divisor_size - 1;

    // do modulo2 cal
    for (int i = 6 + divisor_size; i >= divisor_size - 1; --i)
    {
        if (temp.test(i))
        {
            temp ^= divisor_bit << (i - divisor_size + 1);
        }
    }

    // push to output
    string str_dividend = dividend_bit.to_string();
    for (int i = 0; i < 8; i++)
    {
        output.push_back(str_dividend[i]);
    }
    string str_remain = temp.to_string();
    for (int i = temp.size() - divisor_size + 1; i < temp.size(); i++)
    {
        output.push_back(str_remain[i]);
    }
}

int main(int argc, char *argv[])
{
    int dataword;
    // input, output file open
    ifstream input_file(argv[1]);
    ofstream output_file(argv[2], ios::binary);
    // error check
    if (!input_file.is_open())
    {
        cout << "input file open error\n";
        return 1;
    }
    if (!output_file.is_open())
    {
        cout << "output file open error\n";
        return 1;
    }
    if (atoi(argv[4]) == 4)
    {
        dataword = 4;
    }
    else if (atoi(argv[4]) == 8)
    {
        dataword = 8;
    }
    else
    {
        cout << "dataword size must be 4 or 8\n";
        return 1;
    }

    // get generator
    string generator = argv[3];

    // read input file
    char input_char;
    unsigned int input_int;
    bitset<32> input_binary;
    while (input_file.get(input_char))
    {

        input_int = static_cast<int>(input_char);
        if (dataword == 4)
        {
            gen_is_4_division(input_int / 16, generator);
            gen_is_4_division(input_int % 16, generator);
        }
        // dataword == 8
        else
        {
            gen_is_8_division(input_int, generator);
        }
    }

    // add padding and calculate padding number
    int padding_num = (8 - output.size() % 8) % 8;
    for (int i = 0; i < padding_num; i++)
    {
        output.push_front('0');
    }
    bitset<8> padding_num_bin(padding_num);
    string padding_num_str = padding_num_bin.to_string();
    for (int i = 7; i >= 0; i--)
    {
        output.push_front(padding_num_str[i]);
    }

    // write output file in bits
    size_t numBytes = output.size() / 8;
    for (size_t i = 0; i < numBytes; ++i)
    {
        std::string bitString(output.begin() + i * 8, output.begin() + (i + 1) * 8); // read 8 bits
        std::bitset<8> bits(bitString);                                              // convert string to bitset
        unsigned char byte = static_cast<unsigned char>(bits.to_ulong());
        output_file.write(reinterpret_cast<const char *>(&byte), sizeof(byte));
    }

    // file close
    input_file.close();
    output_file.close();

    return 0;
}