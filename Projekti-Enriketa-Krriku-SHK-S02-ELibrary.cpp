#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef struct book
{
    int id;
    string title;
    string author;
    string description;
    string date;
    int pagecount;
    string isbn;
    string genre;
    int actualpage;
    int rating;
    string review;
    book *next;
    book *prev;
} liste;

liste *db = NULL;
liste *toread = NULL;
liste *reading = NULL;
liste *read = NULL;

int db_counter = 0;
int toread_counter = 0;
int reading_counter = 0;
int read_counter = 0;

void add_to_db();
void add_toshelf(char ans, liste *b);
void afisho_listen(liste * l);
void afisho_librin(liste *b, int c);
void kerko();
void reverse(liste *l);
liste *copy_book(liste *b);
bool remove(liste *book, liste *&l, int &length);
void remove_book(liste *book, liste *&l, int &length);
liste *find_id(int id, liste *l);

int main()
{
    string ans, zgjedhje;
    cout << endl << "E-Library" << endl << endl;
    add_to_db();
    Begin:
        cout << endl << endl << "E-Library";
        cout << endl <<"Shtyp kodin per ekzekutim psh: 2B" << endl;
        cout << endl<< "Afisho         \t\t 1A)Databazen 1B)To read 1C)Reading 1D)Read";
        cout << endl << "Kerko         \t\t 2)Liber me ane te titullit, autor ose ISBN";
        cout << endl << "Rendit        \t\t 3A)To read 3B)Reading 3C)Read";
        cout << endl << "Fshi nga      \t\t 4A)Databaza 4B)To read 4C)Reading 4D)Read";
        cout << endl << "Shto          \t\t 5)Liber te ri";
        cout << endl << "6)Perfundo \n\nZgjedhja: ";
        getline(cin, ans);
        transform(ans.begin(), ans.end(), ans.begin(), ::tolower);

    if (ans.compare("1a") == 0) {
        afisho_listen(db);
    }
    else if (ans.compare("1b") == 0) {
        afisho_listen(toread);
    }
    else if (ans.compare("1c") == 0) {
        afisho_listen(reading);
    }
    else if (ans.compare("1d") == 0) {
        afisho_listen(read);
    }
    else if (ans.compare("2") == 0) {
        kerko();
    }
    else if (ans[0] == '3') {
        do {
            cout << endl << "Afisho A)Me te fundit B)Me te vjetrat ";
            getline(cin, zgjedhje);
        }
        while (zgjedhje[0] != 'a' && zgjedhje[0] != 'A' && zgjedhje[0] != 'b' && zgjedhje[0] != 'B');

        if (ans[1] == 'a') {
            if (zgjedhje[0] == 'a' || zgjedhje[0] == 'A') {
                afisho_listen(toread);
            }
            else {
                reverse(toread);
            }
        }
        else if (ans[1] == 'b') {
            if (zgjedhje[0] == 'a' || zgjedhje[0] == 'A') {
                afisho_listen(reading);
            }
            else {
                reverse(reading);
            }
        }
        else if (ans[1] == 'c'){
            if (zgjedhje[0] == 'a' || zgjedhje[0] == 'A') {
                afisho_listen(read);
            }
            else {
                reverse(read);
            }
        }
    }
    else if (ans[0] == '4') {
        cout << endl << "Fshi me ane te A)Index B)Id te librit ";
        getline(cin, zgjedhje);
        liste *b = NULL;
        int index, id;
        string indexstr, idstr;
        bool found = false;

        if (ans[1] == 'a') {
            liste *l = db;
            if (db == NULL)
            {
                cout << endl
                     << "Nuk ka libra" << endl;
            }
            else
            {
                if (zgjedhje[0] == 'a' || zgjedhje[0] == 'A')
                {
                    do {
                        cout << endl << "Index: ";
                        getline(cin, indexstr);
                        index = stoi(indexstr);
                    } while (index < 1 || index > db_counter);

                    int i = 0;
                    while (l != NULL)
                    {
                        i++;

                        if (i == index)
                        {
                            id = l->id;
                            bool done = remove(l, db, db_counter);
                            if (done)
                            { //nqs nuk kerkoi anullim, remove from shelves too
                                b = find_id(id, toread);
                                if (b != NULL)
                                {
                                    remove_book(b, toread, toread_counter);
                                }

                                b = find_id(id, reading);
                                if (b != NULL)
                                {
                                    remove_book(b, reading, reading_counter);
                                }

                                b = find_id(id, read);
                                if (b != NULL)
                                {
                                    remove_book(b, read, read_counter);
                                }
                            }
                            break;
                        }
                        l = l->next;
                    }
                }
                else  {
                    do {
                        cout << endl << "ID: ";
                        getline(cin, idstr);
                        id = stoi(idstr);
                    }
                    while (id < 100);

                    while (l != NULL) {
                        if (id == l->id) {
                            found = true;
                            bool done = remove(l, db, db_counter);
                            if (done) { //nqs nuk kerkoi anullim, remove from shelves too
                                b = find_id(id, toread);
                                if (b != NULL) {
                                    remove_book(b, toread, toread_counter);
                                }

                                b = find_id(id, reading);
                                if (b != NULL) {
                                    remove_book(b, reading, reading_counter);
                                }

                                b = find_id(id, read);
                                if (b != NULL) {
                                    remove_book(b, read, read_counter);
                                }
                            }
                            break;
                        }

                        l = l->next;
                    }

                    if (!found) {
                        cout << endl << "Libri me ID: " << id << " nuk u gjet";
                    }
                    
                }
            }
        }
        else if (ans[1] == 'b') {
            liste *l = toread;
            if (toread == NULL)
            {
                cout << endl << "Nuk ka libra" << endl;
            }
            else
            {
                if (zgjedhje[0] == 'a' || zgjedhje[0] == 'A')
                {
                    do {
                        cout << endl << "Index: ";
                        getline(cin, indexstr);
                        index = stoi(indexstr);
                    } while (index < 1 || index > toread_counter);

                    int i = 0;
                    while (l != NULL) {
                        i++;
                        if (i == index)
                        {
                            id = l->id;
                            bool done = remove(l, toread, toread_counter);
                            break;
                        }
                        l = l->next;
                    }
                }
                else  {
                    do {
                        cout << endl << "ID: ";
                        getline(cin, idstr);
                        id = stoi(idstr);
                    }
                    while (id < 100);

                    while (l != NULL) {
                        if (id == l->id) {
                            found = true;
                            bool done = remove(l, toread, toread_counter);
                            break;
                        }
                        l = l->next;
                    }

                    if (!found) {
                        cout << endl << "Libri me ID: " << id << " nuk u gjet";
                    }
                    
                }
            }
        }
        else if (ans[1] == 'c'){
            liste *l = reading;
            if (reading == NULL)
            {
                cout << endl << "Nuk ka libra" << endl;
            }
            else
            {
                if (zgjedhje[0] == 'a' || zgjedhje[0] == 'A')
                {
                    do {
                        cout << endl << "Index: ";
                        getline(cin, indexstr);
                        index = stoi(indexstr);
                    } while (index < 1 || index > reading_counter);

                    int i = 0;
                    while (l != NULL) {
                        i++;
                        if (i == index)
                        {
                            id = l->id;
                            bool done = remove(l, reading, reading_counter);
                            break;
                        }
                        l = l->next;
                    }
                }
                else  {
                    do {
                        cout << endl << "ID: ";
                        getline(cin, idstr);
                        id = stoi(idstr);
                    }
                    while (id < 100);

                    while (l != NULL) {
                        if (id == l->id) {
                            found = true;
                            bool done = remove(l, reading, reading_counter);
                            break;
                        }
                        l = l->next;
                    }

                    if (!found) {
                        cout << endl << "Libri me ID: " << id << " nuk u gjet";
                    }
                    
                }
            }
        }
        else if (ans[1] == 'd'){
            liste *l = read;
            if (read == NULL) {
                cout << endl << "Nuk ka libra" << endl;
            }
            else {
                if (zgjedhje[0] == 'a' || zgjedhje[0] == 'A') {
                    do {
                        cout << endl << "Index: ";
                        getline(cin, indexstr);
                        index = stoi(indexstr);
                    } while (index < 1 || index > read_counter);

                    int i = 0;
                    while (l != NULL) {
                        i++;
                        if (i == index)
                        {
                            id = l->id;
                            bool done = remove(l, read, read_counter);
                            break;
                        }
                        l = l->next;
                    }
                }
                else  {
                    do {
                        cout << endl << "ID: ";
                        getline(cin, idstr);
                        id = stoi(idstr);
                    }
                    while (id < 100);

                    while (l != NULL) {
                        if (id == l->id) {
                            found = true;
                            bool done = remove(l, read, read_counter);
                            break;
                        }
                        l = l->next;
                    }

                    if (!found) {
                        cout << endl << "Libri me ID: " << id << " nuk u gjet";
                    }
                    
                }
            }
        }
    }
    else if (ans[0] == '5') {
        add_to_db();
    }

    if (ans.compare("6") != 0) {
        goto Begin;
    }
}

