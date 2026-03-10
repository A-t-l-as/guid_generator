#include "System/MyGuid.hpp"
#include "File/BinFile.hpp"
#include "File/TextFile.hpp"
#include "Console/Console.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    MyGuid guid;

    BinFile output_bin_file;
    guid.WriteTo(output_bin_file);
    output_bin_file.SaveTo("guid.bin");

    TextFile output_txt_file;

    const string guid_line = "GUID generated_guid = " + guid.ToString() + ";\n";
    output_txt_file << guid_line;

    output_txt_file.SaveOnlyStringStream("guid.txt");

    if(argc == 2)
    {
        if(string(argv[1]) == "-p")
        {
            CONSOLE_OUT.PrintLn(guid_line);
        }
        else
        {
            CONSOLE_OUT.PrintLn("Undefined switch. ",
                                "If you just want to generate a GUID,",
                                " simply run the program. ",
                                "If you want to display the GUID in the console, add the -p switch.");
        }
    }
    else
    {
        CONSOLE_OUT.PrintLn("GUID generated and saved!");
    }

    exit(EXIT_SUCCESS);
}
