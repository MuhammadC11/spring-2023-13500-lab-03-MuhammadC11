#include <iostream>
#include <fstream>

void reverse_order(std::string
                       date1,
                   std::string date2)
{

    std::ifstream data_file("Current_Reservoir_Levels.tsv"); // required for file input
    if (data_file.fail())                                    // if program can't open file
    {
        std::cerr << "File cannot be opened for reading." << std::endl; // error message
        exit(1);                                                        // exit if failed to open the file
    }

    // skipping first line because the first line is not data but headers
    std::string junk;
    std::getline(data_file, junk);

    std::string dataDate;
    double eastStorage;
    double eastElevation;
    double westStorage; // data from csv
    double westElevation;
    double westArray[365];
    std::string dateArray[365];
    int index = 0;
    bool startWrite = false;

    while (data_file >> dataDate >> eastStorage >> eastElevation >> westStorage >> westElevation) // reads the file line by line and stores it in the variables declared above until the file ends or an error occurs in reading the file.
    {
        if (dataDate == date1)
        {
            startWrite = true;
        }

        if (startWrite)
        {
            westArray[index] = westStorage;
            dateArray[index] = dataDate;
            index++;
        }
        if (dataDate == date2)
        {
            startWrite = false;
        }

        data_file.ignore(INT_MAX, '\n'); // skips to the end of line, ignores the remaining columns in the line and moves to the next line in the file to read the next line of data in the file. INT_MAX is the maximum value of int. As soon as it reads east storage, it will ignore the rest of the line and move to the next line.
    }

    data_file.close(); // closing the stream
    for (int i = index - 1; i >= 0; i--)
    {
        std::cout << dateArray[i] << " " << westArray[i] << std::endl;
    }
}