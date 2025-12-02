#include<stdio.h> 

typedef enum 
{
    STATE_IDLE,
    STATE_PROCESSING,
    STATE_DONE
}State_t; 

typedef enum 
{
    EVENT_START,
    EVENT_FINISH,
    EVENT_RESET
}Event_t;

//Set the current state as idle 
State_t current_state = STATE_IDLE; 

//State handlers (functions for each state)
void handleIdle(Event_t event)
{
    if(event == EVENT_START)
    {
        printf("Transition: IDLE->PROCESSING\n"); 
        current_state = STATE_PROCESSING;
    }
}

void handleProcessing(Event_t event)
{
    if(event = EVENT_FINISH)
    {
        printf("Transition: Processing -> Done\n");
        current_state = STATE_DONE;
    }
    else if(event = EVENT_RESET)
    {
        printf("Transition: Processing -> Idle\n");
        current_state = STATE_IDLE;
    }
}

void handleDone(Event_t event)
{
    if(event == EVENT_RESET)
    {
        printf("Transition: DONE->IDLE\n"); 
        current_state = STATE_IDLE;
    }
}

void dispatchEvent(Event_t event)
{
    switch(current_state)
    {
        case STATE_IDLE :
            handleIdle(event); 
            break; 
        case STATE_PROCESSING:
            handleProcessing(event); 
            break; 
        case STATE_DONE:
            handleDone(event); 
            break;
    }
}

int main(void)
{
    printf("Initial state: IDLE\n"); 

    dispatchEvent(EVENT_START);
    dispatchEvent(EVENT_FINISH);
    dispatchEvent(EVENT_RESET); 

    return 0;
}