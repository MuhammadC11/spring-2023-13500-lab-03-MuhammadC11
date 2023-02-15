#include <iostream>
#include <fstream>

double get_east_storage(std::string date)
{

    std::ifstream data_file("Current_Reservoir_Levels.tsv"); // required for file input

    if (data_file.fail()) // if program can't open file
    {
        std::cerr << "File cannot be opened for reading." << std::endl; // error message
        exit(1);                                                        // exit if failed to open the file
    }

    std::string junk; // skipping first line because the first line is not data but headers
    std::getline(data_file, junk);

    std::string dataDate;
    double eastStorage; // data from csv

    while (data_file >> dataDate >> eastStorage) // reads the file line by line and stores it in the variables declared above until the file ends or an error occurs in reading the file.
    {

        if (date == dataDate) // if the date is found
        {
            return eastStorage; // return the value of east basin storage as a double value and exit the function
        }

        data_file.ignore(INT_MAX, '\n'); // skips to the end of line, ignores the remaining columns in the line and moves to the next line in the file to read the next line of data in the file. INT_MAX is the maximum value of int. As soon as it reads east storage, it will ignore the rest of the line and move to the next line.
    }

    data_file.close();
    return 0;
}

double get_min_east()
{
    std::ifstream data_file("Current_Reservoir_Levels.tsv"); // required for file input

    if (data_file.fail()) // if program can't open file
    {
        std::cerr << "File cannot be opened for reading." << std::endl; // error message
        exit(1);                                                        // exit if failed to open the file
    }

    // skipping first line because the first line is not data but headers
    std::string junk;
    std::getline(data_file, junk);

    std::string dataDate;
    double eastStorage;              // data from csv
    double minStorage = 10000000000; // variable to store the minimum value of east basin storage starting at first value in the file

    while (data_file >> dataDate >> eastStorage) // reads the file line by line and stores it in the variables declared above until the file ends or an error occurs in reading the file.
    {

        if (eastStorage < minStorage) // if the value of east basin storage is less than the current minimum value
        {
            minStorage = eastStorage; // set the minimum value to the current value of east basin storage
        }

        data_file.ignore(INT_MAX, '\n'); // skips to the end of line, ignores the remaining columns in the line and moves to the next line in the file to read the next line of data in the file. INT_MAX is the maximum value of int. As soon as it reads east storage, it will ignore the rest of the line and move to the next line.
    }

    data_file.close(); // closing the stream
    return minStorage;
}

double get_max_east()
{
    std::ifstream data_file("Current_Reservoir_Levels.tsv"); // required for file input

    if (data_file.fail()) // if program can't open file
    {
        std::cerr << "File cannot be opened for reading." << std::endl; // error message
        exit(1);                                                        // exit if failed to open the file
    }

    // skipping first line because the first line is not data but headers
    std::string junk;
    std::getline(data_file, junk);

    std::string dataDate;
    double eastStorage;    // data from csv
    double maxStorage = 0; // variable to store the minimum value of east basin storage starting at first value in the file

    while (data_file >> dataDate >> eastStorage) // reads the file line by line and stores it in the variables declared above until the file ends or an error occurs in reading the file.
    {

        if (eastStorage > maxStorage) // if the value of east basin storage is greater than the current maximum value
        {
            maxStorage = eastStorage; // set the maximum value to the current value of east basin storage
        }

        data_file.ignore(INT_MAX, '\n'); // skips to the end of line, ignores the remaining columns in the line and moves to the next line in the file to read the next line of data in the file. INT_MAX is the maximum value of int. As soon as it reads east storage, it will ignore the rest of the line and move to the next line.
    }

    data_file.close(); // closing the stream
    return maxStorage;
}

std::string compare_basins(std::string date)
{
    std::ifstream data_file("Current_Reservoir_Levels.tsv"); // required for file input

    if (data_file.fail()) // if program can't open file
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

    while (data_file >> dataDate >> eastStorage >> eastElevation >> westStorage >> westElevation) // reads the file line by line and stores it in the variables declared above until the file ends or an error occurs in reading the file.
    {

        if (date == dataDate) // if the date is found
        {
            if (eastElevation > westElevation) // if the elevation of east basin is greater than the elevation of west basin
            {
                return "East"; // return "East"
            }
            else if (eastElevation < westElevation) // if the elevation of east basin is less than the elevation of west basin
            {
                return "West"; // return "West"
            }
            else
            {
                return "Equal"; // return "Equal"
            }
        }

        data_file.ignore(INT_MAX, '\n'); // skips to the end of line, ignores the remaining columns in the line and moves to the next line in the file to read the next line of data in the file. INT_MAX is the maximum value of int. As soon as it reads east storage, it will ignore the rest of the line and move to the next line.
    }

    data_file.close(); // closing the stream
    return 0;
}