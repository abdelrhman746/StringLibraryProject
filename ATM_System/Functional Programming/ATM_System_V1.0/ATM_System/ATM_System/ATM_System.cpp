#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

enum enMainMenueList { ShowClientList = 0, AddNewClient, DeleteClient, UpdateClientInfo, FindClient, TransactionsMenue, ManageUsers, Logout };
enum enTransactionMenue { Deposit = 1, Withdraw, TotalBalances, TransactionToMainMenue };
enum enManageUsers { ListUsers = 1, AddNewUser, DeleteUser, UpdateUser, FindUser, UsersToMainMenue };
enum enATMMainMenueList { QuickWithdraw = 1, NormalWithdraw, Deposite, CheckBalance, ATMLogout };
const string ClientsFileName = "Clients.txt";
const string UsersInfoFileName = "Users.txt";

enum enWhatToCount { SmallLetters, CapitalLetters, All };
enum enWhatToTrim { enTrimLeft, enTrimRight, enTrimAll };
short Choice = 0;
struct stUserInfo
{
    string UserName;
    string Password;
    short  Permission = 0;
    bool MarkForDelete = false;
};
struct stBankClientData
{
    string AccountNumber;
    string Pincode;
    string ClientName;
    string PhoneNumber;
    int AccountBalance;
    bool MarkForDelete = false;
};
stUserInfo CurrentUser;
stBankClientData CurrentClient;
void ShowMainMenue();
void ShowTransactionMenueScreen();
void ShowLoginScreen();
void ShowManageUsersMenue();
void ShowATMQuickWithdrawScreen(vector<stBankClientData>& vClients);
void ShowATMMainMenue(vector<stBankClientData>& vClients);
void ShowATMWithdrawScreen(vector<stBankClientData>& vClients);


short flag = 0;
int ReadPostiveNumber(string Message)
{
    int Number;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);

    return Number;

}
string ConvertAllLettersToLowerCase(string Words)
{
    for (int i = 0; i < Words.length(); i++)
    {
        Words[i] = tolower(Words[i]);
    }
    return Words;
}

string ConvertAllLettersToUpperCase(string Words)
{
    for (int i = 0; i < Words.length(); i++)
    {
        Words[i] = toupper(Words[i]);
    }
    return Words;
}
char InvertCharacterCase(char A)
{
    return (isupper(A) ? tolower(A) : toupper(A));
}
string InvertStringCase(string S1)
{
    int stringlength = S1.length();
    for (int i = 0; i < stringlength; i++)
    {
        if (isupper(S1[i]))
        {
            S1[i] = tolower(S1[i]);
        }
        else
        {
            S1[i] = toupper(S1[i]);
        }
    }
    return S1;
}
int GetSmallLetterCountInString(string S1)
{
    int counter = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (islower(S1[i]))
        {
            counter++;
        }
    }
    return counter;
}
int GetCapitalLetterCountInString(string S1)
{
    int counter = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
        {
            counter++;
        }
    }
    return counter;
}
int CountLetters(string S1, enWhatToCount WhatToCount)
{

    if (WhatToCount == enWhatToCount::CapitalLetters)
        return GetCapitalLetterCountInString(S1);
    else if (WhatToCount == enWhatToCount::SmallLetters)
        return GetSmallLetterCountInString(S1);
    else if (WhatToCount == enWhatToCount::All)
        return S1.length();
}
int CountCharInString(string S1, char A, bool MatchCase = true)
{
    int counter = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (MatchCase)
        {
            if (S1[i] == A)
                counter++;
        }
        else
        {
            if (tolower(S1[i]) == tolower(A))
                counter++;
        }


    }
    return counter;
}
bool IsVowel(char A)
{
    if (tolower(A) == 'a' || tolower(A) == 'e' || tolower(A) == 'i' || tolower(A) == 'o' || tolower(A) == 'u')
    {
        return true;
    }
    else
    {
        return false;
    }
}
int CountVowelsInString(string S1)
{
    int counter = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
            counter++;
    }
    return counter;
}
void PrintAllVowelsInString(string S1)
{
    cout << "\nVowels in String are : ";
    for (int i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
            cout << S1[i] << "  ";
    }
    cout << endl;
}
char ReadChar(string WordsUser)
{
    char A;
    cout << WordsUser;
    cin >> A;
    return A;
}
void PrintStringWords(string S1)
{
    string delim = " ";//delimiter

    cout << "\nYour string Words are : \n\n";

    short pos = 0;

    string sWord;

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            cout << sWord << endl;
        }
        S1.erase(0, pos + delim.length());
    }

    if (S1 != "")
    {
        cout << S1 << endl;
    }
}
int CountStringWords(string S1)
{
    int counter = 0;
    string sWord = "";
    string delim = " ";
    int pos;
    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            counter++;
        }
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
    {
        counter++;
    }
    return counter;
}
vector<string> SplitString(string S1, string Delim = "#//#")
{
    vector <string> vString;
    int pos = 0;
    string sWord;
    while (((pos = S1.find(Delim)) != std::string::npos))
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1);
    }
    return vString;
}

void PrintSplitString(vector<string>vString)
{
    for (string& s : vString)
    {
        cout << s << endl;
    }
}

string TrimLeft(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ')
        {
            return S1.substr(i, S1.length() - i);
        }
    }
    return "";
}
string TrimRight(string S1)
{
    for (int i = S1.length() - 1; i >= 0; i--)
    {
        if (S1[i] != ' ')
        {
            return S1.substr(0, i + 1);
        }
    }
    return "";
}
string TrimDelim(string S1, enWhatToTrim WhatToTrim)
{
    if (WhatToTrim == enWhatToTrim::enTrimAll)
    {
        return TrimRight(TrimLeft(S1));
    }
    else if (WhatToTrim == enWhatToTrim::enTrimLeft)
    {
        return TrimLeft(S1);
    }
    else if (WhatToTrim == enWhatToTrim::enTrimRight)
    {
        return TrimRight(S1);

    }
    return "";
}
string ReadString(string WordsUser)
{
    string Words;
    cout << WordsUser;
    getline(cin, Words);
    return Words;
}
string JoinString(vector<string> vString, string Delim = " ")
{
    string S1 = "";
    for (string& s : vString)
    {
        S1 = S1 + s + Delim;
    }
    return S1.substr(0, S1.length() - Delim.length());
}
string JoinString(string Array[100], int ArrayLength, string Delim)
{
    string S1 = "";
    for (int i = 0; i < ArrayLength; i++)
    {
        S1 = S1 + Array[i] + Delim;
    }
    return S1.substr(0, S1.length() - Delim.length());
}
string ReverseString(string S1, string Delim)
{
    vector <string>vString, Temp;
    string s = "";
    vString = SplitString(S1, Delim);
    vector<string>::iterator iter = vString.end();
    while (iter != vString.begin())
    {
        iter--;
        s = *iter;
        Temp.push_back(s);
    }
    return JoinString(Temp, Delim);
}
string ReplaceWordsWithMatchCase(string S1, string StringToReplace, string ReplaceTo, bool MatchCase = true, string Delim = " ")
{
    vector<string> vString;
    vString = SplitString(S1, Delim);
    if (MatchCase)
    {
        for (string& s : vString)
        {
            if (s == StringToReplace)
            {
                s = ReplaceTo;
            }
        }
    }
    else
    {
        for (string& s : vString)
        {
            if (ConvertAllLettersToLowerCase(s) == ConvertAllLettersToLowerCase(StringToReplace))
            {
                s = ReplaceTo;
            }
        }
    }
    S1 = JoinString(vString);

    return S1;
}

