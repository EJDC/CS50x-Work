SELECT name FROM people
JOIN people ON stars.person_id = people.id
JOIN movies ON stars.movie_id = movie.id
WHERE movies.name = 'Toy Story'
