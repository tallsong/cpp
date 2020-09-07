

int main()
{

    struct Employee
    {
        short id;
        int age;
        double wage;
    };

    Employee joe{1, 32, 60000.0}; // joe.id = 1, joe.age = 32, joe.wage = 60000.0
    Employee frank{2, 28};        // frank.id = 2, frank.age = 28, frank.wage = 0.0 (default initialization)
}