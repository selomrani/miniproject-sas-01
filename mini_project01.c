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
        printf("**==============================**\n");
        printf("1- Enter grades\n");
        printf("2- Display grades\n");
        printf("3- Statistics\n");
        printf("4- Add a grade\n");
        printf("5- Modify a grade\n");
        printf("6- Delete a grade\n");
        printf("7- Exit the program\n");
        printf("**==============================**\n");

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
                    printf("cant add more grades. Maximum limit \n");
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

void saisirNotes(float notes[], int *n) {
    printf("How many notes would you like to enter ? (The max is 100 notes) : " );
    scanf("%d", n);
    
    if (*n > MAX_NOTES) {
        printf("the notes number exceeds the maximum wich is 100 notes ");
        *n = MAX_NOTES;
    }
    
    for (int i = 0; i < *n; i++) {
        printf("Enter grade %d: ", i + 1);
        scanf("%f", &notes[i]);
        // condition dial min w max value dial notes //
        while (notes[i] < 0 || notes[i] > 20) {
            printf("Invalid grade !! Please enter a grade between 0 and 20  ");
            scanf("%f", &notes[i]);
        }
    }
}

void afficherNotes(float notes[], int n) {
    if (n == 0) {
        printf("No grades to display please return to the main menu and enter grades first!\n");
        return;
    }
    
    printf("\n**==== Grades List ====**\n");
    for (int i = 0; i < n; i++) {
        printf("Grade %d: %.2f\n", i + 1, notes[i]);
    }
}

float calculerMoyenne(float notes[], int n) {
    if (n == 0) return 0.0;
    
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += notes[i];
    }
    return sum / n;
}
float trouverMin(float notes[], int n) {
    if (n == 0) return 0.0;
    
    float min = notes[0];
    for (int i = 1; i < n; i++) {
        if (notes[i] < min) {
            min = notes[i];
        }
    }
    return min;
}
float trouverMax(float notes[], int n) {
    if (n == 0) return 0.0;
    
    float max = notes[0];
    for (int i = 1; i < n; i++) {
        if (notes[i] > max) {
            max = notes[i];
        }
    }
    return max;
} 
int compteradmis(float notes[], int n, float seuil) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (notes[i] >= seuil) {
            count++;
        }
    }
    return count;
}
int ajouterNote(float notes[], int *n, float new_note) {
    if (*n >= MAX_NOTES) {
        return 0; // array full mat9rch tzid lih chi value //
    }
    if (new_note < 0 || new_note > 20) {
        printf("Invalid grade! Please enter a grade between 0 and 20.\n");
        return 0;
    }
    notes[*n] = new_note;
    (*n)++;
    return 1; 
}
int modifierNote(float notes[], int n, int index, float new_note) {
    if (index < 0 || index >= n) {
        return 0; // index kharj 3la l array //
    }
    if (new_note < 0 || new_note > 20) {
        printf("Invalid grade! Please enter a grade between 0 and 20.\n");
        return 0;
    }
    notes[index] = new_note;
    return 1; 
}
int supprimerNote(float notes[], int *n, int index) {
    if (index < 0 || index >= *n) {
        return 0; // index kharj 3la l array //
    }
    for (int i = index; i < *n - 1; i++) {
        notes[i] = notes[i + 1];
    }
    (*n)--;
    return 1; 
}


