#include <iostream>
#include <string>
#include <vector>

using namespace std;

class solution
{
private:
    vector<string> passwds;

public:
    void check(void);
    void split(string s, char c);
};

void solution::split(string s, char c)
{
    std::string::size_type pos1, pos2;
    pos1 = 0;
    pos2 = s.find(c);

    while (std::string::npos != pos2)
    {
        passwds.push_back(s.substr(pos1, pos2 - pos1));

        pos1 = pos2 + 1;
        pos2 = s.find(c, pos1);
    }

    if (pos1 != s.length())
    {
        passwds.push_back(s.substr(pos1));
    }
}

void solution::check(void)
{
    for (auto passwd : passwds)
    {
        if (passwd.size() < 8)
        {
            //长度小于8 输出1
            cout << 1 << endl;
            continue;
        }
        
        int valid = 0;
        for (string::size_type i = 0; i < passwd.size(); i++)
        {
            if ((passwd[i] >= 'A') && (passwd[i] <= 'Z'))
            {
                //大写字母
                valid |= 0x01;
            }
            else if ((passwd[i] >= 'a') && (passwd[i] <= 'z'))
            {
                //小写字母
                valid |= 0x02;
            }
            else if ((passwd[i] >= '0') && (passwd[i] <= '9'))
            {
                //数字
                valid |= 0x04;
            }
            else if ((passwd[i] >= 32) && (passwd[i] < '0'))
            {
                //符号
                valid |= 0x08;
            }
            else if ((passwd[i] > '9') && (passwd[i] < 'A'))
            {
                //符号
                valid |= 0x08;
            }
            else if ((passwd[i] > 'Z') && (passwd[i] < 'a'))
            {
                //符号
                valid |= 0x08;
            }
            else if ((passwd[i] > 'z') && (passwd[i] < 128))
            {
                //符号
                valid |= 0x08;
            }
        }

        if(valid == 0x0f)
        {
            //符合要求
            cout << '0' << endl;
        }
        else
        {
            //有四种字符中的一种不包含
            cout << '2' << endl;
        }
        
    }
    
}

int main()
{
    string s;
    solution solve;

    getline(cin, s);

    solve.split(s, ' ');
    solve.check();

    return 0;
}
