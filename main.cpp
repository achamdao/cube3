#include <iostream>
using namespace std;
#include <cstdlib>
#include <string>
#include <ctime>
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

enum Operation {ADD = 1, SUB = 2, DIV = 3, MUL = 4, NOTFOUND = -1};

struct stInputData
{
    string OperationInput = "";
    short Choice = 0;
    int NumberTimesInput = 0;
    int RangFrom = 0;
    int RangTo = 0;
};

struct stSettingRound
{
    int Number1 = 0;
    int Number2 = 0;
    int ResultUser = 0;
};

struct stCountData
{
    short CounterFalse = 0;
    short CounterTrue = 0;
};

struct stErrors
{
    int Error;
};

struct stGame
{
    stInputData InputData;
    stCountData CountData;
    stSettingRound SettingRound;
    stErrors Errors;
    int Result = 0;
   
};

string InputString(const string &Message, string &Status)
{
    string Input = "0";
    cout << endl<<Message;
    if (!getline(cin, Input))
    {
        Status = "-1";
        return ("");
    }
    return Input;
}

int AtoiCPP(string &Str)
{
    int i = 0;
    int Result = 0;
    short signal = 1;
    if (Str[i] == '-' || Str[i] == '+')
    {
        if (Str[i] == '-')
            signal *= -1;
        i++;
    }
    while (isdigit(Str[i]))
    {
        Result = Result * 10 + (Str[i] - '0');
        i++;
    }
    return (Result * signal);
}

bool CheckIsNumber(const string &Str)
{
    int i = 0;
    if (Str.empty())
        return false;
    if (Str[i] == '-' || Str[i] == '+')
            i++;
    while (isdigit(Str[i]))
        i++;
    if (i != Str.length())
        return false;
    return true;
}

int ReadNumber(const string &Message)
{
    string Str;
    string Status = "0";
    bool  flag = false;
    int i = 0;
    do 
    {
        Str = InputString(Message, Status);
        if(Status == "-1")
            exit(1);
    }while (!CheckIsNumber(Str));
    return AtoiCPP(Str);
}

void Congratulation()
{
    cout << "\t--------------------------------"<<endl;
    cout << "\t CONGRATULATION GOOD ANSWER"<<endl;
    cout << "\t--------------------------------"<<endl;
}

void PrintFormaOperatuion(stGame &Game)
{
    cout <<"\t" <<Game.SettingRound.Number1<<endl;
    cout << Game.InputData.OperationInput<<endl;
    cout <<"\t" <<Game.SettingRound.Number2<<endl;
    cout << "________________"<<endl;
    Game.SettingRound.ResultUser =  ReadNumber("Enter your answer = ");
}

void CorrectAnswer(stGame &Game)
{
    cout << "\t--------------------------"<<endl;
    cout << "\t I M SORRY WRONG ANSWER"<< endl;
    cout << "\t--------------------------"<<endl;
    cout << "\t Your answer    : "<<  Game.SettingRound.ResultUser<<endl;
    cout << "\t Correct answer : "<< Game.Result<<endl;
    cout << "\t--------------------------"<<endl;
}

void drawPlus()
{
    cout << "    +    " << endl;
    cout << "    +    " << endl;
    cout << "+++++++++" << endl;
    cout << "    +    " << endl;
    cout << "    +    " << endl;
}

void drawMinus()
{
    cout << "         " << endl;
    cout << "         " << endl;
    cout << "---------" << endl;
    cout << "         " << endl;
    cout << "         " << endl;
}

void drawMultiply()
{
    cout << "*       *" << endl;
    cout << "  *   *  " << endl;
    cout << "    *    " << endl;
    cout << "  *   *  " << endl;
    cout << "*       *" << endl;
}

void drawDivide()
{
    cout << "        *" << endl;
    cout << "      *  " << endl;
    cout << "    *    " << endl;
    cout << "  *      " << endl;
    cout << "*        " << endl;
}

void printERROR()
{
    system("clear");
    cout << "EEEEEEE  RRRRRR   RRRRRR   OOOOO   RRRRRR" << endl;
    cout << "E        R     R  R     R  O   O   R     R" << endl;
    cout << "EEEEE    RRRRRR   RRRRRR   O   O   RRRRRR" << endl;
    cout << "E        R   R    R   R    O   O   R   R" << endl;
    cout << "EEEEEEE  R     R  R     R  OOOOO   R     R" << endl;
}


enum::Operation ChooseOperation(stGame Game)
{
    if (Game.InputData.OperationInput == "+")
        return Operation::ADD;
    else if (Game.InputData.OperationInput == "-")
        return  Operation::SUB;
    else if (Game.InputData.OperationInput == "*")
        return  Operation::MUL;
    else  if (Game.InputData.OperationInput == "/")
        return Operation::DIV;
    return Operation::NOTFOUND;
}

bool IsTrueAnswer(stGame &Game)
{
    return (Game.Result == Game.SettingRound.ResultUser);
}

int Add(int A, int B)
{
    return A + B;
}

int Sub(int A, int B)
{
    return A - B;
}

int Div(int A, int B)
{
    if (B)
    return A / B;
    else
    return 0;
}

int Mul(int A, int B)
{
    return A * B;
}


