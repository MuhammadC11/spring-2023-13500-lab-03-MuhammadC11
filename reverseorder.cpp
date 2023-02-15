#include <iostream>
#include <fstream>

void reverse_order(std::string
                       date1,
                   std::string date2)
{

    std::ifstream data_file("Current_Reservoir_Levels.tsv"); // opens the file for reading
    if (data_file.fail())                                    // if program can't open file
    {
        std::cerr << "File cannot be opened for reading." << std::endl; // error message
        exit(1);                                                        // exit if failed to open the file
    }

    std::string junk; // skipping first line because the first line is not data but headers
    std::getline(data_file, junk);

    std::string dataDate;
    double eastStorage;
    double eastElevation;
    double westStorage; // data from csv
    double westElevation;
    double westArray[365];
    std::string dateArray[365];
    int index = 0;
    bool startWrite = false; // indicates whether to start writing to the array or not based on a condition which is if the date is equal to the date1.

    while (data_file >> dataDate >> eastStorage >> eastElevation >> westStorage >> westElevation) // reads the file line by line and stores it in the variables declared above until the file ends or an error occurs in reading the file. Variable names should match the names in the file in order.
    {
        if (dataDate == date1) // if the date in the file is equal to the date1 during the loop
        {
            startWrite = true; // set the startWrite to true so that the data can be written to the array
        }

        if (startWrite) // if startWrite is true
        {
            westArray[index] = westStorage; // write the storage data to the westArray
            dateArray[index] = dataDate;    // write the current date to the dateArray
            index++;                        // increment the index
        }
        if (dataDate == date2) // if the date in the file is equal to the date2 during the loop
        {
            startWrite = false; // set the startWrite to false so that the data cannot be written to the array
        }

        data_file.ignore(INT_MAX, '\n'); // skips to the end of line, ignores the remaining columns in the line and moves to the next line in the file to read the next line of data in the file. INT_MAX is the maximum value of int. As soon as it reads east storage, it will ignore the rest of the line and move to the next line.
    }

    data_file.close();                   // closing the stream
    for (int i = index - 1; i >= 0; i--) // print the array in reverse order. The index is decremented by 1 because the index is incremented by 1 at the end of the loop. So the index will be 1 more than the actual number of elements in the array.
    {
        std::cout << dateArray[i] << " " << westArray[i] << std::endl; // print the date and the storage data at the index i
    }
}