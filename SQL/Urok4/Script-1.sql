CREATE TABLE if NOT EXISTS genre (
genre_id SERIAL PRIMARY KEY, 
title VARCHAR(60) NOT NULL
);

CREATE TABLE if NOT EXISTS artist (
artist_id SERIAL PRIMARY KEY, 
name VARCHAR(30) NOT NULL
);

CREATE TABLE if NOT EXISTS album (
album_id SERIAL PRIMARY KEY, 
title VARCHAR(60) NOT NULL, 
year_of_release DATE NOT NULL
);

CREATE TABLE if NOT EXISTS track (
track_id SERIAL PRIMARY KEY, 
title VARCHAR(60) NOT NULL, 
duration INTEGER NOT NULL,
id_album INTEGER references album(album_id)
);

CREATE TABLE if NOT EXISTS collection (
collection_id SERIAL PRIMARY KEY, 
title VARCHAR(60) NOT NULL, 
year_of_release DATE NOT null
);

CREATE TABLE if NOT EXISTS genreArtist (
id_genre INTEGER references genre(genre_id), 
id_artist INTEGER references artist(artist_id), 
constraint pk primary key(id_genre, id_artist)
);

CREATE TABLE if NOT EXISTS artistAlbum (
id_artist INTEGER references artist(artist_id), 
id_album INTEGER references album(album_id), 
constraint aA primary key(id_artist, id_album)
);

CREATE TABLE if NOT EXISTS trackCollection (
id_track INTEGER references track(track_id), 
id_collection INTEGER references collection(collection_id), 
constraint tC primary key(id_track, id_collection)
);
