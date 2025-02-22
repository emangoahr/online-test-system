
#include<iostream>
#include<string>
#include<vector>

using namespace std;

//User class to handle logic and registration
 class User {
     string username, password;

 public:
        void registerUser(){
           cout << "Register New User\n";
           cout << "Enter Username: ";
           cin >> username;
           cout << "Enter Password: ";
           cin >> password;
           cout << "Registration Successful!\n\n";
        }

        bool loginUser(){
            string inputUsername, inputPassword;
            cout << "Logic\n";
            cout << "Enter Username: ";
            cin >> inputUsername;
            cout << "Enter Password: ";
            cin >> inputPassword;

            if (inputUsername == username && inputPassword == password){
               cout << "Login Successful!\n\n";
               return true;
            } else {
               cout << "Invalid Credentials!\n\n";
               return false;
            }
       }
};

//Question class to store and display question
class Question {
    string questionText;
    vector<string> options;
    int correctOption;

public:
    Question(string qText, vector<string> opts,int correct)
        : questionText(qText), options(opts), correctOption(correct){}

    void displayQuestion(){
        cout << questionText << "\n";
        for (int i = 0; i < options.size(); i++){
                cout << i + 1 << ". " << options[i] << "\n";
        }
        cout << "Enter your answer: ";
    }

    bool checkAnswer(int answer){
        return answer == correctOption;
    }
};

//Main test system
int main(){
    User user;
    user.registerUser();

    if (!user.loginUser()){
        cout << "Exiting Program...\n";
        return 0;
    }

    vector<Question> question = {
         Question("What is the capital of Pakistan?",{"Kohat", "Lahore", "Peshawar", "Islamabad"}, 4),
         Question("What is 5 + 3?", {"5", "8", "10", "15"}, 2),
         Question("Which language is used for system programming?",{"Python", "Java", "C++", "Ruby"}, 3)
    };

    int score = 0;

    for (int i = 0; i < question.size(); i++){
        cout << "\nQuestion " << i + 1 << ":\n";
        question[i].displayQuestion();

        int answer;
        cin >> answer;

        if (question[i].checkAnswer(answer)){
            cout << "Correct!\n";
            score++;
        } else {
             cout << "Wrong Answer!\n";
        }
    }

    cout << "\nTest Completed!\n";
    cout << "Your Score: " << score << " / " << question.size() << "\n";

    return 0;
}







