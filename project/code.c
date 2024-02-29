#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Define a structure for a Song
struct Song {
    char title[50];
    char artist[50];
    char genre[20];
};



// Function to recommend a song based on the selected genre
void recommendSong(const char* selectedGenre, const struct Song* songs, int numSongs) {
    // Create an array to store recommended songs
    struct Song recommendedSongs[5];
    int recommendedCount = 0;

    // Loop through the songs to find recommendations
    for (int i = 0; i < numSongs; ++i) {
        // Convert both user input and genre in the songs array to lowercase
        char lowercaseUserGenre[20];
        char lowercaseSongGenre[20];
        strcpy(lowercaseUserGenre, selectedGenre);
        strcpy(lowercaseSongGenre, songs[i].genre);
        for (int j = 0; lowercaseUserGenre[j]; ++j) {
            lowercaseUserGenre[j] = tolower(lowercaseUserGenre[j]);
        }
        for (int j = 0; lowercaseSongGenre[j]; ++j) {
            lowercaseSongGenre[j] = tolower(lowercaseSongGenre[j]);
        }

        if (strcmp(lowercaseSongGenre, lowercaseUserGenre) == 0) {
            recommendedSongs[recommendedCount] = songs[i];
            recommendedCount++;

            // Limit the number of recommendations to 5
            if (recommendedCount == 5) {
                break;
            }
        }
    }

    // Display recommended songs
    printf("Recommended Songs in %s:\n", selectedGenre);
    for (int i = 0; i < recommendedCount; ++i) {
        printf("%d. %s - %s\n", i + 1, recommendedSongs[i].title, recommendedSongs[i].artist);
    }
}

int main() {
    // Seed the random number generator for variety in recommendations
    srand(time(NULL));

    // Define an array of sample songs
    struct Song songs[] = {
        {"Don't Let Me Die", "Rebecca Malope", "Gospel"},
        {"Masimdumise", "Rebecca Malope", "Gospel"},
        {"Baya Vuya", "Rebecca Malope", "Gospel"},
        {"Unamandla", "Rebecca Malope", "Gospel"},
        {"Umoya Wam", "Rebecca Malope", "Gospel"},
        {"Kurhula", "Kelvin Momo", "Amapiano"},
        {"Uthando", "Kelvin Momo", "Amapiano"},
        {"Fool me", "Kelvin Momo", "Amapiano"},
        {"Amanxeba", "Kelvin Momo", "Amapiano"},
        {"Kgomo", "Jonas Gwangwa", "Jazz"},
        {"Morwa", "Jonas Gwangwa", "Jazz"},
        {"Batsumi", "Jonas Gwangwa", "Jazz"},
        {"Diphororo", "Jonas Gwangwa", "Jazz"},
        {"Suited", "Shekhinah", "R&B"},
        {"Questions", "Shekhinah", "R&B"},
        {"Please Mr", "Shekhinah", "R&B"},
        {"Water", "Shekhinah", "R&B"},
    };

    int numSongs = sizeof(songs) / sizeof(songs[0]);

    // Ask the user for the genre they are looking for
    char userGenre[20];
    printf("Enter the genre you are looking for: ");
    scanf("%s", userGenre);

    // Recommend a song based on the selected genre
    recommendSong(userGenre, songs, numSongs);

    return 0;
}
