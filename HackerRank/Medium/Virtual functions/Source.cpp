int ID[2] = {};

class Person
{
public:
    virtual void getdata()
    {
        cin >> name >> age;
    }

    virtual void putdata()
    {
        cout << name << " " << age << " ";
    }

private:
    string name = "";
    int age = 0;

protected:
    int id = 0;
};

class Professor : public Person
{
public:
    virtual void getdata()
    {
        Person::getdata();
        cin >> publication;
        id = ++ID[0];
    }

    virtual void putdata()
    {
        Person::putdata();
        cout << publication << " " << id << endl;
    }

private:
    int publication = 0;
};

class Student : public Person
{
public:
    virtual void getdata()
    {
        Person::getdata();
        for (int iter = 0; iter < 6; iter++)
            cin >> marks[iter];
        id = ++ID[1];
    }

    virtual void putdata()
    {
        Person::putdata();
        cout << marks[0] + marks[1] + marks[2] + marks[3] + marks[4] + marks[5] << " " << id << endl;
    }

private:
    int marks[6] = {};
};