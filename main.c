/* --Checklist--
define a User structure to hold user information and their music preferences.
 create two User instances and populate them with sample data, including their song history, artist history , genre history.
 implement a function to compare the song histories of the two users and identify common songs, artist and genre.
print the common songs and the total number of matches found.

done :
user structure
two user instances
song + artist + genre comparison
printing matches

end
*/

// TODO : Add a innterface through the user can input 2 playlist or 2 user accounts of spotify and then the program will compare the two and give the blend score.

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

    struct User user1 = {"User1"};
    struct User user2 = {"User2"};

    // collecting data for users (for simplicity, using arrays instead of dynamic memory allocation)
            // genres
                    //usr1
    char genre_usr1[][50] = {
        "Rock","Classical","Metal","Pop","Rap"
    };
                    // usr2
    char genre_usr2[][50] = {
        "Pop","K-Pop","Bollywood","Rock","Rap"
    };

    // artists
            // usr 1
    char history_artist_usr1[][100] = { 
        "Liszt","Metallica","AC/DC","The Beatles",
        "Mozart","Beethoven","Bach","Queen",
        "Eminem","Taylor Swift","Rammstein"
    };
                    //usr 2
    char history_artist_usr2[][100] = {
        "Justin Bieber","Blackpink","BTS",       
         "Sabrina Carpenter","AR Rahman",
        "Shreya Ghoshal","Arijit Singh",
        "Neha Kakkar","AC/DC","The Beatles"
    };

    // songs 
    char history_song_usr1[][100] = {
        "Hungarian Rhapsody No. 2","Enter Sandman","Back in Black","Hey Jude",
        "Symphony No. 40","Symphony No. 5","Toccata and Fugue in D minor",
        "Bohemian Rhapsody","Lose Yourself","Blank Space","Du Hast",
        "Nothing Else Matters","Dont Let Me Down","Let It Be","We Will Rock You",
        "Stairway to Heaven","Enter Sandman","Sonne","Engel","Amerika",
        "Somebody To Love","We Are The Champions","Smells Like Teen Spirit",
        "Imagine","Hotel California","Sweet Child O' Mine","Billie Jean",
        "Like A Rolling Stone","I Will Always Love You","Hey Ya!","Beat It"
    };

    char history_song_usr2[][100] = {
        "Beauty And A Beat","Ddu-Du Ddu-Du","Dynamite","Skin",
        "Jiya Jale","Teri Meri Kahani","Channa Mereya","O Saki Saki",
        "Back in Black","Hey Jude","Bohemian Rhapsody","Lose Yourself",
        "Blank Space","Du Hast","Nothing Else Matters","Dont Let Me Down",
        "Let It Be","We Will Rock You","Stairway To Heaven","Enter Sandman",
        "Smells Like Teen Spirit","Imagine","Hotel California",
        "Sweet Child O' Mine","Billie Jean","Like A Rolling Stone",
        "I Will Always Love You","Hey Ya!","Beat It"
    };

    // likes
    int like_usr1[] = {
        1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
    };

    int like_usr2[] = {
        1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
    };

    // sizes
    int size1 = sizeof(history_song_usr1)/sizeof(history_song_usr1[0]);
    int size2 = sizeof(history_song_usr2)/sizeof(history_song_usr2[0]);

    int artist_size1 = sizeof(history_artist_usr1)/sizeof(history_artist_usr1[0]);
    int artist_size2 = sizeof(history_artist_usr2)/sizeof(history_artist_usr2[0]);

    int genre_size1 = sizeof(genre_usr1)/sizeof(genre_usr1[0]);
    int genre_size2 = sizeof(genre_usr2)/sizeof(genre_usr2[0]);

    // ---------------- SONG MATCH ----------------
    printf("Common Songs:\n");

    int song_match = 0;

    for(int i = 0; i < size1; i++) {

        for(int j = 0; j < size2; j++) {

            if(strcmp(history_song_usr1[i], history_song_usr2[j]) == 0
               && like_usr1[i] == 1 && like_usr2[j] == 1) {

                printf("%s\n", history_song_usr1[i]);
                song_match++;
                break;
            }
        }
    }

    // ---------------- ARTIST MATCH ----------------
    printf("\nCommon Artists:\n");

    int artist_match = 0;

    for(int i = 0; i < artist_size1; i++) {

        for(int j = 0; j < artist_size2; j++) {

            if(strcmp(history_artist_usr1[i], history_artist_usr2[j]) == 0) {

                printf("%s\n", history_artist_usr1[i]);
                artist_match++;
                break;
            }
        }
    }

    // ---------------- GENRE MATCH ----------------
    printf("\nCommon Genres:\n");

    int genre_match = 0;

    for(int i = 0; i < genre_size1; i++) {

        for(int j = 0; j < genre_size2; j++) {

            if(strcmp(genre_usr1[i], genre_usr2[j]) == 0) {

                printf("%s\n", genre_usr1[i]);
                genre_match++;
                break;
            }
        }
    }

    // ---------------- FINAL ----------------
    int total = size1 + size2;

    float blend_score = (2.0 * song_match / total) * 100;

    printf("\n----------------------\n");
    printf("Song Matches: %d\n", song_match);
    printf("Artist Matches: %d\n", artist_match);
    printf("Genre Matches: %d\n", genre_match);
    printf("Blend Score: %.2f%%\n", blend_score);

    return 0;
}