bool Operation(stGame &Game)
{
    if (ChooseOperation(Game) == Operation::ADD)
        Game.Result = (Add(Game.SettingRound.Number1, Game.SettingRound.Number2));
    else if (ChooseOperation(Game) == Operation::SUB)
        Game.Result =  (Sub(Game.SettingRound.Number1, Game.SettingRound.Number2));
    else if (ChooseOperation(Game) ==  Operation::MUL)
        Game.Result =  (Mul(Game.SettingRound.Number1, Game.SettingRound.Number2));
    else if (ChooseOperation(Game) ==  Operation::DIV)
        Game.Result =  (Div(Game.SettingRound.Number1, Game.SettingRound.Number2));
    else
        Game.Errors.Error = -1;
    return 0;
}

void PgaesOfRate(stGame &Game)
{
    if (IsTrueAnswer(Game))
    {
        Game.CountData.CounterTrue++;
        Congratulation();
    }
    else
    {
        cout << "llalaal\n";
        Game.CountData.CounterFalse++;
        CorrectAnswer(Game);
    }
}

void ReadCorrectRange(stGame &Game)
{
    Game.InputData.RangFrom = ReadNumber("Enter  number From : ");
    Game.InputData.RangTo = ReadNumber("Enter  number To : ");
    while (Game.InputData.RangTo < Game.InputData.RangFrom)
        Game.InputData.RangTo = ReadNumber("Error !! you must enter  number From [Smaller than] number To : ");
}

string ToLower(string &Str)
{
    int i = 0;

    while (Str[i])
    {
        if (isalpha(Str[i]))
            Str[i] = tolower(Str[i]);
        i++;
    }
    return Str;
}

void Process(stGame &Game)
{
    string Times = "0";
    string Status = "0";
    int i = 0;

    do
    {
        if (Times == "yes" || Times == "y")
            system("clear");
        Game.InputData.NumberTimesInput = ReadNumber("How many time do you want gaming : ") ;
        ReadCorrectRange(Game);
        while (Game.InputData.NumberTimesInput > 0 && i < Game.InputData.NumberTimesInput)
        {
            Game.SettingRound.Number1 = RandomNumber(Game.InputData.RangFrom, Game.InputData.RangTo);
            Game.SettingRound.Number2 = RandomNumber(Game.InputData.RangFrom, Game.InputData.RangTo);
            Operation(Game);
            PrintFormaOperatuion(Game);
            PgaesOfRate(Game);
            i++;
        }
        Times = InputString("If you want continue enter (yes) or (y) : ",Status);
        if (Status == "-1")
            exit(1);
        i = 0;
    }
    while (ToLower(Times) == "yes" || ToLower(Times) == "y");

}

void Status(stGame &Game)
{
    if (Game.CountData.CounterFalse > Game.CountData.CounterTrue)
        cout << "\t Status is  : bed"<<endl;
    else if (Game.CountData.CounterFalse < Game.CountData.CounterTrue)
        cout << "\t Status is  : good"<<endl;
    else
        cout << "\t Status is  : Not bad"<<endl;
}

void Table(stGame &Game)
{
    if (ChooseOperation(Game) == Operation::ADD)
        drawPlus();
    else if (ChooseOperation(Game) == Operation::SUB)
        drawMinus();
    else if (ChooseOperation(Game) ==  Operation::MUL)
        drawMultiply();
    else if (ChooseOperation(Game) ==  Operation::DIV)
        drawDivide();
    else
    {
        Game.Errors.Error = -1;
        printERROR();
    }
}




void finalGame()
{
    system("clear");
    cout << "  GGGGG    AAAAA   M     M  EEEEEEE" << endl;
    cout << " G         A     A  MM   MM  E      " << endl;
    cout << " G  GGGG   AAAAAAA  M M M M  EEEEE  " << endl;
    cout << " G     G   A     A  M  M  M  E      " << endl;
    cout << "  GGGGG    A     A  M     M  EEEEEEE" << endl;
    cout << endl;
    cout << " OOOOO   V        EEEEEEE  RRRRRR " << endl;
    cout << " O   O    V     V  E        R    R" << endl;
    cout << " O   O     V   V   EEEEE    RRRRRR" << endl;
    cout << " O   O      V V    E        R   R " << endl;
    cout << " OOOOO       V     EEEEEEE  R    R" << endl;
}

void FinalRating(stGame Game)
{
    system("clear");
    cout << "\t--------------------------"<<endl;
    cout << "\t\tYOUR STATUS "<< endl;
    cout << "\t--------------------------"<<endl;
    Status(Game);
    cout << "\t Count False : "<< Game.CountData.CounterFalse<<endl;
    cout << "\t Count True  : "<< Game.CountData.CounterTrue<<endl;
    cout << "\t Many Times  : "<< Game.InputData.NumberTimesInput<<endl;
    cout << "\t Operation   : "<< Game.InputData.OperationInput<<endl;
    cout << "\t--------------------------"<<endl;
}


bool SettingGame(stGame Game)
{
    string Continue = "no";
    string Status = "0";
    do
    {
        system("clear");
       Game.InputData.OperationInput = InputString("choose What do you want ...( + - / *) ?:  ", Status);
       if (Status == "-1")
            return 1;
        Table(Game);
        if (Game.Errors.Error == -1)
            return 1;
        Process(Game);
        FinalRating(Game);
        Continue = InputString("If you want continue enter yes or y : ", Status) ;
        if (Status == "-1")
            return 1;
    }while (ToLower(Continue) == "yes" || ToLower(Continue) == "y");
    finalGame();
    return 0;
}

bool StartGame()
{
    stGame Game;
    return SettingGame(Game);
}

int main()
{
    srand(time(0));
    if (StartGame())
        return 1;
    return 0;
}