string RemovePunctuationsFromString(string S1)
{
    string S2 = "";
    for (int i = 0; i < S1.length(); i++)
    {
        if (!(ispunct(S1[i])))
        {
            S2 = S2 + S1[i];
        }
    }
    return S2;
}

string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string ReplaceTo)
{
    int pos = S1.find(StringToReplace);
    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(), ReplaceTo);
        pos = S1.find(StringToReplace);
    }
    return S1;
}
void LoadDataFromFileToVector(string FileName, vector<string>& vFileContent)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);//Read Mode

    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            vFileContent.push_back(Line);
        }
        MyFile.close();
    }
}
void SaveVectorToFile(string FileName, vector<string>& vFileContent)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//Write Mode

    if (MyFile.is_open())
    {
        for (string& Line : vFileContent)
        {
            if (Line != "")
            {
                MyFile << Line << endl;
            }
        }
    }
}
void DeleteRecordFromFile(string FileName, string Record)
{
    vector<string>vFileContent;
    LoadDataFromFileToVector(FileName, vFileContent);
    for (string& Line : vFileContent)
    {
        if (Line == Record)
        {
            Line = "";
        }
    }
    SaveVectorToFile(FileName, vFileContent);
}
void UpdateRecordInFile(string FileName, string Record, string UpdateTo)
{
    vector<string>vFileContent;
    LoadDataFromFileToVector(FileName, vFileContent);
    for (string& Line : vFileContent)
    {
        if (Line == Record)
        {
            Line = UpdateTo;
        }
    }
    SaveVectorToFile(FileName, vFileContent);
}
void PrintFileContent(string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);//Read Mode

    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            cout << Line << endl;
        }
        MyFile.close();
    }
}
stBankClientData ReadBankClientDataRecord(void)
{
    stBankClientData BankClientData;

    cout << "Enter Account Number : ";
    getline(cin >> ws, BankClientData.AccountNumber);
    BankClientData.Pincode = ReadString("Enter Pin Code : ");
    BankClientData.ClientName = ReadString("Enter Client Name : ");
    BankClientData.PhoneNumber = ReadString("Enter Phone Number : ");
    BankClientData.AccountBalance = ReadPostiveNumber("Enter Account Balance : ");

    return BankClientData;
}
string ConvertRecordToLine(stBankClientData BankClientData, string Separator = "#//#")
{
    string S1;
    S1 += BankClientData.AccountNumber + Separator;
    S1 += BankClientData.Pincode + Separator;
    S1 += BankClientData.ClientName + Separator;
    S1 += BankClientData.PhoneNumber + Separator;
    S1 += to_string(BankClientData.AccountBalance);

    return S1;
}
string ConvertRecordToLine(stUserInfo UserInfo, string Separator = "#//#")
{
    string S1;
    S1 += UserInfo.UserName + Separator;
    S1 += UserInfo.Password + Separator;
    S1 += to_string(UserInfo.Permission);

    return S1;
}

stBankClientData ConvertLineToRecord(string LineRecord, string separator = "#//#")
{
    stBankClientData BankClientData;
    vector<string>vBankClientData;
    vBankClientData = SplitString(LineRecord, separator);

    BankClientData.AccountNumber = vBankClientData[0];
    BankClientData.Pincode = vBankClientData[1];
    BankClientData.ClientName = vBankClientData[2];
    BankClientData.PhoneNumber = vBankClientData[3];
    BankClientData.AccountBalance = stoi(vBankClientData[4]);

    return BankClientData;
}
stUserInfo ConvertUserLineToRecord(string LineRecord, string separator = "#//#")
{
    stUserInfo UserInfo;
    vector<string>vUserInfo;
    vUserInfo = SplitString(LineRecord, separator);

    UserInfo.UserName = vUserInfo[0];
    UserInfo.Password = vUserInfo[1];
    UserInfo.Permission = stoi(vUserInfo[2]);

    return UserInfo;
}

