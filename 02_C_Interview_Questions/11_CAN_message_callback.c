#include<stdio.h> 
#include<stdint.h> 

/*----------------Callback Type---------------------------------------*/
typedef void(*CanCallback)(uint32_t id,uint8_t data); 

/*--------------Registered canCallback---------------------------------*/
static CanCallback app_cb = NULL; 

/*--------------Register application callback--------------------------*/
void register_callback(CanCallback cb)
{
    app_cb = cb;
}

/*--------------Simple security check-----------------------------------*/
int is_valid_can_id(uint32_t id)
{
    return (id == 0x100); //Only allow ID 0x100
}
/* Advantaga of callbacks 
    1.Loose coupling (Driver does'nt need depend on app code )
        *CAN Driver does'nt need to know what the application wants to do 
        *Application decides the action by registering a callback 
    2.Reusability : Same driver can be used across many projects 
*/


/*---------------Simulate CAN recieve-------------------------------------*/
void can_recieve(uint32_t id,uint8_t data)
{
    if(!is_valid_can_id(id))
    {
        printf("Blocked unauthorized CAN ID: 0x%X\n",id);
        return ;
    }
    if(app_cb)
    {
        app_cb(id,data); //<---callback
    }
}

/* Application callback-------------------*/
void on_can_message(uint32_t id,uint8_t data)
{
    printf("Recieved valid CAN Frame! ID=0x%X DATA= %d\n",id,data);
}

/*-----------------MAIN----------------------------*/

int main(void)
{
    register_callback(on_can_message); 

    can_recieve(0x100,55); //Allowed 
    can_recieve(0x200,99);//Blocked

    return 0;
}