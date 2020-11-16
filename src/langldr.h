#include <sstream>
#include <fstream>
#include <codecvt>

using namespace std;

string filename = "en_lang.lg"
wstring inputs[5];
    
locale utf8_locale(std::locale(), new gel::stdx::utf8cvt<true>);
wfstream fs;
fs.imbue(utf8_locale);

fs.open(filename, wfstream::in);
if (fs.is_open())
{
    int index = 0;
    while (!fs.eof() && index < 5)
    {
        getline(fs, inputs[index]);
        index++;
    }
    fs.close();
}

wcout << input[0] << endl;




