#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

string* book_title = nullptr, *book_author = nullptr;
int* ids = nullptr;
int choice, id_removeit ;

int id,searching_id, borrow_id, return_id;

const int max_books = 100000;
int book_count = 0;

string* book_tit2 = nullptr, * book_auth2 = nullptr;
int ID2[max_books];


void initialize_id_array() {
	if (ids != nullptr) delete[] ids;

	ids = new int[max_books];

	for (int i = 0; i < max_books; i++) {

		ids[i] = (i+1) ;
	}

}


void initialize_book_title_array() {
	if (book_title != nullptr) delete[] book_title;

	book_title = new string[max_books];
}


void initialize_book_author_array() {
	if (book_author != nullptr)delete[] book_author;

	book_author = new string[max_books];
}


void initialize_all_arrays() {

	initialize_id_array();
	initialize_book_title_array();
	initialize_book_author_array();

}

void clear_heap() {

	if (ids != nullptr) delete[] ids; ids = nullptr;

	if (book_title != nullptr) delete[] book_title; book_title = nullptr;

	if (book_author != nullptr) delete[] book_author; book_author = nullptr;
}

void add_new_book() {

	if (book_count >= max_books) {
		return;
	}

	cin.ignore();


	string input_title, input_author;


	cout << "Please enter the title of the book: ";

	getline(cin, input_title);

	cout << endl;

	cout << "Please enter the author of the book: ";
	getline(cin, input_author);

	cout << endl;

	int back_or_not;
	
	if (input_title.empty() || input_author.empty()) {

		cout << "Please enter 1 to fill in all data first.\n OR Press on any number to back to list.\n";
		cin >> back_or_not;

		if (back_or_not == 1) {
			system("pause");
			system("cls");
			add_new_book();
		}
		else {
			system("cls");
			return;
		}

	}
	else {
		book_title[book_count] = input_title;
		book_author[book_count] = input_author;
		book_count++;


		cout << "\nYou added this book successfully\n\n";
		system("pause");
		system("cls");
		Sleep(1000);

	}



}





bool* hide = new bool[book_count] { false };
bool* borrowing = new bool[book_count] {false};






int remove_books( int id_removeit) {


	int index_removeit=-1;

	bool isnotfound = true;

	for (int i = 0; i < book_count; i++) {
		if (ids[i] == id_removeit) {
			index_removeit = id_removeit;
			hide[i] = true;
			isnotfound = false;
			break;
		}

	}

	if (isnotfound)  return -1;
	return index_removeit;
	

	system("pause");
	system("cls");
	Sleep(1000);



}
void found_to_remove(int id_removeit) {

	if (book_count == 0)cout << "\nThe libarary is empty. \n";
    
	else {


		cout << "Please enter the ID of the book you want to remove: ";
		cin >> id_removeit;


		int indexfo_remove = remove_books(id_removeit);

		if (indexfo_remove == -1) {
			cout << "\nInvalid ID\n";
		}
		else {
			cout << "This book is deleted successfully.\n";
		}
	}
	system("pause");
	system("cls");
	Sleep(1000);

}

void borrow_book( int borrow_id) {

	if (book_count == 0)cout << "\nThe libarary is empty. \n";

	else {

		cout << "Please enter the ID of the book you want to borrow: ";
		cin >> borrow_id;


		bool not_found_book = true;
		for (int i = 0; i < book_count; i++) {
			if (ids[i] == borrow_id) {

				not_found_book = false;

				borrowing[i] = true;
				break;
			}

		}

		if (not_found_book) cout << "This book not found. \n";
		else cout << "You borrowing this book successfuly. \n";
	}
	system("pause");
	system("cls");
	Sleep(1000);
}

void return_book(int return_id) {

	if (book_count == 0)cout << "\nThe libarary is empty. \n";

	else {

		cout << "Please enter the ID of the book you want to return: ";
		cin >> return_id;


		bool not_found_book_return = true;

		for (int i = 0; i < book_count; i++) {
			if (ids[i] == return_id) {

				not_found_book_return = false;
				if (borrowing[i] == true) {

					borrowing[i] = false;
					cout << "You returned this book successfuly. \n";
					break;
				}
				else {

					cout << "This book is already exist. \n";
					break;
				}

			}

		}

		if (not_found_book_return) cout << "This book not found. \n";
	}
	system("pause");
	system("cls");
	Sleep(1000);
  
}

