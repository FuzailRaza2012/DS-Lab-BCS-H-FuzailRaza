#include <iostream>

using namespace std;

struct Song{
	int playCount;
	string name;
	Song* lower;
	Song* higher;
	
	Song(string l, int pc){
		name = l;
		playCount = pc;
		higher = lower = nullptr;
	}
};

Song* newSong(string l, int pc){
	return new Song(l, pc);
}

Song* insertSong(Song* song, string l, int pc){
	if (song == nullptr){
		return newSong(l, pc);
	}
	else{
		if (song->playCount < pc){
			song->higher = insertSong(song->higher, l, pc);
		}
		else{
			song->lower = insertSong(song->lower, l, pc);
		}
		return song;
	}
}

Song* search(Song* song, int pc){
	if (song->playCount == pc || song == nullptr){
		return song;
	}
	else{
		if (song->playCount > pc){
			return search(song->lower, pc);
		}
		else{
			return search(song->higher, pc);
		}
	}
}

void inorder(Song* song){
	if (song == nullptr){
		return;
	}
	else{
		inorder(song->lower);
		cout << song->name << ". ";
		inorder(song->higher);
		return;
	}
}

void postorder(Song* song){
	if (song == nullptr){
		return;
	}
	else{
		postorder(song->lower);
		postorder(song->higher);
		cout << song->name << ". ";
		return;
	}
}

Song* minValue(Song* song){
	while (song->lower != nullptr){
		song = song->lower;
	}
	return song;
}

Song* deleteSong(Song* song, int pc){
	if (song == nullptr){
		return song;
	}
	
	if (pc < song->playCount){
		song->lower = deleteSong(song->lower, pc);
	}
	else if (pc > song->playCount){
		song->higher = deleteSong(song->higher, pc);
	}
	else{
		if (song->lower == nullptr){
			Song* temp = song->higher;
			delete song;
			return temp;
		}
		else if (song->higher == nullptr){
			Song* temp = song->lower;
			delete song;
			return temp;
		}

		Song* temp = minValue(song->higher);
		song->playCount = temp->playCount;
		song->name = temp->name;
		song->higher = deleteSong(song->higher, temp->playCount);
	}
	return song;
}


int main(){
	Song* playlist = nullptr;
    
    playlist = insertSong(playlist, "4U", 610);
    insertSong(playlist, "Need Me", 1111);
    insertSong(playlist, "FLOWERS", 410);
    insertSong(playlist, "Want it Bad", 420);
    insertSong(playlist, "Salty", 670);
    insertSong(playlist, "COLD GIRLS", 11037);
    
    cout << "Inorder: ";
    inorder(playlist);
    cout << endl;
    
    cout << "Postorder: ";
    postorder(playlist);
    cout << endl;
    
    int key = 11037;
    Song* found = search(playlist, key);
    if (found)
        cout << "Found song with play count " << key << ": " << found->name << endl;
    else
        cout << "Song with play count " << key << " not found." << endl;

    playlist = deleteSong(playlist, 1111);
    cout << "Inorder after deleting: " << endl;
    inorder(playlist);
    cout << endl;
}
