#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Card
{
    string name;
    string owner;
    string phone;
    string address;
    string work;
public:
    Card()
    {
        name = "Name";
        owner = "Owner";
        phone = 1;
        address = "Address";
        work = "Work";

    }
    Card(string n, string o, string p, string a, string w)
    {
        name = n;
        owner = o;
        phone = p;
        address = a;
        work = w;
    }
    string GetName()
    {
        return name;
    }
    void SetName(string n)
    {
        name = n;
    }
    string GetOwner()
    {
        return owner;
    }
    void SetOwner(string o)
    {
        owner = o;
    }
    string GetPhone()
    {
        return phone;
    }
    void SetPhone(string p)
    {
        phone = p;
    }
    string GetAddress()
    {
        return address;
    }
    void SetAddress(string a)
    {
        address = a;
    }
    string GetWork()
    {
        return work;
    }
    void SetWork(string w)
    {
        work = w;
    }
    void Print()
    {
        cout << name << endl << work << "\nOwned by " << owner << endl << phone << "\nAddress: " << address << endl << endl;
    }
};

class Notes
{
    Card* arr;
    int size;
public:
    Notes()
    {
        size = 0;
        arr = nullptr;
    }
    void Add(Card obj)
    {
        Card* temp = new Card[size + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        temp[size] = obj;
        if (arr != nullptr)
            delete[] arr;
        arr = temp;
        size++;
    }
    void Delete(int index)
    {
        Card* temp = new Card[size - 1];
        for (int i = 0; i < size-1; i++)
        {
            bool skip = i >= index;
            temp[i] = arr[i+skip];
        }
        if (arr != nullptr)
            delete[] arr;
        arr = temp;
        size--;
    }
    void PrintAll()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << ".\n";
            arr[i].Print();
        }
    }
    void SearchName(string search)
    {
        cout << "Searching for \"" << search << "\":\n";
        for (int i = 0; i < size; i++)
        {
            if (search == arr[i].GetName())
            {
                arr[i].Print();
                return;
            }
        }
        cout << "Not found\n\n";
    }
    void SearchOwner(string search)
    {
        cout << "Searching for \"" << search << "\":\n";
        for (int i = 0; i < size; i++)
        {
            if (search == arr[i].GetOwner())
            {
                arr[i].Print();
                return;
            }
        }
        cout << "Not found\n\n";
    }
    void SearchPhone(string search)
    {
        cout << "Searching for \"" << search << "\":\n";
        for (int i = 0; i < size; i++)
        {
            if (search == arr[i].GetPhone())
            {
                arr[i].Print();
                return;
            }
        }
        cout << "Not found\n\n";
    }
    void SearchWork(string search)
    {
        cout << "Searching for \"" << search << "\":\n";
        for (int i = 0; i < size; i++)
        {
            if (search == arr[i].GetWork())
            {
                arr[i].Print();
                return;
            }
        }
        cout << "Not found\n\n";
    }
    void Write()
    {
        remove("data.txt");
        ofstream out("data.txt");
        if (out.is_open())
        {
            for (int i = 0; i < size; i++)
            {
                out << arr[i].GetName() << endl;
                out << arr[i].GetOwner() << endl;
                out << arr[i].GetPhone() << endl;
                out << arr[i].GetAddress() << endl;
                out << arr[i].GetWork();
                if (i < size - 1)
                    out << endl;
            }
            out.close();
        }
    }
    void Read()
    {
        string n, o, p, a, w;
        ifstream in("data.txt");

        if (in.is_open())
        {
            while (!in.eof())
            {
                getline(in, n);
                getline(in, o);
                getline(in, p);
                getline(in, a);
                getline(in, w);
                Card obj(n, o, p, a, w);
                Add(obj);
            }
            in.close();
        }
    }
    void InputCard()
    {
        string n, o, p, a, w;
        cout << "Name: ";
        cin >> n;
        cout << "Owner: ";
        cin >> o;
        cout << "Phone number: ";
        cin >> p;
        cout << "Address: ";
        cin >> a;
        cout << "Field of work: ";
        cin >> w;
        Card obj(n, o, p, a, w);
        cout << endl;
        Add(obj);
    }
};



int main()
{
    int choice;
    int index;
    string search;
    Notes list;
    list.Read();
    list.PrintAll();

    do
    {
        cout << "0 - exit\n1 - add\n2 - delete\n3 - search by name\n4 - search by owner\n5 - search by phone number\n6 - search by field of work\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            list.InputCard();
            break;
        case 2:
        {
            cout << "enter an index to delete: ";
            cin >> index;
            list.Delete(index);
            break;
        }
        case 3:
            cout << "Search: ";
            cin >> search;
            list.SearchName(search);
            break;
        case 4:
            cout << "Search: ";
            cin >> search;
            list.SearchOwner(search);
            break;
        case 5:
            cout << "Search: ";
            cin >> search;
            list.SearchPhone(search);
            break;
        case 6:
            cout << "Search: ";
            cin >> search;
            list.SearchWork(search);
            break;
        }
        list.Write();
        list.PrintAll();
    } while (choice != 0);


    
}