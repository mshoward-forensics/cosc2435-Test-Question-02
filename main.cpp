/*********************
*Name: Nicole Howard
*Coding 03
*Purpose: Thoroughly test the stack class.
**********************/

#include "main.h"

int main(int argc, char** argv){

    // seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];

    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++)
    {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++)
        {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++)
    {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    cout << "\n*********************************" << endl;
    cout << "BEGIN TESTING ON Queue" << endl;
    cout << "*********************************\n" << endl;

    Fifo myFifo;
    std::cout << "**Created myQueue**\n" << endl;

    //empty Data struct
    Data data;

    //empty Node 
    Node node;

    //tesing isEmpty()
    cout << "**Test if queue is empty**" << endl;
    if (myFifo.isEmpty() == 1){
        cout << "Queue is empty" << endl;
    }
    if (myFifo.isEmpty() != 1){
        cout << "Queue is NOT empty" << endl;
    }
    
    //testing push
    string test = "test push data";
    cout << "\n**Test push **" << "\nid: " << 44 << "  &  " << "data: " << test << endl;
    
    if (myFifo.push(44, &test) == true){
        cout << "push was successful" << endl;
    } else{
        cout << "Information NOT pushed to queue" << endl;
    }

    //testing peek 
    cout << "\n**Testing the peek funcion in queue**" << endl;
    if (myFifo.peek(&data)){
        cout << "peek value: " << data.id << "  &  " << data.data << endl;
    } else {
        cout << "queue is Empty" << endl;
    }

    //randomly testing push
    cout << "\n**Testing the push funcion in queue**" << endl;
    for (int i = 0; i <= (testdatasize/5); i++){  
        if (myFifo.push(ids[i], &strs[i]) == true){
            cout << "push was successful" << endl;
        }
        else{
            cout << "Information NOT pushed to queue" << endl;
        }
    } 


    //testing pull
    cout << "\n**Test pull function of queue**" << endl;
    for (int i = 0; i <= testdatasize/5; i++){
        cout << i << endl;
        if (myFifo.pull(&node)){
            cout << "pull successful" << endl;
            cout << "id: " << node.data.id << "data: " << node.data.data << endl;
        } else{
            cout << "queue empty" << endl;
        }
    }

   

    //testing peek 
    cout << "\n**Testing the peek funcion in queue**" << endl;
    if (myFifo.peek(&data)){
        cout << "peek value: " << data.id << "  &  " << data.data << endl;
    } else {
        cout << "queue is Empty" << endl;
    }

    //testing for isEmpty
   cout << "\n**Test if stack is empty**" << endl;
    if (myFifo.isEmpty() == 1){
        cout << "Queue is empty" << endl;
    }
    if (myFifo.isEmpty() != 1){
        std::cout << "Queue is NOT empty" << endl;
    }

    //randomly do tasks on the stack
    cout << "\n**Randomly test push, pull, peek and isEmpty functions**" << endl;
    int tempTest;
    string string_add;
    for (int i = 0; i <= testdatasize*1.5; i++){
        int k = rand() %6 + 1;
        tempTest = testdatasize + (rand() % OFFSET + 1);
        string_add = rand() % 2 ? (rand() % (26)) + 'A' : (rand() % (26)) + 'a';
        cout << "\n" << "trial number: " <<  i << "\t" << "Random case: " <<  k << endl;
        switch(k){
            case 1: {

            }
            case 2: 
                if (myFifo.push(tempTest, &string_add) == true){
                    std::cout << "push was successful" << std::endl;
                }
                else{
                    std::cout << "push unsuccessful" << std::endl;
                }
                break;
            case 3:
                if (myFifo.peek(&data)){
                    cout << "peek value: " << data.id << "  &  " << data.data << endl;
                } else {
                    cout << "queue is Empty" << endl;
                }
                break;
            case 4:{

            }
            case 5:
                if (myFifo.pull(&node)){
                    cout << "pull successful" << endl;
                    cout << "id: " << node.data.id << "  data: " << node.data.data << endl;
                } else{
                    cout << "queue empty" << endl;
                }
                break;
            case 6:
                if (myFifo.isEmpty() == 1){
                    std::cout << "Queue is empty" << std::endl;
                }
        }
    }
    std::cout << "\n\n***Testing of queue completed***\n" << std::endl;

    return 0; 
}