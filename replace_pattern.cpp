#include <iostream>
#include <string>
using namespace std;

int main() {
    string text, pattern, replacement;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter pattern to replace: ";
    getline(cin, pattern);

    cout << "Enter replacement string: ";
    getline(cin, replacement);

    int pos = text.find(pattern);

    while(pos != string::npos) {
        text.replace(pos, pattern.length(), replacement);
        pos = text.find(pattern, pos + replacement.length());
    }

    cout << "Updated text:\n" << text;

    return 0;
}
