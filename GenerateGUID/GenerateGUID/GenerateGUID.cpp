#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void SaveGuidToBinaryFile(const GUID& guid, const string& file_path)
{
    ofstream file(file_path, ios::binary);

    if (file.is_open())
    {
        file.write(reinterpret_cast<const char*>(&guid), sizeof(GUID));
        file.close();
    }
    else 
    {
        cerr << "The binary file cannot be opened for writing!" << endl;
    }
}

void SaveGuidToTextFile(const GUID& guid, const string& file_path) 
{
    ostringstream oss;
    oss << uppercase << hex << setfill('0')
        << setw(8) << guid.Data1 << "-"
        << setw(4) << guid.Data2 << "-"
        << setw(4) << guid.Data3 << "-"
        << setw(2) << static_cast<int>(guid.Data4[0])
        << setw(2) << static_cast<int>(guid.Data4[1]) << "-"
        << setw(2) << static_cast<int>(guid.Data4[2])
        << setw(2) << static_cast<int>(guid.Data4[3])
        << setw(2) << static_cast<int>(guid.Data4[4])
        << setw(2) << static_cast<int>(guid.Data4[5])
        << setw(2) << static_cast<int>(guid.Data4[6])
        << setw(2) << static_cast<int>(guid.Data4[7]);

    string guidStr = oss.str();
    string outputText = "GUID generated_guid = {" + guidStr + "};\n";

    ofstream file(file_path);
    if (file.is_open()) 
    {
        file << outputText;
        file.close();
    }
    else 
    {
        cerr << "The text file cannot be opened for writing!" << endl;
    }
}

int main()
{
    GUID guid;
    if (CoCreateGuid(&guid) == S_OK)
    {   
        SaveGuidToBinaryFile(guid, "guid.bin");
        SaveGuidToTextFile(guid, "guid.txt");

        cout << "GUID generated and saved!" << endl;
    }
    else
    {
        cerr << "Failed to generate GUID!" << endl;
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}