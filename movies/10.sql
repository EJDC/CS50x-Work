SELECT name FROM people
JOIN directors ON directors.person_id = people.id
JOIN movies ON directors.movie_id = movies.id
JOIN ratings ON directors.movie_id = movies.id
WHERE movies.rating >= 9.0