#pragma once
#include <iostream>
#include <string>

using namespace std;

class Book {
public:
	string Title;
	int Release;
	int Pages;
	int AmountAuthors;
	string Authors[10];
};

int DemoBook();

int ReadBookFromConsole(Book& book);

int WriteBookToConsole(Book& book);

int FindBookByAuthor(Book* books, int booksCount, string author, int authorsCount);