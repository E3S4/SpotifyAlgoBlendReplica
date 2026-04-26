/* --Checklist--
define a User structure to hold user information and their music preferences.
 create two User instances and populate them with sample data, including their song history, artist history , genre history.
 implement a function to compare the song histories of the two users and identify common songs, artist and genre.
print the common songs and the total number of matches found.
done till now :
user structure
two user instances with sample data like song and artist
function to compare in progress, currently comparing only songs, will add artist and genre later
printing common songs and total matches found not done yet, will do after adding artist and genre comparison
end



*/
#include <stdio.h>
#include <string.h>

// struct for all users 
struct User { 
    char name[80]; 
    char genre[5][50]; 
    char artist[5][50]; 
    char song[5][50]; 
    int count ,like, repeat, skip, dislike, share;
};

int main() {
    // define a User structure
    struct User user1 = {"User1"};
    struct User user2 = {"User2"};

    // define most played genres for usr1
    char genre_usr1[][50] = {
        "Rock",
        "Classical",
        "Metal",
        "Pop",
        "Rap"
    };

    // define most played genres for usr2
    char genre_usr2[][50] = {
        "Pop",
        "K-Pop",
        "Bollywood",
        "Rock",
        "Rap"
    };


        // define song history for usr1
  char history_artist_usr1[][100] = { 
    "Liszt",
     "Metallica", 
     "AC/DC", 
     "The Beatles",
      "Mozart", 
      "Beethoven", 
      "Bach", 
      "Queen",
       "Eminem",
        "Taylor Swift", 
        "Rammstein" 
};
 
        // define song history for usr2
char history_artist_usr2[][100] = {
     "Justin Bieber", 
     "Blackpink", 
     "BTS",
      "Sabrina Carpenter", 
      "AR Rahman", 
      "Shreya Ghoshal", 
      "Arijit Singh", 
      "Neha Kakkar",
       "AC/DC",
        "The Beatles" 
};

        //define song history for usr1
    char history_song_usr1[][100] = {
        "Hungarian Rhapsody No. 2",
        "Enter Sandman",
        "Back in Black",
        "Hey Jude",
        "Symphony No. 40",
        "Symphony No. 5",
        "Toccata and Fugue in D minor",
        "Bohemian Rhapsody",
        "Lose Yourself",
        "Blank Space",
        "Du Hast",
        "Nothing Else Matters",
        "Dont Let Me Down",
        "Let It Be",
        "We Will Rock You",
        "Stairway to Heaven",
        "Enter Sandman",
        "Sonne",
        "Engel",
        "Amerika",
        "Somebody To Love",
        "We Are The Champions",
        "Smells Like Teen Spirit",
        "Imagine",
        "Hotel California",
        "Sweet Child O' Mine",
        "Billie Jean",
        "Like A Rolling Stone",
        "I Will Always Love You",
        "Hey Ya!",
        "Beat It"
    };

        //define song history for usr2
    char history_song_usr2[][100] = {
        "Beauty And A Beat",
        "Ddu-Du Ddu-Du",
        "Dynamite",
        "Skin",
        "Jiya Jale",
        "Teri Meri Kahani",
        "Channa Mereya",
        "O Saki Saki",
        "Back in Black",
        "Hey Jude",
        "Bohemian Rhapsody",
        "Lose Yourself",
        "Blank Space",
        "Du Hast",
        "Nothing Else Matters",
        "Dont Let Me Down",
        "Let It Be",
        "We Will Rock You",
        "Stairway To Heaven",
        "Enter Sandman",
        "Smells Like Teen Spirit",
        "Imagine",
        "Hotel California",
        "Sweet Child O' Mine",
        "Billie Jean",
        "Like A Rolling Stone",
        "I Will Always Love You",
        "Hey Ya!",
        "Beat It"
    };
    // replays by usr1 on some specific songs
    int replay_usr1[] = {5, 3, 4, 2, 6, 7, 8, 10, 12, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 105, 110, 115};  

// likes by usr1 on some specific songs
    int like_usr1[] = {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};

//skips by usr1 on some specific songs
    int skip_usr1[] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
    
    //replays by usr2 on some specific songs
    int replay_usr2[] = {4, 2, 3, 1,        5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28}; 

//likes by usr2 on some specific songs
    int like_usr2[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    //skips by usr2 on some specific songs
    int skip_usr2[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};



// checking for common songs
    int size1 = sizeof(history_song_usr1) / sizeof(history_song_usr1[0]);
    int size2 = sizeof(history_song_usr2) / sizeof(history_song_usr2[0]);

    //checking for common genres
    int genre_size1 = sizeof(genre_usr1) / sizeof(genre_usr1[0]);
    int genre_size2 = sizeof(genre_usr2) / sizeof(genre_usr2[0]);
    
//checking for common artists
    int artist_size1 = sizeof(history_artist_usr1) / sizeof(history_artist_usr1[0]);
    int artist_size2 = sizeof(history_artist_usr2) / sizeof(history_artist_usr2[0]);

    //checking for common interactions like, replay and skip
    int interaction_size1 = sizeof(like_usr1) / sizeof(like_usr1[0]);
    int interaction_size2 = sizeof(like_usr2) / sizeof(like_usr2[0]); 
    
    //comparing songs
    printf("Common Songs:\n");
    int common_song_count = 0;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (strcmp(history_song_usr1[i], history_song_usr2[j]) == 0
                && like_usr1[i] == 1 && like_usr2[j] == 1) { // checking if both users liked the song
                printf("%s\n", history_song_usr1[i]);
                common_song_count++;
            }
    

    return 0;
}
