// https://www.codewars.com/kata/54b42f9314d9229fd6000d9c

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

std::string duplicate_encoder(const std::string &word)
{
    // let's use std::map to count the number of unique characters
    map<char, int> counter;

    // iterate over each character in the word
    for (auto &c : word)
    {
        // convert to lower case
        const char lowerC = tolower(c);

        // check if char is in map
        if (!counter.count(lowerC))
            // if not, initialize to 0
            counter[lowerC] = 0;
        // increase to counter
        counter[lowerC] += 1;
    }

    // we start with an empty result string
    string result = "";

    // again iterate over each char in the word
    for (auto &c : word)
    {
        const char lowerC = tolower(c);
        // a bit of defensive programming
        if (counter[lowerC] < 1)
            return "character count can't be lower than 1";

        if (counter[lowerC] == 1) // char appeared once in the string
            result = result + "(";
        else
            result = result + ")"; // char appeared more than once in the string
    }
    return result;
}

int main()
{
    vector<string> words = {
        "din",
        "recede",
        "Success",
        "CodeWarrior",
        "Supralapsarian",
        "(( @",
        " ( ( )",
    };

    vector<string> results = {
        "(((",
        "()()()",
        ")())())",
        "()(((())())",
        ")()))()))))()(",
        "))((",
        ")))))(",
    };

    for (int i = 0; i < words.size(); i++)
    {
        string result = duplicate_encoder(words[i]);
        cout << words[i] << " => " << result << "\n";
        string answer = (result == results[i]) ? "correct" : "incorrect";
        cout << "answer is " << answer << "\n";
    }
}