void add_to_db(){
    liste *b;
    string ans;
    char anschar;

    do {
        b = new liste;
        db_counter++;
        b->id = db_counter + 100;
        cout << "Shto nje liber ne databaze.\nTitulli: ";
        getline(cin, b->title);
        cout << "Author: ";
        getline(cin, b->author);
        cout << "Pershkrimi: ";
        getline(cin, b->description);
        cout << "Data e publikimit: ";
        getline(cin, b->date);

        int pc = -1;
        string pcstr;
        while (pc < 1)
        {
            cout << "Nr i faqeve: ";
            getline(cin, pcstr);
            pc = stoi(pcstr);
        }
        b->pagecount = pc;

        cout << "ISBN: ";
        getline(cin, b->isbn);
        cout << "Zhaner: ";
        getline(cin, b->genre);

        if (db == NULL)
        {
            b->next = NULL;
            b->prev = NULL;
            db = b;
        }
        else
        {
            liste *s = db;

            while (s->next != NULL)
            {
                s = s->next;
            }

            b->next = NULL;
            b->prev = s;
            s->next = b;
        }

        cout << "Ne cilin raft deshironi ta shtoni: A)To read B)Reading C)Read D)Asnje\n";
        getline(cin, ans);
        anschar = ans[0];

        if ((anschar >= 'A' && anschar <= 'C') || (anschar >= 'a' && anschar <= 'c'))
        {
            add_toshelf(anschar, b);
        }
        else
        {
            b->rating = 0;
            b->review = "";
            b->actualpage = 0;
        }

        cout << endl << "Do shtoni me? P / J  ";
        getline(cin, ans);
        anschar = ans[0];
    } while ((anschar == 'P') || (anschar == 'p'));
}

