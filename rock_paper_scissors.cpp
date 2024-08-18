// C++ Program to Play Rock-Paper-Scissors by Ahmed Rayhan

#include <cstdlib> 
#include <ctime> 
#include <iostream> 
using namespace std; 

// Function to generate the computer's move
char generateComputerMove() 
{ 
	int randomValue; 
	// Seed the random number generator with the current time
	srand(time(NULL)); 
	randomValue = rand() % 3; 

	// Return a move based on the generated random number
	if (randomValue == 0) { 
		return 'p'; 
	} 
	else if (randomValue == 1) { 
		return 's'; 
	} 
	return 'r'; 
} 

// Function to determine the game outcome
int determineOutcome(char playerMove, char computerMove) 
{ 
	// Check for a tie
	if (playerMove == computerMove) { 
		return 0; 
	} 

	// Check for player win or loss based on game rules
	if ((playerMove == 's' && computerMove == 'p') || 
	    (playerMove == 'p' && computerMove == 'r') || 
	    (playerMove == 'r' && computerMove == 's')) { 
		return 1; 
	} 
	
	// Otherwise, the player loses
	return -1; 
} 

// Main function
int main() 
{ 
	char playerMove; 

	cout << "\n\n\n\t\t\tWelcome to the Rock-Paper-Scissors Game\n"; 

	cout << "\n\t\tEnter 'r' for ROCK, 'p' for PAPER, and 's' for SCISSORS\n\t\t\t\t\t"; 

	// Get input from the player
	while(true) { 
		cin >> playerMove; 
		if (playerMove == 'p' || playerMove == 'r' || playerMove == 's') { 
			break; 
		} 
		else { 
			cout << "\t\t\tInvalid move! Please try again." << endl; 
		} 
	} 
	
	// Generate the computer's move
	char computerMove = generateComputerMove(); 

	// Determine the game result
	int result = determineOutcome(playerMove, computerMove); 

	// Display the game result
	if (result == 0) { 
		cout << "\n\t\t\tIt's a draw!\n"; 
	} 
	else if (result == 1) { 
		cout << "\n\t\t\tCongratulations! You won!\n"; 
	} 
	else { 
		cout << "\n\t\t\tOh no! The computer won.\n"; 
	} 

	// Show the moves made by both player and computer
	cout << "\t\t\tYour move: " << playerMove << endl; 
	cout << "\t\t\tComputer's move: " << computerMove << endl; 

	return 0; 
}
