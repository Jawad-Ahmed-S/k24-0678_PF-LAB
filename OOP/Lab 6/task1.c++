#include <iostream>
#include <string.h>
using namespace std;

class Message
{
    string text;

public:
    void setText(string text) { this->text = text; };
    string getText() { return this->text; };
    string toString()
    {

        return "";
    };
    bool ContainsKeyword(Message &m, string keyword)
    {
        if (m.getText().find(keyword))
        {
            return true;
        }
        return false;
        // return m.getText().find(keyword)!= string::npos;
    }
    void decodeString(string str)
    {

        int size = str.length();
        for (int i = 0; i < size; i++)
        {
            if (str[i] == 'a')
            {
                str[i] = 'z';
            }
            else if (str[i] == 'A')
            {
                str[i] = 'Z';
            }
            else
            {
                str[i] = str[i] - 1;
            }
        }
        cout << "\nDecoded String : " << str << endl;

        setText(str);
    }
    void encodeString(string str)
    {
        int size = str.length();
        for (int i = 0; i < size; i++)
        {
            if (str[i] == 'z')
            {
                str[i] = 'a';
            }
            else if (str[i] == 'Z')
            {
                str[i] = 'A';
            }
            else
            {
                str[i] = str[i] + 1;
            }
        }
        cout << "\nEncoded : " << str << endl;
        setText(str);
    }
};
class SMS : public Message
{
    string contactNo;

public:
    void setContact(string no) { this->contactNo = no; };
    string getContactNo() { return this->contactNo; };
    string toString()
    {
        setText(getText() + contactNo);
        return (getText());
    }
};
class Email : public Message
{
    string sender;
    string receiver;
    string subject;

public:
    void setSender(string sender) { this->sender = sender; };
    void setReceiver(string receiver) { this->receiver = receiver; };
    void setSubject(string subject) { this->subject = subject; };
    string getSender() { return this->sender; };
    string getReceiver() { return this->receiver; };
    string getSubject() { return this->subject; };
    string toString()
    {
        setText(sender + " - " + receiver + " : " + subject + " - " + getText());
        return (sender + receiver + subject + " " + getText());
    }
};

int main()
{
    SMS s;
    Email e;
    s.setText("Hello World!");
    s.setContact("1234567890");
    e.setText("This is a test email.");
    e.setSender("jaa@example.com");
    e.setReceiver("kaa@example.com");
    e.setSubject("Important Message");
    cout << "SMS: " << s.toString() << endl;
    cout << "Email: " << e.toString() << endl;
    cout << "\nSMS : " << endl;
    cout << "Does the SMS contain the keyword 'World'? " << (s.ContainsKeyword(s, "World") ? "Yes" : "No") << endl;
    s.encodeString(s.getText());
    s.decodeString(s.getText());
    cout << "\nEmail : " << endl;
    cout << "Does the Email contain the keyword 'email'? " << (e.ContainsKeyword(e, "email") ? "Yes" : "No") << endl;
    e.encodeString(e.getText());
    e.decodeString(e.getText());
    return 0;
}