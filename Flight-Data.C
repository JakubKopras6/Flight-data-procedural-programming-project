#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Passenger structure
struct Passenger {
	char passportNumber[20];
	char firstName[50];
	char lastName[50];
	int yearBorn;
	char emailAddress[100];
	char travelArea[20];
	char travelClass[20];
	char tripsPerYear[50];
	char duration[50];
	struct Passenger *next;
};

// Global pointer to the linked list head
struct Passenger *head = NULL;

// All functions
void loadPassengerDataFromFile();

void addToList(struct Passenger *);

void addPassenger(int);

void displayAllPassengers(struct Passenger *);

void displayPassengersDetails();

void deletePassenger();

double *generateStatistics();

void printStatistics();

void printReportToFile();

void yearBasedList();

void cleanupAndExit();

void clearInput();

void savePassengerDataToFile();

int verifyEmailAddress(const char *);


// Main driver method to start application
int main() {
	//function call to load data from csv file
	loadPassengerDataFromFile();

	int choice = 0;
	while (choice != 9) {
		printf("\nPassenger Database");
		printf("\n------------------\n");
		printf("1. Add Passenger\n");
		printf("2. Display All Passengers To Screen\n");
		printf("3. Display Passenger Details\n");
		printf("4. Update A Passenger Statistics\n");
		printf("5. Delete Passenger\n");
		printf("6. Generate Statistics Based On The Passenger Travel From\n");
		printf("7. Print All Passenger Details Into A Report File\n");
		printf("8. List all the passenger in order of year born\n");
		printf("9. Exit\n\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		clearInput();

		switch (choice) {
			case 1:
				addPassenger(0);
				break;
			case 2:
				displayAllPassengers(head);
				break;
			case 3:
				displayPassengersDetails();
				break;
			case 4:
				addPassenger(1);
				break;
			case 5:
				deletePassenger();
				break;
			case 6:
				printStatistics();
				break;
			case 7:
				printReportToFile();
				break;
			case 8:
				yearBasedList();
				break;
			case 9:
				savePassengerDataToFile();
				cleanupAndExit();
				break;
			default:
				printf("\nInvalid choice. Please select again.\n");
		}
	}

	return 0;
}


void addDetails(struct Passenger *newPassenger) {
	// Populate passenger details
	printf("Enter First Name: ");
	scanf("%s", newPassenger->firstName);
	clearInput();

	printf("Enter Last Name: ");
	scanf("%s", newPassenger->lastName);
	clearInput();

	printf("Enter Year Born: ");
	scanf("%d", &newPassenger->yearBorn);
	clearInput();

	while (1) {
		printf("Enter Email Address (someone@xyz.com): ");
		scanf("%s", newPassenger->emailAddress);
		clearInput();

		int verify = verifyEmailAddress(newPassenger->emailAddress);
		if (verify == 0) {
			printf("\nError: Invalid Email Address. Try Again\n");
		} else {
			break;
		}
	}

	// Travel Area Selection
	int area = 0;
	while (area < 1 || area > 5) {
		printf("Select Travel Area (1-5):\n");
		printf("1. UK\n");
		printf("2. Rest of Europe\n");
		printf("3. Asia\n");
		printf("4. America\n");
		printf("5. Australia\n");
		printf("\nEnter Your Choice: ");
		scanf("%d", &area);
		clearInput();
		switch (area) {
			case 1:
				strcpy(newPassenger->travelArea, "UK");
				break;
			case 2:
				strcpy(newPassenger->travelArea, "Rest of Europe");
				break;
			case 3:
				strcpy(newPassenger->travelArea, "Asia");
				break;
			case 4:
				strcpy(newPassenger->travelArea, "America");
				break;
			case 5:
				strcpy(newPassenger->travelArea, "Australia");
				break;
			default:
				printf("\nInvalid Choice. Try Again\n");
				area = 0;
		}
	}
    // travel class selection
	int class = 0;
while (class < 1 || class > 4) {
    printf("Select Travel Class (1-4):\n");
    printf("1. Economy\n");
    printf("2. Premium Economy\n");
    printf("3. Business Class\n");
    printf("4. First Class\n");
    printf("\nEnter Your Choice: ");

    if (scanf("%d", &class) != 1) {
        printf("\nInvalid input. Please enter a number.\n");
        clearInput();  // Clear the input buffer to avoid an infinite loop
        class = 0;     // Reset class to trigger the loop again
        continue;
    }

    clearInput();

    switch (class) {
        case 1:
            strcpy(newPassenger->travelClass, "Economy");
            break;
        case 2:
            strcpy(newPassenger->travelClass, "Premium Economy");
            break;
        case 3:
            strcpy(newPassenger->travelClass, "Business Class");
            break;
        case 4:
            strcpy(newPassenger->travelClass, "First Class");
            break;
        default:
            printf("\nInvalid Choice. Try Again\n");
            class = 0;
    }
}

	// Trips Selection
	int trip = 0;
	while (trip < 1 || trip > 4) {
		printf("Select Number Of Trips Per Year (1-3):\n");
		printf("1. Less than 3 times per year\n");
		printf("2. Less than 5 times per year\n");
		printf("3. More than 5 times per year\n");
		printf("\nEnter Your Choice: ");
		scanf("%d", &trip);
		clearInput();
		switch (trip) {
			case 1:
				strcpy(newPassenger->tripsPerYear, "Less than 3 times per year");
				break;
			case 2:
				strcpy(newPassenger->tripsPerYear, "Less than 5 times per year");
				break;
			case 3:
				strcpy(newPassenger->tripsPerYear, "More than 5 times per year");
				break;
			default:
				printf("\nInvalid Choice. Try Again\n");
				trip = 0;
		}
	}

	// Duration Selection
	int duration = 0;
	while (duration < 1 || duration > 4) {
		printf("Select Average Duration (1-4):\n");
		printf("1. One Day\n");
		printf("2. Less than 3 days\n");
		printf("3. Less than 7 days\n");
		printf("4. More than 7 days\n");
		printf("\nEnter Your Choice: ");
		scanf("%d", &duration);
		clearInput();
		switch (duration) {
			case 1:
				strcpy(newPassenger->duration, "One day");
				break;
			case 2:
				strcpy(newPassenger->duration, "Less than 3 days");
				break;
			case 3:
				strcpy(newPassenger->duration, "Less than 7 days");
				break;
			case 4:
				strcpy(newPassenger->duration, "More than 7 days");
				break;
			default:
				printf("\nInvalid Choice. Try Again\n");
				duration = 0;
		}
	}
}


// Method to add new node in linked list
void addToList(struct Passenger *newPassenger) {
	if (head == NULL || strcmp(head->passportNumber, newPassenger->passportNumber) >= 0) {
		newPassenger->next = head;
		head = newPassenger;
	} else {
		struct Passenger *currentNode = head;

		while (currentNode->next != NULL &&
			   strcmp(currentNode->next->passportNumber, newPassenger->passportNumber) < 0) {
			currentNode = currentNode->next;
		}
		newPassenger->next = currentNode->next;
		currentNode->next = newPassenger;
	}
}


// Function to add a new passenger to the linked list
void addPassenger(int update) {

	printf("\nAdd New Passenger Details:");
	printf("\n--------------------------\n");

	struct Passenger *newPassenger = (struct Passenger *) malloc(sizeof(struct Passenger));

	printf("Enter Passport Number: ");
	scanf("%s", newPassenger->passportNumber);
	clearInput();

	// Check if passport number already exists
	struct Passenger *current = head;
	while (current != NULL) {
		if (strcmp(current->passportNumber, newPassenger->passportNumber) == 0) {
			printf("Passport Number already exists. Updating passenger stats.\n");

			addDetails(newPassenger);

			free(current->firstName);
			free(current->lastName);
			free(current->emailAddress);
			free(current->travelArea);
			free(current->travelClass);
			free(current->tripsPerYear);
			free(current->duration);

			strcpy(current->firstName, newPassenger->firstName);
			strcpy(current->lastName, newPassenger->lastName);
			current->yearBorn = newPassenger->yearBorn;
			strcpy(current->emailAddress, newPassenger->emailAddress);
			strcpy(current->travelArea, newPassenger->travelArea);
			strcpy(current->travelClass, newPassenger->travelClass);
			strcpy(current->tripsPerYear, newPassenger->tripsPerYear);
			strcpy(current->duration, newPassenger->duration);

			free(newPassenger);
			printf("\nPassenger details updated successfully!\n");
			return;
		}
		current = current->next;
	}

	if (update == 0) {
		// Add Other Details
		addDetails(newPassenger);

		// Insert passenger in sorted order
		addToList(newPassenger);

		printf("\nPassenger added successfully!\n");
	}
	else{
		printf("\nNo Passenger Found!\n");
	}
}


// Function to display all passengers
void displayAllPassengers(struct Passenger *listHead) {
	printf("\nPassenger Details:\n");
	printf("----------------------------------------------------------------------------------------------------");
	printf("----------------------------------------------------------------------------------------------------\n");
	printf("%-20s | %-15s | %-15s | %-10s | %-30s | %-20s | %-15s | %-25s | %-20s\n",
		   "Passport", "First Name", "Last Name", "Year Born", "Email Address",
		   "Travel Area", "Travel Class", "Trips Per Year", "Duration");
	printf("----------------------------------------------------------------------------------------------------");
	printf("----------------------------------------------------------------------------------------------------\n");

	struct Passenger *current = listHead;
	while (current != NULL) {
		printf("%-20s | %-15s | %-15s | %-10d | %-30s | %-20s | %-15s | %-25s | %-20s\n",
			   current->passportNumber, current->firstName, current->lastName,
			   current->yearBorn, current->emailAddress, current->travelArea,
			   current->travelClass, current->tripsPerYear, current->duration);

		current = current->next;
		printf("----------------------------------------------------------------------------------------------------");
		printf("----------------------------------------------------------------------------------------------------\n");

	}
}


// Function to display passenger details based on passport number or name
void displayPassengersDetails() {
	char input[50];
	printf("Enter Passport Number Or First Name: ");
	scanf("%s", input);

	struct Passenger *current = head;
	printf("Passenger Details :\n");
	printf("------------------------------\n");
	int present = 0;
	while (current != NULL) {
		if ((strcmp(current->passportNumber, input) == 0) || (strcmp(current->firstName, input) == 0)) {
			printf("%-15s : %s\n", "Passport Number", current->passportNumber);
			printf("%-15s : %s\n", "First Name", current->firstName);
			printf("%-15s : %s\n", "Last Name", current->lastName);
			printf("%-15s : %d\n", "Year Born", current->yearBorn);
			printf("%-15s : %s\n", "Email Address", current->emailAddress);
			printf("%-15s : %s\n", "Travel Area", current->travelArea);
			printf("%-15s : %s\n", "Travel Class", current->travelClass);
			printf("%-15s : %s\n", "Trips Per Year", current->tripsPerYear);
			printf("%-15s : %s\n", "Duration", current->duration);
			printf("------------------------------\n");
			present = 1;
		}
		current = current->next;
	}

	if (present == 0) {
		printf("No Passenger Found!\n");
	}
}


// Function to delete a passenger by passport number
void deletePassenger() {

	char passportNumber[20];
	printf("Enter Passport Number to delete: ");
	scanf("%s", passportNumber);

	struct Passenger *current = head;
	struct Passenger *prev = NULL;

	while (current != NULL && strcmp(current->passportNumber, passportNumber) != 0) {
		prev = current;
		current = current->next;
	}

	if (current == NULL) {
		printf("Passenger not found.\n");
		return;
	}

	if (prev == NULL) {
		head = current->next;
	} else {
		prev->next = current->next;
	}

	free(current);
	printf("Passenger deleted successfully!\n");
}


//
double *generateStatistics() {

	int total = 0;
	struct Passenger *current = head;

	while (current != NULL) {
		total++;
		current = current->next;
	}

	int uk = 0;
	current = head;
	while (current != NULL) {
		if (strcmp(current->travelArea, "UK") == 0) {
			uk++;
		}
		current = current->next;
	}

	int eu = 0;
	current = head;
	while (current != NULL) {
		if (strcmp(current->travelArea, "Rest of Europe") == 0) {
			eu++;
		}
		current = current->next;
	}

	int asia = 0;
	current = head;
	while (current != NULL) {
		if (strcmp(current->travelArea, "Asia") == 0) {
			asia++;
		}
		current = current->next;
	}

	int america = 0;
	current = head;
	while (current != NULL) {
		if (strcmp(current->travelArea, "America") == 0) {
			america++;
		}
		current = current->next;
	}


	int australia = 0;
	current = head;
	while (current != NULL) {
		if (strcmp(current->travelArea, "Australia") == 0) {
			australia++;
		}
		current = current->next;
	}

	double *percentage = (double *) malloc(5 * sizeof(double));
	if (total != 0) {
		percentage[0] = ((double) uk * 100) / (double) total;
		percentage[1] = ((double) eu * 100) / (double) total;
		percentage[2] = ((double) asia * 100) / (double) total;
		percentage[3] = ((double) america * 100) / (double) total;
		percentage[4] = ((double) australia * 100) / (double) total;
	} else {
		percentage[0] = 0.0;
		percentage[1] = 0.0;
		percentage[2] = 0.0;
		percentage[3] = 0.0;
		percentage[4] = 0.0;
	}

	return percentage;
}


// Printing stats to txt file
void printStatistics() {
	double *percentage = generateStatistics();

	printf("\nStatistics based on the passenger travel class:");
	printf("\n-----------------------------------------------");
	printf("\nA. %6.2f%% of passengers travel from the UK", percentage[0]);
	printf("\nB. %6.2f%% of passengers travel from the Rest of Europe", percentage[1]);
	printf("\nC. %6.2f%% of passengers travel from the Asia", percentage[2]);
	printf("\nD. %6.2f%% of passengers travel from the America", percentage[3]);
	printf("\nE. %6.2f%% of passengers travel from the Australia", percentage[4]);
	printf("\n-----------------------------------------------\n");
}


// Print Report To File
void printReportToFile() {
	FILE *file = fopen("report.txt", "w"); // Open the file for writing

	if (file == NULL) {
		printf("Error opening the file.\n");
		return;
	}

	// Print passenger details to the file
	fprintf(file, "\nPassenger Details:\n");
	fprintf(file,
			"----------------------------------------------------------------------------------------------------");
	fprintf(file,
			"----------------------------------------------------------------------------------------------------\n");
	fprintf(file, "%-20s | %-15s | %-15s | %-10s | %-30s | %-20s | %-15s | %-25s | %-20s\n",
			"Passport", "First Name", "Last Name", "Year Born", "Email Address",
			"Travel Area", "Travel Class", "Trips Per Year", "Duration");
	fprintf(file,
			"----------------------------------------------------------------------------------------------------");
	fprintf(file,
			"----------------------------------------------------------------------------------------------------\n");

	struct Passenger *current = head;
	while (current != NULL) {
		fprintf(file, "%-20s | %-15s | %-15s | %-10d | %-30s | %-20s | %-15s | %-25s | %-20s\n",
				current->passportNumber, current->firstName, current->lastName,
				current->yearBorn, current->emailAddress, current->travelArea,
				current->travelClass, current->tripsPerYear, current->duration);

		current = current->next;
		fprintf(file,
				"----------------------------------------------------------------------------------------------------");
		fprintf(file,
				"----------------------------------------------------------------------------------------------------\n");

	}

	double *percentage = generateStatistics();
	fprintf(file, "\n\n");
	fprintf(file, "\nStatistics based on the passenger travel class:");
	fprintf(file, "\n-----------------------------------------------");
	fprintf(file, "\nA. %6.2f%% of passengers travel from the UK", percentage[0]);
	fprintf(file, "\nB. %6.2f%% of passengers travel from the Rest of Europe", percentage[1]);
	fprintf(file, "\nC. %6.2f%% of passengers travel from the Asia", percentage[2]);
	fprintf(file, "\nD. %6.2f%% of passengers travel from the America", percentage[3]);
	fprintf(file, "\nE. %6.2f%% of passengers travel from the Australia", percentage[4]);
	fprintf(file, "\n-----------------------------------------------\n");

	fclose(file); // Close the file

	printf("\nReport Save Successfully\n");
}


// Function to insert a Passenger into a new sorted list
void insertSorted(struct Passenger **sortedHead, struct Passenger *newPassenger) {
	if (*sortedHead == NULL || newPassenger->yearBorn <= (*sortedHead)->yearBorn) {
		newPassenger->next = *sortedHead;
		*sortedHead = newPassenger;
	} else {
		struct Passenger *current = *sortedHead;
		while (current->next != NULL && newPassenger->yearBorn > current->next->yearBorn) {
			current = current->next;
		}
		newPassenger->next = current->next;
		current->next = newPassenger;
	}
}

// Function to sort the linked list by creating a new sorted list
struct Passenger *sortLinkedListByYearBorn() {
	struct Passenger *sortedHead = NULL;
	struct Passenger *current = head;

	while (current != NULL) {
		struct Passenger *nextPassenger = current->next;
		current->next = NULL; // Remove the current node from the original list
		insertSorted(&sortedHead, current);
		current = nextPassenger;
	}

	return sortedHead;
}


// Year based list
void yearBasedList() {
	struct Passenger *sortedList = sortLinkedListByYearBorn();
	displayAllPassengers(sortedList);
}


// Function to save passenger data to a text file
void savePassengerDataToFile() {
	FILE *file = fopen("passenger_data.csv", "w");
	if (file == NULL) {
		printf("Error opening file for writing.\n");
		return;
	}

	struct Passenger *current = head;
	while (current != NULL) {
		fprintf(file, "%s,%s,%s,%d,%s,%s,%s,%s,%s\n",
				current->passportNumber, current->firstName, current->lastName,
				current->yearBorn, current->emailAddress, current->travelArea,
				current->travelClass, current->tripsPerYear, current->duration);

		current = current->next;
	}

	fclose(file);
	printf("Passenger data saved to file.\n");
}


// Function to load passenger data from a text file
void loadPassengerDataFromFile() {
	FILE *file = fopen("passenger_data.csv", "r");
	if (file == NULL) {
		printf("Error opening file for reading.\n");
		return;
	}

	// Clear the existing linked list
	struct Passenger *current = head;
	while (current != NULL) {
		struct Passenger *temp = current;
		current = current->next;
		free(temp);
	}
	head = NULL;

	char line[500];
	while (fgets(line, sizeof(line), file) != NULL) {
		struct Passenger *newPassenger = (struct Passenger *) malloc(sizeof(struct Passenger));
		sscanf(line, "%19[^,],%49[^,],%49[^,],%d,%99[^,],%19[^,],%19[^,],%49[^,],%49[^,\n]",
			   newPassenger->passportNumber, newPassenger->firstName, newPassenger->lastName,
			   &newPassenger->yearBorn, newPassenger->emailAddress, newPassenger->travelArea,
			   newPassenger->travelClass, newPassenger->tripsPerYear, newPassenger->duration);

		addToList(newPassenger);
	}

	fclose(file);
	printf("Passenger data loaded from file.\n");
}


//
void clearInput() {
	while (getchar() != '\n');
}


// Function to free memory and exit the program
void cleanupAndExit() {
	struct Passenger *current = head;
	while (current != NULL) {
		struct Passenger *temp = current;
		current = current->next;
		free(temp);
	}
	exit(0);
}


int verifyEmailAddress(const char *email) {
	int atPosition = -1; // Position of '@'
	int dotPosition = -1; // Position of the first '.'
	int length = strlen(email);

	// Find the position of '@' and the first '.'
	for (int i = 0; i < length; i++) {
		if (email[i] == '@') {
			atPosition = i;
			break;
		}
	}

	// If '@' is not found or is the first or last character
	if (atPosition <= 0 || atPosition == length - 1) {
		return 0; // Invalid email
	}

	for (int i = atPosition + 1; i < length; i++) {
		if (email[i] == '.') {
			dotPosition = i;
			break;
		}
	}

	// If '.' is not found or is the last character
	if (dotPosition <= atPosition + 1 || dotPosition == length - 1) {
		return 0; // Invalid email
	}

	// Check if the last part of the email is ".com"
	if (strcmp(email + dotPosition, ".com") != 0) {
		return 0; // Invalid email
	}

	return 1; // Valid email
}
