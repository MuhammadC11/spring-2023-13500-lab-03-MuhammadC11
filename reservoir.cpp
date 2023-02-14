#include <iostream>
#include <fstream>

double get_east_storage(std::string date)
{

    std::ifstream inp_file("Current_Reservoir_Levels.tsv"); // required for file input

    if (inp_file.fail()) // if program can't open file
    {
        std::cerr << "File cannot be opened for reading." << std::endl; // error message
        exit(1);                                                        // exit if failed to open the file
    }

    // skipping first line because the first line is not data but headers
    std::string junk;
    std::getline(inp_file, junk);

    // file reading

    std::string entry_date, east_basin_storage; // data from csv

    while (inp_file >> entry_date >> east_basin_storage)
    {

        if (date == entry_date)
        {
            return std::stold(east_basin_storage);
        }

        inp_file.ignore(INT_MAX, '\n'); // skips to the end of line,
    }

    inp_file.close(); // closing the stream
    return -1;
}