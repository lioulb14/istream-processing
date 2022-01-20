#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::getline;

/*
 * Before running the program take a look at the following two pages:
 * --> getline:    http://cplusplus.com/reference/string/string/getline/
 * --> operator>>: http://cplusplus.com/reference/string/string/operator%3E%3E/
 *
 * 1. When does the getline function stop reading from the input stream?
 * - stops if the end of file is reached in is or if some other error occurs during the input operation.

 * 2. When does the operator>> stop reading from the input stream?
 * -
 */

int main() {
    /*
     * When you run the program,
     * try the following names:
     * not-here.txt
     * --> The program should respond:
     *     Unable to open not-here.txt
     * --> 3. Any idea why the output is shown in a different color?
     *
     * data.txt
     * 4. Was it able to open it? Any idea why?
     * -It wasn't able to open because file failed because its not in the right directory
     *
     * ../data.txt
     * This time the program must've been able to open the file
     * 5. Why do you think that is? A hint: where is the program running from?
     * -the "../" looks for it in the parent directory
     */

    string filename;
    cout << "Please input file name: ";
    cin >> filename;

    ifstream input;
    string string1, string2;

    input.open(filename);
    if (input.fail()){
        cerr << "Unable to open " << filename << endl;
        return 1;
    }
    /*
     * Notice in this part of the program that we are reading from the file
     * first by using the stream extraction operator >>
     * and then using the function getline
     * Notice the output.
     * 6. Why do you think the output looks like that?
     * -because in gets string2 as getline and not input>>
     *
     */
    input >> string1;
    getline(input, string2);
    cout << "input << string1;   getline(input, string2);" << endl;
    cout << "string1 = " << string1 << endl;
    cout << "string2 = " << string2 << endl;

    input.close(); // to reset
    input.open(filename);
    // Just in case
    if (input.fail()){
        cerr << "Unable to open " << filename << endl;
        return 1;
    }
    /*
     * Now the program is reading from the file but this time
     * first by using getline and then by using the stream operator >>
     * Is it different from the output you saw from the previous code?
     * 7. Why is that?
     * -While the first line only has "An" thats the full line but input>> only extracts Amazing  
     */
    getline(input, string1);
    input >> string2;
    cout << "getline(input, string2);   input << string1;" << endl;
    cout << "string1 = " << string1 << endl;
    cout << "string2 = " << string2 << endl;

    input.close();

    return 0;
}