liste *copy_book(liste *b) {
    liste *b1 = new liste;
    b1->id = b->id;
    b1->title = b->title;
    b1->author = b->author;
    b1->description = b->description;
    b1->date = b->date;
    b1->pagecount = b->pagecount;
    b1->isbn = b->isbn;
    b1->genre = b->genre;
    b1->actualpage = b->actualpage;
    b1->rating = b->rating;
    b1->review = b->review;
    return b1;
}

void add_toshelf(char ans, liste *b)
{
    b->actualpage= 0;
    if (ans == 'c' || ans == 'C') { //read
        read_counter++;
        int r = -1;
        string rr;
        while (r < 1 || r > 5) {
            cout << "Rating: ";
            getline(cin, rr);
            r = stoi(rr);
        }
        b->rating = r;

        cout << "Review: ";
        getline(cin, b->review);
        liste *b1 = copy_book(b); //create copy for shelves

        if (read == NULL)
        {
            b1->next = NULL;
            b1->prev = NULL;
            read = b1;
        }
        else
        {
            b1->next = read;
            b1->prev = NULL;
            if (read != NULL) {
                read->prev = b1;
            }
            read = b1;
        }
    }
    else {
        b->rating = 0;
        b->review = "";
        if (ans == 'a' || ans == 'A') {
            toread_counter++;
            b->actualpage = 0;
            liste *b1 = copy_book(b);
            if (toread == NULL) {
                b1->next = NULL;
                b1->prev = NULL;
                toread = b1;
            }
            else {
                b1->next = toread;
                b1->prev = NULL;
                
                if (toread != NULL) {
                    toread->prev = b1;
                }
                toread = b1;
            }
        }
        else {
            reading_counter++;
            int ap = -1;
            string apstr;
            while (ap < 1 || ap > b->pagecount) {
                cout << "Nr i faqes ku po lexoni: ";
                getline(cin, apstr);
                ap = stoi(apstr);
            }
            b->actualpage = ap;
            liste *b1 = copy_book(b);

            if (reading == NULL) {
                b1->next = NULL;
                b1->prev = NULL;
                reading = b1;
            }
            else {
                b1->next = reading;
                b1->prev = NULL;
                
                if (reading != NULL) {
                    reading->prev = b1;
                }
                reading = b1;
            }
        }
    }
}

