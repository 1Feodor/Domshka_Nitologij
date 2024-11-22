insert into artist
values (1, 'Nif-nif');

insert into artist
values (2, 'Naf-naf');

insert into artist
values (3, 'Nuf-nuf');

insert into artist
values (4, 'BioWolf');

insert into genre
values (1, 'Country');

insert into genre
values (2, 'Pop');

insert into genre
values (3, 'Disco');

insert into album
values (1, 'The wolf', '2020-06-28');

insert into album
values (2, 'The pink wind', '2019-03-20');

insert into album
values (3, 'A house in the sky', '2018-09-16');

insert into track 
values (1, 'My father is Fifty Bucks', 182, 3);

insert into track 
values (2, 'The straw dream', 177, 3);

insert into track 
values (3, 'Happy village', 202, 3);

insert into track 
values (4, 'Seasons of the year', 235, 3);

insert into track 
values (5, 'After the sunset', 126, 3);

insert into track 
values (6, 'Air castle', 147, 2);

insert into track 
values (7, 'Before sunrise', 168, 2);

insert into track 
values (8, 'Across the field', 124, 2);

insert into track 
values (9, 'My house is my fortress', 111, 2);

insert into track 
values (10, 'Around the woods', 191, 2);

insert into track 
values (11, 'We are not afraid of the BioWolf', 129);

insert into track 
values (12, 'The Wolf and the Seven Goats', 259);

insert into track 
values (13, 'I can see all your cracks', 149, 1);

insert into track 
values (14, 'I am a gray wolf - click with my teeth', 137, 1);

insert into track 
values (15, 'Count my teeth', 194, 1);

insert into collection 
values (1, 'The BioWolf forever', '2021-02-28');

insert into collection 
values (2, 'Pink world', '2020-04-08');

insert into collection 
values (3, 'Lets live together', '2022-09-25');

insert into collection 
values (4, 'He wont catch up with us.', '2021-12-09');

insert into genreartist (id_genre, id_artist) 
values (1, 1);

insert into genreartist (id_genre, id_artist) 
values (1, 4);

insert into genreartist (id_genre, id_artist) 
values (2, 2);

insert into genreartist (id_genre, id_artist) 
values (2, 3);

insert into genreartist (id_genre, id_artist) 
values (3, 3);

insert into genreartist (id_genre, id_artist) 
values (3, 4);

insert into artistalbum (id_artist , id_album) 
values (1, 2);

insert into artistalbum (id_artist , id_album) 
values (2, 2);

insert into artistalbum (id_artist , id_album) 
values (3, 3);

insert into artistalbum (id_artist , id_album) 
values (4, 1);

insert into trackcollection (id_track , id_collection) 
values (6, 1);

insert into trackcollection (id_track , id_collection) 
values (12, 1);

insert into trackcollection (id_track , id_collection) 
values (13, 1);

insert into trackcollection (id_track , id_collection) 
values (15, 1);

insert into trackcollection (id_track , id_collection) 
values (11, 2);

insert into trackcollection (id_track , id_collection) 
values (10, 2);

insert into trackcollection (id_track , id_collection) 
values (6, 2);

insert into trackcollection (id_track , id_collection) 
values (2, 2);

insert into trackcollection (id_track , id_collection) 
values (1, 3);

insert into trackcollection (id_track , id_collection) 
values (3, 3);

insert into trackcollection (id_track , id_collection) 
values (7, 3);

insert into trackcollection (id_track , id_collection) 
values (8, 3);

insert into trackcollection (id_track , id_collection) 
values (2, 4);

insert into trackcollection (id_track , id_collection) 
values (8, 4);

insert into trackcollection (id_track , id_collection) 
values (9, 4);

insert into trackcollection (id_track , id_collection) 
values (11, 4);