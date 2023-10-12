#include <iostream>
#include <string>

using namespace std;

const int numItems = 6;
const string marketItemNames[numItems] = { "Metal_Ore", "Computronics", "Battle_Weaponry", "Food_Packs", "Minerals", "Gas_Cannisters" };

void printInventory(int shipInventory[numItems]);
void printImportDemandItems(int importDemandItems[numItems]);
void printExportDemandItems(int exportDemandItems[numItems]);
void printSaleItems(int saleItems[numItems]);
void printSellItems(int shipInventory[numItems]);

bool buyItems(int shipInventory[numItems]);
bool sellItems(int shipInventory[numItems]);

int main()
{

	bool isDone = false;
	
	int shipInventory[numItems] = { 0, 0, 0, 1, 0, 0 };

	int importDemandItems[numItems] = { 1, 0, 0, 1, 1, 1 };

	int exportDemandItems[numItems] = { 0, 1, 1, 0, 0, 0 };

	int saleItems[numItems] = { 0, 5, 3, 0, 0, 0 }; //Items we can buy, that are on sale

	cout << "*** Welcome to the Sirroco Station Commodity Exchange! ***\n";

	cout << "*** How can I help you today? ***\n";

	//for (int i = 0; i < 6; i++) {
	//	cout << marketItemNames[i] << endl;
	//}
	//cout << "**********\n\n";

	while (isDone == false) {
		printImportDemandItems(importDemandItems);
		printExportDemandItems(exportDemandItems);
		printSaleItems(saleItems);
		printSellItems(shipInventory);
		printInventory(shipInventory);

		isDone = buyItems(shipInventory) || sellItems(shipInventory);
	}


	system("PAUSE");
	return 0;
}

void printImportDemandItems(int importDemandItems[numItems])
{
	cout << "* Major Import Items on Demand *\n";
	for (int i = 0; i < numItems; i++) {
		if (importDemandItems[i] > 0) {
			cout << importDemandItems[i] << " x " << marketItemNames[i] << endl;
		}
	}
	cout << endl;
}

void printExportDemandItems(int exportDemandItems[numItems])
{
	cout << "* Major Export Items on Demand *\n";
	for (int i = 0; i < numItems; i++) {
		if (exportDemandItems[i] > 0) {
			cout << exportDemandItems[i] << " x " << marketItemNames[i] << endl;
		}
	}
	cout << endl;
}

void printSaleItems(int saleItems[numItems])
{
	cout << "* Local Commodity Exchange - on Sale *\n";
	for (int i = 0; i < numItems; i++) {
		if (saleItems[i] > 0) {
			cout << saleItems[i] << " x " << marketItemNames[i] << endl;
		}
	}
	cout << endl;
}

void printSellItems(int tradeItems[numItems])
{
	cout << "* Local Commodity Exchange - sell your wares *\n";
	for (int i = 0; i < numItems; i++) {
		if (tradeItems[i] > 0) {
			cout << tradeItems[i] << " x " << marketItemNames[i] << endl;
		}
	}
	cout << endl;
}

void printInventory(int shipInventory[numItems])
{
	cout << "Contents of your ship\'s hold is: \n";
	for (int i = 0; i < numItems; i++) {
		if (shipInventory[i] > 0) {
			cout << shipInventory[i] << " x " << marketItemNames[i] << endl;
		}
	}
	cout << endl;
}

bool buyItems(int shipInventory[numItems])
{
	int input;

	cout << "What would you like to buy? Enter -1 to quit. Enter (" << 1 << "-" << numItems << "):";
	cin >> input;

	if (input == -1) {
		return true; //Program ends
	}

	if (input -1 < 0 || input > numItems) {
		cout << "That was a bad input!\n";
		return false; //keep going
	}

	//Add one to the item that we bought
	shipInventory[input - 1]++;
	return false;
}

bool sellItems(int shipInventory[numItems])
{
	int input;

	cout << "What would you like to sell? Enter -1 to quit. Enter (" << 1 << "-" << numItems << "):";
	cin >> input;

	if (input == -1) {
		return true; //Program ends
	}

	if (input -1 < 0 || input > numItems) {
		cout << "That was a bad input!\n";
		return false; //keep going
	}

	//Add one to the item that we bought
	shipInventory[input - 1]++;
	return false;
}