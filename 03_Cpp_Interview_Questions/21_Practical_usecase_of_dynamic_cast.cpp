#include<iostream> 
using namespace std; 

//Base class 
class DiagnosticMessage
{
public:
    virtual ~DiagnosticMessage() {};
};

class UDSRequest : public DiagnosticMessage 
{
public:
    void handleUDS()
    {
        cout<<"Handle UDS request"<<endl;
    }
};
class OBDRequest : public DiagnosticMessage 
{
public:
    void handleOBD()
    {
        cout<<"Handle OBD request"<<endl;
    }
};

void processMessage(DiagnosticMessage *msg)
{
    //perform safe downcast using dynamic cast 
    if(auto uds = dynamic_cast<UDSRequest*>(msg))
    {
        uds->handleUDS();
    }
    if(auto obd = dynamic_cast<OBDRequest*>(msg))
    {
        obd->handleOBD();
    }
}


int main(void)
{
    DiagnosticMessage *btr = new UDSRequest(); 
    processMessage(btr); 
    btr = new OBDRequest(); 
    processMessage(btr);

    return 0;
}