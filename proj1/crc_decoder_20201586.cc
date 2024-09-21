#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <cstdlib>
#include <deque>
#include <sstream>

using namespace std;

// deocde dataword size 4
char decode_size_4(string input, int generator_size)
{
    bitset<8> decoded_1(input.substr(0, 4));
    bitset<8> decoded_2(input.substr(3 + generator_size, 4));
    decoded_1 <<= 4;
    decoded_1 ^= decoded_2;
    return char(decoded_1.to_ulong());
}

// check there is error, if not return true
bool CRC_check_size_4(string input, string generator, int generator_size)
{
    bitset<203> dataword(input);
    bitset<203> generator_bit(generator);
    for (int i = 2 + generator_size; i >= 0; i--)
    {
        if (dataword.test(i))
        {
            dataword ^= (generator_bit << (i - generator_size + 1));
        }
    }
    return dataword.to_ulong() == 0;
}

// deocde dataword size 4
char decode_size_8(string input, int generator_size)
{
    bitset<8> decoded(input.substr(0, 8));
    return char(decoded.to_ulong());
}

// check there is error, if not return true
bool CRC_check_size_8(string input, string generator, int generator_size)
{
    bitset<207> dataword(input);
    bitset<207> generator_bit(generator);
    for (int i = 6 + generator_size; i >= 0; i--)
    {
        if (dataword.test(i))
        {
            dataword ^= (generator_bit << (i - generator_size + 1));
        }
    }
    return dataword.to_ulong() == 0;
}

int main(int argc, char *argv[])
{
    int dataword_size;
    // input, output file open
    ifstream input_file(argv[1]);
    ofstream output_file(argv[2], ios::binary);
    ofstream result_file(argv[3]);
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
    if (!result_file.is_open())
    {
        cout << "result file open error\n";
        return 1;
    }

    if (atoi(argv[5]) == 4)
    {
        dataword_size = 4;
    }
    else if (atoi(argv[5]) == 8)
    {
        dataword_size = 8;
    }
    else
    {
        cout << "dataword size must be 4 or 8\n";
        return 1;
    }

    // get generator
    string generator = argv[4];
    int generator_size = generator.size();

    // index of reading input_file
    int idx = 8;
    // read input
    string input;
    stringstream ss;

    // read bits
    unsigned char byte;
    while (input_file.read(reinterpret_cast<char *>(&byte), sizeof(byte)))
    {
        bitset<8> bits(byte);
        ss << bits;
    }
    input = ss.str();

    // remvoe pedding
    bitset<8> padding_num_bit(input.substr(0, 8));
    int padding_num = padding_num_bit.to_ulong();
    idx += padding_num;

    // total frame num and valid frame num
    int total_frame_num = (input.size() - 8 - padding_num) / (dataword_size + generator_size - 1);
    int error_frame_num = 0;

    // cut input into dataword and decode and write, check it's error or not
    if (dataword_size == 4)
    {
        while (idx < input.size())
        {
            output_file << decode_size_4(input.substr(idx, 6 + (generator_size * 2)), generator_size);
            if (!CRC_check_size_4(input.substr(idx, 3 + generator_size), generator, generator_size))
                error_frame_num++;
            if (!CRC_check_size_4(input.substr(idx + 3 + generator_size, 3 + generator_size), generator, generator_size))
                error_frame_num++;
            idx += 6 + (generator_size * 2);
        }
    }
    // dataword_size == 8
    else
    {
        while (idx < input.size())
        {
            output_file << decode_size_8(input.substr(idx, 7 + generator_size), generator_size);
            if (!CRC_check_size_8(input.substr(idx, 7 + generator_size), generator, generator_size))
                error_frame_num++;
            idx += (7 + generator_size);
        }
    }

    // write result file
    result_file << total_frame_num << " " << error_frame_num;

    return 0;
}