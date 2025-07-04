SELECT name from people where id IN(select person_id from directors where movie_id IN(select movie_id from ratings where rating >= 9.0 )) Group by name;
