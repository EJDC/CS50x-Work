SELECT title FROM movies
JOIN stars ON stars.person_id = people.id
JOIN movies ON stars.movie_id = movies.id
JOIN ratings ON ratings.movie_id = movies.id
