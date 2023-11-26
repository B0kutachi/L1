#include "Music.h"

void DemoBand()
{
	Band band;
	band.BandBuild("TOPBAND", "group_#1");
	Album albums[3] = {
		{"album#1", 2019},
		{"album#2", 2018},
		{"album#3", 2017} };
	band.setAlbums(albums, 3);

	Song songs1[4] = {
	{"song#1", 300, Song::RAP},
	{"song#2", 298, Song::CLASSIC},
	{"song#3", 296, Song::ELECTRONICAL},
	{"song#4", 294, Song::ROCK} };
	Song songs2[4] = {
	{"song#5", 292, Song::METAL},
	{"song#6", 290, Song::RAVE},
	{"song#7", 288, Song::HIPHOP},
	{"song#8", 286, Song::ROCK} };
	Song songs3[4] = {
	{"song#9", 284, Song::JAZZ},
	{"song#10", 282, Song::CLASSIC},
	{"song#11", 280, Song::ELECTRONICAL},
	{"song#12", 278, Song::ROCK} };

	band.getAlbums()[0].setSongs(songs1, 4);
	band.getAlbums()[1].setSongs(songs2, 4);
	band.getAlbums()[2].setSongs(songs3, 4);

	// ‘”Õ ÷»ﬂ FindSong
	Song* foundsong = band.FindSong("song#5");
	cout << "\nFound song#5. " << "Title: " << foundsong->getTitle() << ", Duration: " << foundsong->getDuration() << ", Genre: ";
	switch (foundsong->getGenres())
	{
	case 1:
		cout << "CLASSIC ";
		break;
	case 2:
		cout << "ELECTRONICAL ";
		break;
	case 3:
		cout << "ROCK ";
		break;
	case 4:
		cout << "METAL ";
		break;
	case 5:
		cout << "RAVE ";
		break;
	case 6:
		cout << "HIPHOP ";
		break;
	case 7:
		cout << "JAZZ ";
		break;
	case 8:
		cout << "RAP ";
		break;
	}
	cout << endl;

	// ‘”Õ ÷»ﬂ FindAlbum
	Song song("song#5", 292, Song::METAL);
	Song* findSong = &song;
	Album* _album = band.FindAlbum(&song);
	cout << "Album title: " << _album->getTitle() << ", Release: " << _album->getRelease();

	// ‘”Õ ÷»ﬂ GetAllSongs
	int allSongsCount = 12;
	Song* allSongs = band.GetAllSongs(allSongsCount);
	cout << endl << endl;
	for (int i = 0; i < allSongsCount; i++) {
		cout << "Title: " << allSongs[i].getTitle() << ", Duration: " << allSongs[i].getDuration() << ", Genre: ";
		switch (allSongs[i].getGenres())
		{
		case 1:
			cout << "CLASSIC ";
			break;
		case 2:
			cout << "ELECTRONICAL ";
			break;
		case 3:
			cout << "ROCK ";
			break;
		case 4:
			cout << "METAL ";
			break;
		case 5:
			cout << "RAVE ";
			break;
		case 6:
			cout << "HIPHOP ";
			break;
		case 7:
			cout << "JAZZ ";
			break;
		case 8:
			cout << "RAP ";
			break;
		}
		cout << endl;
	}

	// ‘”Õ ÷»ﬂ GetAllGenreSongs
	Song* foundGenreSongs = band.GetAllGenreSongs(Song::ELECTRONICAL, allSongsCount);
	cout << "\nFound songs with genre 'ELECTRONICAL': ";
	for (int i = 0; i < allSongsCount; i++) {
		cout << "\nTitle: " << foundGenreSongs[i].getTitle() << ", Duration: " << foundGenreSongs[i].getDuration();
	}

	delete foundsong; foundsong = nullptr;
	delete _album; _album = nullptr;
	delete[] allSongs; allSongs = nullptr;
	delete[] foundGenreSongs; foundGenreSongs = nullptr;
}