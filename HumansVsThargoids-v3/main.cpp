// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int getNumHumans();
int getNumThargoids();
void simBattle(int &numHumans, int &NumThargoids);
void printResults(int numHumans, int numThargoids, int startHumans, int startThargoids);

int main()
{

    int startHumans;
    int startThargoids;

    int numHumans;
    int numThargoids;

    cout << "*** Thargoids are swarming our positions, they're going to overun us unless we stand our ground! ***\n";

    numHumans = getNumHumans();

    startHumans = numHumans;

    numThargoids = getNumThargoids();

    startThargoids = numThargoids;

    simBattle(numHumans, numThargoids);

    printResults(numHumans, numThargoids, startHumans, startThargoids);

    system("PAUSE");
    return 0;


}

int getNumHumans() {

    //Get the number of humans
    int numHumans;
    cout << "Enter number of Human combatants: ";
    cin >> numHumans;
    return numHumans;

}

int getNumThargoids() {

    //Get the number of humans
    int numThargoids;
    cout << "Enter number of Thargoid combatants: ";
    cin >> numThargoids;
    return numThargoids;

}

void simBattle(int &numHumans, int &numThargoids) {

    //RNG seeded with time
    static default_random_engine randomEngine(time(NULL));
    uniform_real_distribution<float> attack(0.0f, 1.0f);

    // human combatants

    float humanAttackChance = 0.6f;
    float humanHealth = 250.0f;
    float humanDamage = 200.0f;

    // Thargoid drones

    float thargoidAttackChance = 0.88f;
    float thargoidHealth = 1000.0f;
    float thargoidDamage = 900.0f;

    float currentHumanHealth = humanHealth;

    float currentThargHealth = thargoidHealth;

    char turn = 'H';

    float attackResult;

    //face-off!

    cout << "\n The Thargoids are landing drones! Brace your selves soldiers!\n\n";

    while ((numHumans > 0) && (numThargoids > 0)) {

        //humans turn
        if (turn == 'H') {
            //Get our attack result
            attackResult = attack(randomEngine);

            //Check if attack was successful
            if (attackResult <= humanAttackChance) {
                currentThargHealth -= humanDamage;

                if (currentThargHealth < 0) {
                    numThargoids--;
                    currentThargHealth = thargoidHealth;
                }
            }

            turn = 'T';
        }
        else {

            if (attackResult <= thargoidAttackChance) {
                currentHumanHealth -= thargoidDamage;

                if (currentHumanHealth < 0) {
                    numHumans--;
                    currentHumanHealth = humanHealth;
                }
            }

            turn = 'H';
        }

    }

}

void printResults(int numHumans, int numThargoids, int startHumans, int startThargoids) {

    cout << "\n The Engagement is over!\n\n";

    //Print out the results

    if (numHumans > 0) {
        cout << "Humans won!\n";
        cout << "There are " << numHumans << " human combatants remaining!";
    }
    else {
        cout << "Thargoids won!\n";
        cout << "There are " << numThargoids << " Thargoid drones remaining!";
    }

    //KILL COUNTER

    cout << startHumans - numHumans << " humans and " << startThargoids - numThargoids << " Thargoids were killed. \n\n";

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
