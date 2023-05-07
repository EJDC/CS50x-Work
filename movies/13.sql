SELECT DISTINCT otherstar.name FROM people
JOIN movies ON stars.movie_id = movies.id
JOIN stars kevin ON kevin.movie_id = movies.id
JOIN people kevin ON kevin.person_id = person1.id
JOIN stars otherstar ON otherstar.movie_id = movies.id
JOIN people otherstar ON otherstar.person_id = person2.id
WHERE kevin.name = 'Kevin Bacon' AND kevin.birth = 1958