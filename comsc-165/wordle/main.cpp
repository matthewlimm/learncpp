#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Wordle.h"

// "Wordle recreated" project finished in ~ 2 hours

// #define PRINT_WORDLE_WORDS

void Wordle::setAnswer()
{
    srand(time(nullptr));
    std::ifstream inFile;
    std::string wordAnswer{};
    inFile.open("/Users/matthewlim/Dev/COMSC-165/wordle/combined_wordlist.txt", std::ios::in); // shuffled_real_wordles.txt is all the words that have been or will be solutions

    if (inFile.is_open())
    {
#ifdef PRINT_WORDLE_WORDS // conditional complication preprocessor directive to print .txt file word list
        getline(inFile, wordAnswer);
        while(!inFile.eof())
        {
            std::cout << wordAnswer << '\n';
            getline(inFile, wordAnswer);
        }
        std::cout << "EOF\n";
#endif
        int randomPick{ 1 + (rand() % 12973) };
        std::cout << randomPick << '\n';
        for(int i = 1; i < randomPick; ++i)
        {
            getline(inFile, wordAnswer);
        }
        getline(inFile, wordAnswer);
        m_answer = wordAnswer;

    }
    else
    {
        std::cout << "ERROR: could not open file\n";
        m_answer = "ERROR";
    }
}

void Wordle::setGuess(std::string guess)
{
    m_guess = guess;
    m_misplacedLetters = "";
    int r = m_try - 1;
    for(int c = 0; c < 5; ++c)
    {
        if(m_guess.substr(c, 1) == m_answer.substr(c, 1))
        {
            m_grid[r][c] = "🟩";
        }
        else if(m_answer.find(m_guess.substr(c, 1)) != std::string::npos)
        {
            m_grid[r][c] = "🟨";
            setMisplacedLetters(m_guess.substr(c, 1));
        }
        else
        {
            m_grid[r][c] = "🔲";
            if(getInvalidLetters().find(m_guess.substr(c, 1)) == std::string::npos)
            {
                setInvalidLetters(m_guess.substr(c, 1));
            }
        }
    }
    std::cout << "Invalid letters: " << m_invalidLetters << '\n';
    std::cout << "Misplaced letters: " << m_misplacedLetters << '\n';
    displayGrid();
    setStatus(r);
}

void Wordle::setTry()
{
    m_try += 1;
}

void Wordle::setGrid()
{
    for(int r = 0; r < 6; ++r)
    {
        for(int c = 0; c < 5; ++c)
        {
            m_grid[r][c] = "⬛";
        }
    }
}

void Wordle::setInvalidLetters(std::string invalidLetter)
{
    m_invalidLetters += invalidLetter + ' ';
}

void Wordle::setMisplacedLetters(std::string misplacedLetter)
{
    m_misplacedLetters += misplacedLetter + ' ';
}

void Wordle::setStatus(int r)
{
    for(int c = 0; c < 5; ++c)
    {
        if(m_grid[r][c] != "🟩")
        {
            m_status = 0;
            break;
        }
        else
        {
            m_status = 1;
        }
    }
}

void Wordle::promptUser()
{
    for(int r = 0; r < 6; ++r)
    {
        if(getStatus() == 1)
        {
            break;
        }
        std::cout << "Guess a 5-letter word: ";
        std::string guess{};
        std::cin >> guess;
        while(guess.length() != 5 || isValid(guess) != 1)
        {
            if(guess.length() == 5 && isValid(guess) == 1)
            {
                break;
            }
            std::cout << guess << " is not 5-letters or a valid word\n";
            std::cin >> guess;
        }
        setTry();
        setGuess(guess);
    }
    checkStatus();
}

void Wordle::displayGrid()
{
    for(int r = 0; r < 6; ++r)
    {
        for(int c = 0; c < 5; ++c)
        {
            std::cout << m_grid[r][c];
        }
        std::cout << '\n';
    }
};

bool Wordle::isValid(std::string guess)
{
    std::ifstream inFile;
    std::string word{};
    inFile.open("/Users/matthewlim/Dev/COMSC-165/wordle/combined_wordlist.txt",
                std::ios::in);

    if (inFile.is_open()) {
        getline(inFile, word);
        while (!inFile.eof()) {
            if (word == guess) {
                return true;
            }
            getline(inFile, word);
        }
        return false;
    } else {
        std::cout << "ERROR: could not open file\n";
        m_answer = "ERROR";
    }
    return false;
}

void Wordle::checkStatus()
{
    if(getTries() == 1)
    {
        std::cout << "Genius\n";
        std::cout << "Wordle solved in " << getTries() << " tries\n";
        std::cout << "Answer: " << getAnswer() << '\n';
    }
    else if(getTries() == 2)
    {
        std::cout << "Magnificent\n";
        std::cout << "Wordle solved in " << getTries() << " tries\n";
        std::cout << "Answer: " << getAnswer() << '\n';
    }
    else if(getTries() == 3)
    {
        std::cout << "Impressive\n";
        std::cout << "Wordle solved in " << getTries() << " tries\n";
        std::cout << "Answer: " << getAnswer() << '\n';
    }
    else if(getTries() == 4)
    {
        std::cout << "Splendid\n";
        std::cout << "Wordle solved in " << getTries() << " tries\n";
        std::cout << "Answer: " << getAnswer() << '\n';
    }
    else if(getTries() == 5)
    {
        std::cout << "Great\n";
        std::cout << "Wordle solved in " << getTries() << " tries\n";
        std::cout << "Answer: " << getAnswer() << '\n';
    }
    else if(getTries() == 6 && getStatus() == 1)
    {
        std::cout << "Phew\n";
        std::cout << "Wordle solved in " << getTries() << " tries\n";
        std::cout << "Answer: " << getAnswer() << '\n';
    }
    else if(getTries() == 6 && getStatus() == 0)
    {
        std::cout << "Answer: " << getAnswer() << '\n';
    }
    else
    {
        std::cout << "ERROR";
    }
}

void Wordle::initializeGame()
{
    setAnswer();
    setGrid();
    displayGrid();
    promptUser();
}

int main()
{
    Wordle game;
    game.setAnswer();
//    std::cout << game.getAnswer() << '\n';
    game.setGrid();
    std::cout << "🇼🇴🇷🇩🇱🇪 (Recreated by Matthew Lim)\n";
    game.displayGrid();
    game.promptUser();


    Wordle game2;
    game2.initializeGame();

    return 0;
}