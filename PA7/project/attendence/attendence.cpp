#include "..\project\attendence\attendence.hpp"
#include <sstream>

//node
template <class T>
Node<T>::~Node()
{
    delete nextNode;
}

//list

template <class T>
//masterlist call
//idk i think im supposed to delete master still, call orders weird, ima just do it anyways
void List<T>::loadList(std::ifstream& infile)
 {
    delete headNode;
    headNode = nullptr;

    std::string line;

    while(getline(infile, line))
    {
        std::stringstream linestream(line);
        std::string tok;
        Node<Data>* newNode = new Node<Data>();
        newNode->nextNode = headNode;
        headNode = newNode;

        //stupid front number (i added it back)
        getline(linestream, tok, ',');
        //id
        getline(linestream, tok, ',');
        newNode->data.ID = std::stoi(tok);
        //name (comma in the middle cuz andy felt like it)
        getline(linestream, tok, '"');
        getline(linestream, tok, '"');
        newNode->data.fullName = tok;
        //email
        getline(linestream, tok, ',');
        newNode->data.email = tok;
        //units
        getline(linestream, tok, ',');
        newNode->data.units = std::stoi(tok);
        //program
        getline(linestream, tok, ',');
        newNode->data.program = tok;
        //level
        getline(linestream, tok, ',');
        newNode->data.level = std::stoi(tok);

        while(getline(linestream, tok, ','))
        {
            newNode->data.absenceDates.push(tok);
            newNode->data.absences += 1;
        }
        
    }
 }

template <class T>
//classlist call
//it said delete master so i delete the list and the file
void List<T>::loadList(std::ifstream& infile, std::ifstream& delfile)
 {
    delete headNode;
    headNode = nullptr;

    std::string line;
    getline(infile, line);

    while(getline(delfile, line))
    {

    }

    while(getline(infile, line))
    {
        std::stringstream linestream(line);
        std::string tok;
        Node<Data>* newNode = new Node<Data>();
        newNode->nextNode = headNode;
        headNode = newNode;

        //stupid front number
        getline(linestream, tok, ',');
        //id
        getline(linestream, tok, ',');
        newNode->data.ID = std::stoi(tok);
        //name (comma in the middle cuz andy felt like it)
        getline(linestream, tok, '"');
        getline(linestream, tok, '"');
        newNode->data.fullName = tok;
        //email
        getline(linestream, tok, ',');
        newNode->data.email = tok;
        //units
        getline(linestream, tok, ',');
        newNode->data.units = std::stoi(tok);
        //program
        getline(linestream, tok, ',');
        newNode->data.program = tok;
        //level
        getline(linestream, tok, ',');
        newNode->data.level = std::stoi(tok);
        
        newNode->data.absences = 0;
    }
 }

template <class T>
void List<T>::writeToFile(std::ofstream& outfile)
{
    Node<T>* curNode = headNode;
    int row = 0;
    while(curNode != nullptr)
    {
        row++;
        outfile << row << "," << curNode->data.ID << ",\"" << curNode->data.fullName << "\"," << curNode->data.email << "," << curNode->data.units << "," << curNode->data.program << "," << curNode->data.level << "," << curNode->data.absences << ",";

        std::stack<std::string> tempStack;
        while(!curNode->data.absenceDates.empty())
        {
            tempStack.push(curNode->data.absenceDates.top());
            curNode->data.absenceDates.pop();
        }

        while(!tempStack.empty())
        {
            outfile << tempStack.top();
            curNode->data.absenceDates.push(tempStack.top());
            tempStack.pop();
            if(!tempStack.empty()) outfile << ";";
        }

        outfile << std::endl;
        curNode = curNode->nextNode;
    }
}

template <class T>
void List<T>::checkAttendance()
{
    Node<T>* curPointer = headNode;
    while(curPointer != nullptr)
    {
        char answer = 0;
        while(tolower(answer) != 'y' && tolower(answer) != 'n')
        {
            system("cls");
            std::cout << "Was " << curPointer->data.fullName << " here today?" << std::endl;
            std::cin >> answer;
        }
        
        if(tolower(answer) == 'n')
        {
            time_t t = time(0);
            struct tm* now = localtime(&t);

            std::string date = std::to_string(now->tm_mon + 1) + "/" +
                               std::to_string(now->tm_mday) + "/" +
                               std::to_string(now->tm_year + 1900);

            curPointer->data.absenceDates.push(date);
            curPointer->data.absences += 1;
        }
        curPointer = curPointer->nextNode;
    }
}

template <class T>
void List<T>::generateReport(std::ofstream& outfile)
{
    Node<T>* curPointer = headNode;
    while(curPointer != nullptr)
    {
        if(curPointer->data.absenceDates.empty())
        {
            outfile << curPointer->data.fullName << " has no absences" << std::endl;
        }
        else
        {
            outfile << curPointer->data.fullName << " was absent last on " << curPointer->data.absenceDates.top() << std::endl;
        }
        curPointer = curPointer->nextNode;
    }
}

template <class T>
void List<T>::editAbsences()
{
    Node<T>* curPointer = headNode;
    int currentStudent = 1;
    int choice = 0;

    system("cls");
    //print the students
    while(curPointer != nullptr)
    {
        std::cout << currentStudent << ". " << curPointer->data.fullName << std::endl;
        curPointer = curPointer->nextNode;
        currentStudent++;
    }

    do
    {
        std::cout << std::endl;
        std::cout << "Choice: " << std::endl;
        std::cin >> choice;
    } while(!isMenuInput(choice, 1, currentStudent - 1));

    //get that student
    curPointer = headNode;
    for(int i = 1; i < choice; i++)
    {
        curPointer = curPointer->nextNode;
    }

    system("cls");
    std::stack<std::string> tempStack;
    int count = 0;
    //print all absences
    while(!curPointer->data.absenceDates.empty())
    {
        count++;
        std::cout << count << ". " << curPointer->data.absenceDates.top() << std::endl;
        tempStack.push(curPointer->data.absenceDates.top());
        curPointer->data.absenceDates.pop();
    }

    do
    {
        std::cout << std::endl;
        std::cout << "Choice: " << std::endl;
        std::cin >> choice;
    } while(!isMenuInput(choice, 1, count));

    //change stack back
    int otherCount = count;
    std::stack<std::string> rebuiltStack;
    while(!tempStack.empty())
    {
        if(otherCount == choice)
        {
            std::string newDate;
            std::cout << "Whats the new date: (mm/dd/year): ";
            std::cin >> newDate;
            rebuiltStack.push(newDate);
        }
        else
        {
            rebuiltStack.push(tempStack.top());
        }
        tempStack.pop();
        otherCount--;
    }

    // put rebuilt stack back
    while(!rebuiltStack.empty())
    {
        curPointer->data.absenceDates.push(rebuiltStack.top());
        rebuiltStack.pop();
    }
}

template <class T>
void List<T>::generateReport(std::ofstream& outfile, int maxAbsences)
{
    Node<T>* curPointer = headNode;
    while(curPointer != nullptr)
    {
        if(curPointer->data.absences >= maxAbsences)
        {
            outfile << curPointer->data.fullName << " has " << curPointer->data.absences << " absences" << std::endl;
        }
        curPointer = curPointer->nextNode;
    }
}