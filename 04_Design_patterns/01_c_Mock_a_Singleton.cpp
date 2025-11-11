//------------------------------Production Singleton-------------------------------------
class Logger 
{
private : 
    Logger() {}; 
public:
    static Logger& getInstance()
    {
        static Logger instance; 
        return instance;
    }

    virtual void Log(const String& msg)
    {
        std::cout<<"[LOG] "<<msg<<endl;
    }
};
//--------------------------Mocking Singleton----------------------------------------------------

/*Step 1 : Create an Interface */
class ILogger 
{
public :
    virtual void Log(const string& str) =0; 
    virtual ~ILogger() = default;
}; 
/*Step 2 : Make production Singleton implement the interface */
class Logger : public ILogger
{
private : 
    Logger() {}; 
public:
    static Logger& getInstance()
    {
        static Logger instance; 
        return instance;
    }

    void Log(const String& msg) override
    {
        std::cout<<"[LOG] "<<msg<<endl;
    }
};
/* Make the client code use the ILogger (Not Singleton )*/

class CAN
{
private:
    ILogger & logger; 
private:
    void process()
    {
        logger.log("Tx message sent");
        logger.log("Rx message recieved");
    }
};

//---------------------------Mock class------------------------------
class MockLogger : public ILogger
{
public:
    vector<std::string> calls; 

    void log(const string& msg)override 
    {
        calls.push_back(msg);
    }
}; 

//-------------------Google Test Fixture-------------------------------
class CAN : public ::testing::test 
{
protected:
    MockLogger mock ; 
    CAN *processor = nullptr; 

    void setup() override 
    {
        processor = new CAN(mock);
    }

    void TearDown() override
    {
        delete processor;
    }
};

