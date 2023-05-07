SELECT DISTINCT otherstar.name
FROM people kevin
JOIN stars kevin_stars ON kevin_stars.person_id = kevin.id
JOIN movies ON movies.id = kevin_stars.movie_id
JOIN stars other_stars ON other_stars.movie_id = movies.id
JOIN people otherstar ON otherstar.id = other_stars.person_id
WHERE kevin.name = 'Kevin Bacon' AND kevin.birth = 1958; AND otherstar.name!= 'Kevin Bacon'