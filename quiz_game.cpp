#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
using namespace std;

struct Questions
{
    string text;
    vector<string> options;
    char corrans;
};

int calaculatepoints(char useranswer, char corrans)
{

    if (tolower(useranswer) == corrans)
    {

        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    vector<Questions> questions;
    ifstream inputfile("rand_questions.txt");

    if (!inputfile)
    {

        cout << "unabel to open file!" << endl;

        return 1;
    }

    string line;

    while (getline(inputfile, line))
    {

        size_t delimter1 = line.find('|');
        size_t delimter2 = line.rfind('|');

        string text = line.substr(0, delimter1);
        string optionsStr = line.substr(delimter1 + 1, delimter2 - delimter1 - 1);
        string corrans = line.substr(delimter2 + 1);

        vector<string> options;

        size_t pos = 0;

        while ((pos = optionsStr.find(',')) != string::npos)
        {

            options.push_back(optionsStr.substr(0, pos));
            optionsStr.erase(0, pos + 1);
        }
        options.push_back(optionsStr);

        Questions newquestions = {text, options, corrans[0]};
        questions.push_back(newquestions);
    }

    inputfile.close();

    char useranswer;
    int totalscore = 0;

    cout << "answer the following questions" << endl;

    for (int i = 0; i < questions.size(); i++)
    {
        cout << i + 1 << "." << questions[i].text << endl;
        for (int j = 0; j < questions[i].options.size(); j++)
        {

            cout << " " << char('a' + j) << ")" << questions[i].options[j] << endl;
        }

        cout << "enter your choice" << endl;
        cin >> useranswer;

        totalscore += calaculatepoints(useranswer, questions[i].corrans);

        if (tolower(useranswer) == questions[i].corrans)
        {
            cout << "correct!" << endl;
        }
        else
        {
            cout << "incorrect " << "the correct answer is: " << questions[i].corrans "/" questions.size() << endl;
        }
    }

    cout << " your final score is: " << totalscore;

    return 0;
}