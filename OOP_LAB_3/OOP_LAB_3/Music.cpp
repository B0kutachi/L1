#include "Music.h"


void DemoBand()
{
	Band band;
	band.BandBuild("TOPBAND", "group_#1");
	band.getAlbums()[0].AlbumBuild("album#1", 2019);
	band.getAlbums()[0].getSongs()[0].SongBuild("song#1", 300, Song::RAP);
	band.getAlbums()[0].getSongs()[1].SongBuild("song#2", 298, Song::CLASSIC);
	band.getAlbums()[0].getSongs()[2].SongBuild("song#3", 296, Song::ELECTRONICAL);
	band.getAlbums()[0].getSongs()[3].SongBuild("song#4", 294, Song::ROCK);

	band.getAlbums()[1].AlbumBuild("album#2", 2018);
	band.getAlbums()[1].getSongs()[0].SongBuild("song#5", 292, Song::METAL);
	band.getAlbums()[1].getSongs()[1].SongBuild("song#6", 290, Song::RAVE);
	band.getAlbums()[1].getSongs()[2].SongBuild("song#7", 288, Song::HIPHOP);
	band.getAlbums()[1].getSongs()[3].SongBuild("song#8", 286, Song::ROCK);

	band.getAlbums()[2].AlbumBuild("album#3", 2017);
	band.getAlbums()[2].getSongs()[0].SongBuild("song#9", 284, Song::JAZZ);
	band.getAlbums()[2].getSongs()[1].SongBuild("song#10", 282, Song::CLASSIC);
	band.getAlbums()[2].getSongs()[2].SongBuild("song#11", 280, Song::ELECTRONICAL);
	band.getAlbums()[2].getSongs()[3].SongBuild("song#12", 278, Song::ROCK);
	
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
	Song song;
	song.SongBuild("song#5", 292, Song::METAL);
	Song* findSong = &song;
	Album* album = band.FindAlbum(&song);
	cout << "Album title: " << album->getTitle() << ", Release: " << album->getRelease();

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

	//cout << "________________________________________________________" << allSongsCount;
	cout << "\nFound songs with genre 'ELECTRONICAL': ";
	for (int i = 0; i < allSongsCount; i++) {
		cout << "\nTitle: " << foundGenreSongs[i].getTitle() << ", Duration: " << foundGenreSongs[i].getDuration();
	}

	delete foundsong; foundsong = nullptr;
	delete album; album = nullptr;
	delete[] allSongs; allSongs = nullptr;
	delete[] foundGenreSongs; foundGenreSongs = nullptr;
}