void list_of_books() {

	if (book_count >= max_books) {
		return;
	}

	if (book_count == 0)cout << "\nThe libarary is empty. \n";
	else {

		for (int i = 0; i < book_count; i++) {
			if (hide[i] == true) {

				continue;
			}

			if (borrowing[i] == true) {

				cout << "ID: " << ids[i] << endl
					<< "Book title: " << book_title[i] << endl
					<< "Book author: " << book_author[i] << endl
					<< "Status: Not avalabil. \n"
					<< "================================" << endl;
			}
			else {

				cout << "ID: " << ids[i] << endl
					<< "Book title: " << book_title[i] << endl
					<< "Book author: " << book_author[i] << endl
					<< "Status: Avalabil. \n"
					<< "================================" << endl;
			}
		}

	}

	
	system("pause");
	system("cls");
	Sleep(1000);
	
}


void list_by_alpha_of_title() {

	if (book_count == 0)cout << "\nThe libarary is empty. \n";
	else {

		cout << "Here all books are displayed even deleted books:\n\n";

		book_tit2 = new string[max_books];
		book_auth2 = new string[max_books];

		for (int i = 0; i < max_books; i++) {

			book_tit2[i] = book_title[i];
			book_auth2[i] = book_author[i];
			ID2[i] = ids[i];
		}


		for (int i = 0; i < book_count; i++) {

				for (int j = i + 1; j < book_count; j++) {

					if (book_tit2[i] > book_tit2[j]) {

						string temp_title = book_tit2[i];
						book_tit2[i] = book_tit2[j];
						book_tit2[j] = temp_title;


						string temp_book_athour = book_auth2[i];
						book_auth2[i] = book_auth2[j];
						book_auth2[j] = temp_book_athour;

						int temp_id = ID2[i];
						ID2[i] = ID2[j];
						ID2[j] = temp_id;
						
					}
				}

			
		}

		for (int i = 0; i < book_count; i++) {

			

			if (borrowing[i] == true) {

				cout << "ID: " << ID2[i] << endl
					<< "Book title: " << book_tit2[i] << endl
					<< "Book author: " << book_auth2[i] << endl
					<< "================================" << endl;
			}
			else {

				cout << "ID: " << ID2[i] << endl
					<< "Book title: " << book_tit2[i] << endl
					<< "Book author: " << book_auth2[i] << endl
					<< "================================" << endl;
			}
		}
	}

	system("pause");
	system("cls");
	Sleep(1000);

	delete[] book_tit2 , book_auth2;
	book_tit2, book_auth2 = nullptr;
}

void updating_books(int id) {
	int index_book=-1;
	

	if (book_count == 0)cout << "\nThe libarary is empty. \n";
	else {

		cout << "Please enter the ID of the book you want to update: ";
		cin >> id;

		for (int i = 0; i < book_count; i++) {
			if (ids[i] == id) {
				index_book = i;
				break;
			}

		}
		cin.ignore();
		if (index_book != -1) {
			cout << "Please enter the title of the book: \n";

			getline(cin, book_title[index_book]);

			cout << "Please enter the author of the book: \n";
			getline(cin, book_author[index_book]);

			cout << "This book is updated successfully.\n";
		}
		else {
			cout << "\nInvalid ID.\n\n";
		}
	}

		system("pause");
		system("cls");
		Sleep(1000);
		
		
		
	
	
	
}

void search_book(int searching_id) {

	
	if (book_count == 0)cout << "\nThe libarary is empty. \n";
	else {

		cout << "Please enter the ID of the book you want to search for: ";
		cin >> searching_id;

		if (searching_id > book_count || searching_id <= 0) {
			cout << "\nInvalid ID\n";
		}
		else {
			for (int i = 0; i < book_count; i++) {

				if (ids[i] == searching_id ) {


					if (hide[i] == true) {

						continue;
					}

					if (borrowing[i] == true) {

						cout << "ID: " << ids[i]<< endl
							<< "Book title: " << book_title[i] << endl
							<< "Book author: " << book_author[i] << endl
							<< "Status: Not avalabil. \n"
							<< "================================" << endl;
					}
					else {

						cout << "ID: " << ids[i]<< endl
							<< "Book title: " << book_title[i] << endl
							<< "Book author: " << book_author[i] << endl
							<< "Status: Avalabil. \n"
							<< "================================" << endl;
					}
				}


			}

			for (int i = 0; i < book_count; i++) {


				if (ID2[i] == searching_id) {

					if (hide[i] == true) {

						continue;
					}

					if (borrowing[i] == true) {

						cout << "ID: " << ID2[i] << endl
							<< "Book title: " << book_tit2[i] << endl
							<< "Book author: " << book_auth2[i] << endl
							<< "Status: Not avalabil. \n"
							<< "================================" << endl;
					}
					else {

						cout << "ID: " << ID2[i] << endl
							<< "Book title: " << book_tit2[i] << endl
							<< "Book author: " << book_auth2[i] << endl
							<< "Status: Avalabil. \n"
							<< "================================" << endl;
					}
				}
			}

			
		}
	}
	system("pause");
	system("cls");
	Sleep(1000);
}


