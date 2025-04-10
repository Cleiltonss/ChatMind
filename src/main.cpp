#include "chatbot.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {
    srand(time(0));  // Randomize the replies


    string userInput;
    cout << "\nChatbot: Hello! Type something to chat (type 'exit' to quit).\n";

    while (1) {
        cout << "You: ";
        getline(cin, userInput); // Take more than 1 word from an input
        
        // Convert input to lowercase
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

        if(userInput == "exit") {break;}

        string reply = getResponse(userInput);
        cout << "\nChatbot: " << reply << "\n";
    }

    cout << "\nChatbot: See you next time! :)\n\n";
    return 0;
}