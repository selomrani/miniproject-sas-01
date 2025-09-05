#include <stdio.h>
#include <stdlib.h>
#define MAX_NOTES 100

void saisirNotes(float notes[], int *n);
void afficherNotes(float notes[], int n);
float calculerMoyenne(float notes[], int n);
float trouverMin(float notes[], int n);
float trouverMax(float notes[], int n);
int compteradmis(float notes[], int n, float seuil);
int ajouterNote(float notes[], int *n, float new_note);
int modifierNote(float notes[], int n, int index, float new_note);
int supprimerNote(float notes[], int *n, int index);

int main(void) {
    int num_notes = 0;
    float notes[MAX_NOTES];
    int choice;
    float average, min, max, new_note;
    int admis_count, index;

    while (1) { 
        printf("\nWelcome to grades manager!\n");
        printf("================================\n");
        printf("1- Enter grades\n");
        printf("2- Display grades\n");
        printf("3- Statistics\n");
        printf("4- Add a grade\n");
        printf("5- Modify a grade\n");
        printf("6- Delete a grade\n");
        printf("7- Exit the program\n");
        printf("================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                saisirNotes(notes, &num_notes);
                break;
                
            case 2:
                afficherNotes(notes, num_notes);
                break;
                
            case 3:
                if (num_notes == 0) {
                    printf("No grades entered yet!\n");
                    break;
                }
                average = calculerMoyenne(notes, num_notes);
                min = trouverMin(notes, num_notes);
                max = trouverMax(notes, num_notes);
                admis_count = compteradmis(notes, num_notes, 10.0);
                
                printf("\n=== Statistics ===\n");
                printf("Average: %.2f\n", average);
                printf("Minimum: %.2f\n", min);
                printf("Maximum: %.2f\n", max);
                printf("Passing grades (>=10): %d\n", admis_count);
                printf("Total grades: %d\n", num_notes);
                break;
                
            case 4:
                if (num_notes >= MAX_NOTES) {
                    printf("Cannot add more grades. Maximum limit reached!\n");
                    break;
                }
                printf("Enter new grade: ");
                scanf("%f", &new_note);
                if (ajouterNote(notes, &num_notes, new_note)) {
                    printf("Grade added successfully!\n");
                }
                break;
                
            case 5:
                if (num_notes == 0) {
                    printf("No grades to modify!\n");
                    break;
                }
                printf("Enter index to modify (1-%d): ", num_notes);
                scanf("%d", &index);
                printf("Enter new grade: ");
                scanf("%f", &new_note);
                if (modifierNote(notes, num_notes, index-1, new_note)) {
                    printf("Grade modified successfully!\n");
                } else {
                    printf("Invalid index!\n");
                }
                break;
                
            case 6:
                if (num_notes == 0) {
                    printf("No grades to delete!\n");
                    break;
                }
                printf("Enter index to delete (1-%d): ", num_notes);
                scanf("%d", &index);
                if (supprimerNote(notes, &num_notes, index-1)) {
                    printf("Grade deleted successfully!\n");
                } else {
                    printf("Invalid index!\n");
                }
                break;
                
            case 7:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}