void search_by_first_litter() {

	char first_litter;
	bool is_notfound_first = true;

	if (book_count == 0)cout << "\nThe libarary is empty. \n";

	else {

		cout << "Please enter the first litter of the title of the books you want to search for: ";
		cin >> first_litter;

		for (int i = 0; i < book_count; i++) {

			if (hide[i] == true) {

				continue;
			}
			else {
				if (book_title[i][0] == first_litter) {

					is_notfound_first = false;

					cout << "ID: " << ids[i] << endl
						<< "Book title: " << book_title[i] << endl
						<< "Book author: " << book_author[i] << endl
						<< "Status: Avalabil. \n"
						<< "================================" << endl;
				}

			}
		}
	}

	if (is_notfound_first) cout << "Not found this book.\n";

	system("pause");
	system("cls");
	Sleep(1000);

}



int get_index_by_id( int id, int size) {
	
	for (int i = 0; i < size; i++) {

		if (ids[i] == id) {

			return i; 
		}
	}

	return -1;
}

void display_info( int id, int size) {
	
	int index = get_index_by_id(id, size);

	if (index == -1) {

		cout << "\n this book does not exist \n";

		return;
	}

	cout << "ID: " << ids[index] << endl
		<< "The title of this book is: " << book_title[index] << endl
		<< "The author of this book is: " << book_author[index] << endl;
}

void welcome() {

	cout << "\n\n\n\n\n\n\n\n";




	cout <<
		"                               #####    #        ######    #   #\n"
		"                               #   #    #        #          # # \n"
		"                               #   #    #        #           #  \n"
		"                               #####    #        #####       #  \n"
		"                               #   #    #        #          # # \n"
		"                               #   #    #        #         #   #\n"
		"                               #   #    #####    ######    #   #\n\n";


	cout <<
		"                               #        #####   #####    #####   #####    #####    #   #\n"
		"                               #          #     #    #   #   #   #   #    #   #     # # \n"
		"                               #          #     #     #  #####   #####    #####      #  \n"
		"                               #          #     ######   # #     #   #    # #        #  \n"
		"                               #          #     #     #  #  #    #   #    #   #      #  \n"
		"                               #          #     #    #   #   #   #   #    #     #    #  \n"
		"                               ######   #####   #####    #    #  #   #    #      #   #  \n";



	Sleep(3000);
	system("cls");
}

void display_all_menu() {

	while (true) {

	there:

		cout << "What do you need: \n\n";
		cout << "1- List all books.\n\n";
		cout << "2- list of all books by alphabet of the titles of the books.\n\n";
		cout << "3- Add new book.\n\n";
		cout << "4- Update an existing book.\n\n";
		cout << "5- Remove a book.\n\n";
		cout << "6- Borrow a book.\n\n";
		cout << "7- Return a book.\n\n";
		cout << "8- search for a book.\n\n";
		cout << "9- search for all books by the first litter of the title of these books.\n\n";
		cout << "10- Exit.\n\n";


		cout << "Choose only a number please: ";

		cin >> choice;


		if (choice < 1 || choice > 10) {
			cout << "\nWrong choice.\n\n";

			system("pause");
			system("cls");
			goto there;

		}
		else {
			switch (choice) {
			case 1:
				system("cls");
				list_of_books();
				break;
			case 2:
				system("cls");
				list_by_alpha_of_title();
				break;
			case 3:
				system("cls");
				add_new_book();
				break;
			case 4:
				system("cls");

				updating_books(id);
				break;
			case 5:
				system("cls");

				found_to_remove(id_removeit);
				break;
			case 6:
				system("cls");

				borrow_book(borrow_id);
				break;
			case 7:
				system("cls");

				return_book(return_id);
				break;
			case 8:
				system("cls");

				search_book(searching_id);
				break;
			case 9:
				system("cls");
				search_by_first_litter();
				break;
			case 10:
				system("cls");
				cout << "Thank you for using Alex libarary.\n";
				return ;
			}
		}



	}
}


int main() {

	cout << "\a";

	system("color 71");

	welcome();
	

	initialize_all_arrays();
	
	
	display_all_menu();
	
	


	clear_heap();

}
