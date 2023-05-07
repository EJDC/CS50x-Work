SELECT AVG(energy) from SONGS
JOIN ARTISTS ON artists.id = songs.artist_id
WHERE artists.name = 'Drake';