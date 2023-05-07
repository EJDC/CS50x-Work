SELECT title FROM movies
JOIN stars star1 ON star1.movie_id = movies.id
JOIN people person1 ON star1.person_id = person1.id
JOIN stars star2 ON star2.movie_id = movies.id
JOIN people person2 ON star2.person_id = person2.id
WHERE person1.name = 'Johnny Depp' AND person2.name = 'Helena Bonham Carter'