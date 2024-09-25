#include <array>
#include <cassert>
#include <sstream>
#include <string>
#include <stdexcept>
#include <iostream>
#include <optional>
#include <random>

using namespace std;

enum class Choice {
    ROCK,
    PAPER,
    SCISSORS
};
static array CHOICE_STR{ "Rock", "Paper", "Scissors" };

istream& operator>>(istream& is, Choice& choice) {
    string input;
    is >> input;
    for (auto & c: input) c = static_cast<char>(toupper(c));
    if (input == "ROCK") {
        choice = Choice::ROCK;
    } else if (input == "PAPER") {
        choice = Choice::PAPER;
    } else if (input == "SCISSORS") {
        choice = Choice::SCISSORS;
    } else {
        throw runtime_error("Invalid choice: " + input);
    }

    return is;
}

ostream& operator<<(ostream& os, const Choice& result) {
    int result_int = static_cast<int>(result);
    if (result_int < 0 || result_int > 2) {
        throw runtime_error("Invalid choice: " + to_string(result_int));
    }
    os << CHOICE_STR[result_int];
    return os;
}


enum class Result {
    DRAW,
    PLAYER,
    COMPUTER
};

string result_to_string(Result result) {
    array lookup = {"Draw",  "Player", "Computer"};
    int result_int = static_cast<int>(result);
    if (result_int >= 0 && result_int < 3) {
        return lookup[result_int];
    } else {
        throw runtime_error("Invalid choice: " + to_string(static_cast<int>(result)));
    }
}

ostream& operator<<(ostream& os, const Result& result) {
    os << result_to_string(result);
    return os;
}

void show(ostream & os, const string & words) {
    os << words << endl;
}

optional<int> input(istream & is) {
    int result;
    is >> result;

    if (is) {
        return result;
    } else {
        return {};
    }
}

std::optional<int> zero_one_or_two(std::istream& is) {
    int number{};
    is >> number;
    if (is && (0 <= number) && (number <3)) {
        return number;
    }
    is.clear();

    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return {};
}

void tests() {
    istringstream iss("42 13 not_a_number");

    assert(input(iss) == 42);
    assert(input(iss) == 13);
    assert(!input(iss).has_value());

    istringstream nums{"1 4"};
    assert(zero_one_or_two(nums) == 1);
    assert(!zero_one_or_two(nums).has_value());
}

Result who_is_the_winner(Choice your_guess, Choice computer_guess) {
    switch (your_guess) {
        case Choice::ROCK:
            switch (computer_guess) {
                case Choice::ROCK:
                    return Result::DRAW;
                case Choice::PAPER:
                    return Result::COMPUTER;
                case Choice::SCISSORS:
                    return Result::PLAYER;
                default:
                    throw logic_error("Invalid choice");
            }
        case Choice::PAPER:
            switch (computer_guess) {
                case Choice::ROCK:
                    return Result::PLAYER;
                case Choice::PAPER:
                    return Result::DRAW;
                case Choice::SCISSORS:
                    return Result::COMPUTER;
                default:
                    throw logic_error("Invalid choice");
            }
        case Choice::SCISSORS:
            switch (computer_guess) {
                case Choice::ROCK:
                    return Result::COMPUTER;
                case Choice::PAPER:
                    return Result::PLAYER;
                case Choice::SCISSORS:
                    return Result::DRAW;
                default:
                    throw logic_error("Invalid choice");
            }
        default:
            throw logic_error("Invalid choice");
    }
}

int main()
{
    tests();

    std::default_random_engine gen{std::random_device{}()};

    std::uniform_int_distribution dist{0,2};

    while (true) {

        cout << "gimme a guess:" << endl;

        Choice your_guess;
        cin >> your_guess;


        Choice computer_guess = static_cast<Choice>(dist(gen));

        cout << "Player's guess was: " << your_guess << " and Computer's guess was " << computer_guess << endl;
        cout << "Winner was " << who_is_the_winner(your_guess, computer_guess) << endl;
    }

    return 0;
}

