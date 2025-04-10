#include "chatbot.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;


// Rule of responses
map<string, vector<string>> rules = {
    {"hello", {"Hey", "Hi there!", "Yo!", "Hello, friend!"}},
    {"hi", {"Hey!", "Hi there!", "Howdy!", "Hi again!"}},
    {"how are you", {"I'm just code, but I'm doing fine!", "All systems go!", "I'm functioning as expected!"}},
    {"bye", {"Goodbye!", "See you later!", "Bye bye!", "Take care!"}},
    {"help", {"Try typing: hello, how are you, bye, or exit to leave the chat."}},
    {"menu", {"Here are some things I understand: hello, how are you, bye, help."}},
    {"commands", {"Try saying: hello, how are you, bye, exit, help."}}
};

// Memory store of informations
map<string, string> memory;


string getResponse(string input) {   
    // User tells their name
    if(input.find("my name is") != string::npos) {
        string name = input.substr(input.find("my name is") + strlen("my name is"));
        name.erase(0, name.find_first_not_of(" "));
        memory["name"] = name;
        return "Nice to meet you," + name + "!";
    }

    // User asks their name
    if(input.find("what is my name") != string::npos || input.find("what's my name") != string::npos) {
        if(memory.count("name")) {
            return "Your name is:" + memory["name"];
        } else {
            return "I don't know your name yet. Tell me by saying 'my name is ...'";
        }
    }

    // User tells their age
    if (input.find("my age is") != string::npos) {
        string age = input.substr(input.find("my age is") + strlen("my age is"));
        age.erase(0, age.find_first_not_of(" "));
        memory["age"] = age;
        return "Alright, I'll remember that you're " + age + " years old.";
    }
    
    // User asks their age
    if (input.find("what is my age") != string::npos || input.find("what's my age") != string::npos) {
        if (memory.count("age")) {
            return "You're " + memory["age"] + " years old.";
        } else {
            return "I don't know your age yet. Tell me using 'my age is ...'";
        }
    }
    
    // User tells their favorite color
    if (input.find("my favorite color is") != string::npos) {
        string color = input.substr(input.find("my favorite color is") + strlen("my favorite color is"));
        color.erase(0, color.find_first_not_of(" "));
        memory["favorite_color"] = color;
        return "Nice! I'll remember your favorite color is " + color + ".";
    }

    // User asks their favorite color
    if (input.find("what is my favorite color") != string::npos || input.find("what's my favorite color") != string::npos) {
        if (memory.count("favorite_color")) {
            return "Your favorite color is " + memory["favorite_color"] + ".";
        } else {
            return "I don't know your favorite color yet. Tell me using 'my favorite color is ...'";
        }
    }
    
    // User tells their favorite food
    if (input.find("my favorite food is") != string::npos) {
        string food = input.substr(input.find("my favorite food is") + strlen("my favorite food is"));
        food.erase(0, food.find_first_not_of(" "));
        memory["favorite_food"] = food;
        return "Yum! I'll remember that your favorite food is " + food + ".";
    }

    // User asks their favorite food
    if (input.find("what is my favorite food") != string::npos || input.find("what's my favorite food") != string::npos) {
        if (memory.count("favorite_food")) {
            return "Your favorite food is " + memory["favorite_food"] + ".";
        } else {
            return "I don't know your favorite food yet. Tell me using 'my favorite food is ...'";
        }
    }
    


    // Teach the chat to think
    if(input.find("teach ") == 0) {
        string phrase = input.substr(input.find("teach ") + strlen("teach "));
        
        size_t spacePos = phrase.find(" ");
        if (spacePos != string::npos) {
            string keyword = phrase.substr(0, spacePos);
            string response = phrase.substr(spacePos + 1);
            rules[keyword].push_back(response);
            return "Got it! I'll remember that.";
        } else {
            return "Oops! Use: teach <keyword> <response>";
        }
    }
    
    for(const auto& rule: rules) {
        if(input.find(rule.first) != string::npos) {
            const vector<string>& possibleReplies = rule.second;

            // Randomize a number and take the rest of the division by the size of a answer, given the index of each answer! 
            int randomIndex = rand() % possibleReplies.size(); 
            return possibleReplies[randomIndex];
        }
    }

    // If no keyword matched
    // Save all unknwon informations in a file .txt
    ofstream file("data/unknown_inputs.txt", ios::app); // Create and open the file
    file << input << endl;
    file.close(); // Close the file
    return "Sorry, I don't understand that.";
}

