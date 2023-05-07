SELECT songs.name from SONGS
JOIN ARTISTS ON artists.id = songs.artist_id
WHERE LOWER(artists.name) LIKE '%feat.%';