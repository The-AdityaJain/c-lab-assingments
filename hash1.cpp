#include<iostream>
#include<fstream>
using namespace std;

class student {
public:
    int rollno;
    string name;
    int marks;
};

class hashtable {
    int hashTable[10][2];
    int fileloc;
public:
    hashtable() {
        for (int i = 0; i < 10; i++) {
            hashTable[i][0] = -1;
            hashTable[i][1] = -1;
        }
    }
    void create();
    void displayhashtable();
    void display_file();
    void search();
    void create_rep();
};

void hashtable::create_rep() {
    int rec = 0;
    char choice;
    int size;

    fstream fout;
    student s;
    fout.open("student.txt", ios::binary | ios::out);
    
    do {
        cout << "Enter student name, rollno and marks: ";
        cin >> s.name >> s.rollno >> s.marks;
        fout.write((char*)&s, sizeof(s));
        
        int loc = s.rollno % 10;
        
        if (hashTable[loc][0] == -1) {
            hashTable[loc][0] = s.rollno;
            hashTable[loc][1] = rec;
        }
        else {
            
            int newloc = hashTable[loc][0] % 10;
            if (newloc == loc) {
                
                for (int i = (loc + 1) % 10; i != loc; i = (i + 1) % 10) {
                    if (hashTable[i][0] == -1) {
                        hashTable[i][0] = s.rollno;
                        hashTable[i][1] = rec;
                        break;
                    }
                }
            }
            else {
                
                int temprollno = hashTable[loc][0];
                int temploc = hashTable[loc][1];

                hashTable[loc][0] = s.rollno;
                hashTable[loc][1] = rec;

                for (int i = (loc + 1) % 10; i != loc; i = (i + 1) % 10) {
                    if (hashTable[i][0] == -1) {
                        hashTable[i][0] = temprollno;
                        hashTable[i][1] = temploc;
                        break;
                    }
                }
            }
        }
        
        rec++;
        cout << "Do you want to add more records?";
        cin >> choice;
    } while (choice == 'Y');
    
    fout.close();
}

void hashtable::create() {
    int rec = 0;
    char choice;
    int size;
    fstream fout;
    student s;
    fout.open("student.txt", ios::binary | ios::out);
    do {
        cout << "Enter student name, rollno and marks: ";
        cin >> s.name >> s.rollno >> s.marks;
        fout.write((char*)&s, sizeof(s));
        int loc = s.rollno % 10;
        if (hashTable[loc][0] == -1) {
            hashTable[loc][0] = s.rollno;
            hashTable[loc][1] = rec;
        }
        else {
            for (int i = (loc + 1) % 10; i != loc; i = (i + 1) % 10) {
                if (hashTable[i][0] == -1) {
                    hashTable[i][0] = s.rollno;
                    hashTable[i][1] = rec;
                    break;
                }
            }
        }
        rec++;
        cout << "Do you want to add more records?";
        cin >> choice;
    } while (choice == 'Y');
    fout.close();
}

void hashtable::displayhashtable() {
    cout << "Rollno: " << "location" << endl;
    for (int i = 0; i < 10; i++) {
        cout << hashTable[i][0] << " " << hashTable[i][1] << endl;
    }
}

void hashtable::display_file() {
    fstream fin;
    student s;
    fin.open("student.txt", ios::in | ios::binary);
    if (!fin) {
        cout << "Error opening file";
        return;
    }
    while (fin.read((char*)&s, sizeof(s))) {
        cout << s.rollno << " " << s.marks << " " << s.name << endl;
    }
    fin.close();
}

void hashtable::search() {
    student s;
    fstream fin;
    fin.open("student.txt", ios::in | ios::binary);
    cout << "Enter roll number: " << endl;
    int r;
    cin >> r;
    int loc = r % 10;
    if (hashTable[loc][0] == r) {
        int fileloc = hashTable[loc][1] * sizeof(s);
        fin.seekg(fileloc, ios::beg);
        fin.read((char*)&s, sizeof(s));
        cout << s.rollno << " " << s.marks << " " << s.name;
    }
    else {
        bool found = false;
        for (int i = (loc + 1) % 10; i != loc; i = (i + 1) % 10) {
            if (hashTable[i][0] == r) {
                int fileloc = hashTable[i][1] * sizeof(s);
                fin.seekg(fileloc, ios::beg);
                fin.read((char*)&s, sizeof(s));
                cout << s.rollno << " " << s.marks << " " << s.name;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Record not found." << endl;
        }
    }
    fin.close();
}

int main() {
    int ch;
    cin>>ch;
    hashtable h;
    switch(ch){
	    case 1:
	    h.create();
	    break;
	    case 2:
	    h.create_rep();
	    break;
	    default:
	    cout<<"invalid choice";
	    break;
    }
    h.displayhashtable();
    h.display_file();
    h.search();
    return 0;
}

