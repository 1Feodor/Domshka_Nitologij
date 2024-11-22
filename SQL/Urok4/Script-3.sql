select title, duration
from track 
ORDER BY duration DESC
LIMIT 1;

select title, duration
from track 
where duration >= 3.5 * 60;

select title, year_of_release 
from collection
where date(year_of_release) BETWEEN '2018-01-01' AND '2020-12-31';

select title, year_of_release 
from collection
where EXTRACT(YEAR from year_of_release) BETWEEN '2018' AND '2020';

select name 
from artist
where  name not like '% %';

select title 
from track
where  title like '%My%' or title like '%my%';