void afisho_listen(liste * l) { //afisho counterin
    liste *t = l;
    int c = 0;

    if (t == NULL) {
        cout << "Nuk ndodhen libra.";
    }
    else {
        if (l == db) {
            if (db_counter == 1) {
                cout << endl << "Ndodhet vetem 1 liber ne databaze." << endl;
            }
            else {
                cout << endl << "Ndodhen " << db_counter << " libra ne databaze." << endl;
            }
        }
        else if (l == toread) {
            if (toread_counter == 1) {
                cout << endl << "Ndodhet vetem 1 liber ne raftin 'To read'." << endl;
            }
            else {
                cout << endl << "Ndodhen " << toread_counter << " libra ne raftin 'To read'." << endl;
            }
        }
        else if (l == read) {
            if (read_counter == 1) {
                cout << endl << "Ndodhet vetem 1 liber ne raftin 'Read'." << endl;
            }
            else {
                cout << endl << "Ndodhen " << read_counter << " libra ne raftin 'Read'." << endl;
            }
        }
        else {
            if (reading_counter == 1) {
                cout << endl << "Ndodhet vetem 1 liber ne raftin 'Reading'." << endl;
            }
            else {
                cout << endl << "Ndodhen " << reading_counter << " libra ne raftin 'Reading'." << endl;
            }
        }

        while (t != NULL) {
            c++;
            afisho_librin(t, c);
            t = t->next;
        }
    }
}

void afisho_librin(liste *b, int c) {
    if (c != -1) { //nrast se po afishohet per fshirje
        cout << endl << c << ". Titulli: " << b->title;
    }
    else {
        cout << endl << "   Titulli: " << b->title;
    }

    cout << endl  << "   Autori: " << b->author;
    cout << endl  << "   Pershkrimi: " << b->description;
    cout << endl  << "   Data: " << b->date;
    cout << endl  << "   Nr i faqeve: " << b->pagecount;
    cout << endl  << "   Zhaner: " << b->genre;

    if (b->actualpage != 0) {
        cout << endl  << "   Faqja ku po lexon: " << b->actualpage;
    }

    if (b->rating == 0) {
        cout << endl  << "   Rating: Nuk ka";
    }
    else {
        cout << endl  << "   Rating: " << b->rating;
    }

    if ((b->review).compare("") == 0) {
        cout << endl  << "   Review: Nuk ka";
    }
    else {
        cout << endl  << "   Review: " << b->review;
    }

    cout << endl  << "   ISBN: " << b->isbn;
    cout << endl  << "   ID: " << b->id <<endl;
}

void kerko() {
    string key, title, author;
    bool found = false;
    int c = 0;
    cout << endl << "Fjala kyqe: ";
    getline(cin, key);
    transform(key.begin(), key.end(), key.begin(), ::tolower);

    liste *t = db;

    if (t == NULL) {
        cout << endl << "Nuk ka libra.";
    }
    else {
        while (t != NULL) {
            title = t->title;
            transform(title.begin(), title.end(), title.begin(), ::tolower);
            author = t->author;
            transform(author.begin(), author.end(), author.begin(), ::tolower);

            if (title.find(key) != string::npos || author.find(key) != string::npos || (t->isbn).find(key) != string::npos) {
                c++;
                afisho_librin(t, c);
                found = true;
            }
            t = t->next;
        }

        if (!found) {
            cout << endl << "Asgje nuk u gjet.";
        }
    }
}

void reverse(liste *l) {
    int c = 0;
    liste *s = l;

    if (s == NULL) {
        cout << "Nuk ka libra.";
    }
    else {
        while (s->next != NULL) {
            s = s->next;
        }

        while (s != NULL) {
            c++;
            afisho_librin(s, c);
            s = s->prev; 
        }
    }   
}

bool remove(liste *book, liste *&l, int &length) {
    string ans;
    afisho_librin(book, -1);
    cout  << "Do qe ta fshish kete liber? P / J ";
    getline(cin, ans);

    if (ans[0] == 'p' || ans[0] == 'P'){
        if (book != NULL)
        {
            remove_book(book, l, length);
            cout << endl << "Fshirja u krye me sukses";
        }
        else {
            cout << endl << "Libri nuk ekziston" << endl;
        }
    }
    else {
        cout << endl << "Fshirja u anullua" << endl;
        return false;
    }

    return true;
}

void remove_book(liste *book, liste *&l, int &length)
{
    if (book == l && l->next == NULL) {
        l = NULL;
    }
    else if (book == l && l->next != NULL) {
        l = l->next;
        l->prev = NULL;
    }
    else if (book != l && book->next == NULL) {
        book->prev->next = NULL;
    }
    else {
        book->prev->next = book->next;
        book->next->prev = book->prev;
    }

    delete book;
    length--;
}

liste *find_id(int id, liste *l) {
    liste *s = l;

    if (s == NULL) {
        return NULL;
    }
    else {
        while (s != NULL) {
            if (id == s->id) {
                return s;
            }
            s = s->next; 
        }
    }

    return NULL;   

}