SELECT name FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON stars.movie_id = movie.id
WHERE name = 'Toy Story';
