#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

string computeSingleParityBit(string senderData)
{
    cout << "Computing Parity Bit using Even Parity..." << endl;
    string data = senderData;
    int numberOfOnes = 0;
    for (int i = 0; i < data.length(); i++)
    {
        if (data[i] == '1')
        {
            numberOfOnes++;
        }
    }
    if (numberOfOnes % 2 == 0)
    {
        data.append("0");
    }
    else
    {
        data.append("1");
    }
    cout << "Coded Data : " << data << endl;
    cout << endl;
    return data;
}

string corruptData(string data)
{

    cout << "Simulating Corruption of data" << endl;
    cout << "Corrupting the first digit of data" << endl;
    string corruptedData = data;
    if (corruptedData[0] == '0')
    {
        corruptedData[0] = '1';
    }
    else
    {
        corruptedData[0] = '0';
    }
    cout << "Data successfully corrupted" << endl;
    cout << "First Bit Flipped" << endl;
    cout << "Corrupted Data :" << corruptedData << endl;
    cout << endl;

    return corruptedData;
}

void checkSingleParity(string codedData)
{
    cout << "Checking Parity Bit using Even Parity..." << endl;
    string data = codedData;
    int numberOfOnes = 0;
    for (int i = 0; i < data.length(); i++)
    {
        if (data[i] == '1')
        {
            numberOfOnes++;
        }
    }
    if (numberOfOnes % 2 == 0)
    {
        cout << "No pariy error, but there could be corruption of Data" << endl;
    }
    else
    {
        cout << "Data Corrupted" << endl;
    }
}

int main()
{
    string senderData;
    cout << "Enter the data to be coded : ";
    cin >> senderData;
    cout << "Sender Side" << endl;
    string codedData = computeSingleParityBit(senderData);
    cout << "Do you want to simulate Corruption of Data?" << endl;
    string corrupt = "";
    cin >> corrupt;
    if (corrupt == "Y" || corrupt == "y")
    {
        string corruptedCodedData = corruptData(codedData);
        cout << "Using Single Parity" << endl;
        cout << "Coded String is : " << corruptedCodedData << endl;
        cout << "Receiver Side" << endl;
        checkSingleParity(corruptedCodedData);
    }
    else
    {
        cout << "Using Single Parity" << endl;
        cout << "Coded String is : " << codedData << endl;
        cout << "Receiver Side" << endl;
        checkSingleParity(codedData);
    }
}