void printBankClientRecord(stBankClientData BankClientData)
{
    cout << "Account Number : " << BankClientData.AccountNumber << endl;
    cout << "Pin Code       : " << BankClientData.Pincode << endl;
    cout << "Name           : " << BankClientData.ClientName << endl;
    cout << "Phone          : " << BankClientData.PhoneNumber << endl;
    cout << "Account Balance: " << BankClientData.AccountBalance << endl;
}
void printUserRecord(stUserInfo UserInfo)
{
    cout << "User Name  : " << UserInfo.UserName << endl;
    cout << "Password   : " << UserInfo.Password << endl;
    cout << "Permission : " << UserInfo.Permission << endl;
}
void AddDataLineToFile(string FileName, string DataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);
    if (MyFile.is_open())
    {
        MyFile << DataLine << endl;

        MyFile.close();
    }
}
bool ClientExistByAccountNumber(vector<stBankClientData> vClient, string AccountNumber)
{
    for (stBankClientData& Client : vClient)
    {
        if (Client.AccountNumber == AccountNumber)
        {
            return true;
        }
    }
    return false;
}
bool UserExistByUserName(vector<stUserInfo> vUserInfo, string UserName)
{
    for (stUserInfo& User : vUserInfo)
    {
        if (User.UserName == UserName)
        {
            return true;
        }
    }
    return false;
}
void AddNewClientCard(vector<stBankClientData>vClients)
{
    stBankClientData BankClientData;

    cout << "Enter Account Number : ";
    getline(cin >> ws, BankClientData.AccountNumber);
    while ((ClientExistByAccountNumber(vClients, BankClientData.AccountNumber)))
    {
        cout << "\nClient With [" << BankClientData.AccountNumber << "] already exists, Enter Another Account Number" << endl;
        getline(cin >> ws, BankClientData.AccountNumber);
    }

    BankClientData.Pincode = ReadString("Enter Pin Code : ");
    BankClientData.ClientName = ReadString("Enter Client Name : ");
    BankClientData.PhoneNumber = ReadString("Enter Phone Number : ");
    BankClientData.AccountBalance = ReadPostiveNumber("Enter Account Balance : ");

    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(BankClientData));
}
void SetUserPermissions(short& Permission, enMainMenueList MainMenueList)
{
    short pos = MainMenueList;
    char ClientListAccess = 'n';
    cin >> ClientListAccess;
    if (tolower(ClientListAccess) == 'y')
    {
        Permission |= (1 << pos);
    }
    else
    {
        Permission &= ~(1 << pos);
    }

}
bool CheckUserPermissions(stUserInfo UserInfo, enMainMenueList MainMenueList)
{
    short pos = MainMenueList;
    if ((UserInfo.Permission) & (1 << pos))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void ReadUserPermissions(stUserInfo& User)
{
    printf("Show Client List?(y/n)");
    SetUserPermissions(User.Permission, enMainMenueList::ShowClientList);
    printf("Add New Client?(y/n)");
    SetUserPermissions(User.Permission, enMainMenueList::AddNewClient);
    printf("Delete New Client?(y/n)");
    SetUserPermissions(User.Permission, enMainMenueList::DeleteClient);
    printf("Update New Client?(y/n)");
    SetUserPermissions(User.Permission, enMainMenueList::UpdateClientInfo);
    printf("Find Client?(y/n)");
    SetUserPermissions(User.Permission, enMainMenueList::FindClient);
    printf("Transactions?(y/n)");
    SetUserPermissions(User.Permission, enMainMenueList::TransactionsMenue);
    printf("Manage Users?(y/n)");
    SetUserPermissions(User.Permission, enMainMenueList::ManageUsers);
}
void AddNewUserCard(vector<stUserInfo>vUserInfo)
{
    stUserInfo User;
    char FullAccess = 'n';
    cout << "Enter Username : ";
    getline(cin >> ws, User.UserName);
    while ((UserExistByUserName(vUserInfo, User.UserName)))
    {
        cout << "\tUser [" << User.UserName << "] already exists, Enter Another Account Number" << endl;
        cout << "\nEnter Username : ";
        getline(cin >> ws, User.UserName);
    }
    User.Password = ReadString("Enter Password: ");
    printf("Do you want to give a full access?(y/n)");
    cin >> FullAccess;
    if (tolower(FullAccess) == 'y')
    {
        User.Permission = -1;
    }
    else
    {
        cout << "\nDo you want to give access to : \n";
        ReadUserPermissions(User);
        if (User.Permission == 127)
        {
            User.Permission = -1;
        }
    }
    AddDataLineToFile(UsersInfoFileName, ConvertRecordToLine(User));
}
void AddNewClients(vector<stBankClientData>vClients, string separator = "#//#")
{
    char addmore = 'Y';
    do
    {
        system("cls");

        cout << "Adding New Client:\n\n";

        AddNewClientCard(vClients);

        cout << "Client Added Successfully, do you want to add more clients? Y/N " << endl;

        cin >> addmore;


    } while (toupper(addmore) == 'Y');

}
void AddNewUsers(vector<stUserInfo>vUserInfo, string separator = "#//#")
{
    char addmore = 'Y';
    do
    {
        system("cls");

        cout << "Adding New User:\n\n";

        AddNewUserCard(vUserInfo);

        cout << "User Added Successfully, do you want to add more Users? Y/N " << endl;

        cin >> addmore;


    } while (toupper(addmore) == 'Y');

}
void ShowAccessDeniedScreen()
{
    system("cls");
    cout << "===============================================================" << endl;
    cout << "Access Denied,\n";
    cout << "You don't have permission to do this,\n";
    cout << "Please Contact Your Admin.\n";
    cout << "===============================================================" << endl;
}
void ShowAddNewClientScreen(vector<stBankClientData>vClients)
{
    if (!(CurrentUser.Permission == -1 || CheckUserPermissions(CurrentUser, enMainMenueList::AddNewClient)))
    {
        ShowAccessDeniedScreen();
        return;
    }
    cout << "===============================================================" << endl;
    cout << "\t\tAdd New Client Screen\n";
    cout << "===============================================================" << endl;

    AddNewClients(vClients);
}
void ShowAddNewUserScreen(vector<stUserInfo>vUserInfo)
{
    cout << "===============================================================" << endl;
    cout << "\t\tAdd New User Screen\n";
    cout << "===============================================================" << endl;
    AddNewUsers(vUserInfo);
}
vector<stBankClientData> LoadClientsDataFromFile(string FileName)
{
    vector<stBankClientData>vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//Read Mode

    if (MyFile.is_open())
    {
        string Line;
        stBankClientData Client;
        while (getline(MyFile, Line))
        {
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}
vector<stUserInfo> LoadUsersDataFromFile(string FileName)
{
    vector<stUserInfo>vUsersInfo;
    fstream MyFile;
    MyFile.open(FileName, ios::in);//Read Mode

    if (MyFile.is_open())
    {
        string Line;
        stUserInfo UserInfo;
        while (getline(MyFile, Line))
        {
            UserInfo = ConvertUserLineToRecord(Line);
            vUsersInfo.push_back(UserInfo);
        }
        MyFile.close();
    }
    return vUsersInfo;
}
void PrintClientRecord(stBankClientData Client)
{
    cout << "|" << left << setw(15) << Client.AccountNumber;
    cout << "|" << left << setw(10) << Client.Pincode;
    cout << "|" << left << setw(40) << Client.ClientName;
    cout << "|" << left << setw(12) << Client.PhoneNumber;
    cout << "|" << left << setw(12) << Client.AccountBalance;
}
void PrintClientNameBalance(stBankClientData Client)
{
    cout << "|" << left << setw(15) << Client.AccountNumber;

    cout << "|" << left << setw(40) << Client.ClientName;

    cout << "|" << left << setw(12) << Client.AccountBalance;
}
void PrintListUsers(stUserInfo User)
{
    cout << "|" << left << setw(15) << User.UserName;

    cout << "|" << left << setw(40) << User.Password;

    cout << "|" << left << setw(12) << User.Permission;
}
void PrintAllClientsData(vector<stBankClientData>vClients)
{
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s)." << endl;
    cout << "________________________________________________________________________________________________" << endl;

    cout << "|" << left << setw(15) << "Account Number";
    cout << "|" << left << setw(10) << "Pin Code";
    cout << "|" << left << setw(40) << "Client Name";
    cout << "|" << left << setw(12) << "phone";
    cout << "|" << left << setw(12) << "Balance";

    cout << "\n________________________________________________________________________________________________" << endl;

    for (stBankClientData Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }

    cout << "________________________________________________________________________________________________" << endl;

}
void PrintAllClientsBalanceAndTotalBalance(vector<stBankClientData>vClients)
{
    int TotalBalance = 0;
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s)." << endl;
    cout << "________________________________________________________________________________________________" << endl;

    cout << "|" << left << setw(15) << "Account Number";

    cout << "|" << left << setw(40) << "Client Name";

    cout << "|" << left << setw(12) << "Balance";

    cout << "\n________________________________________________________________________________________________" << endl;

    for (stBankClientData Client : vClients)
    {
        PrintClientNameBalance(Client);
        TotalBalance = TotalBalance + Client.AccountBalance;
        cout << endl;
    }

    cout << "________________________________________________________________________________________________" << endl;
    cout << "\n\t\t\t\t\tTotal Balance =" << TotalBalance << endl;
}
void PrintUsersList(vector<stUserInfo>vUsers)
{
    cout << "\n\t\t\t\t\tUser List (" << vUsers.size() << ") User(s)." << endl;
    cout << "________________________________________________________________________________________________" << endl;

    cout << "|" << left << setw(15) << "User Name";

    cout << "|" << left << setw(40) << "Password";

    cout << "|" << left << setw(12) << "Permissions";

    cout << "\n________________________________________________________________________________________________" << endl;

    for (stUserInfo User : vUsers)
    {
        PrintListUsers(User);
        cout << endl;
    }

    cout << "________________________________________________________________________________________________" << endl;
}
void ShowClientsListScreen(vector<stBankClientData>vClients)
{
    if (!(CurrentUser.Permission == -1 || CheckUserPermissions(CurrentUser, enMainMenueList::ShowClientList)))
    {
        ShowAccessDeniedScreen();
        return;
    }
    PrintAllClientsData(vClients);
}

bool FindClientByAccountNumber(vector<stBankClientData> vClient, stBankClientData& Clients, string AccountNumber)
{
    for (stBankClientData& Client : vClient)
    {
        if (Client.AccountNumber == AccountNumber)
        {
            Clients = Client;
            return true;
        }
    }
    return false;
}
bool FindUserByUserName(vector<stUserInfo> vUsersInfo, stUserInfo& UsersInfo, string UserName)
{
    for (stUserInfo& UserInfo : vUsersInfo)
    {
        if (UserInfo.UserName == UserName)
        {
            UsersInfo = UserInfo;
            return true;
        }
    }
    return false;
}

string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter Account Number" << endl;
    cin >> AccountNumber;
    return AccountNumber;
}
string ReadUserUserName()
{
    string UserName = "";
    cout << "\nPlease enter Username" << endl;
    cin >> UserName;
    return UserName;
}
void ShowFindClientScreen(vector<stBankClientData> vClients)
{
    if (!(CurrentUser.Permission == -1 || CheckUserPermissions(CurrentUser, enMainMenueList::FindClient)))
    {
        ShowAccessDeniedScreen();
        return;
    }
    string AccountNumber;
    cout << "===============================================================" << endl;
    cout << "\t\tFind Client Screen\n";
    cout << "===============================================================" << endl;
    stBankClientData Client;
    AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(vClients, Client, AccountNumber))
    {
        printBankClientRecord(Client);
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is NOT Found!\n";
    }
}
void ShowFindUsersScreen(vector<stUserInfo> vUserInfo)
{
    string UserName;
    cout << "===============================================================" << endl;
    cout << "\t\tFind User Name Screen\n";
    cout << "===============================================================" << endl;
    stUserInfo User;
    UserName = ReadUserUserName();
    if (FindUserByUserName(vUserInfo, User, UserName))
    {
        printUserRecord(User);
    }
    else
    {
        cout << "\nUser with User Name (" << UserName << ") is NOT Found!\n";
    }
}

