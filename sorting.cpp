#include <iostream>
using namespace std;

void calculate(string sample, int* get)
{
    int q = 0;
    get[0] = 0;
    int i = 1;
    while (i < sample.size())
    {
        if (sample[i] == sample[q])
        {
            q++;
            get[i] = q;
            i++;
        }
        else
        {
            if (q != 0)
            {
                q = get[q - 1];
            }
            else
            {
                get[i] = 0;
                i++;
            }
        }
    }
}

int Search(const string& sample, const string& text)
{
    int* score = new int[sample.size()];
    calculate(sample, score);

    int counter = 0;
    int i = 0;
    int q = 0;
    while (i < text.size())
    {
        if (sample[q] == text[i])
        {
            q++;
            i++;
        }
        if (q == sample.size())
        {
            cout << "Найден по индексу(periodic)\t" << i - q << endl;
            q = score[q - 1];
            counter++;
        }
        else if (i < text.size() && sample[q] != text[i])
        {
            if (q != 0)
            {
                q = score[q - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
    delete[] score;
    return counter;
}

