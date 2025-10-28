#include<iostream>
#include<cstring>
using namespace std; 

class String 
{
private : 
    char *data; 
public : 
    String() : data(new char[1])
    {
        data[0] = '\0';
    }
    //Parameterized constructor 
    String(char *str )
    {
        data = new char[strlen(str)+1]; 
        strcpy(data,str);
    }
    //Copy constructor 
    String(const String& str)
    {
        data = new char{strlen(str.data)+1}; 
        strcpy(data,str.data); 
    }
    //Move constructor 
    String(String&& other)
    {
        data = other.data; 
        other.data = nullptr;
    }

    //Copy assignment operator 
    String& operator==(const String& str)
    {
        if(this != &str)
        {
            delete[] data; 
            data = new char[strlen(str.data)+1]; 
            strcpy(data,str.data);
        }
        return *this;
    }
    //Move Assignment operator 
    String& operator==(String&& other)noexcept
    {
        if(this != &other)
        {
            data = other.data; 
            other.data = nullptr;
        }
        return *this; 
    }
    //string concatenation 
    String operator+(const String& str)
    {
        char *newdata = new char[strlen(data)+strlen(str.data)+1]; 
        //copy the current data to the newdata
        strcpy(newdata,data);
        delete []data; 
        //Perform string concatenation 
        strcat(newdata,str.data);

        data = newdata;
        return String(data);
    }
    //String indexing 
    char& operator[](int index)
    {
        return data[index];
    }

    int length()
    {
        return strlen(data);
    }

    //destructor 
    ~String()
    {
        delete[] data; 
    }

    friend std::ostream& operator<<(std::ostream& os,const String& str)
    {
        os<<str.data; 
        return os;
    }
};

int main()
{
	String s1("Hello");
	String s2("World");
	String s3 = s1+s2;

	cout<<"Concatenated: "<<s3<<endl;
	cout<<"Length: "<<s3.length()<<endl;
	cout<<"Character at 1 : "<<s3[1]<<endl;

	//Use overloaded friend function
	String s4("how");
	cout<<s4;

	return 0;
}