SELECT AVG(rating) FROM ratings
JOIN ratings.movie_id = movies.id
WHERE movies.year = 2012;