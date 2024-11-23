-- Количество исполнителей в каждом жанре
select id_genre, count(id_genre) as number_of_actors
from genreartist
group by id_genre;

select title, count(id_genre) as number_of_actors
from genre g
join genreartist ga on g.genre_id = ga.id_genre 
group by title;

-- Количество треков, вошедших в альбомы 2019–2020 годов
select a.title, year_of_release, count(t.title) as number_of_tracks
from track t
join album a on t.id_album = a.album_id 
where EXTRACT(YEAR from year_of_release) BETWEEN '2019' AND '2020'
group by a.title, a.year_of_release;

select count(t.title) as number_of_tracks
from track t
left join album a on t.id_album = a.album_id 
where EXTRACT(YEAR from year_of_release) BETWEEN '2019' AND '2020'
;

-- Средняя продолжительность треков по каждому альбому
select a.title, avg(t.duration) as avg_of_tracks
from track t
join album a on t.id_album = a.album_id 
group by a.title;

-- Все исполнители, которые не выпустили альбомы в 2020 году
select name, title, year_of_release
from artist a
join artistalbum aa on a.artist_id = aa.id_artist 
join album al on aa.id_album = al.album_id 
where EXTRACT(YEAR from year_of_release) != '2020';

select name
from artist a
join artistalbum aa on a.artist_id = aa.id_artist 
join album al on aa.id_album = al.album_id 
where EXTRACT(YEAR from year_of_release) != '2020';

-- Названия сборников, в которых присутствует конкретный исполнитель (выберите его сами)
select c.title, ar.name
from collection c 
join trackcollection tc on c.collection_id = tc.id_collection 
join track t on tc.id_track = t.track_id 
join album a on t.id_album = a.album_id 
join artistalbum aal on a.album_id = aal.id_album 
join artist ar on aal.id_artist = ar.artist_id 
where name = 'BioWolf'
group by c.title, ar.name;