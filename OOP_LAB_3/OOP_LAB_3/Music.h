#pragma once
#include <iostream>
#include <string>

using namespace std;


class Song
{

public:
	enum Genre
	{
		CLASSIC = 1,
		ELECTRONICAL,
		ROCK,
		METAL,
		RAVE,
		HIPHOP,
		JAZZ,
		RAP
	};

private:
	string Title;
	int Duration;
	Genre Genres;

public:
	Song()
	{
		Title = "";
		Duration = 0;
		Genres = CLASSIC;
	}

	Song(string title, int duration, Genre genres) 
	{
		this->Title = title;
		this->Duration = duration;
		this->Genres = genres;
	}

	void SongBuild(string title, int duration, Genre genres)
	{
		this->Title = title;
		this->Duration = duration;
		this->Genres = genres;
	}

	void setTitle(string title)
	{
		this->Title = title;
	}

	void setDuration(int duration)
	{
		this->Duration = duration;
	}

	void setGenres(Genre genres)
	{
		Genres = genres;
	}

	string getTitle()
	{
		return Title;
	}

	int getDuration()
	{
		return Duration;
	}

	Genre getGenres()
	{
		return Genres;
	}

};


class Album
{
private:
	string Title;
	int Release;
	Song Songs[10];

public:
	Album()
	{
		Title = "";
		Release = 0;
	}

	void AlbumBuild(string title, int release)
	{
		this->Title = title;
		this->Release = release;
	}

	void setTitle(string title)
	{
		this->Title = title;
	}

	void setRelease(int release)
	{
		this->Release = release;
	}

	string getTitle()
	{
		return Title;
	}

	int getRelease()
	{
		return Release;
	}
	
	Song* getSongs()
	{
		return Songs;
	}
};


class Band
{
private:
	string Title;
	string Description;
	Album Albums[10];

public:
	void BandBuild(string title, string description)
	{
		this->Title = title;
		this->Description = description;
	}

	void setTitle(string title)
	{
		this->Title = title;
	}

	void setDescription(string description)
	{
		this->Description = description;
	}

	string getTitle()
	{
		return Title;
	}

	string getDescription()
	{
		return Description;
	}

	Album* getAlbums()
	{
		return Albums;
	}

	Song* FindSong(string songTitle)
	{
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 100; j++) {
				if (this->getAlbums()[i].getSongs()[j].getTitle() == songTitle) {
					Song* foundsong = new Song;
					foundsong->setTitle(this->getAlbums()[i].getSongs()[j].getTitle());
					foundsong->setDuration(this->getAlbums()[i].getSongs()[j].getDuration());
					foundsong->setGenres(this->getAlbums()[i].getSongs()[j].getGenres());
					return foundsong;
					break;
				}
			}
		}

		cout << "\nThis song wasn't found. ";
		return nullptr;
	}

	Album* FindAlbum(Song* song)
	{
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (this->getAlbums()[i].getSongs()[j].getTitle() == song->getTitle()) {
					Album* foundalbum = new Album;
					foundalbum->setTitle(this->getAlbums()[i].getTitle());
					foundalbum->setRelease(this->getAlbums()[i].getRelease());
					return foundalbum;
				}
			}
		}

		cout << "\nThis album wasn't found. ";
		return nullptr;
	}

	Song* GetAllSongs(int& allSongsCount)
	{
		allSongsCount = 0;

		for (int i = 0; i < 10; i++) {
			Album album = this->getAlbums()[i];
			for (int j = 0; j < 10; j++) {
				Song song = album.getSongs()[j];
				if (song.getTitle() != "") {
					allSongsCount++;
				}
			}
		}

		Song* allSongs = new Song[allSongsCount];
		int currentIndex = 0;

		for (int i = 0; i < 10; i++) {
			Album album = this->getAlbums()[i];
			for (int j = 0; j < 10; j++) {
				Song song = album.getSongs()[j];
				if (song.getTitle() != "") {
					allSongs[currentIndex].setTitle(song.getTitle());
					allSongs[currentIndex].setDuration(song.getDuration());
					allSongs[currentIndex].setGenres(song.getGenres());
					currentIndex++;
				}
			}
		}

		return allSongs;
	}

	Song* GetAllGenreSongs(Song::Genre findingGenre, int& allSongsCount)
	{
		allSongsCount = 0;
		Song* foundsongs = new Song[10];
		for (int i = 0; i < 10; i++) {
			Album album = this->getAlbums()[i];
			for (int j = 0; j < 10; j++) {
				Song song = album.getSongs()[j];
				if (song.getGenres() == findingGenre) {
					allSongsCount++;
				}
			}
		}

		Song* foundSongs = new Song[allSongsCount];
		int currentIndex = 0;

		for (int i = 0; i < 10; i++) {
			Album album = this->getAlbums()[i];
			for (int j = 0; j < 10; j++) {
				Song song = album.getSongs()[j];
				if (song.getGenres() == findingGenre) {
					foundSongs[currentIndex].setTitle(song.getTitle());
					foundSongs[currentIndex].setDuration(song.getDuration());
					foundSongs[currentIndex].setGenres(song.getGenres());
					currentIndex++;
				}
			}
		}

		return foundSongs;
	}

};


void DemoBand();
