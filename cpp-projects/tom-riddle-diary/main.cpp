#include <iostream>
#include <fstream>

using namespace std:

// Create the array with the output sentences.
string output[4] = {
    "Hello and welcome to my diary!\nDo you want to hear a story?",
    "Wonderful!\nOnce up on a time I was a student at Hogwarts, and I wrote down my thoughts in this diary.\nNow I pass it along to you. Are you ready?",
    "Well then, let us begin!\nMy name is Tom Riddle and you have found my diary.\nYou will help me get revenge! What do you think of that?",
    "I'm afraid that you don't have a choice, my dear.\nYou will help me kill Harry Potter!",
}

// Create the array with the input sentences.
string input[4] = {
    "Yes",
	"Yes, of course I am",
	"I don't wanna help you!",
	"I will obey",
} 

int main() {
    cout << "The book is opening..." << endl;

    for (int i = 0; i < 4; i++) {
        cout << "Pass number: " << i+1 << endl;

        cout << "The book is opening..." << endl;
    }

}
