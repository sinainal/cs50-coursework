SELECT name from people where id IN(select person_id from stars where movie_id IN(select id from movies where year = 2004)) Group by name order by birth;
