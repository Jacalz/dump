#include <iostream>
#include <fstream>
#include <thread>

using namespace std;

// writeToDiary writes data to the diray and creats the file if it does not exist.
void writeToDiary(string output) {
    // Create the file variable.
    ofstream file;

    // Open the file, it might be non existent though. The trunc option clears the content in the file.
    file.open("diary.txt", ofstream::out | ofstream::trunc);

    // Write the output to the file. If it is non existent, the file will be created.
    file << output;

    // Close our file.
    file.close();
}

// readFromDiary reads the input of what is written inside the diary.
string readFromDiary() {
    // Create the data string for containing file data.
    string filedata;

    // Create the file variable.
    ifstream file;

    // open the file.
    file.open("diary.txt");

    // If the file was opened, we read the line of it (inputs are just one line).
    if (file.is_open()) {
        getline(file, filedata);
    }

    // We end by closing the opened file.
    file.close();

    return filedata;
}


int main() {

    // Create the array with the output sentences.
    string output[4] = {
        "Hello and welcome to my diary!\nDo you want to hear a story?",
        "Wonderful!\nOnce up on a time I was a student at Hogwarts, and I wrote down my thoughts in this diary.\nNow I pass it along to you. Are you ready?",
        "Well then, let us begin!\nMy name is Tom Riddle and you have found my diary.\nYou will help me get revenge! What do you think of that?",
        "I'm afraid that you don't have a choice, my dear.\nYou will help me kill Harry Potter!",
    };

    // Create the array with the input sentences.
    string input[4] = {
        "Yes",
	"Yes, of course I am",
	"I don't wanna help you!",
        "I will obey",
    };

    // The loop that serves as the main point in our game.
    for (int i = 0; i < 4; i++) {
        // Write the output to the diary file. On first iteration, this will create the file.
        writeToDiary(output[i]);

        // Sleep the main thread for five seconds.
        this_thread::sleep_for(5s);

        // Clear the diary by printing "nothing" to it.
        writeToDiary("");

        // Sleep the main thread for 15 seconds while waiting for input.
        this_thread::sleep_for(15s);

        // Read the text from the diary.
        string text = readFromDiary(); 

        // Check that inputed text matches input dat in array.
        if (input[i] != text) {
            writeToDiary("You have entered an invalid answer! Please try again :)");
            break;
        }
    }
}