bool MarkClientDataForDelete(string AccountNumber, vector<stBankClientData>& vClients)
{
    for (stBankClientData& Client : vClients)
    {
        if (AccountNumber == Client.AccountNumber)
        {
            Client.MarkForDelete = true;
            return true;
        }
    }
    return false;
}
bool MarkUserDataForDelete(string UserName, vector<stUserInfo>& vUsers)
{
    for (stUserInfo& User : vUsers)
    {
        if (UserName == User.UserName)
        {
            User.MarkForDelete = true;
            return true;
        }
    }
    return false;
}
vector<stBankClientData> SaveClientDataToFile(string FileName, vector<stBankClientData> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);

    string DataLine;
    if (MyFile.is_open())
    {
        for (stBankClientData& Client : vClients)
        {
            if (Client.MarkForDelete == false)
            {
                DataLine = ConvertRecordToLine(Client);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}
vector<stUserInfo> SaveUserDataToFile(string FileName, vector<stUserInfo> vUsers)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);

    string DataLine;
    if (MyFile.is_open())
    {
        for (stUserInfo& User : vUsers)
        {
            if (User.MarkForDelete == false)
            {
                DataLine = ConvertRecordToLine(User);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vUsers;
}
bool DeleteClientDataFromFile(string AccountNumber, vector<stBankClientData>& vClients)
{
    stBankClientData Client;
    char DeleteAccount = 'n';

    if (FindClientByAccountNumber(vClients, Client, AccountNumber))
    {
        printBankClientRecord(Client);
        cout << "Are you sure to delete this client ?(Y/N)" << endl;
        cin >> DeleteAccount;
        if (toupper(DeleteAccount) == 'Y')
        {
            MarkClientDataForDelete(AccountNumber, vClients);
            SaveClientDataToFile(ClientsFileName, vClients);
            vClients = LoadClientsDataFromFile(ClientsFileName);//refresh
            cout << "\n\nClient Deleted Successfully. " << endl;
            return true;
        }
    }
    else
    {
        cout << "Client with Account Number (" << AccountNumber << ") Not Found!\n\n";
        return false;
    }


}
bool DeleteUserDataFromFile(string Username, vector<stUserInfo>& vUserInfo)
{
    stUserInfo User;
    char DeleteUser = 'n';
    bool FoundUserName = FindUserByUserName(vUserInfo, User, Username);
    if (User.UserName == "admin")
    {
        cout << "\n\nYou can't Delete This User." << endl;
        return false;
    }
    else if (FoundUserName)
    {
        printUserRecord(User);
        cout << "Are you sure to delete this user ?(Y/N)" << endl;
        cin >> DeleteUser;
        if (toupper(DeleteUser) == 'Y')
        {
            MarkUserDataForDelete(Username, vUserInfo);
            SaveUserDataToFile(UsersInfoFileName, vUserInfo);
            vUserInfo = LoadUsersDataFromFile(UsersInfoFileName);//refresh
            cout << "\n\nUser Deleted Successfully. " << endl;
            return true;
        }
    }
    else
    {
        cout << "User with User Name (" << Username << ") Not Found!\n\n";
        return false;
    }
}
void ShowDeleteClientScreen(vector<stBankClientData>& vClients)
{
    if (!(CurrentUser.Permission == -1 || CheckUserPermissions(CurrentUser, enMainMenueList::DeleteClient)))
    {
        ShowAccessDeniedScreen();
        return;
    }
    string AccountNumber;
    cout << "===============================================================" << endl;
    cout << "\t\tDelete Client Screen\n";
    cout << "===============================================================" << endl;
    AccountNumber = ReadClientAccountNumber();
    DeleteClientDataFromFile(AccountNumber, vClients);
}
void ShowDeleteUserScreen(vector<stUserInfo>& vUserInfo)
{
    string UserName;
    cout << "===============================================================" << endl;
    cout << "\t\tDelete Users Screen\n";
    cout << "===============================================================" << endl;
    UserName = ReadUserUserName();
    DeleteUserDataFromFile(UserName, vUserInfo);
}
stBankClientData EditBankClientDataRecord(string AccountNumber)
{
    stBankClientData Client;
    Client.AccountNumber = AccountNumber;
    cout << "Enter Pin Code : ";
    getline(cin >> ws, Client.Pincode);
    Client.ClientName = ReadString("Enter Client Name : ");
    Client.PhoneNumber = ReadString("Enter Phone Number : ");
    Client.AccountBalance = ReadPostiveNumber("Enter Account Balance : ");
    return Client;
}

stUserInfo EditUserDataRecord(string UserName)
{
    stUserInfo User;
    User.UserName = UserName;
    cout << "Enter Password : ";
    getline(cin >> ws, User.Password);
    char FullAccess = 'n';
    printf("Do you want to give a full access?(y/n)");
    cin >> FullAccess;
    if (tolower(FullAccess) == 'y')
    {
        User.Permission = -1;
    }
    else
    {
        cout << "\nDo you want to give access to : \n";
        ReadUserPermissions(User);
        if (User.Permission == 127)
        {
            User.Permission = -1;
        }
    }
    return User;
}
void SaveClientData(vector<stBankClientData>& vClients)
{
    for (stBankClientData& Client : vClients)
    {
        if (CurrentClient.AccountNumber == Client.AccountNumber)
        {
             Client= CurrentClient;
        }
    }
    vClients=SaveClientDataToFile(ClientsFileName, vClients);
}
bool DepositeAmountOfMoney(stBankClientData& Client, int AmountOfMoneyToDeposite)
{

    Client.AccountBalance = Client.AccountBalance + AmountOfMoneyToDeposite;
    return true;
}
bool WithdrawAmountOfMoney(stBankClientData& Client, int AmountOfMoneyToDeposite)
{
    while (Client.AccountBalance < AmountOfMoneyToDeposite)
    {
        cout << "Amount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
        cout << "Please enter another amount :";
        cin >> AmountOfMoneyToDeposite;
    }
    DepositeAmountOfMoney(Client, AmountOfMoneyToDeposite * -1);
    return true;
}
bool UpdateClientByAccountNumber(string AccountNumber, vector<stBankClientData>& vClients)
{
    stBankClientData Client;
    char UpdateClient = 'n';

    if (FindClientByAccountNumber(vClients, Client, AccountNumber))
    {
        printBankClientRecord(Client);
        cout << "Are you sure you want update this client? (y/n) ";
        cin >> UpdateClient;
        if (toupper(UpdateClient) == 'Y')
        {
            for (stBankClientData& C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = EditBankClientDataRecord(AccountNumber);
                    Client = C;
                    break;
                }

            }
            SaveClientDataToFile(ClientsFileName, vClients);

            cout << "\n\nClient Updated Successfully. " << endl;
            return true;
        }
    }
    else
    {
        cout << "Client with Account Number (" << AccountNumber << ") Not Foound!\n\n";
        return false;
    }
}
bool UpdateUserByUserName(string UserName, vector<stUserInfo>& vUsersInfo)
{
    stUserInfo User;
    char UpdateUser = 'n';

    if (FindUserByUserName(vUsersInfo, User, UserName))
    {
        printUserRecord(User);
        cout << "Are you sure you want update this user? (y/n) ";
        cin >> UpdateUser;
        if (toupper(UpdateUser) == 'Y')
        {
            for (stUserInfo& U : vUsersInfo)
            {
                if (U.UserName == UserName)
                {
                    U = EditUserDataRecord(UserName);
                    User = U;
                    break;
                }

            }
            SaveUserDataToFile(UsersInfoFileName, vUsersInfo);

            cout << "\n\nUser Updated Successfully. " << endl;
            return true;
        }
    }
    else
    {
        cout << "User with UserName (" << UserName << ") Not Foound!\n\n";
        return false;
    }
}
void ShowUpdateClientScreen(vector<stBankClientData>& vClients)
{
    if (!(CurrentUser.Permission == -1 || CheckUserPermissions(CurrentUser, enMainMenueList::UpdateClientInfo)))
    {
        ShowAccessDeniedScreen();
        return;
    }
    string AccountNumber;
    cout << "===============================================================" << endl;
    cout << "\t\tUpdate Client Screen\n";
    cout << "===============================================================" << endl;
    AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);
}
void ShowUpdateUserScreen(vector<stUserInfo>& vUserInfo)
{
    string Username;
    cout << "===============================================================" << endl;
    cout << "\t\tUpdate Users Screen\n";
    cout << "===============================================================" << endl;
    Username = ReadUserUserName();
    UpdateUserByUserName(Username, vUserInfo);
}
void ShowExitScreen()
{
    cout << "===============================================================\n" << endl;
    cout << "\t\tProgram Ends :-)\n";
    cout << "\n===============================================================" << endl;
}
short ReadMainMenueOption()
{
    cout << "Choose what do you want to do ? [1 to 8]?";
    cin >> Choice;
    return --Choice;
}
short ReadATMMainMenueOption()
{
    cout << "Choose what do you want to do ? [1 to 5]?";
    cin >> Choice;
    return Choice;
}
short ReadATMQuickWithdrawOption()
{
    cout << "Choose what to withdraw from [1] to [8] ?";
    cin >> Choice;
    return Choice;
}
short ReadTransactionsMenueOption()
{
    cout << "Choose what do you want to do ? [1 to 4]?";
    cin >> Choice;
    return Choice;
}
short ReadManageUsersMenueOption()
{
    cout << "Choose what do you want to do ? [1 to 6]?";
    cin >> Choice;
    return Choice;
}
void GoBackToMainMenue()
{
    cout << "Press any key to go back to Main Menue..." << endl;
    system("pause>0");
    ShowMainMenue();
}
void GoBackToATMMainMenue(vector<stBankClientData>& vClients)
{
    cout << "Press any key to go back to ATM Main Menue..." << endl;
    system("pause>0");
    ShowATMMainMenue(vClients);
}
void GoBackToManageUsersMenue()
{
    cout << "Press any key to go back to Manage Users  Menue..." << endl;
    system("pause>0");
    ShowManageUsersMenue();
}
void GoBackToTransactionsMenue()
{
    cout << "Press any key to go back to Transactions Menue..." << endl;
    system("pause>0");
    ShowTransactionMenueScreen();
}
bool DepositMoney(vector<stBankClientData> vClients, stBankClientData& Client, string AccountNumber)
{
    int DepositeAmount;
    char DepositeMoney = 'N';
    cout << "Please enter deposite amount :  ";
    cin >> DepositeAmount;
    cout << "Are you sure you want to perform this transaction ? Y/N  ";
    cin >> DepositeMoney;
    if (toupper(DepositeMoney) == 'Y')
    {
        for (stBankClientData& C : vClients)
        {
            if (C.AccountNumber == Client.AccountNumber)
            {
                DepositeAmountOfMoney(C, DepositeAmount);
                Client = C;
                break;
            }
        }
        SaveClientDataToFile(ClientsFileName, vClients);
        cout << "\n\nDone Successfully, New Balance is " << Client.AccountBalance << " ." << endl;
        return true;
    }
    else
    {
        return false;
    }
}
bool DepositMoneyByAccountNumber(vector<stBankClientData>& vClients)
{
    stBankClientData Client;

    cout << "Enter Account Number : ";
    getline(cin >> ws, Client.AccountNumber);
    while (!(FindClientByAccountNumber(vClients, Client, Client.AccountNumber)))
    {
        cout << "\nClient With [" << Client.AccountNumber << "] doesn't exist.\nEnter Another Account Number" << endl;
        getline(cin >> ws, Client.AccountNumber);
    }
    printBankClientRecord(Client);
    return DepositMoney(vClients, Client, Client.AccountNumber);
}
bool ATMDepositMoney(vector<stBankClientData>& vClients)
{
    char PerformTransaction = 'n';
    int DepositeAmount;
    cout << "Enter a postive Deposite Amount: ";
    cin >> DepositeAmount;

    cout << "Are you sure you want perform this transaction?(Y/N)?";
    cin >> PerformTransaction;

    if (tolower(PerformTransaction) == 'y')
    {
        CurrentClient.AccountBalance += DepositeAmount;
        cout << "Done Successfully. New balance is: " << CurrentClient.AccountBalance << endl;
        return true;
    }
    else
    {
        return false;
    }
}
bool WithdrawMoney(vector<stBankClientData> vClients, stBankClientData& Client, string AccountNumber)
{
    int WithdrawAmount;
    char WithdrawMoney = 'N';
    cout << "Please enter withdraw amount :  ";
    cin >> WithdrawAmount;
    cout << "Are you sure you want to perform this transaction ? Y/N  ";
    cin >> WithdrawMoney;
    if (toupper(WithdrawMoney) == 'Y')
    {
        for (stBankClientData& C : vClients)
        {
            if (C.AccountNumber == Client.AccountNumber)
            {
                WithdrawAmountOfMoney(C, WithdrawAmount);
                Client = C;
                break;
            }

        }
        SaveClientDataToFile(ClientsFileName, vClients);

        cout << "\n\nDone Successfully, New Balance is " << Client.AccountBalance << " ." << endl;
        return true;
    }
    else
    {
        return false;
    }
}
bool WithdrawMoneyByAccountNumber(vector<stBankClientData>& vClients)
{
    stBankClientData Client;

    cout << "Enter Account Number : ";
    getline(cin >> ws, Client.AccountNumber);
    while (!(FindClientByAccountNumber(vClients, Client, Client.AccountNumber)))
    {
        cout << "\nClient With [" << Client.AccountNumber << "] doesn't exist, Enter Another Account Number" << endl;
        getline(cin >> ws, Client.AccountNumber);
    }
    printBankClientRecord(Client);
    return WithdrawMoney(vClients, Client, Client.AccountNumber);
}
short ATMQuickWithdraw(short QuickWithdrawOption)
{
    if (QuickWithdrawOption == 1)
        return 20;
    else if (QuickWithdrawOption == 2)
        return 50;
    else if (QuickWithdrawOption == 3)
        return 100;
    else if (QuickWithdrawOption == 4)
        return 200;
    else if (QuickWithdrawOption == 5)
        return 400;
    else if (QuickWithdrawOption == 6)
        return 600;
    else if (QuickWithdrawOption == 7)
        return 800;
    else if (QuickWithdrawOption == 8)
        return 1000;
    else if (QuickWithdrawOption == 9)
        return -1;
}   
bool ATMQuickWithdrawMoney(vector<stBankClientData>& vClients,short QuickWithdrawAmount)
{    
    char PerformTransaction='n';
       
    if (QuickWithdrawAmount == -1)
    {
        return false;
    }
    if (QuickWithdrawAmount > CurrentClient.AccountBalance)
    {
        cout << "The amount exceeds your balance, make another choice." << endl;
        cout << "Press Anykey to continue..." << endl;
        system("pause>0");

        ShowATMQuickWithdrawScreen(vClients);
        return true;
    }
    
    cout << "Are you sure you want perform this transaction?(Y/N)?";
    cin >> PerformTransaction;

    if (tolower(PerformTransaction) == 'y')
    {
        CurrentClient.AccountBalance -= QuickWithdrawAmount;
        cout << "\nDone Successfully. New balance is: " << CurrentClient.AccountBalance << endl;
        return true;
    }
    else
    {
        return false;
    }
    
}
bool ATMWithdrawMoney(vector<stBankClientData>& vClients)
{
    int  WithdrawAmount;
    char PerformTransaction = 'n';

    do
    {
        cout << "Enter an amount multiple of 5's : ";
        cin >> WithdrawAmount;
    } while (WithdrawAmount % 5 != 0);

    if (WithdrawAmount > CurrentClient.AccountBalance)
    {
        cout << "The amount exceeds your balance, make another choice." << endl;
        cout << "Press Anykey to continue..." << endl;
        system("pause>0");
        ShowATMWithdrawScreen(vClients);
        return true;
    }

    cout << "Are you sure you want perform this transaction?(Y/N)?";
    cin >> PerformTransaction;

    if (tolower(PerformTransaction) == 'y')
    {
        CurrentClient.AccountBalance -= WithdrawAmount;
        cout << "Done Successfully. New balance is: " << CurrentClient.AccountBalance << endl;
        return true;
    }
    else
    {
        return false;
    }

}
void ShowDepositScreen(vector<stBankClientData>& vClients)
{
    system("cls");
    cout << "===============================================================" << endl;
    cout << "\t\tDeposite Screen\n";
    cout << "===============================================================" << endl;
    DepositMoneyByAccountNumber(vClients);
}
void ShowATMDepositScreen(vector<stBankClientData>& vClients)
{
    system("cls");
    cout << "===============================================================" << endl;
    cout << "\t\tDeposite Screen\n";
    cout << "===============================================================" << endl;
    ATMDepositMoney(vClients);
}
void ShowListUsersScreen(vector<stUserInfo>& vUsers)
{
    system("cls");
    cout << "===============================================================" << endl;
    cout << "\t\tList Users Screen\n";
    cout << "===============================================================" << endl;
    PrintUsersList(vUsers);
}
void ShowWithdrawScreen(vector<stBankClientData>& vClients)
{
    system("cls");
    cout << "===============================================================" << endl;
    cout << "\t\tWithdraw Screen\n";
    cout << "===============================================================" << endl;
    WithdrawMoneyByAccountNumber(vClients);
}
void ShowATMWithdrawScreen(vector<stBankClientData>& vClients)
{
    system("cls");
    cout << "===============================================================" << endl;
    cout << "\t\t Normal Withdraw Screen\n";
    cout << "===============================================================" << endl;
    ATMWithdrawMoney(vClients);
}
void ShowATMQuickWithdrawScreen(vector<stBankClientData>& vClients)
{
    system("cls");
    cout << "=========================================" << endl;
    cout << "\t\t Quick Withdraw Screen\n";
    cout << "=========================================" << endl;
    cout << "\t[1] 20" << "\t\t[2] 50" << endl;
    cout << "\t[3] 100"<< "\t\t[4] 200" << endl;
    cout << "\t[5] 400"<< "\t\t[6] 600" << endl;
    cout << "\t[7] 800"<< "\t\t[8] 1000" << endl;
    cout << "\t[9] Exit" << endl;
    cout << "==========================================" << endl;
    printf("Your Balance is %d\n", CurrentClient.AccountBalance);
    ATMQuickWithdrawMoney(vClients,ATMQuickWithdraw(ReadATMQuickWithdrawOption()));
}
void ShowTotalBalanceListScreen(vector<stBankClientData>vClients)
{
    system("cls");
    PrintAllClientsBalanceAndTotalBalance(vClients);
}
void ShowListOFUsersScreen(vector<stUserInfo>vUserInfo)
{
    system("cls");
    PrintUsersList(vUserInfo);
}
void TransactionsMenueChoose(enTransactionMenue TransactionMenue)
{
    vector<stBankClientData> vClients = LoadClientsDataFromFile(ClientsFileName);
    switch (TransactionMenue)
    {
    case enTransactionMenue::Deposit:
        ShowDepositScreen(vClients);
        GoBackToTransactionsMenue();
        break;
    case enTransactionMenue::Withdraw:
        ShowWithdrawScreen(vClients);
        GoBackToTransactionsMenue();
        break;
    case enTransactionMenue::TotalBalances:
        ShowTotalBalanceListScreen(vClients);
        GoBackToTransactionsMenue();
        break;
    case enTransactionMenue::TransactionToMainMenue:
        ShowMainMenue();
        break;
    }

}
void ShowTransactionMenueScreen()
{
    if (!(CurrentUser.Permission == -1 || CheckUserPermissions(CurrentUser, enMainMenueList::AddNewClient)))
    {
        ShowAccessDeniedScreen();
        return;
    }
    system("cls");
    cout << "===============================================================" << endl;
    cout << "\t\tMain Menue Screen\n";
    cout << "===============================================================" << endl;
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] Total Balances.\n";
    cout << "\t[4] Main Menue.\n";
    cout << "===============================================================" << endl;
    TransactionsMenueChoose((enTransactionMenue)ReadTransactionsMenueOption());
}
void ManageUsersChoose(enManageUsers ManageUsers)
{
    vector<stUserInfo> vUsers = LoadUsersDataFromFile(UsersInfoFileName);
    switch (ManageUsers)
    {
    case enManageUsers::ListUsers:
        ShowListOFUsersScreen(vUsers);
        GoBackToManageUsersMenue();
        break;
    case enManageUsers::AddNewUser:
        AddNewUsers(vUsers);
        GoBackToManageUsersMenue();
        break;
    case enManageUsers::DeleteUser:
        system("cls");
        ShowDeleteUserScreen(vUsers);
        GoBackToManageUsersMenue();
        break;
    case enManageUsers::UpdateUser:
        system("cls");
        ShowUpdateUserScreen(vUsers);
        GoBackToManageUsersMenue();
        break;
    case enManageUsers::FindUser:
        system("cls");
        ShowFindUsersScreen(vUsers);
        GoBackToManageUsersMenue();
        break;
    case enManageUsers::UsersToMainMenue:
        ShowMainMenue();
        break;
    }
}
void ShowManageUsersMenue()
{
    if (!(CurrentUser.Permission == -1 || CheckUserPermissions(CurrentUser, enMainMenueList::ManageUsers)))
    {
        ShowAccessDeniedScreen();
        return;
    }
    system("cls");
    cout << "===============================================================" << endl;
    cout << "\t\tManage Users Screen\n";
    cout << "===============================================================" << endl;
    cout << "\t[1] List Users.\n";
    cout << "\t[2] Add New User.\n";
    cout << "\t[3] Delete User.\n";
    cout << "\t[4] Update User.\n";
    cout << "\t[5] Find User.\n";
    cout << "\t[6] Main Menue.\n";
    cout << "===============================================================" << endl;
    ManageUsersChoose((enManageUsers)ReadManageUsersMenueOption());
}
stUserInfo ReadUserInfo()
{
    stUserInfo UserInfo;
    cout << "Enter Username: ";
    getline(cin >> ws, UserInfo.UserName);
    cout << "Enter Password: ";
    getline(cin, UserInfo.Password);
    return UserInfo;
}
stBankClientData ReadClientAccountNumberandPinCode()
{
    stBankClientData Client;
    cout << "Enter Account Number: ";
    getline(cin >> ws, Client.AccountNumber);
    cout << "Enter Pincode: ";
    getline(cin, Client.Pincode);
    return Client;
}
bool CheckUserNamePassWord(vector<stUserInfo>vUserInfo, stUserInfo& UserInfo, string UserName)
{
    stUserInfo User = UserInfo;
    if (FindUserByUserName(vUserInfo, UserInfo, UserName))
    {
        if (User.Password == UserInfo.Password)
        {
            CurrentUser = UserInfo;
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
bool CheckClientAccountNumberandPinCode(vector<stBankClientData>vClients, stBankClientData& Client, string AccountNumber)
{
    stBankClientData C = Client;
    if (FindClientByAccountNumber(vClients, Client, AccountNumber))
    {
        if (C.Pincode == Client.Pincode)
        {
            CurrentClient = Client;
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
void LoginWithUserNameAndPassword()
{
    stUserInfo UserInfo;
    bool flag = false;
    vector<stUserInfo>vUserInfo;
    vUserInfo = LoadUsersDataFromFile(UsersInfoFileName);
    UserInfo = ReadUserInfo();
    bool UsernamePassword = false;
    UsernamePassword = CheckUserNamePassWord(vUserInfo, UserInfo, UserInfo.UserName);
    do
    {
        if (UsernamePassword)
        {
            flag = true;
            ShowMainMenue();
        }
        else
        {
            ShowLoginScreen();
            cout << "Invalid Username/Password!" << endl;
            UserInfo = ReadUserInfo();
            UsernamePassword = CheckUserNamePassWord(vUserInfo, UserInfo, UserInfo.UserName);
        }
    } while (flag == false);

}
void LoginWithAccountNumberandPinCode()
{
    stBankClientData Client;
    bool flag = false;
    vector<stBankClientData>vClients;
    vClients = LoadClientsDataFromFile(ClientsFileName);
    Client = ReadClientAccountNumberandPinCode();
    bool AccountNUmberPinCode = false;
    AccountNUmberPinCode = CheckClientAccountNumberandPinCode(vClients, Client, Client.AccountNumber);
    do
    {
        if (AccountNUmberPinCode)
        {
            flag = true;
            ShowATMMainMenue(vClients);
        }
        else
        {
            ShowLoginScreen();
            cout << "Invalid Username/Password!" << endl;
            Client = ReadClientAccountNumberandPinCode();
            AccountNUmberPinCode = CheckClientAccountNumberandPinCode(vClients, Client, Client.AccountNumber);
        }
    } while (flag == false);

}
void ShowLoginScreen()
{
    system("cls");
    cout << "===============================================================" << endl;
    cout << "\t\tLogin Screen\n";
    cout << "===============================================================" << endl;
}
void MainMenueChoose(enMainMenueList MainMenueList)
{

    vector<stBankClientData> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber;
    string S1;
    switch (MainMenueList)
    {
    case  enMainMenueList::ShowClientList:
        system("cls");
        ShowClientsListScreen(vClients);
        GoBackToMainMenue();
        break;
    case  enMainMenueList::AddNewClient:
        system("cls");
        ShowAddNewClientScreen(vClients);
        GoBackToMainMenue();
        break;
    case  enMainMenueList::DeleteClient:
        system("cls");
        ShowDeleteClientScreen(vClients);
        GoBackToMainMenue();
        break;
    case  enMainMenueList::UpdateClientInfo:
        system("cls");
        ShowUpdateClientScreen(vClients);
        GoBackToMainMenue();
        break;
    case  enMainMenueList::FindClient:
        system("cls");
        ShowFindClientScreen(vClients);
        GoBackToMainMenue();
        break;
    case  enMainMenueList::TransactionsMenue:
        system("cls");
        ShowTransactionMenueScreen();
        GoBackToMainMenue();
        break;
    case  enMainMenueList::ManageUsers:
        system("cls");
        ShowManageUsersMenue();
        GoBackToMainMenue();
        break;
    case  enMainMenueList::Logout:
        system("cls");
        ShowLoginScreen();
        LoginWithUserNameAndPassword();
        break;
    }
}
void CheckBalanceScreen(vector<stBankClientData>& vClients)
{
    
    system("cls");
    cout << "===============================================================" << endl;
    cout << "\t\t Check Balance Screen\n";
    cout << "===============================================================" << endl;
    for (stBankClientData& Client : vClients)
    {
        if (CurrentClient.AccountNumber == Client.AccountNumber)
        {
            CurrentClient = Client;
        }
    }
    printf("Your Balance is %d\n\n", CurrentClient.AccountBalance);
}
void ATMMainMenueChoose(vector<stBankClientData>& vClients,enATMMainMenueList ATMMainMenueList)
{
    switch (ATMMainMenueList)
    {
    case  enATMMainMenueList::QuickWithdraw:
        system("cls");
        ShowATMQuickWithdrawScreen(vClients);
        SaveClientData(vClients);
        GoBackToATMMainMenue(vClients);
        break;
    case  enATMMainMenueList::NormalWithdraw:
        system("cls");
        ShowATMWithdrawScreen(vClients);
        SaveClientData(vClients);
        GoBackToATMMainMenue(vClients);
        break;
    case  enATMMainMenueList::Deposite:
        system("cls");
        ShowATMDepositScreen(vClients);
        SaveClientData(vClients);
        GoBackToATMMainMenue(vClients);
        break;
    case  enATMMainMenueList::CheckBalance:
        system("cls");
        CheckBalanceScreen(vClients);
        SaveClientData(vClients);
        GoBackToATMMainMenue(vClients);
        break;
    case  enATMMainMenueList::ATMLogout:
        system("cls");
        ShowLoginScreen();
        LoginWithAccountNumberandPinCode();
        break;
    }
}
void ShowMainMenue()
{
    system("cls");
    cout << "===============================================================" << endl;
    cout << "\t\tMain Menue Screen\n";
    cout << "===============================================================" << endl;
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transactions Menue.\n";
    cout << "\t[7] User Management.\n";
    cout << "\t[8] Logout.\n";
    cout << "===============================================================" << endl;
    MainMenueChoose((enMainMenueList)ReadMainMenueOption());
}
void ShowATMMainMenue(vector<stBankClientData>& vClients)
{
    system("cls");
    cout << "===============================================================" << endl;
    cout << "\t\tATM Main Menue Screen\n";
    cout << "===============================================================" << endl;
    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdraw.\n";
    cout << "\t[3] Deposite.\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "===============================================================" << endl;
    ATMMainMenueChoose(vClients,(enATMMainMenueList)ReadATMMainMenueOption());
}
int main()
{
    ShowLoginScreen();
    LoginWithAccountNumberandPinCode();

    system("pause>0");

    return 0;
}
