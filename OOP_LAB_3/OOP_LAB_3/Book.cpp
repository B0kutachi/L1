#pragma once
#include <iostream>
#include <string>
#include "Book.h"

using namespace std;

int DemoBook() {
	const int size = 2;
	Book book[size];
	for (int i = 0; i < size; i++) {
		cout << "\nEnter the book #" << i + 1 << ": " << endl;
		ReadBookFromConsole(book[i]);
	}
	for (int i = 0; i < size; i++) {
		cout << "\nThe book #" << i + 1 << ": " << endl;
		WriteBookToConsole(book[i]);
	}

	string author;
	cout << "\nEnter author which u wanna to found: ";
	getline(cin, author);

	FindBookByAuthor(book, size, author, book->AmountAuthors);
	
	return 0;
}

int ReadBookFromConsole(Book& book)
{
	cout << "\nEnter title of the book: ";
	cin >> book.Title;


	cout << "\nEnter release year: ";
	cin >> book.Release;
	while (book.Release < 1 || book.Release > 2023) {
		cout << "\nInvalid year. Enter release year(0 - 2023): ";
		cin >> book.Release;
	}

	cout << "\nEnter amount of pages: ";
	cin >> book.Pages;
	while (book.Pages < 1) {
		cout << "\nInvalid amount. Enter amount of pages(0+): ";
		cin >> book.Pages;
	}

	cout << "\nEnter amount of authors(no more than 10): ";
	cin >> book.AmountAuthors;
	while (book.AmountAuthors < 1 || book.AmountAuthors > 10)
	{
		cout << "\nInvalid amount. Enter amount of authors(no more than 10): ";
		cin >> book.AmountAuthors;
	}

	cin.ignore();
	for (int i = 0; i < book.AmountAuthors; i++) {
		cout << "\nEnter author #" << i + 1 << ": ";
		getline(cin, book.Authors[i]);
	}

	cout << endl;
	return 0;
};

int WriteBookToConsole(Book& book)
{
	for (int i = 1; i < book.AmountAuthors; i++) {
		cout << book.Authors[i - 1] << ", ";
		if (i + 1 == book.AmountAuthors) {
			cout << book.Authors[i] << ".";
		}
	}

	cout << "  " << book.Title;
	cout << ".  " << book.Release;
	cout << ". - " << book.Pages << "p." << endl;

	return 0;
}

int FindBookByAuthor(Book* books, int booksCount, string author, int authorsCount)
{
	for (int i = 0; i < booksCount; i++)
	{
		Book* book = &books[i];
		for (int j = 0; j < authorsCount; j++)
		{
			if (book->Authors[j] == author) {
				cout << "\nFounded book: " << endl;
				WriteBookToConsole(books[i]);
				return 0;
			}
		}
	}
	cout << "\nThere's no book with that author.";
	return -1;
}