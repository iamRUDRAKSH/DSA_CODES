/*This code is for e-library
Rudraksh Charhate
FY23I005*/

#include <stdio.h>
#include <string.h>

typedef struct book{
    char title[30];
    char author[30];
    char genre[30];
    char release_date[10];
}book;

int main() {
    int n;
    printf("Enter the number of books you have: ");
    scanf("%d", &n);
    book A[n];

    for (int i = 0; i < n; i++) {
        printf("Enter title, author, genre, release_date (YYYYMMDD) for book %d:\n", i + 1);
        scanf("%s %s %s %s", A[i].title, A[i].author, A[i].genre, A[i].release_date);
    }

    // printing original array of books' details

    printf("Original array of book details is:\n");
    for (int i = 0; i < n; i++) {
        printf("Title :%s||\tAuthor :%s||\tGenre :%s||\tRelease Date :%s\n", A[i].title, A[i].author, A[i].genre, A[i].release_date);
    }

    int choice;
    printf("1 for sorting by title\n");
    printf("2 for sorting by author\n");
    printf("3 for sorting by genre\n");
    printf("4 for sorting by release date\n");
    printf("Enter your choice (1 or 2 or 3 or 4): ");
    scanf("%d", &choice);

    if (choice == 1) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (strcmp(A[j].title, A[j + 1].title) > 0) {
// Swapping
//d[j].title is lexicographically greater than d[j+1].title
//lexicographical comparison means that the strings are compared character by character

                    book temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                }
            }
        }
        printf("The sorted array of book details is:\n");
        for (int i = 0; i < n; i++) {
            printf("Title :%s||\tAuthor :%s||\tGenre :%s||\tRelease Date :%s\n", A[i].title, A[i].author, A[i].genre, A[i].release_date);
        }
    }
    else if (choice == 2) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (strcmp(A[j].author, A[j + 1].author) > 0) {
// Swap if the authors are in the wrong order
                    book temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                }
            }
        }
        printf("The sorted array of books' details is:\n");
        for (int i = 0; i < n; i++) {
            printf("Title :%s||\tAuthor :%s||\tGenre :%s||\tRelease Date :%s\n", A[i].title, A[i].author, A[i].genre, A[i].release_date);
        }
    }
    else if (choice == 3) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (strcmp(A[j].genre, A[j + 1].genre) > 0) {
// Swap if the genres are in the wrong order
                    book temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                }
            }
        }
        printf("The sorted array of books' details is:\n");
        for (int i = 0; i < n; i++) {
            printf("Title :%s||\tAuthor :%s||\tGenre :%s||\tRelease Date :%s\n", A[i].title, A[i].author, A[i].genre, A[i].release_date);
        }
    }
    else if (choice == 4) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (strcmp(A[j].release_date, A[j + 1].release_date) > 0) {
// Swap if the release dates are in the wrong order

                    book temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                }
            }
        }
        printf("The sorted array of books' details is:\n");
        for (int i = 0; i < n; i++) {
            printf("Title :%s||\tAuthor :%s||\tGenre :%s||\tRelease Date :%s\n", A[i].title, A[i].author, A[i].genre, A[i].release_date);
        }
    }

    else {
        printf("Invalid choice\n");
    }

return 0;
}
